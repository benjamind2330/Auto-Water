#include "LEDControl.h"
#include "Arduino.h"

namespace LedConstants
{
	const unsigned int LedGroundPin = 19;
	const unsigned int LedBluePin = 18;
	const unsigned int LedGreenPin = 17;
	const unsigned int LedRedPin = 16;
}

namespace LED
{
	void initialize()
	{
		pinMode(LedConstants::LedGroundPin, OUTPUT);
		pinMode(LedConstants::LedBluePin, OUTPUT);
		pinMode(LedConstants::LedGreenPin, OUTPUT);
		pinMode(LedConstants::LedRedPin, OUTPUT);

		digitalWrite(LedConstants::LedGroundPin, 0);
	}

	void clearLed()
	{
		digitalWrite(LedConstants::LedBluePin, 0);
		digitalWrite(LedConstants::LedGreenPin, 0);
		digitalWrite(LedConstants::LedRedPin, 0);
	}

	void setColor(const Color color)
	{
		switch (color) {
			case BLUE:
				setLedBlue();
				break;
			case GREEN:
				setLedGreen();
				break;
			case RED:
				setLedRed();
				break;
			case NONE:
				clearLed();
				break;
		}
	}

	void setLedBlue()
	{
		digitalWrite(LedConstants::LedBluePin, 1);
		digitalWrite(LedConstants::LedGreenPin, 0);
		digitalWrite(LedConstants::LedRedPin, 0);
	}

	void setLedGreen()
	{
		digitalWrite(LedConstants::LedBluePin, 0);
		digitalWrite(LedConstants::LedGreenPin, 1);
		digitalWrite(LedConstants::LedRedPin, 0);
	}

	void setLedRed()
	{
		digitalWrite(LedConstants::LedBluePin, 0);
		digitalWrite(LedConstants::LedGreenPin, 0);
		digitalWrite(LedConstants::LedRedPin, 1);
	}


};
