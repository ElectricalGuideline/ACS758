#ifndef ACS758_h
#define ACS758_h

#include <Arduino.h>

#define ADC_SCALE 1023.0
#define VREF 5.0
#define DEFAULT_FREQUENCY 50

enum ACS758_type {ACS758LCB_050B, ACS758LCB_050U, ACS758LCB_100B, ACS758LCB_100U, ACS758KCB_150B, ACS758KCB_150U, ACS758ECB_200B, ACS758ECB_200U};

class ACS758 {
public:
	ACS758(ACS758_type type, uint8_t _pin);
	int calibrate();
	void setZeroPoint(int _zero);
	void setSensitivity(float sens);
	float getCurrentDC();
	float getCurrentAC();
	float getCurrentAC(uint16_t frequency);

private:
	float zero = 512.0;
	float sensitivity;
	uint8_t pin;
};

#endif