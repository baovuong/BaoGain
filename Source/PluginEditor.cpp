/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
BaoGainAudioProcessorEditor::BaoGainAudioProcessorEditor (BaoGainAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState(vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 400);    
    addAndMakeVisible(levelSlider);
    levelSlider.setRange(0, MAX_VALUE, 0.01);
    levelSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    levelSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    levelSlider.addListener(this);
    levelAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "gain", levelSlider));

    addAndMakeVisible(levelLabel);
    levelLabel.setText("Level", juce::NotificationType::dontSendNotification);
    levelLabel.attachToComponent(&levelSlider, false);
    levelLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(blurbLabel);
    blurbLabel.setText("\"Ey This Gon Get Loud Now\"", juce::NotificationType::dontSendNotification);

    addAndMakeVisible(versionLabel);
    versionLabel.setText(juce::String("v") + JucePlugin_VersionString, juce::NotificationType::dontSendNotification);
    versionLabel.setJustificationType(juce::Justification::right);

}

BaoGainAudioProcessorEditor::~BaoGainAudioProcessorEditor()
{
}

//==============================================================================
void BaoGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::black);
    //g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
    g.fillRect(getLocalBounds());
}

void BaoGainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    levelSlider.setBounds(getWidth()/2-getWidth()/4, getHeight()/2 - getHeight()/4, getWidth()/2, getHeight()/2);

    blurbLabel.setBounds(getWidth()/2-getWidth()/4, levelSlider.getY()+levelSlider.getHeight(), getWidth()/2, 20);

    versionLabel.setBounds(getWidth() - 100, getHeight() - 50, 100, 75);
}

void BaoGainAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
}