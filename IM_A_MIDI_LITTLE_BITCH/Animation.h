#pragma once

#include "Global_Definitions.h"

class Animation
{
protected:
	CRGBSet led_set;

	std::vector<Animation*> animations;

public:
	Animation(CRGBSet led_set);

	void ani_callback(Event event, byte note, byte velocity);
};
