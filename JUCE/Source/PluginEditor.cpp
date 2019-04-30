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
	addAndMakeVisible(lfoFreq);
    lfoFreq.setSliderStyle(Slider::SliderStyle::Rotary);
    lfoFreq.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	lfoFreq.addListener(this);
	
	
    setSize (400, 300);
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
    lfoFreq.setBounds(getLocalBounds());
}

void SynthboyAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
	if (slider == &lfoFreq) {
		processor.lfoFreq = lfoFreq.getValue();
		std::cout << lfoFreq.getValue() << endl;
	} 
}
