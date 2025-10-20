// license:BSD-3-Clause
// copyright-holders:blueonesarefaster
/***************************************************************************

I2C RTC + 512*8 memory + watchdog

inputs:
 sda       serial data
 scl       serial clock

outputs:
 sda       serial data


TODO: implement watchdog

***************************************************************************/

#include "emu.h"
#include "machine/isl12027.h"

constexpr int STATE_IDLE(0);
constexpr int STATE_DEVSEL(1);
constexpr int STATE_ADDRESSHIGH(2);
constexpr int STATE_ADDRESSLOW(3);
constexpr int STATE_DATAIN(4);
constexpr int STATE_READSELACK(5);
constexpr int STATE_DATAOUT(6);

constexpr int DEVSEL_RW(1);


enum
{
	REG_SCA0=0x200,
	REG_MNA0,
	REG_HRA0,
	REG_DTA0,
	REG_MOA0,
	REG_YRA0,
	REG_DWA0,
	REG_Y2K0,
	REG_SCA1,
	REG_MNA1,
	REG_HRA1,
	REG_DTA1,
	REG_MOA1,
	REG_YRA1,
	REG_DWA1,
	REG_Y2K1,
	REG_BL,
	REG_INT,
	REG_ATR,
	REG_DTR,
	REG_PWR,
	REG_SC = 0x230,
	REG_MN,
	REG_HR,
	REG_DT,
	REG_MO,
	REG_YR,
	REG_DW,
	REG_Y2K,
	REG_SR = 0x23f
};

enum
{
	SR_RTCF,
	SR_WEL,
	SR_RWEL,
	SR_BIT3,
	SR_OSCF,
	SR_AL0,
	SR_AL1,
	SR_BAT
};

//**************************************************************************
//  GLOBAL VARIABLES
//**************************************************************************

DEFINE_DEVICE_TYPE(ISL12027, isl12027_device, "isl12027", "ISL12027 RTC with 512x8 RAM and watchdog")

//**************************************************************************
//  LIVE DEVICE
//**************************************************************************

//-------------------------------------------------
//  isl12027_device - constructor
//-------------------------------------------------

isl12027_device::isl12027_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: device_t(mconfig, ISL12027, tag, owner, clock),
	device_rtc_interface(mconfig, *this),
	device_nvram_interface(mconfig, *this),
	m_region(*this, DEVICE_SELF),
	m_clock_timer(nullptr),
	m_scl(0),
	m_sdaw(0),
	m_sdar(1),
	m_state(STATE_IDLE),
	m_bits(0),
	m_shift(0),
	m_devsel(0),
	m_addresshigh(0),
	m_byteaddr(0),
	m_page_offset(0),
	m_page_written_size(0),
	m_write_page_size(0),
	m_read_page_size(0)
{
}


//-------------------------------------------------
//  device_start - device-specific startup
//-------------------------------------------------

void isl12027_device::device_start()
{
	// allocate timers
	m_clock_timer = timer_alloc(FUNC(isl12027_device::clock_tick), this);
	m_clock_timer->adjust(attotime::from_hz(clock() / 32768), 0, attotime::from_hz(clock() / 32768));

	save_item( NAME(m_scl) );
	save_item( NAME(m_sdaw) );
	save_item( NAME(m_sdar) );
	save_item( NAME(m_state) );
	save_item( NAME(m_bits) );
	save_item( NAME(m_shift) );
	save_item( NAME(m_devsel) );
	save_item( NAME(m_addresshigh) );
	save_item( NAME(m_byteaddr) );
	save_item( NAME(m_page_offset) );
	save_item( NAME(m_page_written_size) );
	save_item( NAME(m_write_page_size) );
	save_item( NAME(m_read_page_size) );
	save_item( NAME(m_page) );
	save_item(NAME(m_data));
	save_item(NAME(m_accessing_rtc));
}


//-------------------------------------------------
//  nvram_default - called to initialize NVRAM to
//  its default state
//-------------------------------------------------

