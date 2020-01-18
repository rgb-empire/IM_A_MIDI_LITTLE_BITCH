#pragma once

#include "Global_Definitions.h"

class Pixel_Map
{
public:
	CRGBSet source;
	CRGBSet drain;

	Pixel_Map(CRGBSet source, CRGBSet drain);

	void add_source_to_drain(uint8_t alpha);
};

