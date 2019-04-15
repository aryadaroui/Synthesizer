/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthboyAudioProcessorEditor::SynthboyAudioProcessorEditor (SynthboyAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
	highCutFreq.setSliderStyle(Slider::SliderStyle::LinearVertical);
	highCutFreq.setRange(1000, 20000);
	highCutFreq.setValue(1000);
	highCutFreq.setTextBoxStyle(Slider::TextBoxBelow, true,20.0, 10.0);
	highCutFreq.addListener(this);
	addAndMakeVisible(highCutFreq);
}

SynthboyAudioProcessorEditor::~SynthboyAudioProcessorEditor()
{
}

//==============================================================================
void SynthboyAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void SynthboyAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	highCutFreq.setBounds(10, 10, 40, 100);
}


//Allows override of virtual function for changing slider values
void SynthboyAudioProcessorEditor::sliderValueChanged(juce::Slider*slider)
{

}