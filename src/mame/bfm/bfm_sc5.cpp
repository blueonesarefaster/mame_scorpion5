// license:BSD-3-Clause
// copyright-holders:David Haywood
/*

    Scorpion 5

    Skeleton Driver - For note keeping.

    This system is not emulated.

 SCORPION 5 PCB
 _________________________________________________________________________
 | ______________________  _____________  _____________  _________    __  |
 | |____PLUG_J_LAMPS_____| |___PLUG_K___| |___PLUG_L___| |_PLUG_M_|   |P| |
 |                                                                    |L| |
 | D20NF D20NF D20NF D20NF D20NF D20NF D20NF                          |N| |
 | D20NF D20NF D20NF D20NF D20NF D20NF D20NF                          __  |
 | __          D20NF  D20NF                    MM74HCT                |P| |
 | |P|                                                                |L| |
 | |L| ______  ______ ______  ______  ULN28030AG  CS4341AKSZ          |P| |
 | |U| ULN28030AG x 2 UDN2982LWT x 2                                  __  |
 | |G|               ____ ____ ____   ULN28030AG                      |P| |
 | | |               HC14 HC14 HC14  _________  __________  ___       |L| |
 | |F|               ______  ______  |AMI S   | |YAMAHA   | |P |      |Q| |
 | |_|               UDN2982LWT x 2  |0728DC0 | |YMZ280B-F| |L |      __  |
 | __   _____  _____                 |BFG206ML| |_________| |U | IC20 |P| |
 | |P|  |    | |    |                 62215-001      XTL1   |G |      |L| |
 | |L|  |DB9 | |DB9 |                                       |  | IC19 |R| |
 | |E|  |MALE| |FEMALE                 ______   ___________ |Z |      |_| |
 | |_|  |____| |____| 74HCT00          |NXP  |  |COLDFIRE  ||  |  __  __  |
 | __            ___      XTL3  SCC68681C1A44|  |MCF5206EAB40  |  |P| |P| |
 | |P|           |SW|  o <- LED        |_____|  |          ||  |  |L| |L| |
 | |L|           | 4| __                        |          ||  |  |U| |U| |
 | |U|           |__| |_| SW RESET              |__________||  |  |G| |G| |
 | |G|           |SW| |_| SW TEST      ____  ______  ______ |  |  | | | | |
 | | |           | 1|                  |GAL| IS62C256AL x 2 |__|  |U| |S| |
 | |D|           |__|                  |___|                          __  |
 | |_|                 o o o o o o o <- LEDS                     XTL2 |P| |
 |  _______ _______ ____________________                   _______    |L| |
 | |PLUG C||PLUG B| |______PLUG A_______|    BATTERY 3.6V  |PLUG V|   |T| |
 |________________________________________________________________________|

SW1 = 8 dipswitches
SW4 = 8 dipswitches

IC20 = MC1489DG
IC19 = SN75188

XTL1 = 16.9344 MHz
XTL2 = 40.0000 MHz
XTL3 = 3.6864 MHz

PLUG A = POWER IN
PLUG B = CAB SWITCHES
PLUG C = REEL INPUTS
PLUG D = REEL OUTPUTS
PLE = PLUG E = GAME SWITCHES
PLUG F = L.E.D.S
PLUG J = LAMPS
PLUG K = REEL LAMPS
PLUG L = GENERAL I/O
PLUG M = AUDIO OUTPUT
PLN = PLUG N = ALPHA
PLP = PLUG P = SEC METER
PLQ = PLUG Q = CCTalk I/F
PLR = PLUG R = RS232 PORT 2
PLUG S = RS232 PORT 1 (DB25 female)
PLT = PLUG T = I2C I/F
PLUG U = BDM I/F
PLUG V = I2C I/F
PLUG Z = GAME CARD / VIDEO CARD


ISS 3 ADDER 5 VIDEO CARD

       COMPONENT SIDE                           SOLDER SIDE
  ___________________________            ___________________________
 | _______  _______ _______ |            |                          |
 ||      | |__CN2_||__CN1_| |            |                          |
 || IC3  |     MAX202 MAX202|            |                          |
 ||______|  XTL3            |            |                          |
 |  _________________       |___      ___|                          |
 | |                | ___   |__|      |__|                          |
 | | ROM 2 IC7      | |IC8  |__|      |__|                          |
 | |________________|       |__| PLG1 |__|                          |
 |  _________________       |__|      |__|                          |
 | |                |       |__|      |__|                          |
 | | ROM 1 IC6      | XTL2  |__|      |__|                          |
 | |________________|       |__|      |__|                          |
 | _______________________  |__|      |__|  ____                    |
 ||_|_|_|_|__PLG3__|_|_|_|  |__|      |__|  |IC | ____________      |
 |    ____                  |__|      |__|  |11 | |     ______|     |
 |   |IC5|                  |__|      |__|  |___| |    |__          |
 |   |___|              XTL1|__|      |__|  ____  |    |__          |
 |  __________________      |__|      |__|  |IC | |    |__          |
 |  |                 |     |__|      |__|  | 9 | |PL1 |__          |
 |  | IC1             |     |__|      |__|  |___| |    |__          |
 |  | YAMAHA          |     |__|      |__|  ____  |    |__          |
 |  | YGV619-V        |     |__|      |__|  |IC | |    |__          |
 |  |                 |     |__|      |__|  |10 | |    |__          |
 |  |                 |     |            |  |___| |    |______      |
 |  |_________________|     |            |        |___________|     |
 | _____    _____       ____|            |____                      |
 | |    |   |    |     |                      |                     |
 | | IC2|   | IC4|     |                      |                     |
 | |    |   |    |     |                      |                     |
 | |____|   |____|     |                      |                     |
 |             ______  |                      |  ______             |
 |_____________|     |_|                      |_|     |_____________|
              | PLG2  |                        |       |
              |_______|                        |_______|

XTL1 = 20.00 MHz
XTL2 = 20.00 MHz
XTL3 = 3.686 MHz

IC2 = Samsung K4S641632H-UC75
IC3 = Philips / NXP SCC6861C1A44
IC4 = Samsung K4S641632H-UC75
IC5 = GAL16V8D
IC8 = PIC (for external Serial EEPROM)
IC9 = LCX245
IC10 = LCX245
IC11 = 74HCT2730

PLG1 = To mother board
PLG2 = VGA OUT (HD15)
PLG3 = Flash (for pluging flash ROMs)

CN1 = RS232 Port 3
CN2 = RS232 Port 4

PL1 = Compact Flash Slot

*/


