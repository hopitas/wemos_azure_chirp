#include "chirp.h"

void CHIRP::initialise() {
	if (powerOn()) { return; }
	pinMode(waterLevel, INPUT); // define as input
	Wire.begin();
	writeI2CRegister8bit(0x20, 6); //reset
	delay(100);
	initialised = true;
}

void CHIRP::writeI2CRegister8bit(int addr, int value) {
	Wire.beginTransmission(addr);
	Wire.write(value);
	Wire.endTransmission();
}

unsigned int CHIRP::readI2CRegister16bit(int addr, int reg) {
	Wire.beginTransmission(addr);
	Wire.write(reg);
	Wire.endTransmission();
	delay(20);
	Wire.requestFrom(addr, 2);
	unsigned int t = Wire.read() << 8;
	t = t | Wire.read();
	return t;
}

void CHIRP::measure() {
	int retryCount = 0;
	initialise();
	temperature = wlevel = moisture = light = 0;
	wlevel = digitalRead(waterLevel); // read value from diode and print it

		do {
			delay(100);
			temperature = readI2CRegister16bit(0x20, 5);
			moisture = readI2CRegister16bit(0x20, 0);
			writeI2CRegister8bit(0x20, 3); //request light measurement
			delay(200);                   //this can take a while
			light = readI2CRegister16bit(0x20, 4);
		} while ((isnan(temperature) || isnan(moisture) || isnan(light)) && ++retryCount < 20);

	powerOff();
}
