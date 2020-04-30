#ifndef FLOWSENSOR_H
#define FLOWSENSOR_H

#include "Arduino.h"

volatile static unsigned long pulseCount;

class FlowSensor
{
public:
	FlowSensor(int pin);
	void begin();
	void run();
	// Returns current timer as formatted string HH:MM:SS
	char* getTotalVolume();
	char* getVolumePerMinute();
private:
	int _pin;
	byte sensorInterrupt = 0;  // 0 = digital pin 2

	// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
	// litre/minute of flow.
	float calibrationFactor = 4.5;

	float flowRate = 0;

	unsigned int fractional;
	unsigned int flowMilliLitres;
	unsigned long totalMilliLitres;

	unsigned long oldTime;

	//volatile byte pulseCount;
	static void pulseCounter();

	char _formatted_time[10];
};

#endif
