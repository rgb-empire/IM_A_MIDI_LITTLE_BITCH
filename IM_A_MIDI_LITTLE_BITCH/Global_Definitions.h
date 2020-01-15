#pragma once

#include "arduino.h"
#include <bitset>
#include <vector>
#include <string>
#include <FastLED.h>
//#include <MIDI.h>

#define NUM_LEDS 2304
#define NUM_MIDI_CHANNELS 16
#define NUM_LEDS_PER_CHANNEL 288

#define NUM_OCTAVES 12

extern CRGBArray<NUM_LEDS> gleds;

class Universe;
class Tweener;
class Midi_Controller;
class Midi_Channel;
class Animation_Controller;
class Animation;

//extern midi::MidiInterface<HardwareSerial> MIDI;

extern std::vector<Midi_Channel*> gchannels;
extern std::vector<Animation_Controller*> gcontrollers;

enum Ease { LINEAR, SINE, QUAD, CUBIC, QUART, QUINT };
enum Ease_Type { IN, OUT, INOUT };

enum Animation_Name {
	NONE,
	COLOR,
	WIPE,
	STROBE
};

enum Event {
	OFF,
	ON,
	POLY,
	CC,
	PC,
	ATC,
	PITCH
};

typedef void(*Animation_Func)(Event,byte,byte);

struct Note
{
	byte note;
	byte velocity;
};

struct After_Touch_Poly
{
	byte note;
	byte pressure;
};

struct Channel_Vars
{
	Event last_event;
	
	byte program;
	byte old_program;
	int fade_fract;

	Note note_on;
	Note note_off;

	After_Touch_Poly after_touch_poly;

	byte after_touch_pressure;

	int pitch_bend;
};

struct Pixel_Source
{
	CRGBSet leds;
	int start_pos;
	int end_pos;
	int len;
};

struct Pixel_Drain
{
	CRGBSet leds;
	int start_pos;
	int end_pos;
	int len;
};

struct Pixel_Map
{
	Pixel_Source source;
	Pixel_Drain drain;
};

// Control Changes
// TODO: Put all control change instructions here maybe

#include "Universe.h"

#include "Tweener.h"
#include "Midi_Controller.h"

#include "Midi_Channel.h"
#include "Animation_Controller.h"
#include "Animation.h"