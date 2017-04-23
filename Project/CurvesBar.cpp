#include "CurvesBar.h"

CurvesBar::CurvesBar(Renderer *renderer) : m_renderer(renderer), m_visible(false), m_BezierEnabled(false), m_drawBezier(false),
	m_HermiteEnabled(false), m_drawHermite(false), m_CatmullRomenabled(false), m_drawCatmullRom(false)
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

	m_HermiteCurvesPanel.setup();
	m_HermiteCurvesPanel.setName("Create Hermite curve");
	m_HermiteCurvesPanel.setPosition(440,0);

	m_CatmullRomPanel.setup();
	m_CatmullRomPanel.setName("Create CatmullRom Patch");
	m_CatmullRomPanel.setPosition(440,0);

	m_panel.add(m_BezierCubicButton.setup("Add Bezier Cubic Curve"));
	m_panel.add(m_HermiteCubicButton.setup("Add Hermite Cubic Curve"));
	m_panel.add(m_CatmullRomPatchButton.setup("Add CatmullRom"));

	m_BezierCurvesPanel.add(m_BezierPt1X.setup("Bezier Point1 X", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt1Y.setup("Bezier Point1 Y", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt1Z.setup("Bezier Point1 Z", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt2X.setup("Bezier Point2 X", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt2Y.setup("Bezier Point2 Y", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt2Z.setup("Bezier Point2 Z", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt3X.setup("Bezier Point3 X", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt3Y.setup("Bezier Point3 Y", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt3Z.setup("Bezier Point3 Z", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt4X.setup("Bezier Point4 X", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt4Y.setup("Bezier Point4 Y", 0, -500, 500));
	m_BezierCurvesPanel.add(m_BezierPt4Z.setup("Bezier Point4 Z", 0, -500, 500));
	m_BezierCurvesPanel.add(m_CreateBezier.setup("Draw Bezier Curve"));

	m_HermiteCurvesPanel.add(m_HermitePt1X.setup("Hermite Point1 X", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermitePt1Y.setup("Hermite Point1 Y", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermitePt1Z.setup("Hermite Point1 Z", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermitePt2X.setup("Hermite Point2 X", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermitePt2Y.setup("Hermite Point2 Y", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermitePt2Z.setup("Hermite Point2 Z", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermiteVct1X.setup("Hermite Vector1 X", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermiteVct1Y.setup("Hermite Vector1 Y", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermiteVct1Z.setup("Hermite Vector1 Z", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermiteVct2X.setup("Hermite Vector2 X", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermiteVct2Y.setup("Hermite Vector2 Y", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_HermiteVct2Z.setup("Hermite Vector2 Z", 0, -500, 500));
	m_HermiteCurvesPanel.add(m_CreateHermite.setup("Draw Hermite Curve"));

	m_CatmullRomPanel.add(m_CatmullRomPt1X.setup("CatmullRom Point1 X", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt1Y.setup("CatmullRom Point1 Y", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt1Z.setup("CatmullRom Point1 Z", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt2X.setup("CatmullRom Point2 X", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt2Y.setup("CatmullRom Point2 Y", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt2Z.setup("CatmullRom Point2 Z", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt3X.setup("CatmullRom Point3 X", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt3Y.setup("CatmullRom Point3 Y", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt3Z.setup("CatmullRom Point3 Z", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt4X.setup("CatmullRom Point4 X", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt4Y.setup("CatmullRom Point4 Y", 0, -500, 500));
	m_CatmullRomPanel.add(m_CatmullRomPt4Z.setup("CatmullRom Point4 Z", 0, -500, 500));
	m_CatmullRomPanel.add(m_CreateCatmullRom.setup("Draw CatmullRom Patch"));


	m_BezierCubicButton.addListener(this, &CurvesBar::AddBezierCubicCurve);
	m_HermiteCubicButton.addListener(this, &CurvesBar::AddHermiteCubicCurve);
	m_CatmullRomPatchButton.addListener(this, &CurvesBar::AddCatmullRomPatch);
	m_CreateBezier.addListener(this, &CurvesBar::DrawBezierCurve);
	m_CreateHermite.addListener(this, &CurvesBar::DrawHermiteCubicCurve);
	m_CreateCatmullRom.addListener(this, &CurvesBar::DrawCatmullRomPatch);
}

void	CurvesBar::Draw()
{
	if (m_visible)
		m_panel.draw();
	if (m_BezierEnabled)
		m_BezierCurvesPanel.draw();
	if (m_HermiteEnabled)
		m_HermiteCurvesPanel.draw();
	if (m_CatmullRomenabled)
		m_CatmullRomPanel.draw();
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
	if (m_drawHermite)
		DrawHermite();
	if (m_drawCatmullRom)
	{
		ofSetHexColor(0xFF0000);
		ofNoFill();
		ofDrawCurve(m_CatmullRomPt1X, m_CatmullRomPt1Y, m_CatmullRomPt1Z,
			m_CatmullRomPt2X, m_CatmullRomPt2Y, m_CatmullRomPt2Z,
			m_CatmullRomPt3X, m_CatmullRomPt3Y, m_CatmullRomPt3Z,
			m_CatmullRomPt4X, m_CatmullRomPt4Y, m_CatmullRomPt4Z);
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
	m_HermiteEnabled = false;
	m_CatmullRomenabled = false;
}

void	CurvesBar::AddBezierCubicCurve()
{
	m_BezierEnabled = true;
}

void	CurvesBar::AddHermiteCubicCurve()
{
	m_HermiteEnabled = true;
}

void	CurvesBar::AddCatmullRomPatch()
{
	m_CatmullRomenabled = true;
}

void	CurvesBar::DrawBezierCurve()
{
	m_drawBezier = true;
}

void	CurvesBar::DrawHermiteCubicCurve()
{
	m_drawHermite = true;
}

void	CurvesBar::DrawCatmullRomPatch()
{
	m_drawCatmullRom = true;
}

void	CurvesBar::DrawHermite()
{
	ofPoint Pt1(m_HermitePt1X, m_HermitePt1Y, m_HermitePt1Z);
	ofPoint Pt2(m_HermitePt2X, m_HermitePt2Y, m_HermitePt2Z);
	ofVec3f V1(m_HermiteVct1X, m_HermiteVct1Y, m_HermiteVct1Z);
	ofVec3f V2(m_HermiteVct2X, m_HermiteVct2Y, m_HermiteVct2Z);
	ofPolyline line;
	for (float t = 0.0f; t <= 1; t += 0.01)
	{
		line.addVertex((1 + 2 * t) * pow((1 - t), 2) * Pt1 + t * pow((1 - t), 2) * V1
						+ pow(t, 2) * (t - 1) * V2 + pow(t, 2) * (3 - 2 * t) * Pt2);
	}
	ofSetHexColor(0xFF0000);
	line.draw();
	ofSetHexColor(0xFFFFFF);
}

void	CurvesBar::DrawCatmullRom()
{
	
}