#include "emu.h"
#include "bfm_sc5.h"

#include "awpvid.h"

#include "bfm_sc45_helper.h"
#include "speaker.h"

#include "bfm_sc5.lh"
#include "bfm_sc5_gu96x8.lh"



uint16_t bfm_sc5_state::sc5_duart_r(offs_t offset, uint16_t mem_mask)
{
	if (ACCESSING_BITS_8_15)
	{
		return m_duart->read(offset)<<8;
	}
	else
	{
		logerror("%s: duart_r %1x %04x\n", machine().describe_context(), offset, mem_mask);
		return 0;
	}

}

void bfm_sc5_state::sc5_duart_w(offs_t offset, uint16_t data, uint16_t mem_mask)
{
	// clearly a duart of some kind, write patterns are the same as SC4 games
//  logerror("%s: duart_w %1x %04x %04x\n", machine().describe_context(), offset, data, mem_mask);

	if (ACCESSING_BITS_8_15)
	{
		m_duart->write(offset,(data>>8)&0x00ff);
	}
	else
	{
		logerror("%s: duart_w %1x %04x %04x\n", machine().describe_context(), offset, data, mem_mask);
	}

}

uint8_t bfm_sc5_state::sc5_mux1_r(offs_t offset)
{
	if(offset < 128)
	{
		if(offset & 0x0f)
		{
			return 0;
		}
		else
		{
			if((offset>>4) < 4)
			{
				uint8_t data = (m_mux1_in[(offset>>4) + 8]->read() & 0x7)<<5;
				return m_mux1_in[(offset>>4)]->read() | data;
			}
			else
			{
				uint8_t data = (m_mux1_in[(offset>>4) + 4]->read() & 0x18)<<2;
				return m_mux1_in[(offset>>4)]->read() | data;
			}
		}
	}
	else
	{
		//switch (offset)
		//{
//			case 0x20:
				//return 0xff;
				//return machine().rand();
		//}
	}

	logerror("%s: sc5_mux1_r %1x\n", machine().describe_context(), offset);

	return 0xff;
}


