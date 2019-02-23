#ifndef STEREOPOSEDITOR_H_
#define STEREOPOSEDITOR_H_

#include <EditorHeaders.h>
#include "StereoPos.h"

enum class BOARDPROP {
	kWidth,
	kHeight,
	kSquareSize
};

class StereoPosEditor : public GenericEditor
{
public:
	StereoPosEditor(GenericProcessor * parentNode, bool useDefaultParameterEditors);
	~StereoPosEditor() {};

	void editorShown(Label*, TextEditor& textEditorShown) {};

	void buttonEvent(Button* button);

	void updateSettings() {};
	void update() {};

	double getBoardDims(BOARDPROP);

	bool showCapturedImages() { return m_setShowCapture; }

private:
	StereoPos * m_proc;

	ScopedPointer<TextEditor> intervalText;
	ScopedPointer<TextEditor> boardWidthText;
	ScopedPointer<TextEditor> boardHeightText;
	ScopedPointer<TextEditor> boardSquareSizeText;
	ScopedPointer<Label> intervalLabel;
	ScopedPointer<UtilityButton> captureButton;
	ScopedPointer<ToggleButton> showVideoCapture;

	bool m_setShowCapture = false;

	String board_width("137");
	String board_height("148");
	String square_size("11");

	const unsigned int nCalibrationImagesToCaputure = 1;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StereoPosEditor);
};

#endif