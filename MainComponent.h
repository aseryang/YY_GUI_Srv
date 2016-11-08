/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SPIniReadWrite.h"
#include "PublicDef.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component, public ListBoxModel, public ButtonListener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();
	int  getNumRows()
	{
		return 30;
	}
	void paintListBoxItem (int rowNumber,
		Graphics& g,
		int width, int height,
		bool rowIsSelected);
	void buttonClicked(Button* btnPressed);
	void loadDataFromCfg();

private:
	String			parentPath;
	CSPIniReadWrite sysCfg;
	CSPIniReadWrite users;
	CSPIniReadWrite userFriends;

	TextButton* btnStart;
	TextButton* btnStop;
	TextPropertyComponent* ip;
	TextPropertyComponent* tcpPort;
	TextPropertyComponent* udpPort;
	Label * connlab;
	Label * conn;
	Label * roomLab;
	Label * roomNum;
	ListBox* scrollBox;
private:
	friends			dataFriends;
	userAndPassword dataNameAndPasswords;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