void bfm_sc5_state::sc5_mux1_w(offs_t offset, uint8_t data)
{
	if ((offset&0xf)==0)
	{
		mux_output_w((offset & 0x01f0)>>4, data);
	}
	else
	{
		logerror("%s: sc5_mux1_w %1x %04x\n", machine().describe_context(), offset, data);
	}
}

uint8_t bfm_sc5_state::sc5_mux2_r(offs_t offset)
{
	if(offset < 128)
	{
		if(offset & 0x0f)
		{
			return 0;
		}
		else
		{
			if((offset>>4) < 4)
			{
				uint8_t data = (m_mux2_in[(offset>>4) + 8]->read() & 0x7)<<5;
				return m_mux2_in[(offset>>4)]->read() | data;
			}
			else
			{
				uint8_t data = (m_mux2_in[(offset>>4) + 4]->read() & 0x18)<<2;
				return m_mux2_in[(offset>>4)]->read() | data;
			}
		}
	}
	else
	{
		//switch (offset)
		//{
//			case 0x20:
				//return 0xff;
				//return machine().rand();
		//}
	}

	logerror("%s: sc5_mux2_r %1x\n", machine().describe_context(), offset);

	return 0xff;
}

void bfm_sc5_state::sc5_mux2_w(offs_t offset, uint8_t data)
{
	if ((offset&0xf)==0)
	{
		mux_output2_w((offset & 0x01f0)>>4, data);
	}
	else
	{
		logerror("%s: sc5_mux2_w %1x %04x\n", machine().describe_context(), offset, data);
	}
}

void bfm_sc5_state::sec_port_w(offs_t offset, uint8_t data)
{
	switch (offset)
	{
		case 0x0:
			m_sec->cs_w(BIT(data,2));
			m_sec->data_w(BIT(data,1));
			m_sec->clk_w(BIT(data,0));
			//m_maincpu->gpio_pin_w(1,m_sec->data_r());
			//m_maincpu->gpio_pin_w(0,1); // test switch input - to sort
			break;

		case 0x1:
		case 0x2:
		case 0x3:
			logerror("%s: 01020300_w %d - %02x\n", machine().describe_context(), offset, data);
			break;
	}
}

uint8_t bfm_sc5_state::read_port_a()
{
	return (m_sec->data_r() ? 2 : 0 ) | m_test_switch->read();
	//m_maincpu->gpio_pin_w(1,m_sec->data_r());
	//m_maincpu->gpio_pin_w(0,1); // test switch input - to sort
}

void bfm_sc5_state::yamaha_w(offs_t offset, uint8_t data)
{
	m_ymz->write(BIT(offset,1), data);
}

uint8_t bfm_sc5_state::yamaha_r(offs_t offset)
{
	return m_ymz->read(BIT(offset,1));
}

