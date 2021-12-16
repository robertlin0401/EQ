#include "PluginProcessor.h"
#include "PluginEditor.h"

EQAudioProcessorEditor::EQAudioProcessorEditor(EQAudioProcessor &p)
    : AudioProcessorEditor(&p),
      audioProcessor(p),
      spectrum(p)
{
    setSize(600, 600);

    for (auto &subcomponent : subcomponents) {
        addAndMakeVisible(subcomponent);
    }
}

EQAudioProcessorEditor::~EQAudioProcessorEditor()
{

}

void EQAudioProcessorEditor::paint(juce::Graphics &g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void EQAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    juce::FlexBox flexBox;
    flexBox.flexDirection = juce::FlexBox::Direction::column;
    flexBox.items.add(juce::FlexItem(spectrum).withFlex(3.0f));
    flexBox.performLayout(area.reduced(10));
    for (auto &subcomponent : subcomponents) {
        subcomponent->setBounds(subcomponent->getBounds().reduced(3));
    }
}
