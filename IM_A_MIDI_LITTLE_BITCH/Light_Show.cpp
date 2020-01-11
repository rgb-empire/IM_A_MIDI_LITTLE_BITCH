#include "Light_Show.h"
#include "NOW.h"

void Light_Show::init(int num_channels)
{
	for (int i = 0; i < num_channels; i++)
	{
		channels.push_back(new Midi_Channel());
		controllers.push_back(new Animation_Controller(channels.back()));
	}

	Details::update();
}

void Light_Show::loop()
{
	Details::update();

	for (auto& channel : channels)
	{
		channel->loop();
	}

	for (auto& controller : controllers)
	{
		controller->loop();
	}
}
