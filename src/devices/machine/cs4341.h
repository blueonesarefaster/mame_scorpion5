// license:BSD-3-Clause
// copyright-holders:blueonesarefaster
/***************************************************************************

    Stereo dac with volume control.

***************************************************************************/

#ifndef MAME_MACHINE_CS4341_H
#define MAME_MACHINE_CS4341_H

#pragma once

/***************************************************************************
    CONSTANTS
***************************************************************************/

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************


class cs4341_device : public device_t
{
public:
	// construction/destruction
	cs4341_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	void write_sda(int state);
	void write_scl(int state);
	int read_sda();

protected:

	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

private:
	TIMER_CALLBACK_MEMBER(clock_tick);

	// internal state
	uint8_t m_data[5];
	uint8_t m_scl;
	uint8_t m_sdaw;
	uint8_t m_sdar;
	uint8_t m_state;
	uint8_t m_bits;
	uint8_t m_shift;
	uint8_t m_devsel;
	uint16_t m_byteaddr;
};

DECLARE_DEVICE_TYPE(CS4341, cs4341_device)

#endif // MAME_MACHINE_CS4341_H
