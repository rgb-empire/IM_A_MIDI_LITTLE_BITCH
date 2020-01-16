#include "Global_Definitions.h"

std::vector<Midi_Channel*> gchannels;
std::vector<Animation_Controller*> gcontrollers;

CRGBArray<NUM_LEDS> gleds;

Range Midi_Channel_Settings[] =
{
	{0 * NUM_LEDS_PER_CHANNEL,	1 * NUM_LEDS_PER_CHANNEL - 1, NUM_LEDS_PER_CHANNEL},
	{1 * NUM_LEDS_PER_CHANNEL,	2 * NUM_LEDS_PER_CHANNEL - 1, NUM_LEDS_PER_CHANNEL},
	{2 * NUM_LEDS_PER_CHANNEL,	3 * NUM_LEDS_PER_CHANNEL - 1, NUM_LEDS_PER_CHANNEL},
	{3 * NUM_LEDS_PER_CHANNEL,	4 * NUM_LEDS_PER_CHANNEL - 1, NUM_LEDS_PER_CHANNEL},
	{4 * NUM_LEDS_PER_CHANNEL,	5 * NUM_LEDS_PER_CHANNEL - 1, NUM_LEDS_PER_CHANNEL},
	{5 * NUM_LEDS_PER_CHANNEL,	6 * NUM_LEDS_PER_CHANNEL - 1, NUM_LEDS_PER_CHANNEL},
	{6 * NUM_LEDS_PER_CHANNEL,	7 * NUM_LEDS_PER_CHANNEL - 1, NUM_LEDS_PER_CHANNEL},
	{7 * NUM_LEDS_PER_CHANNEL,	8 * NUM_LEDS_PER_CHANNEL - 1, NUM_LEDS_PER_CHANNEL},
	{0 * NUM_LEDS_PER_CHANNEL,	2 * NUM_LEDS_PER_CHANNEL - 1, 2 * NUM_LEDS_PER_CHANNEL},
	{2 * NUM_LEDS_PER_CHANNEL,	4 * NUM_LEDS_PER_CHANNEL - 1, 2 * NUM_LEDS_PER_CHANNEL},
	{4 * NUM_LEDS_PER_CHANNEL,	6 * NUM_LEDS_PER_CHANNEL - 1, 2 * NUM_LEDS_PER_CHANNEL},
	{6 * NUM_LEDS_PER_CHANNEL,	8 * NUM_LEDS_PER_CHANNEL - 1, 2 * NUM_LEDS_PER_CHANNEL},
	{0 * NUM_LEDS_PER_CHANNEL,	4 * NUM_LEDS_PER_CHANNEL - 1, 4 * NUM_LEDS_PER_CHANNEL},
	{4 * NUM_LEDS_PER_CHANNEL,	8 * NUM_LEDS_PER_CHANNEL - 1, 4 * NUM_LEDS_PER_CHANNEL},
	{0 * NUM_LEDS_PER_CHANNEL,	8 * NUM_LEDS_PER_CHANNEL - 1, 8 * NUM_LEDS_PER_CHANNEL},
	{8 * NUM_LEDS_PER_CHANNEL - 1,	0 * NUM_LEDS_PER_CHANNEL, 8 * -NUM_LEDS_PER_CHANNEL},
};