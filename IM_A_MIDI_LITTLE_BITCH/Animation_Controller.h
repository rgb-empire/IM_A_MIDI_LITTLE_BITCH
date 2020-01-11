#pragma once

#include <FastLED.h>
#include <vector>

#include "Midi_Channel.h"
#include "Details.h"
#include "Tweener.h"

class Animation_Controller
{
public:
	enum Animation_Name {
		NONE,
		COLOR,
		WIPE,
		STROBE
	};

	struct Animation
	{
		Animation_Name name;

		typedef void(*Animation_Func)(Animation*, Midi_Channel*);
		Animation_Func func;

		bool active;
		uint8_t brite;

		//std::vector<Event_Link> links;
	};

protected:

public:
	Animation_Controller(Midi_Channel* channel, Animation_Name ani_name = COLOR);
	~Animation_Controller();

	void loop();

	void start_animation(Animation_Name ani_name);
	void stop_animation(Animation_Name ani_name, int number = -1);
	void stop_animation(int index = 0, int number = -1);

protected:
	Midi_Channel* channel;
	std::vector<Animation*> cur_anis;
	int num_anis;
	static Animation animations[];

	static void none(Animation* ani, Midi_Channel* channel);
	static void color(Animation* ani, Midi_Channel* channel);
	static void wipe(Animation* ani, Midi_Channel* channel);
	static void strobe(Animation* ani, Midi_Channel* channel);

};

