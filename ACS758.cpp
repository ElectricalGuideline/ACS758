#include "ACS758.h"
int zero; 
ACS758::ACS758(ACS758_type type, uint8_t _pin) {
	switch (type) {
		case ACS758LCB_050B:
			sensitivity = 0.0400;
			break;
		case ACS758LCB_050U:
			sensitivity = 0.0600;
			break;
		case ACS758LCB_100B:
			sensitivity = 0.0200;
			break;
		case ACS758LCB_100U:
			sensitivity = 0.0400;
			break;
		case ACS758KCB_150B:
			sensitivity = 0.0133;
			break;
		case ACS758KCB_150U:
			sensitivity = 0.0267;
			break;
		case ACS758ECB_200B:
			sensitivity = 0.0100;
			break;
		case ACS758ECB_200U:
			sensitivity = 0.0200;
			break;
		default:
			sensitivity = 0.0100;
			break;
	}
	pin = _pin;
}

int ACS758::calibrate() {
	int _zero = 0;
	for (int i = 0; i < 10; i++) {
		_zero += analogRead(pin);
		delay(10);
	}
	_zero /= 10;
	zero = _zero;
	return _zero;
}

void ACS758::setZeroPoint(int _zero) {
	zero = _zero;
}

void ACS758::setSensitivity(float sens) {
	sensitivity = sens;
}

float ACS758::getCurrentDC() {
	float I = (zero - analogRead(pin)) / ADC_SCALE * VREF / sensitivity;
	return I;
}

float ACS758::getCurrentAC() {
	return getCurrentAC(DEFAULT_FREQUENCY);
}

float ACS758::getCurrentAC(uint16_t frequency) {
	uint32_t period = 1000000 / frequency;
	uint32_t t_start = micros();

	uint32_t Isum = 0, measurements_count = 0;
	int32_t Inow;

	while (micros() - t_start < period) {
		Inow = zero - analogRead(pin);
		Isum += Inow*Inow;
		measurements_count++;
	}

	float Irms = sqrt(Isum / measurements_count) / ADC_SCALE * VREF / sensitivity;
	return Irms;
}
