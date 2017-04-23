#ifndef GUI_H_
#define GUI_H_

#include <vector>
#include "GeometryBar.h"
#include "LightsBar.h"
#include "ShadersBar.h"
#include "CurvesBar.h"

class GUI
{
public:
	explicit GUI(Renderer *);
	virtual ~GUI();

	void Setup();
	void Draw();

	void GeometryClicked();
	void LightsClicked();
	void ShadersClicked();
	void CurvesClicked();
private:
	Renderer *m_renderer;
	GeometryBar *m_geometrybar;
	LightsBar *m_lightsbar;
	ShadersBar *m_shadersbar;
	CurvesBar *m_curvesbar;

	ofxPanel *m_mainPanel;
	ofxButton m_geometryButton;
	ofxButton m_lightsButton;
	ofxButton m_shadersButton;
	ofxButton m_curvesButton;
};

#endif //GUI_H_