#ifndef CURVESBAR_H_
#define CURVESBAR_H_

#include "ofxGui.h"
#include "Renderer.h"
#include "ToolBar.h"

class CurvesBar : public ToolBar
{
public:
	explicit CurvesBar(Renderer*);
	virtual ~CurvesBar();

	void Setup();
	void Draw();
	void Show();
	void Hide();

	void AddBezierCubicCurve();

	void DrawBezierCurve();

private:
	ofxPanel m_panel;
	ofxButton m_BezierCubicButton;

	bool m_visible;

	// Bezier Cubic curves
	ofxPanel m_BezierCurvesPanel;
	ofxFloatSlider m_BezierPt1X;
	ofxFloatSlider m_BezierPt1Y;
	ofxFloatSlider m_BezierPt2X;
	ofxFloatSlider m_BezierPt2Y;
	ofxFloatSlider m_BezierPt3X;
	ofxFloatSlider m_BezierPt3Y;
	ofxFloatSlider m_BezierPt4X;
	ofxFloatSlider m_BezierPt4Y;
	ofxButton m_CreateBezier;

	bool m_BezierEnabled;
	bool m_drawBezier;
	
	Renderer *m_renderer;
};

#endif //CURVESBAR_H_