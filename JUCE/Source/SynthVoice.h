/*
  ==============================================================================

    SynthVoice.h
    Created: 16 Feb 2019 11:12:49pm
    Author:  Arya Daroui

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice
{
public:
	bool canPlaySound(SynthesiserSound* sound)
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}
	
	void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchwheelPosition)
	{
		frequency  = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		std::cout << midiNoteNumber << std::endl;
	}
	
	void stopNote (float velocity, bool allowTailOff)
	{
		clearCurrentNote();
	}
	
	void pitchWheelMoved (int newPitchWheelValue)
	{
		
	}
	
	void controllerMoved (int controllerNumber, int newControllerValue)
	{
		
	}
	
	void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
		
	}
private:
	double level;
	double frequency;
};