void isl12027_device::nvram_default()
{
	std::fill(std::begin(m_data), std::end(m_data), 0);

	/* populate from a memory region if present */
	if (m_region.found())
	{
		if( m_region->bytes() != sizeof(m_data) )
		{
			fatalerror( "isl12027 region '%s' wrong size (expected size = 0x%X)\n", tag(), sizeof(m_data) );
		}

		if( m_region->bytewidth() != 1 )
		{
			fatalerror( "isl12027 region '%s' needs to be an 8-bit region\n", tag() );
		}

		std::copy_n(m_region->base(), m_region->bytes(), &m_data[0]);
		m_data[REG_SR] &= ~((1<<SR_WEL) | (1<<SR_RWEL));
	}
}


//-------------------------------------------------
//  nvram_read - called to read NVRAM from the
//  .nv file
//-------------------------------------------------

bool isl12027_device::nvram_read( util::read_stream &file )
{
	auto const [err, actual] = read( file, &m_data[0], sizeof(m_data) );
	m_data[REG_SR] &= ~((1<<SR_WEL) | (1<<SR_RWEL));
	return !err && ( actual == sizeof(m_data) );
}

//-------------------------------------------------
//  nvram_write - called to write NVRAM to the
//  .nv file
//-------------------------------------------------

bool isl12027_device::nvram_write( util::write_stream &file )
{
	auto const [err, actual] = write( file, &m_data[0], sizeof(m_data) );
	return !err;
}

TIMER_CALLBACK_MEMBER(isl12027_device::clock_tick)
{
	advance_seconds();
}

void isl12027_device::rtc_clock_updated(int year, int month, int day, int day_of_week, int hour, int minute, int second)
{
	m_data[REG_SC] = convert_to_bcd(second);
	m_data[REG_MN] = convert_to_bcd(minute);
	if(m_data[REG_HR]&0x80)
	{
		m_data[REG_HR] = 0x80 | convert_to_bcd(hour);
	}
	else
	{
		m_data[REG_HR]=0;
		if(hour>=12)
		{
			m_data[REG_HR]=0x20;
			hour-=12;
		}
		if(hour==0)
		{
			hour=12;
		}
		m_data[REG_HR] |=hour;
	}
	m_data[REG_DW] = convert_to_bcd(day_of_week);
	m_data[REG_DT] = convert_to_bcd(day);
	m_data[REG_MO] = convert_to_bcd(month);
	m_data[REG_YR] = convert_to_bcd(year);
	m_data[REG_Y2K] = 0x20;
}

//**************************************************************************
//  READ/WRITE HANDLERS
//**************************************************************************

void isl12027_device::write_sda(int state)
{
	state = state != 0;
	if( m_sdaw != state )
	{
		m_sdaw = state;

		if( m_scl )
		{
			if( m_sdaw )
			{
				if( m_page_written_size > 0 )
				{
					bool clear_rwel = false;
					int base = data_offset();
					int root = base & ~( m_write_page_size - 1 );
					for( int i = 0; i < m_page_written_size; i++ )
					{
						unsigned address = root | ((base + i) & (m_write_page_size - 1));

						if(m_accessing_rtc)
						{
							if(address==REG_SR)
							{
								if(BIT(m_page[i],SR_RWEL))
								{
									if(BIT(m_data[REG_SR],SR_WEL))
									{
										m_data[address] = m_page[i];
									}
								}
								else
								{
									m_data[address] = m_page[i];
								}
							}
							else
							{
								if(BIT(m_data[REG_SR],SR_RWEL))
								{
									clear_rwel = true;
									if(address==REG_HR)
									{
										m_data[address] = (m_data[address]&0x80) | m_page[i];
									}
									else
									{
										m_data[address] = m_page[i];
									}
								}
							}
						}
						else
						{
							m_data[address] = m_page[i];
						}
					}
					if(clear_rwel)
					{
						m_data[REG_SR] &= ~(1<<SR_RWEL);
					}

					m_page_written_size = 0;
				}
				m_state = STATE_IDLE;
			}
			else
			{
				m_state = STATE_DEVSEL;
				m_bits = 0;
			}

			m_sdar = 1;
		}
	}
}

