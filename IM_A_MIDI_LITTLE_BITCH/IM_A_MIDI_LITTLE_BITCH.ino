/*
 Name:		IM_A_MIDI_LITTLE_BITCH.ino
 Created:	1/8/2020 6:26:04 PM
 Author:	pikipupiba
*/

// the setup function runs once when you press reset or power the board

#include <vector>
#include <Arduino.h>
#include <FastLED.h>
#include <MIDI.h>

#define NUM_LEDS 2304



#include "Details.h"
#include "Midi_Channel.h"
#include "Animation_Controller.h"
#include "Light_Show.h"

std::vector<Midi_Channel*> channels;
std::vector<Animation_Controller*> controllers;

CRGBArray<NUM_LEDS> leds;

void setup() {
	for (int i = 0; i < 16; i++)
	{
		channels.push_back(new Midi_Channel());
		controllers.push_back(new Animation_Controller(channels.back()));
	}

	Details::loop();
}

// the loop function runs over and over again until power down or reset
void loop() {
	Details::loop();

	for (auto& channel : channels)
	{
		channel->loop();
	}

	for (auto& controller : controllers)
	{
		controller->loop();
	}
}
