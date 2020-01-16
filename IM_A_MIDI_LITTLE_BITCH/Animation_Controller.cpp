#include "Animation_Controller.h"

Animation_Controller::Animation Animation_Controller::animations[] = {
	{NONE, Animation_Controller::none, true, 0},
	{COLOR, Animation_Controller::color, true, 0},
	{WIPE, Animation_Controller::wipe, true, 0},
	{STROBE, Animation_Controller::strobe, true, 0}
};

Animation_Controller::Animation_Controller(Midi_Channel* channel, Animation_Name ani_name)
{
}

Animation_Controller::~Animation_Controller()
{

}

void Animation_Controller::loop()
{
	for (auto& ani : cur_anis)
	{
		ani->func(ani, channel);
	}
}

void Animation_Controller::start_animation(Animation_Name ani_name)
{
	cur_anis.push_back(new Animation(animations[ani_name]));

	num_anis++;
}

void Animation_Controller::stop_animation(Animation_Name ani_name, int number)
{
	for (std::vector<Animation*>::iterator it = cur_anis.begin(); it != cur_anis.end();)
	{
		if (it[0]->active && it[0]->name == ani_name)
		{
			it[0]->active = false;
			number--;
		}
		else
		{
			it++;
		}

		if (number == 0)
		{
			break;
		}
	}
}

void Animation_Controller::stop_animation(int index, int number)
{
	for (std::vector<Animation*>::iterator it = cur_anis.begin() + index; it != cur_anis.end();)
	{
		it[0]->active = false;

		if (--number == 0)
		{
			break;
		}

		it++;
	}
}

void Animation_Controller::none(Animation* ani, Midi_Channel* channel)
{
}

void Animation_Controller::color(Animation* ani, Midi_Channel* channel)
{
	CHSV color = CHSV(beat8(2), beat8(1), ani->brite);

	for (auto& led : channel->ch_led_set)
	{
		led += color;
	}
}

void Animation_Controller::wipe(Animation* ani, Midi_Channel* channel)
{
}

void Animation_Controller::strobe(Animation* ani, Midi_Channel* channel)
{
}