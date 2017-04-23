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
	void AddHermiteCubicCurve();

	void DrawBezierCurve();
	void DrawHermiteCubicCurve();
	void DrawHermite();

private:
	ofxPanel m_panel;
	ofxButton m_BezierCubicButton;
	ofxButton m_HermiteCubicButton;

	bool m_visible;

	// Bezier Cubic curves
	ofxPanel m_BezierCurvesPanel;
	ofxFloatSlider m_BezierPt1X;
	ofxFloatSlider m_BezierPt1Y;
	ofxFloatSlider m_BezierPt1Z;
	ofxFloatSlider m_BezierPt2X;
	ofxFloatSlider m_BezierPt2Y;
	ofxFloatSlider m_BezierPt2Z;
	ofxFloatSlider m_BezierPt3X;
	ofxFloatSlider m_BezierPt3Y;
	ofxFloatSlider m_BezierPt3Z;
	ofxFloatSlider m_BezierPt4X;
	ofxFloatSlider m_BezierPt4Y;
	ofxFloatSlider m_BezierPt4Z;
	ofxButton m_CreateBezier;

	// Hermite Cubic curves
	ofxPanel m_HermiteCurvesPanel;
	ofxFloatSlider m_HermitePt1X;
	ofxFloatSlider m_HermitePt1Y;
	ofxFloatSlider m_HermitePt1Z;
	ofxFloatSlider m_HermitePt2X;
	ofxFloatSlider m_HermitePt2Y;
	ofxFloatSlider m_HermitePt2Z;
	ofxFloatSlider m_HermiteVct1X;
	ofxFloatSlider m_HermiteVct1Y;
	ofxFloatSlider m_HermiteVct1Z;
	ofxFloatSlider m_HermiteVct2X;
	ofxFloatSlider m_HermiteVct2Y;
	ofxFloatSlider m_HermiteVct2Z;
	ofxButton m_CreateHermite;

	bool m_BezierEnabled;
	bool m_HermiteEnabled;
	bool m_drawBezier;
	bool m_drawHermite;
	
	Renderer *m_renderer;
};

#endif //CURVESBAR_H_