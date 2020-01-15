#include "Animation.h"

Animation::Animation(CRGBSet led_set)
	:led_set(led_set)
{

}

void Animation::ani_callback(Event event, byte note, byte velocity)
{
	if (event == ON)
	{
		led_set.fill_solid((note * 2 * NUM_OCTAVES) % 255);
	}
	else if (event == OFF)
	{
		led_set.fill_solid(CRGB::Black);
	}
}
