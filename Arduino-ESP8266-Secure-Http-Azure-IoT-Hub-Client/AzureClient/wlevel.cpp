#include "wlevel.h"

void WLEVEL::initialise() {
	if (powerOn()) { return; }
	pinMode(waterLevel, INPUT); // define as input
	delay(100);
	initialised = true;
}

void WLEVEL::measure() {
	initialise();
	wlevel = 0;
	//delay(100);
	wlevel = digitalRead(waterLevel); // read value from diode and print it
	powerOff();
}
