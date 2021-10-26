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
    setSize (600, 400);
    addAndMakeVisible(levelSlider);
    levelSlider.setRange(0, MAX_VALUE, 0.01);
    levelSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    levelSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    levelAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "gain", levelSlider));
    levelSlider.addListener(this);

    addAndMakeVisible(levelLabel);
    levelLabel.setText("Level", juce::NotificationType::dontSendNotification);
    levelLabel.attachToComponent(&levelSlider, false);
    levelLabel.setJustificationType(juce::Justification::centred);

    // addAndMakeVisible(blurbLabel);
    // blurbLabel.setText("\"Ey This Gon Get Loud Now\"", juce::NotificationType::dontSendNotification);

    addAndMakeVisible(versionLabel);
    versionLabel.setText(juce::String("v") + JucePlugin_VersionString, juce::NotificationType::dontSendNotification);
    versionLabel.setJustificationType(juce::Justification::left);


    vince1 = juce::ImageCache::getFromMemory(BinaryData::vincemcmahon1_png, BinaryData::vincemcmahon1_pngSize);
    vince2 = juce::ImageCache::getFromMemory(BinaryData::vincemcmahon2_png, BinaryData::vincemcmahon2_pngSize);
    vince3 = juce::ImageCache::getFromMemory(BinaryData::vincemcmahon3_png, BinaryData::vincemcmahon3_pngSize);
    vince4 = juce::ImageCache::getFromMemory(BinaryData::vincemcmahon4_png, BinaryData::vincemcmahon4_pngSize);
    vince5 = juce::ImageCache::getFromMemory(BinaryData::vincemcmahon5_png, BinaryData::vincemcmahon5_pngSize);

    chosenVince = std::make_unique<juce::Image>(vince1);

    *chosenVince = vince1;
    chosenVinceNum = 1;
}

BaoGainAudioProcessorEditor::~BaoGainAudioProcessorEditor()
{
}

//==============================================================================
void BaoGainAudioProcessorEditor::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)

    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour(juce::Colours::black);
    g.fillRect(getLocalBounds());

    g.drawImageAt(*chosenVince, 71, 0);
}

void BaoGainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    levelSlider.setBounds(15, 25, 50, getHeight()-55);

    blurbLabel.setBounds(getWidth()/2-getWidth()/4, levelSlider.getY()+levelSlider.getHeight(), getWidth()/2, 20);

    versionLabel.setBounds(0, getHeight() - 50, 100, 75);


}

void BaoGainAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    
    double value = slider->getValue() / MAX_VALUE;

    int current = 1;
    
    if (value >= 0.8)
    {
        *chosenVince = vince5;
        current = 5;
    } 
    else if (value >= 0.6)
    { 
        *chosenVince = vince4;
        current = 4;
    }
    else if (value >= 0.4)
    {
        *chosenVince = vince3;
        current = 3;
    }
    else if (value >= 0.2)
    {
        *chosenVince = vince2;
        current = 2;
    }
    else
    {
        *chosenVince = vince1;
        current = 1;
    }
    
    // don't call repaint unless it's different
    if (current != chosenVinceNum)
    {
        chosenVinceNum = current;
        repaint();
    }
}