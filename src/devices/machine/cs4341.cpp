// license:BSD-3-Clause
// copyright-holders:blueonesarefaster
/***************************************************************************

Digital stereo dac with volume control

TODO: Change the volume of sounds

***************************************************************************/

#include "emu.h"
#include "machine/cs4341.h"

constexpr int STATE_IDLE(0);
constexpr int STATE_DEVSEL(1);
constexpr int STATE_ADDRESSLOW(2);
constexpr int STATE_DATAIN(3);
constexpr int STATE_READSELACK(4);
constexpr int STATE_DATAOUT(5);

constexpr int DEVSEL_RW(1);


//**************************************************************************
//  GLOBAL VARIABLES
//**************************************************************************

DEFINE_DEVICE_TYPE(CS4341, cs4341_device, "cs4341", "CS4341 Stereo DAC with volume control")

//**************************************************************************
//  LIVE DEVICE
//**************************************************************************

//-------------------------------------------------
//  cs4341_device - constructor
//-------------------------------------------------

cs4341_device::cs4341_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: device_t(mconfig, CS4341, tag, owner, clock),
	m_scl(0),
	m_sdaw(0),
	m_sdar(1),
	m_state(STATE_IDLE),
	m_bits(0),
	m_shift(0),
	m_devsel(0),
	m_byteaddr(0)
{
}


//-------------------------------------------------
//  device_start - device-specific startup
//-------------------------------------------------

void cs4341_device::device_start()
{
	save_item( NAME(m_scl) );
	save_item( NAME(m_sdaw) );
	save_item( NAME(m_sdar) );
	save_item( NAME(m_state) );
	save_item( NAME(m_bits) );
	save_item( NAME(m_shift) );
	save_item( NAME(m_devsel) );
	save_item( NAME(m_byteaddr) );
	save_item(NAME(m_data));
}

void cs4341_device::device_reset()
{
	m_data[0]=0;
	m_data[1]=0x83;
	m_data[2]=0;
	m_data[3]=0;
	m_data[4]=0;
}


//**************************************************************************
//  READ/WRITE HANDLERS
//**************************************************************************

void cs4341_device::write_sda(int state)
{
	state = state != 0;
	if( m_sdaw != state )
	{
		m_sdaw = state;

		if( m_scl )
		{
			if( m_sdaw )
			{
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

void cs4341_device::write_scl(int state)
{
	state = state != 0;
	if( m_scl != state )
	{
		m_scl = state;

		switch( m_state )
		{
		case STATE_DEVSEL:
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
							
							if((m_devsel&0xfe)!=0x20)
							{
								m_state = STATE_IDLE;
							}
							else if( ( m_devsel & DEVSEL_RW ) == 0 )
							{
								m_state = STATE_ADDRESSLOW;
							}
							else
							{
								m_state = STATE_READSELACK;
							}
							break;

						case STATE_ADDRESSLOW:
							m_byteaddr = m_shift;

							
							m_byteaddr = ((m_byteaddr&0x7f)%5) | (m_byteaddr&0x80);

							m_state = STATE_DATAIN;

							break;

						case STATE_DATAIN:
							m_data[ m_byteaddr&0x7f]=m_shift;
							if(BIT(m_byteaddr,7))
							{
								m_byteaddr++;
								
								m_byteaddr = ((m_byteaddr&0x7f)%5) | 0x80;
							}
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

						m_shift = m_data[m_byteaddr&0x7f];

						if(BIT(m_byteaddr,7))
						{
							m_byteaddr++;
							m_byteaddr = ((m_byteaddr&0x7f)%5) | 0x80;
						}
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


int cs4341_device::read_sda()
{
	int res = m_sdar & 1;

	return res;
}
