#ifndef HTU21DF_h
#define HTU21DF_h

#include "Sensor.h"
#include "Adafruit_HTU21DF.h"
#include <Wire.h>
#include "Device.h"
#include "DigitalPin.h"

class HTU21DF : public Sensor {
public:
	HTU21DF() {};
	HTU21DF(DigitalPin *powerPin) :Sensor(powerPin) {};
	void measure();

protected:
	Adafruit_HTU21DF htu = Adafruit_HTU21DF();

private:
	//Adafruit_HTU21DF htu;
	void initialise();
};

#endif