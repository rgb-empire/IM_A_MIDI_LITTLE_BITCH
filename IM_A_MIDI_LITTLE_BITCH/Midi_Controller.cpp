#include "Midi_Controller.h"

//void Midi_Controller::init(midi::MidiInterface<HardwareSerial> &MIDI)
//{
//	MIDI.begin(MIDI_CHANNEL_OMNI);
//
//	MIDI.setHandleNoteOff(handleNoteOff);
//	MIDI.setHandleNoteOn(handleNoteOn);
//	MIDI.setHandleAfterTouchPoly(handleAfterTouchPoly);
//	MIDI.setHandleControlChange(handleControlChange);
//	MIDI.setHandleProgramChange(handleProgramChange);
//	MIDI.setHandleAfterTouchChannel(handleAfterTouchChannel);
//	MIDI.setHandlePitchBend(handlePitchBend);
//	MIDI.setHandleSystemExclusive(handleSystemExclusive);
//	MIDI.setHandleTimeCodeQuarterFrame(handleTimeCodeQuarterFrame);
//	MIDI.setHandleSongPosition(handleSongPosition);
//	MIDI.setHandleSongSelect(handleSongSelect);
//	MIDI.setHandleTuneRequest(handleTuneRequest);
//	MIDI.setHandleClock(handleClock);
//	MIDI.setHandleStart(handleStart);
//	MIDI.setHandleContinue(handleContinue);
//	MIDI.setHandleStop(handleStop);
//	MIDI.setHandleActiveSensing(handleActiveSensing);
//	MIDI.setHandleSystemReset(handleSystemReset);
//}

void Midi_Controller::handleNoteOff(byte channel, byte note, byte velocity)
{
	START3;
	gchannels[channel]->note_off(note, velocity);
	END3;
}

void Midi_Controller::handleNoteOn(byte channel, byte note, byte velocity)
{
	START3;
	gchannels[channel]->note_on(note, velocity);
	END3;
}

void Midi_Controller::handleAfterTouchPoly(byte channel, byte note, byte pressure)
{
	START3;
	gchannels[channel]->after_touch_poly(note, pressure);
	END3;
}

void Midi_Controller::handleControlChange(byte channel, byte number, byte value)
{
	START3;
	gchannels[channel]->control_change(number, value);
	END3;
}

void Midi_Controller::handleProgramChange(byte channel, byte number)
{
	START3;
	gchannels[channel]->program_change(number);
	END3;
}

void Midi_Controller::handleAfterTouchChannel(byte channel, byte pressure)
{
	START3;
	gchannels[channel]->after_touch_channel(pressure);
	END3;
}

void Midi_Controller::handlePitchBend(byte channel, int bend)
{
	START3;
	gchannels[channel]->pitch_bend(bend);
	END3;
}

void Midi_Controller::handleSystemExclusive(byte* array, unsigned size)
{
	START3;
	END3;
}

void Midi_Controller::handleTimeCodeQuarterFrame(byte data)
{
	START3;
	END3;
}

void Midi_Controller::handleSongPosition(unsigned int beats)
{
	START3;
	END3;
}

void Midi_Controller::handleSongSelect(byte songnumber)
{
	START3;
	END3;
}

void Midi_Controller::handleTuneRequest(void)
{
	START3;
	END3;
}

void Midi_Controller::handleClock(void)
{
	START3;
	END3;
}

void Midi_Controller::handleStart(void)
{
	START3;
	END3;
}

void Midi_Controller::handleContinue(void)
{
	START3;
	END3;
}

void Midi_Controller::handleStop(void)
{
	START3;
	END3;
}

void Midi_Controller::handleActiveSensing(void)
{
	START3;
	END3;
}

void Midi_Controller::handleSystemReset(void)
{
	START3;
	END3;
}
