/*
  ==============================================================================

    BaoLookAndFeel.cpp
    Created: 26 Oct 2021 4:49:42pm
    Author:  bvuong

  ==============================================================================
*/

#include "BaoLookAndFeel.h"

BaoLookAndFeel::BaoLookAndFeel()
{
    setColour(juce::Slider::thumbColourId, juce::Colours::green);
}

void BaoLookAndFeel::drawLinearSlider (Graphics &, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider &)
{

}