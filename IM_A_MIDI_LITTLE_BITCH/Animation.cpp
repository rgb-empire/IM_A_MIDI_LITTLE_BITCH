#include "Animation.h"

Animation::Animation(CRGBSet led_set)
	:led_set(led_set)
{

}

void Animation::ani_callback(Event event, byte note, byte velocity)
{
	if (event == ON)
	{
		mySerial.println("ONNNNNN");
		led_set.fill_solid(CHSV(note * 2 * NUM_OCTAVES, 255, velocity));
	}
	else if (event == OFF)
	{
		mySerial.println("OFF");
		led_set.fill_solid(CRGB::Black);
	}
}

Animation* Animation::create(CRGBSet new_set)
{
	return nullptr;

}
