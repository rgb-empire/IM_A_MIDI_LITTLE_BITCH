#pragma once

#include "Global_Definitions.h"

class Animation
{
protected:
	CRGBSet led_set;

	int start;
	int end;

	std::vector<Animation*> animations;

public:
	Animation(CRGBSet led_set);

	void ani_callback(Event event, byte note, byte velocity);

	Animation* create(CRGBSet new_set);
};
