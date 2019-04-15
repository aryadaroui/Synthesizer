/*
  ==============================================================================
  Plugin EDITOR
  UI, Graphical elements (Sliders and dials)
    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../dependencies/maximilian/maximilian.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SynthboyAudioProcessorEditor  : public AudioProcessorEditor,
									  public Slider::Listener
	
{
	
public:
    SynthboyAudioProcessorEditor (SynthboyAudioProcessor&);
    ~SynthboyAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void sliderValueChanged(Slider*slider) override; // Allow sliders to be read
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthboyAudioProcessor& processor;
	Slider highCutFreq;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthboyAudioProcessorEditor)
};
