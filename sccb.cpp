// 
// 
// 

#include "sccb.h"
#include "C:\Program Files (x86)\Arduino\hardware\teensy\avr\libraries\Wire/Wire.h"
#include "ov7675_REG.h"
#include <Wire.h>

sccb::sccb(int _deviceAddress)
{
	// Save device address and join i2c bus as master
	deviceAddress = _deviceAddress;
	Wire.begin();
}

bool sccb::scanfordevices()
{
	// Scans the i2c bus for a valid device
	for (int i = 8; i<127; i++)
	{
		Wire.beginTransmission(i);
		uint8_t error = Wire.endTransmission();
		if (error == 0)
		{
			Serial.print("I2C device found at: 0x");
			Serial.println(i, HEX);
			return true;
		}
	}
	return false;
}

// read the value of a register
uint8_t sccb::read_register(uint8_t reg_address)
{
	uint8_t data;
	Wire.beginTransmission(deviceAddress);
	Wire.write(reg_address);
	Wire.endTransmission();

	Wire.requestFrom(deviceAddress, (uint8_t)1);
	data = Wire.read();
	Wire.endTransmission();

	return data;
}

// write a value to a register address
uint8_t sccb::writeRegister(uint8_t address, uint8_t data)
{
	Wire.beginTransmission(deviceAddress);
	Wire.write(address);
	Wire.write(data);
	return Wire.endTransmission();
}

// write to a list of registers
bool sccb::writeRegister_list(reg_val reg_list[], uint8_t list_length)
{
	for (int i = 0; i < list_length; i++)
	{
		uint8_t error=sccb::writeRegister(reg_list[i].reg_address, reg_list[i].val);
		if (error) { return false; }
	}
	return true;
}

// reset default register values
void sccb::reset7675()
{
	writeRegister(REG_COM7, COM7_RESET);
}
