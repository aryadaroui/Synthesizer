/*
  ==============================================================================

    SynthSound.h
    Created: 16 Feb 2019 11:12:38pm
    Author:  Arya Daroui

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../dependencies/maximilian/maximilian.h"


class SynthSound : public SynthesiserSound
{
public:
	bool appliesToNote(int midiNoteNumber)
	{
		return true;
	}
	
	bool appliesToChannel(int midiChannel)
	{
		return true;
	}
};
