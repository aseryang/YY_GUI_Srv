/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include <Windows.h>

String getModuleFilePathEx()  
{
	static String strModulePath;
	if (strModulePath.isEmpty())
	{
		wchar_t path[MAX_PATH];
		::GetModuleFileName(NULL, (LPWSTR)path, MAX_PATH);
		strModulePath = path;
		strModulePath = strModulePath.substring( 0, strModulePath.lastIndexOfChar(L'\\') + 1);
	}
	return strModulePath;
}
//==============================================================================
MainContentComponent::MainContentComponent():
	parentPath(File(getModuleFilePathEx()).getParentDirectory().getFullPathName()),
	sysCfg(parentPath + "/config/srv_system_cfg.ini"),
	users(parentPath + "/config/srv_users.ini"),
	userFriends(parentPath + "/config/srv_userdata_friends.ini")
{
    setSize (800, 480);
	btnStart = new TextButton;
	btnStart->setBounds(10, 10, 60, 25);
	btnStart->setButtonText("Start");
	btnStart->addListener(this);
	addAndMakeVisible(btnStart);

	btnStop = new TextButton;
	btnStop->setBounds(100, 10, 60, 25);
	btnStop->setButtonText("Stop!");
	btnStop->addListener(this);
	addAndMakeVisible(btnStop);

	ip = new TextPropertyComponent (Value (var ("input...")), "Tcp.ip", 50, false);
	ip->setBounds(200,10, 150, 25);
	addAndMakeVisible(ip);

	tcpPort = new TextPropertyComponent (Value (var ("input...")), "Tcp.port", 50, false);
	tcpPort->setBounds(360,10, 140, 25);
	addAndMakeVisible(tcpPort);

	udpPort = new TextPropertyComponent (Value (var ("input...")), "Udp.port", 50, false);
	udpPort->setBounds(510,10, 140, 25);
	addAndMakeVisible(udpPort);

	connlab = new Label;
	connlab->setBounds(10, 35, 100, 25);
	connlab->setText("Connections:", dontSendNotification);
	addAndMakeVisible(connlab);

	conn = new Label;
	conn->setBounds(115, 35, 100, 25);
	conn->setText("0", dontSendNotification);
	addAndMakeVisible(conn);

	roomLab = new Label;
	roomLab->setBounds(160, 35, 60, 25);
	roomLab->setText("Rooms:", dontSendNotification);
	addAndMakeVisible(roomLab);

	roomNum = new Label;
	roomNum->setBounds(220, 35, 100, 25);
	roomNum->setText("0", dontSendNotification);
	addAndMakeVisible(roomNum);

	scrollBox = new ListBox();
	scrollBox->setModel(this);
	scrollBox->setBounds(10, 60, 780, 400);
	addAndMakeVisible(scrollBox);
	scrollBox->scrollToEnsureRowIsOnscreen(30);	
}

MainContentComponent::~MainContentComponent()
{
}
void MainContentComponent::loadDataFromCfg()
{

}
void MainContentComponent::buttonClicked(Button* btnPressed)
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
