/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (800, 480);
	TextButton* btnStart = new TextButton;
	btnStart->setBounds(10, 10, 60, 25);
	btnStart->setButtonText("Start");
	addAndMakeVisible(btnStart);

	TextButton* btnStop = new TextButton;
	btnStop->setBounds(100, 10, 60, 25);
	btnStop->setButtonText("Stop!");
	addAndMakeVisible(btnStop);

	TextPropertyComponent* ip = new TextPropertyComponent (Value (var ("input...")), "Tcp.ip", 50, false);
	ip->setBounds(200,10, 150, 25);
	addAndMakeVisible(ip);

	TextPropertyComponent* tcpPort = new TextPropertyComponent (Value (var ("input...")), "Tcp.port", 50, false);
	tcpPort->setBounds(360,10, 140, 25);
	addAndMakeVisible(tcpPort);

	TextPropertyComponent* udpPort = new TextPropertyComponent (Value (var ("input...")), "Udp.port", 50, false);
	udpPort->setBounds(510,10, 140, 25);
	addAndMakeVisible(udpPort);

	Label * connlab = new Label;
	connlab->setBounds(10, 35, 100, 25);
	connlab->setText("Connections:", dontSendNotification);
	addAndMakeVisible(connlab);

	Label * conn = new Label;
	conn->setBounds(115, 35, 100, 25);
	conn->setText("0", dontSendNotification);
	addAndMakeVisible(conn);

	Label * roomLab = new Label;
	roomLab->setBounds(160, 35, 60, 25);
	roomLab->setText("Rooms:", dontSendNotification);
	addAndMakeVisible(roomLab);

	Label * roomNum = new Label;
	roomNum->setBounds(220, 35, 100, 25);
	roomNum->setText("0", dontSendNotification);
	addAndMakeVisible(roomNum);

	ListBox* scrollBox = new ListBox();
	scrollBox->setModel(this);
	scrollBox->setBounds(10, 60, 780, 400);
	addAndMakeVisible(scrollBox);
	scrollBox->scrollToEnsureRowIsOnscreen(30);

// 	TextEditor * pTe = new TextEditor;
// 	pTe->setBounds(110, 30, 100, 20);
// 	//pTe->grabKeyboardFocus();
// 	addAndMakeVisible(pTe);




	
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paintListBoxItem (int rowNumber,
	Graphics& g,
	int width, int height,
	bool rowIsSelected)
{
	if (rowIsSelected)
		g.fillAll (Colours::lightblue);

	g.setColour (Colours::black);
	g.setFont (height * 0.7f);

	g.drawText ("13:33 #" + String (rowNumber + 1),
		5, 0, width, height,
		Justification::centredLeft, true);
}

void MainContentComponent::paint (Graphics& g)
{
    //g.fillAll (Colour (0xff001F36));

//     g.setFont (Font (16.0f));
//     g.setColour (Colours::white);
//     g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