void bfm_sc5_state::sc5_map(address_map &map)
{
	// ROM (max size?)
	map(0x00000000, 0x002fffff).rom();
	// ?
	map(0x01000000, 0x0100ffff).ram().share("nvram");;

#if 1
	// dev1
	map(0x01010000, 0x010101ff).rw(FUNC(bfm_sc5_state::sc5_mux2_r), FUNC(bfm_sc5_state::sc5_mux2_w));

	map(0x010102f0, 0x010102f3).w(FUNC(bfm_sc5_state::reel3_w));

	map(0x01010330, 0x01010333).w(FUNC(bfm_sc5_state::reel24_w));
#endif


#if 0

	map(0x01010200, 0x01010203).nopw();
	map(0x01010210, 0x01010213).nopw();
	map(0x01010220, 0x01010223).nopw();
	map(0x01010230, 0x01010233).nopw();

	map(0x01010280, 0x01010283).nopw();

	map(0x010102a0, 0x010102a3).nopw();

	map(0x010102c0, 0x010102c3).nopw();

	map(0x010102f0, 0x010102f3).w(FUNC(bfm_sc5_state::reel3_w));

	map(0x01010300, 0x01010303).nopw();

	map(0x01010330, 0x01010333).w(FUNC(bfm_sc5_state::reel24_w));

	map(0x01010360, 0x01010363).nopw();

	map(0x01010380, 0x01010383).nopw();
	map(0x01010390, 0x01010393).nopw();
#endif

	map(0x01010244, 0x0101024b).rw(FUNC(bfm_sc5_state::yamaha_r),FUNC(bfm_sc5_state::yamaha_w));

#if 1
	
	map(0x01020000, 0x010201ff).rw(FUNC(bfm_sc5_state::sc5_mux1_r), FUNC(bfm_sc5_state::sc5_mux1_w));
#endif

#if 0

	map(0x01020200, 0x01020203).nopw();
	map(0x01020210, 0x01020213).nopw();
	map(0x01020220, 0x01020223).nopw();
	map(0x01020230, 0x01020233).nopw();

	map(0x01020280, 0x01020283).nopw();

	map(0x010202a0, 0x010202a3).nopw();
	map(0x010202b0, 0x010202b3).nopw();
	map(0x010202c0, 0x010202c3).nopw();
#endif
	map(0x010202F0, 0x010202F3).rw(FUNC(bfm_sc5_state::sc5_10202F0_r), FUNC(bfm_sc5_state::sc5_10202F0_w));
#if 1
	map(0x01020300, 0x01020303).w(FUNC(bfm_sc5_state::sec_port_w));
	map(0x01020330, 0x01020333).w(FUNC(bfm_sc5_state::reel12_w));

	map(0x01020350, 0x01020353).nopw();
	map(0x01020360, 0x01020363).nopw();
	map(0x01020370, 0x01020373).nopw();

	map(0x01020390, 0x01020393).nopw();
#endif
	map(0x02000000, 0x0200001f).rw(FUNC(bfm_sc5_state::sc5_duart_r),FUNC(bfm_sc5_state::sc5_duart_w));

	// ram
	map(0x40000000, 0x4000ffff).ram();
}

