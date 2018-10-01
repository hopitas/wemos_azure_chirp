#include "Arduino.h"
#include "DigitalPin2.h"

void DigitalPin2::on()
{
	if (_invert) {
		digitalWrite(_pin, LOW);
	}
	else {
		digitalWrite(_pin, HIGH);
	}
}

void DigitalPin2::off()
{
	if (_invert) {
		digitalWrite(_pin, HIGH);
	}
	else {
		digitalWrite(_pin, LOW);
	}
}

void DigitalPin2::toggle()
{
	_state = !_state;
	if (_state) { on(); }
	else { off(); }
}

