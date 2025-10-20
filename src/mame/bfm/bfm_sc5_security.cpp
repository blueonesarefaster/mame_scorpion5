// license:BSD-3-Clause
// copyright-holders:blueonesarefaster
/***************************************************************************

Security/config pic for Scorpion5

***************************************************************************/

#include "emu.h"
#include "bfm_sc5_security.h"

constexpr int STATE_IDLE(0);
constexpr int STATE_DEVSEL(1);
constexpr int STATE_DATAIN(2);
constexpr int STATE_READSELACK(3);
constexpr int STATE_DATAOUT(4);

constexpr int DEVSEL_RW(1);

//**************************************************************************
//  GLOBAL VARIABLES
//**************************************************************************

DEFINE_DEVICE_TYPE(BFM_SC5_SECURITY, bfm_sc5_security_device, "bfmsc5security", "BFM Scorpion5 Security")

//**************************************************************************
//  LIVE DEVICE
//**************************************************************************

//-------------------------------------------------
//  bfm_sc5_security_device - constructor
//-------------------------------------------------

bfm_sc5_security_device::bfm_sc5_security_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: device_t(mconfig, BFM_SC5_SECURITY, tag, owner, clock),
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

void bfm_sc5_security_device::device_start()
{
	save_item( NAME(m_scl) );
	save_item( NAME(m_sdaw) );
	save_item( NAME(m_sdar) );
	save_item( NAME(m_state) );
	save_item( NAME(m_bits) );
	save_item( NAME(m_shift) );
	save_item( NAME(m_devsel) );
	save_item( NAME(m_byteaddr) );
}

void bfm_sc5_security_device::device_reset()
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

void bfm_sc5_security_device::write_sda(int state)
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

void bfm_sc5_security_device::write_scl(int state)
{
	state = state != 0;
	if( m_scl != state )
	{
		m_scl = state;

		switch( m_state )
		{
		case STATE_DEVSEL:
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
							
							if((m_devsel&0xfe)!=0x12)
							{
								m_state = STATE_IDLE;
							}
							else if( ( m_devsel & DEVSEL_RW ) == 0 )
							{
								m_byteaddr = 0;
								m_state = STATE_DATAIN;
							}
							else
							{
								uint8_t key[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
								m_byteaddr = 0;
								crypt(key, m_data,m_data);
								m_data[12]=0x02;
								m_data[13]=0x76;
								m_data[14]='B';
								m_data[15]='F';
								m_data[16]='G';
								m_data[17]='P';
								m_state = STATE_READSELACK;
							}
							break;

						case STATE_DATAIN:
							m_data[ m_byteaddr++] = m_shift;
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
						m_shift = m_data[m_byteaddr++];
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


int bfm_sc5_security_device::read_sda()
{
	int res = m_sdar & 1;

	return res;
}

void bfm_sc5_security_device::crypt( uint8_t *key, uint8_t *plain, uint8_t *cipher)
{
//algorithm removed!
}