INPUT_PORTS_START( bfm_sc5 )
	PORT_START("MUX1IN-0")
	PORT_DIPNAME( 0x01, 0x01, "IN1 0-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 0-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 0-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 0-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 0-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1) PORT_NAME("Cancel")
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON3) PORT_NAME("Hold 1")
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3) PORT_NAME("Hold 2")
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON4) PORT_NAME("Hold 3")
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4) PORT_NAME("Collect")

	PORT_START("MUX1IN-2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON5) PORT_NAME("Change Stake")
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON5) PORT_NAME("Start")
	PORT_DIPNAME( 0x02, 0x02, "IN1 2-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 2-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 2-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-3")
	PORT_DIPNAME( 0x01, 0x01, "IN1 3-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 3-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 3-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 3-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 3-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-4")
	PORT_DIPNAME( 0x01, 0x01, "IN1 4-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 4-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 4-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 4-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 4-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-5")
	PORT_DIPNAME( 0x01, 0x01, "IN1 5-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 5-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 5-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 5-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 5-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-6")
	PORT_DIPNAME( 0x01, 0x01, "IN1 6-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 6-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 6-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 6-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 6-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-7")
	PORT_DIPNAME( 0x01, 0x01, "IN1 7-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 7-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 7-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 7-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 7-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-8")
	PORT_DIPNAME( 0x01, 0x01, "IN1 8-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 8-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 8-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 8-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 8-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-9")
	PORT_DIPNAME( 0x01, 0x01, "IN1 9-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 9-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 9-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 9-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 9-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-10")
	PORT_DIPNAME( 0x01, 0x01, "IN1 10-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 10-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 10-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 10-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 10-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX1IN-11")
	PORT_DIPNAME( 0x01, 0x01, "IN1 11-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN1 11-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN1 11-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN1 11-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN1 11-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-0")
	PORT_DIPNAME( 0x01, 0x01, "IN2 0-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 0-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 0-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 0-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 0-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-1")
	PORT_DIPNAME( 0x01, 0x01, "IN2 1-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 1-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 1-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 1-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 1-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-2")
	PORT_DIPNAME( 0x01, 0x01, "IN2 2-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 2-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 2-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 2-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 2-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-3")
	PORT_DIPNAME( 0x01, 0x01, "IN2 3-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 3-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 3-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 3-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 3-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-4")
	PORT_DIPNAME( 0x01, 0x01, "IN2 4-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 4-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 4-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 4-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 4-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-5")
	PORT_DIPNAME( 0x01, 0x01, "IN2 5-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 5-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 5-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 5-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 5-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-6")
	PORT_DIPNAME( 0x01, 0x01, "IN2 6-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 6-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 6-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 6-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 6-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-7")
	PORT_DIPNAME( 0x01, 0x01, "IN2 7-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 7-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 7-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 7-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 7-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-8")
	PORT_DIPNAME( 0x01, 0x01, "IN2 8-0" )		PORT_DIPLOCATION("DIL1:01")
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 8-1" )		PORT_DIPLOCATION("DIL1:02")
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 8-2" )		PORT_DIPLOCATION("DIL1:03")
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 8-3" )		PORT_DIPLOCATION("DIL1:04")
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 8-4" )		PORT_DIPLOCATION("DIL1:05")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-9")
	PORT_DIPNAME( 0x01, 0x01, "IN2 9-0" )		 PORT_DIPLOCATION("DIL1:06")
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 9-1" )		 PORT_DIPLOCATION("DIL1:07")
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 9-2" )		 PORT_DIPLOCATION("DIL1:08")
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 9-3" )		 PORT_DIPLOCATION("DIL2:01")
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 9-4" )		 PORT_DIPLOCATION("DIL2:02")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-10")
	PORT_DIPNAME( 0x01, 0x01, "IN2 10-0" )		 PORT_DIPLOCATION("DIL2:03")
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 10-1" )		 PORT_DIPLOCATION("DIL2:04")
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 10-2" )		 PORT_DIPLOCATION("DIL2:05")
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 10-3" )		 PORT_DIPLOCATION("DIL2:06")
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 10-4" )		 PORT_DIPLOCATION("DIL2:07")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("MUX2IN-11")
	PORT_DIPNAME( 0x01, 0x01, "IN2 11-0" )		PORT_DIPLOCATION("DIL2:08")
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "IN2 11-1" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "IN2 11-2" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "IN2 11-3" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "IN2 11-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("TEST_SWITCH")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("Green Test")


INPUT_PORTS_END

uint8_t bfm_sc5_state::sc5_10202F0_r(offs_t offset)
{
	switch (offset)
	{
		case 0x0:
		case 0x1:
		case 0x2:
		case 0x3:
			logerror("%s: sc5_10202F0_r %d\n", machine().describe_context(), offset);
			//return machine().rand();
			return 0xff;
	}

	return 0;
}

void bfm_sc5_state::sc5_10202F0_w(offs_t offset, uint8_t data)
{
	switch (offset)
	{
		case 0x0:
			bfm_sc45_write_serial_vfd((data &0x4)?1:0, (data &0x1)?1:0, (data&0x2) ? 0:1);
			if (data&0xf8) logerror("%s: sc5_10202F0_w %d - %02x\n", machine().describe_context(), offset, data);
			break;
		case 0x1:
		case 0x2:
		case 0x3:
			logerror("%s: sc5_10202F0_w %d - %02x\n", machine().describe_context(), offset, data);
			break;
	}
}


