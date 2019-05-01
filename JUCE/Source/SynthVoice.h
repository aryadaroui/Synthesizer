/*
  ==============================================================================

    SynthVoice.h
    Created: 16 Feb 2019 11:12:49pm
    Author:  Arya Daroui

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../dependencies/maximilian/maximilian.h"
#include "SynthSound.h"

enum shape {PULSE, SQUARE, SINE, TRIANGLE, RAMP};

class SynthVoice : public SynthesiserVoice
{
public:
	bool canPlaySound(SynthesiserSound* sound)
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}
	
	//======================================================================================
	void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchwheelPosition)
	{
        level = .5;
		carFreq  = MidiMessage::getMidiNoteInHertz(midiNoteNumber); // gets the midi note and converts it to the carFreq in Hz it should be
        
        std::cout << "key: " <<  midiNoteNumber << " @ "  << carFreq << " Hz. w/ lfoFreq " << lfoFreq <<  std::endl; // for debug
	}
	
	void stopNote (float velocity, bool allowTailOff)
	{
        level = 0;
		clearCurrentNote();
	}
	
	//=======================================================================================
	void pitchWheelMoved (int newPitchWheelValue)
	{
		
	}
	
	void controllerMoved (int controllerNumber, int newControllerValue)
	{
		
	}
	
	void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
		// TO DO: Windows Distribution off by 30Hz at 440Hz (A4). Error is multiplicative with octave.
        double theWave;
        
        for (int sample = 0; sample < numSamples; ++sample)
        {
            theWave = car.sinewave(carFreq * lfo.sinewave(lfoFreq)) * level;
            
			for (int channel = 0; channel < outputBuffer.getNumChannels(); ++ channel)
            {
				
                outputBuffer.addSample(channel, startSample, theWave);
            }
            ++startSample;
        }
		
	}
	
	void getParams(double* lfoFreqNew)
	{
		lfoFreq = *lfoFreqNew;
	}

private:
	double level;
	double carFreq;
	double lfoFreq;
	
    maxiOsc car; // carrier wave
    maxiOsc lfo; // LFO wave
	
	maxiEnv carEnv;
	maxiEnv lfoEnv;
	
	shape carShape;
	shape lfoShape;
};
