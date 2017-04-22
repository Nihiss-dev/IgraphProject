#ifndef GUI_H_
#define GUI_H_

#include <vector>
#include "GeometryBar.h"
#include "LightsBar.h"

class GUI
{
public:
	explicit GUI(Renderer *);
	virtual ~GUI();

	void Setup();
	void Draw();

	void GeometryClicked();
	void LightsClicked();
private:
	Renderer *m_renderer;
	GeometryBar *m_geometrybar;
	LightsBar *m_lightsbar;

	ofxPanel *m_mainPanel;
	ofxButton m_geometryButton;
	ofxButton m_lightsButton;
};

#endif //GUI_H_