/*
 Name:		IM_A_MIDI_LITTLE_BITCH.ino
 Created:	1/8/2020 6:26:04 PM
 Author:	pikipupiba
*/

// the setup function runs once when you press reset or power the board
#include "Global_Definitions.h"

void setup() {
	for (int i = 0; i < NUM_MIDI_CHANNELS; i++)
	{
		gchannels.push_back(new Midi_Channel());
		gcontrollers.push_back(new Animation_Controller(gchannels.back()));
	}

	Velocity::loop();
}

// the loop function runs over and over again until power down or reset
void loop() {
	Velocity::loop();

	for (auto& channel : gchannels)
	{
		channel->loop();
	}

	for (auto& controller : gcontrollers)
	{
		controller->loop();
	}
}
