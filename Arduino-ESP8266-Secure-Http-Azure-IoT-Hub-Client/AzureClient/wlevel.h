// wlevel.h

#ifndef _WLEVEL_h
#define _WLEVEL_h

#include "Sensor.h"
#include "Device.h"
#include "DigitalPin.h"

class WLEVEL : public Sensor {
public:
	WLEVEL() {};
	WLEVEL(DigitalPin *powerPin) :Sensor(powerPin) {};
	void measure();

protected:

private:
	void initialise();
	byte waterLevel = D3; // Water level sensor pin
//	short sensor_val;    // water level sensor reading

};

#endif