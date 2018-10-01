#ifndef CHIRP_h
#define CHIRP_h

#include "Sensor.h"
#include "Wire.h"
#include "Device.h"
#include "DigitalPin.h"

class CHIRP : public Sensor {
public:
	CHIRP() {};
	CHIRP(DigitalPin *powerPin) :Sensor(powerPin) {};
	void measure();

protected:

private:
	void initialise();
	void writeI2CRegister8bit(int addr, int value);
	unsigned int readI2CRegister16bit(int addr, int reg);
	byte waterLevel = D3; // Water level sensor pin
};

#endif