#ifndef LedControl_h
#define LedControl_h

namespace LED
{
	enum Color
	{
		BLUE,
		GREEN,
		RED,
		NONE
	};
	void initialize();
	void clearLed();
	void setLed(const Color colour);
	void setLedBlue();
	void setLedGreen();
	void setLedRed();
}


namespace LedSequencer
{
	
	template <LED::Color C, unsigned int T> 
	struct LightSequence
	{

	};
}








#endif // LedControl_h