void isl12027_device::write_scl(int state)
{
	state = state != 0;
	if( m_scl != state )
	{
		m_scl = state;

		switch( m_state )
		{
		case STATE_DEVSEL:
		case STATE_ADDRESSHIGH:
		case STATE_ADDRESSLOW:
		case STATE_DATAIN:
			if( m_bits < 8 )
			{
				if( m_scl )
				{
					m_shift = ( ( m_shift << 1 ) | m_sdaw ) & 0xff;
					m_bits++;
				}
			}
			else
			{
				if( m_scl )
				{
					m_bits++;
				}
				else
				{
					if( m_bits == 8 )
					{
						switch( m_state )
						{
						case STATE_DEVSEL:
							m_devsel = m_shift;
							
							m_accessing_rtc = 0;

							if((m_devsel&0xfe)==0xde)
							{
								m_accessing_rtc = 1;
							}

							if((m_devsel&0xfe)!=0xae && (m_devsel&0xfe)!=0xde)
							{
								m_state = STATE_IDLE;
							}
							else if( ( m_devsel & DEVSEL_RW ) == 0 )
							{
								m_state = STATE_ADDRESSHIGH;
							}
							else
							{
								m_state = STATE_READSELACK;
							}
							break;

						case STATE_ADDRESSHIGH:
							m_addresshigh = m_shift;

							m_state = STATE_ADDRESSLOW;
							break;

						case STATE_ADDRESSLOW:
							m_byteaddr = m_shift | m_addresshigh << 8;
							m_page_offset = 0;
							m_page_written_size = 0;

							m_state = STATE_DATAIN;

							if(m_accessing_rtc)
							{
								m_write_page_size = 16;
								m_read_page_size = 0x40;
								m_byteaddr += 0x200;
								if(m_byteaddr >= 0x240)
								{
									m_state = STATE_IDLE;
								}
							}
							else
							{
								m_write_page_size = 16;
								m_read_page_size = 512;
								if(m_byteaddr >= 512)
								{
									m_state = STATE_IDLE;
								}
							}
							break;

						case STATE_DATAIN:
							m_page[ m_page_offset ] = m_shift;

							m_page_offset++;
							if( m_page_offset == m_write_page_size )
								m_page_offset = 0;
							m_page_written_size++;
							if( m_page_written_size > m_write_page_size)
								m_page_written_size = m_write_page_size;
							break;
						}

						if( m_state != STATE_IDLE )
						{
							m_sdar = 0 ;
						}
					}
					else
					{
						m_bits = 0;
						m_sdar = 1;
					}
				}
			}
			break;

		case STATE_READSELACK:
			m_bits = 0;
			m_state = STATE_DATAOUT;
			break;

		case STATE_DATAOUT:
			if( m_bits < 8 )
			{
				if( m_scl )
				{
					m_bits++;
				}
				else
				{
					if( m_bits == 0 )
					{
						int offset = data_offset();

						m_shift = m_data[offset];
						m_byteaddr = (m_byteaddr & ~(m_read_page_size - 1)) | ((m_byteaddr + 1) & (m_read_page_size - 1));

					}

					m_sdar = ( m_shift >> 7 ) & 1;

					m_shift = ( m_shift << 1 ) & 0xff;
				}
			}
			else
			{
				if( m_scl )
				{
					if( m_sdaw )
					{
						m_state = STATE_IDLE;
					}

					m_bits = 0;
				}
				else
				{
					m_sdar = 1;
				}
			}
			break;
		}
	}
}


int isl12027_device::read_sda()
{
	int res = m_sdar & 1;

	return res;
}

int isl12027_device::data_offset()
{
	if(m_accessing_rtc)
	{
		return (m_byteaddr & 0x3f) | 0x200;
	}
	else
	{
		return m_byteaddr & 0x1ff;
	}
}
