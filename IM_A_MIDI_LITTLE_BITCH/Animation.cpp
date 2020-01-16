#include "Animation.h"

Animation::Animation(CRGBSet led_set)
	:led_set(led_set)
{

}

void Animation::ani_callback(Event event, byte note, byte velocity)
{
	if (event == ON)
	{
		led_set.fill_solid(CHSV(note * 2, velocity, 100));
	}
	else if (event == OFF)
	{
		led_set.fill_solid(CRGB::Black);
	}
}

Animation* Animation::create(CRGBSet new_set)
{
	return nullptr;

}
