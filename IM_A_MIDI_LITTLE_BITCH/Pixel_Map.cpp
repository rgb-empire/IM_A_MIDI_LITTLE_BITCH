#include "Pixel_Map.h"

Pixel_Map::Pixel_Map(CRGBSet source, CRGBSet drain)
	:source(source),
	drain(drain)
{
}

void Pixel_Map::add_source_to_drain(uint8_t alpha)
{
	if (alpha)
	{
		drain += source.nscale8(alpha);
	}
	else
	{
		drain += source;
	}
}