void bfm_sc5_state::bfm_sc5_duart_irq_handler(int state)
{
	m_maincpu->write_irq_4(state);
	logerror("bfm_sc5_duart_irq_handler\n");
}

void bfm_sc5_state::bfm_sc5_duart_txa(int state)
{
	m_duart->rx_a_w(state);
	logerror("bfm_sc5_duart_a_tx\n");
}

void bfm_sc5_state::bfm_sc5_duart_txb(int state)
{
	m_duart->rx_b_w(state);
	logerror("bfm_sc5_duart_b_tx\n");
}

uint8_t bfm_sc5_state::bfm_sc5_duart_input_r()
{
	logerror("bfm_sc5_duart_input_r\n");
	return m_optic_pattern;
}

void bfm_sc5_state::cpu_uart_tx1(int state)
{
	logerror("cpu 1 tx\n");
}

void bfm_sc5_state::cpu_uart_tx2(int state)
{
	logerror("cpu 2 tx\n");
}

void bfm_sc5_state::sda(u8 state)
{
	m_rtc->write_sda(state);
	m_security->write_sda(state);
	m_dac->write_sda(state);
}

int bfm_sc5_state::sda_r()
{
	return (m_rtc->read_sda() & m_security->read_sda() & m_dac->read_sda()) ? 1 : 0;
}

void bfm_sc5_state::scl(u8 state)
{
	m_rtc->write_scl(state);
	m_security->write_scl(state);
	m_dac->write_scl(state);
	m_maincpu->scl_write(state);
}

void bfm_sc5_state::reel12_w(uint8_t data)
{
	m_reel12_latch = data;

	if(m_reel[0])
	{
		m_reel[0]->update( data & 0x0f );
		awp_draw_reel(machine(),"reel1", *m_reel[0]);
	}
}

void bfm_sc5_state::reel24_w(uint8_t data)
{
	m_reel24_latch = data;
	
	if(m_reel[3])
	{
		m_reel[3]->update( data & 0x0f );
		awp_draw_reel(machine(),"reel4", *m_reel[3]);
	}

	if(m_reel[1])
	{
		uint8_t drive = (m_reel12_latch >> 4) & 0x03;
		drive |= (( m_reel24_latch >> 2 ) & 0x0c);
		m_reel[1]->update( drive );
		awp_draw_reel(machine(),"reel2", *m_reel[1]);
	}
}

void bfm_sc5_state::reel3_w(uint8_t data)
{
	m_reel3_latch = data;

	if(m_reel[2])
	{
		m_reel[2]->update(( data >> 1 ) & 0x0f );
		awp_draw_reel(machine(),"reel3", *m_reel[2]);
	}
}

void bfm_sc5_state::bfm_sc5_duart_output_w(uint8_t data)
{
	logerror("bfm_sc5_duart_output_w\n");
	m_reel56_latch = data;

	if(m_reel[4])
	{
		m_reel[4]->update( data & 0x0f );
		awp_draw_reel(machine(),"reel5", *m_reel[4]);
	}

	if (m_reel[5])
	{
		m_reel[5]->update(( data >> 4 ) & 0x0f );
		awp_draw_reel(machine(),"reel6", *m_reel[5]);
	}

}

