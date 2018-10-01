#include "HTU21DF.h"

void HTU21DF::initialise() {
//	if (initialised) { return; }
	if (powerOn()) { return; }
	htu.begin();
	delay(100);
	initialised = true;
}

void HTU21DF::measure() {
	int retryCount = 0;
	initialise();
	temperature = humidity = 0;
	const int numberOfSamples = 4;

	for (int c = 0; c < numberOfSamples; c++) {
		do {
			delay(100);
			temperature += htu.readTemperature();
			humidity += htu.readHumidity();
		} while ((isnan(temperature) || isnan(humidity)) && ++retryCount < 20);
	}
	temperature /= numberOfSamples;
	humidity /= numberOfSamples;

	powerOff();
}