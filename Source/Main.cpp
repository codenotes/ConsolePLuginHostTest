/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>

class FilterGraph : public FileBasedDocument
{
public:

};



struct AsyncCallback : public AudioPluginFormat::InstantiationCompletionCallback
{
	AsyncCallback(double inX, double inY)
		//: owner(myself), posX(inX), posY(inY)
	{}

	void completionCallback(AudioPluginInstance* instance, const String& error) override
	{
		printf("ok, here, error?:%s", error.toStdString().c_str());
	//	owner->addFilterCallback(instance, error, posX, posY);
	}

	//FilterGraph* owner;
	double posX, posY;
};



//==============================================================================
int main (int argc, char* argv[])
{
	AudioPluginFormatManager test;
	AudioDeviceManager deviceManager;
	AudioPluginFormatManager formatManager;


	formatManager.addDefaultFormats();

	OwnedArray <PluginDescription> internalTypes;
	KnownPluginList knownPluginList;
	KnownPluginList::SortMethod pluginSortMethod;
//
	PluginDescription desc;

	

//	AudioPluginFormat::InstantiationCompletionCallback * icc = &tb;

	
	const char *p2 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n\r\n<PLUGIN name=\"UVIWorkstationVSTx64\" descriptiveName=\"UVIWorkstation\"\r\n        format=\"VST\" category=\"Synth\" manufacturer=\"UVI\" version=\"V2.6.6\"\r\n";
	const char *p = "VST-UVIWorkstationVSTx64-477f9402-55564957";

	const char * p3 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
		"<PLUGIN name=\"UVIWorkstationVSTx64\" descriptiveName=\"UVIWorkstation\""
		"        format=\"VST\" category=\"Synth\" manufacturer=\"UVI\" version=\"V2.6.6\""
		"        file=\"C:\\Program Files\\Steinberg\\VSTPlugins\\UVIWorkstationVSTx64.dll\""
		"        uid=\"55564957\" isInstrument=\"1\" fileTime=\"154c4946c30\" infoUpdateTime=\"15554f39039\""
		"        numInputs=\"0\" numOutputs=\"34\" isShell=\"0\"/>";



	juce::String s(p3);
	
	juce::XmlDocument doc(s);
	ScopedPointer<XmlElement> mainElement(doc.getDocumentElement());

	//juce::XmlElement xe(doc);
	
	
	auto b=desc.loadFromXml(*mainElement);

	if (b)
	{
		printf("!%s\n\n",s.toStdString().c_str());
	}
////	class PluginListWindow;
	//ScopedPointer<PluginListWindow> pluginListWindow;
	
	// AudioPluginFormat::InstantiationCompletionCallback*

	//todo, figure out where 2560 ie 0xa00 came from
//	formatManager.createPluginInstanceAsync(desc, 44100, 0xa00,  new AsyncCallback( 1.0, 1.0));

	auto n=formatManager.createPluginInstance(desc, 44100, 0xa00, s);

	printf("error:%d %s\n",n, s.toStdString().c_str());

	//VSTPluginFormat //I think I need this


	//from: https://forum.juce.com/t/newbie-using-juce-for-vst-needs-a-hand/3360
	//possible sample...
	/*const juce::PluginDescription *des = list->getTypeForFile(*file);
	juce::VSTPluginFormat *format = new juce::VSTPluginFormat();

	juce::AudioPluginInstance *plugin = format->createInstanceFromDescription(*des);

	//here are some chink from fxp utility code
	https://forum.juce.com/t/loading-a-binary-file-as-a-fxp-into-a-vst-setchunk/4449/4
	looks like I am supposed to set state with setStateInformation(), so I guess just
	chunk up the context and call that?
	*/


	if (n)
	{//woo hoo!
		
	//	VSTPluginFormat vf;
		//vf.loadFromFXBFile(n, data, sz);
		
		//n->setStateInformation

	}
    // ..your code goes here!
	int junk;
	std::cin >> junk;

    return 0;
}
