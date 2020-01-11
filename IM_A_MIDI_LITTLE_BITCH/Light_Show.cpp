#include "Light_Show.h"
#include "NOW.h"

Light_Show::Light_Show()
	:num_leds(G_NUM_LEDS)
{
	for (int i = 0; i < 16; i++)
	{
		channels.push_back(Midi_Channel(num_leds));
	}

	Details::update();

}

Light_Show::~Light_Show()
{
}

void Light_Show::loop()
{
	Details::update();
}
