// sccb.h

#ifndef _SCCB_h
#define _SCCB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ov7675_REG.h"

class sccb
{
public:

	sccb() { deviceAddress = 0; } // default constructor
	sccb(int _deviceAddress); // save device address

	bool scanfordevices(); // find device and print address
	//void init7675();
	void reset7675();
	//void read_all_7670registers();
	uint8_t read_register(uint8_t reg_address);
	uint8_t writeRegister(uint8_t address, uint8_t data);
	bool writeRegister_list(reg_val[], uint8_t);

private:
	uint8_t deviceAddress;
	//uint8_t readRegister(uint8_t address);
	//void writeRegister(uint8_t address);
	//void writeRegister_list(const reg_val* reg_list);
};

#endif //end include guard


