#include "StereoPos.h"
#include "StereoPosEditor.h"
#include "../PosTracker/PosTracker.h"

StereoPos::StereoPos() : GenericProcessor("Stereo Pos")
{
	setProcessorType (PROCESSOR_TYPE_FILTER);
	sendSampleCount = false;
}

void StereoPos::process(AudioSampleBuffer& buffer)
{}

void StereoPos::updateSettings()
{

}

AudioProcessorEditor * StereoPos::createEditor() {
	editor = new StereoPosEditor(this, true);
	return editor;

}

void StereoPos::testFcn() {
	GenericProcessor * maybe_merger = getSourceNode();
	if ( maybe_merger->isMerger() ) {
		maybe_merger->switchIO(0); // sourceNodeA
		PosTracker* video_A = (PosTracker*)maybe_merger->getSourceNode();
		if ( video_A )
			std::cout << "video_A->getDeviceName() " << video_A->getDeviceName() << std::endl;
		maybe_merger->switchIO(1); // sourceNodeA
		PosTracker* video_B = (PosTracker*)maybe_merger->getSourceNode();
		if ( video_1 ) {
			std::cout << "video_B->getDeviceName() " << video_B->getDeviceName() << std::endl;
		}
	}
}

void StereoPos::saveCustomParametersToXml(XmlElement * xml)
{
	xml->setAttribute("Type", "StereoPos");
	XmlElement * paramXml = xml->createNewChildElement("Parameters");
}

void StereoPos::loadCustomParametersFromXml()
{
	forEachXmlChildElementWithTagName(*parametersAsXml, paramXml, "Parameters")
	{

	}
	updateSettings();
}
