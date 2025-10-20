// license:BSD-3-Clause
// copyright-holders:David Haywood
#ifndef MAME_BFM_BFM_SC5_H
#define MAME_BFM_BFM_SC5_H

#pragma once

#include "bfm_sc4.h"
#include "cpu/m68000/mcf5206e.h"
#include "machine/isl12027.h"
#include "machine/cs4341.h"
#include "bfm_sc5_security.h"

class bfm_sc5_state : public bfm_sc45_state
{
public:
	bfm_sc5_state(const machine_config &mconfig, device_type type, const char *tag)
		: bfm_sc45_state(mconfig, type, tag)
		, m_maincpu(*this, "maincpu")
		, m_nvram(*this, "nvram")
		, m_rtc(*this, "rtc")
		, m_security(*this, "security")
		, m_dac(*this, "dac")
		, m_sec(*this, "sec")
		, m_reel(*this, "reel%u", 1U)
		, m_mux1_in(*this, "MUX1IN-%u", 0U)
		, m_mux2_in(*this, "MUX2IN-%u", 0U)
		, m_test_switch(*this, "TEST_SWITCH")


	{ }

	void init_sc5();

	void bfm_sc5(machine_config &config);
	void sc5_6reels(machine_config &config);
	
	virtual void machine_start() override ATTR_COLD;
	virtual void machine_reset() override ATTR_COLD;
	
	uint8_t m_reel12_latch = 0;
	uint8_t m_reel24_latch = 0;
	uint8_t m_reel3_latch = 0;
	uint8_t m_reel56_latch = 0;
	uint8_t m_optic_pattern = 0;
	template <unsigned N> void reel_optic_cb(int state) { if (state) m_optic_pattern |= (1 << N); else m_optic_pattern &= ~(1 << N); }

protected:
	void sc5_map(address_map &map) ATTR_COLD;

	required_device<mcf5206e_device> m_maincpu;
	required_device<nvram_device> m_nvram;
	required_device<isl12027_device> m_rtc;
	required_device<bfm_sc5_security_device> m_security;
	required_device<cs4341_device> m_dac;
	required_device<sec_device> m_sec;
	optional_device_array<stepper_device, 6> m_reel;
	optional_ioport_array<12> m_mux1_in;
	optional_ioport_array<12> m_mux2_in;
	required_ioport m_test_switch;


	uint8_t sc5_10202F0_r(offs_t offset);
	void sc5_10202F0_w(offs_t offset, uint8_t data);
	uint16_t sc5_duart_r(offs_t offset, uint16_t mem_mask = ~0);
	void sc5_duart_w(offs_t offset, uint16_t data, uint16_t mem_mask = ~0);

	uint8_t sc5_mux1_r(offs_t offset);
	void sc5_mux1_w(offs_t offset, uint8_t data);
	uint8_t sc5_mux2_r(offs_t offset);
	void sc5_mux2_w(offs_t offset, uint8_t data);

	void bfm_sc5_duart_irq_handler(int state);
	void bfm_sc5_duart_txa(int state);
	void bfm_sc5_duart_txb(int state);
	uint8_t bfm_sc5_duart_input_r();
	void bfm_sc5_duart_output_w(uint8_t data);
	
	void reel12_w(uint8_t data);
	void reel24_w(uint8_t data);
	void reel3_w(uint8_t data);

	void cpu_uart_tx1(int state);
	void cpu_uart_tx2(int state);
	
	uint8_t read_port_a();
	
	uint8_t yamaha_r(offs_t offset);
	void yamaha_w(offs_t offset, uint8_t data);
	
	void sec_port_w(offs_t offset, uint8_t data);

	void sda(u8 state);
	int sda_r();
	void scl(u8 state);
};

INPUT_PORTS_EXTERN( bfm_sc5 );

#endif // MAME_BFM_BFM_SC5_H
