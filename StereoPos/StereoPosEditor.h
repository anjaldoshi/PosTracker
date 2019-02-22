#ifndef STEREOPOSEDITOR_H_
#define STEREOPOSEDITOR_H_

#include <EditorHeaders.h>
#include "StereoPos.h"

class StereoPosEditor : public GenericEditor
{
public:
	StereoPosEditor(GenericProcessor * parentNode, bool useDefaultParameterEditors);
	~StereoPosEditor() {};

	void editorShown(Label*, TextEditor& textEditorShown) {};

	void buttonEvent(Button* button);

	void updateSettings() {};
	void update() {};

private:
	StereoPos * m_proc;

	ScopedPointer<TextEditor> intervalText;
	ScopedPointer<Label> intervalLabel;
	ScopedPointer<UtilityButton> captureButton;

	const unsigned int nCalibrationImagesToCaputure = 20;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StereoPosEditor);
};

#endif