// license:BSD-3-Clause
// copyright-holders:blueonesarefaster
/***************************************************************************

    RTC + 512*8 memory + watchdog

***************************************************************************/

#ifndef MAME_MACHINE_ISL12027_H
#define MAME_MACHINE_ISL12027_H

#pragma once

#include "dirtc.h"

/***************************************************************************
    CONSTANTS
***************************************************************************/

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************


class isl12027_device :
	public device_t,
	public device_rtc_interface,
	public device_nvram_interface
{
public:
	// construction/destruction
	isl12027_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	void write_sda(int state);
	void write_scl(int state);
	int read_sda();

protected:

	// device-level overrides
	virtual void device_start() override;

	// device_rtc_interface overrides
	virtual void rtc_clock_updated(int year, int month, int day, int day_of_week, int hour, int minute, int second) override;

	// device_nvram_interface overrides
	virtual void nvram_default() override;
	virtual bool nvram_read( util::read_stream &file ) override;
	virtual bool nvram_write( util::write_stream &file ) override;

private:
	TIMER_CALLBACK_MEMBER(clock_tick);

	int data_offset();

	optional_memory_region m_region;

	emu_timer *m_clock_timer;

	// internal state
	uint8_t m_data[512+0x40];
	uint8_t m_page[16];
	uint8_t m_scl;
	uint8_t m_sdaw;
	uint8_t m_sdar;
	uint8_t m_state;
	uint8_t m_bits;
	uint8_t m_shift;
	uint8_t m_devsel;
	uint8_t m_addresshigh;
	uint16_t m_byteaddr;
	uint8_t m_page_offset;
	uint8_t m_page_written_size;
	uint8_t m_write_page_size;
	uint16_t m_read_page_size;
	uint8_t m_accessing_rtc;
};

DECLARE_DEVICE_TYPE(ISL12027, isl12027_device)

#endif // MAME_MACHINE_ISL12027_H
