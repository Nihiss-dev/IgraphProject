#include "CurvesBar.h"

CurvesBar::CurvesBar(Renderer *renderer) : m_renderer(renderer), m_visible(false), m_BezierEnabled(false), m_drawBezier(false)
{

}

CurvesBar::~CurvesBar()
{

}

void	CurvesBar::Setup()
{
	m_panel.setup();
	m_panel.setName("Curves");
	m_panel.setPosition(225,0);

	m_BezierCurvesPanel.setup();
	m_BezierCurvesPanel.setName("Create Bezier curve");
	m_BezierCurvesPanel.setPosition(440,0);

	m_panel.add(m_BezierCubicButton.setup("Add Bezier Cubic Curve"));

	m_BezierCurvesPanel.add(m_BezierPt1X.setup("Bezier Point1 X", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt1Y.setup("Bezier Point1 Y", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt2X.setup("Bezier Point2 X", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt2Y.setup("Bezier Point2 Y", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt3X.setup("Bezier Point3 X", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt3Y.setup("Bezier Point2 Y", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt4X.setup("Bezier Point4 X", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt4Y.setup("Bezier Point2 Y", 0, -500, 500));
	m_BezierCurvesPanel.add(m_CreateBezier.setup("Draw Bezier Curve"));

	m_BezierCubicButton.addListener(this, &CurvesBar::AddBezierCubicCurve);
	m_CreateBezier.addListener(this, &CurvesBar::DrawBezierCurve);
}

void	CurvesBar::Draw()
{
	if (m_visible)
		m_panel.draw();
	if (m_BezierEnabled)
		m_BezierCurvesPanel.draw();
	if (m_drawBezier)
	{
		ofSetHexColor(0xFF0000);
		ofNoFill();
		ofDrawBezier((float)m_BezierPt1X, (float)m_BezierPt1Y,
			(float)m_BezierPt2X, (float)m_BezierPt2Y,
			(float)m_BezierPt3X, (float)m_BezierPt3Y,
			(float)m_BezierPt4X, (float)m_BezierPt4Y);
		ofSetHexColor(0xFFFFFF);
	}
}

void	CurvesBar::Show()
{
	m_visible = true;
}

void	CurvesBar::Hide()
{
	m_visible = false;
	m_BezierEnabled = false;
	m_drawBezier = false;
}

void	CurvesBar::AddBezierCubicCurve()
{
	m_BezierEnabled = true;
}

void	CurvesBar::DrawBezierCurve()
{
	m_drawBezier = true;
}