void bfm_sc5_state::bfm_sc5(machine_config &config)
{
	MCF5206E(config, m_maincpu, 40000000); /* MCF5206eFT */
	m_maincpu->set_addrmap(AS_PROGRAM, &bfm_sc5_state::sc5_map);
	m_maincpu->sda_w_cb().set(FUNC(bfm_sc5_state::sda));
	m_maincpu->sda_r_cb().set(FUNC(bfm_sc5_state::sda_r));
	m_maincpu->scl_w_cb().set(FUNC(bfm_sc5_state::scl));
	m_maincpu->tx1_w_cb().set(FUNC(bfm_sc5_state::cpu_uart_tx1));
	m_maincpu->tx2_w_cb().set(FUNC(bfm_sc5_state::cpu_uart_tx2));
	m_maincpu->gpio_r_cb().set(FUNC(bfm_sc5_state::read_port_a));
	
	NVRAM(config, "nvram", nvram_device::DEFAULT_ALL_0);
	
	ISL12027(config, m_rtc, 32768);

	/* sound hardware */
	SPEAKER(config, "mono").front_center();

	MC68681(config, m_duart, 3686400); // ?? Mhz
	//m_duart->set_clocks(16000000/2/8, 16000000/2/16, 16000000/2/16, 16000000/2/8);
	m_duart->irq_cb().set(FUNC(bfm_sc5_state::bfm_sc5_duart_irq_handler));
	m_duart->a_tx_cb().set(FUNC(bfm_sc5_state::bfm_sc5_duart_txa));
	m_duart->b_tx_cb().set(FUNC(bfm_sc5_state::bfm_sc5_duart_txb));
	m_duart->inport_cb().set(FUNC(bfm_sc5_state::bfm_sc5_duart_input_r));
	m_duart->outport_cb().set(FUNC(bfm_sc5_state::bfm_sc5_duart_output_w));

	// BFM_BDA(config, m_vfd0, 60, 0);
	BFM_GU96X8M_K657C2(config, m_vfd1, 60, 0);

	BFM_SC5_SECURITY(config, m_security, 4000000);
	
	CS4341(config, m_dac, 0);

	// config.set_default_layout(layout_bfm_sc5);
	config.set_default_layout(layout_bfm_sc5_gu96x8);

	YMZ280B(config, m_ymz, 16000000); // ?? Mhz
	m_ymz->add_route(ALL_OUTPUTS, "mono", 1.0);
	
	SEC(config, m_sec);
}

void bfm_sc5_state::sc5_6reels(machine_config &config)
{
	printf("sc5_6reels\n");
	bfm_sc5(config);
	
	REEL(config, m_reel[0], STARPOINT_48STEP_REEL, 16, 24, 0x09, 7);
	m_reel[0]->optic_handler().set(FUNC(bfm_sc5_state::reel_optic_cb<0>));
	REEL(config, m_reel[1], STARPOINT_48STEP_REEL, 16, 24, 0x09, 7);
	m_reel[1]->optic_handler().set(FUNC(bfm_sc5_state::reel_optic_cb<1>));
	REEL(config, m_reel[2], STARPOINT_48STEP_REEL, 16, 24, 0x09, 7);
	m_reel[2]->optic_handler().set(FUNC(bfm_sc5_state::reel_optic_cb<2>));
	REEL(config, m_reel[3], STARPOINT_48STEP_REEL, 16, 24, 0x09, 7);
	m_reel[3]->optic_handler().set(FUNC(bfm_sc5_state::reel_optic_cb<3>));
	REEL(config, m_reel[4], STARPOINT_48STEP_REEL, 16, 24, 0x09, 7);
	m_reel[4]->optic_handler().set(FUNC(bfm_sc5_state::reel_optic_cb<4>));
	REEL(config, m_reel[5], STARPOINT_48STEP_REEL, 16, 24, 0x09, 7);
	m_reel[5]->optic_handler().set(FUNC(bfm_sc5_state::reel_optic_cb<5>));

}

void bfm_sc5_state::machine_reset()
{
	bfm_sc45_state::machine_reset();
}

void bfm_sc5_state::machine_start()
{
	printf("bfm_sc5_state::machine_start\n");
	bfm_sc45_state::machine_start();

	//m_nvram->set_base(m_mainram, sizeof(m_mainram));

	//m_maincpu->set_port_callbacks(
			//m68307_cpu_device::porta_read_delegate(*this, FUNC(sc4_state::bfm_sc4_68307_porta_r)),
			//m68307_cpu_device::porta_write_delegate(*this, FUNC(sc4_state::bfm_sc4_68307_porta_w)),
			//m68307_cpu_device::portb_read_delegate(*this, FUNC(sc4_state::bfm_sc4_68307_portb_r)),
			//m68307_cpu_device::portb_write_delegate(*this, FUNC(sc4_state::bfm_sc4_68307_portb_w)));
}
