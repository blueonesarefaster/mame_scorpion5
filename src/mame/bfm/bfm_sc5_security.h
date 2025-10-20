// license:BSD-3-Clause
// copyright-holders:blueonesarefaster
/***************************************************************************


***************************************************************************/

#ifndef MAME_BFM_BFM_SC5_SECURITY_H
#define MAME_BFM_BFM_SC5_SECURITY_H

#pragma once

/***************************************************************************
    CONSTANTS
***************************************************************************/

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************


class bfm_sc5_security_device : public device_t
{
public:
	// construction/destruction
	bfm_sc5_security_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	void write_sda(int state);
	void write_scl(int state);
	int read_sda();

protected:

	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

private:
	TIMER_CALLBACK_MEMBER(clock_tick);
	
	void crypt( uint8_t *key, uint8_t *plain, uint8_t *cipher);

	// internal state
	uint8_t m_data[50];
	uint8_t m_scl;
	uint8_t m_sdaw;
	uint8_t m_sdar;
	uint8_t m_state;
	uint8_t m_bits;
	uint8_t m_shift;
	uint8_t m_devsel;
	uint16_t m_byteaddr;
};

DECLARE_DEVICE_TYPE(BFM_SC5_SECURITY, bfm_sc5_security_device)

#endif // MAME_BFM_BFM_SC5_SECURITY_H
