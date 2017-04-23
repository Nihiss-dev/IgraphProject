#include "GUI.h"

GUI::GUI(Renderer *renderer) : m_renderer(renderer)
{
	m_geometrybar = new GeometryBar(m_renderer);
	m_lightsbar = new LightsBar(m_renderer);
	m_mainPanel = new ofxPanel();
	m_shadersbar = new ShadersBar(m_renderer);
	m_curvesbar = new CurvesBar(m_renderer);
}

GUI::~GUI()
{
	delete m_geometrybar;
	delete m_lightsbar;
	delete m_mainPanel;
	delete m_shadersbar;
	delete m_curvesbar;
}

void	GUI::Setup()
{
	m_geometrybar->Setup();
	m_lightsbar->Setup();
	m_shadersbar->Setup();
	m_curvesbar->Setup();
	m_mainPanel->setup();

	// Add button
	m_mainPanel->add(m_geometryButton.setup("Geometry"));
	m_mainPanel->add(m_lightsButton.setup("Lights"));
	m_mainPanel->add(m_shadersButton.setup("Shaders"));
	m_mainPanel->add(m_curvesButton.setup("Curves"));

	// Set listener
	m_geometryButton.addListener(this, &GUI::GeometryClicked);
	m_lightsButton.addListener(this, &GUI::LightsClicked);
	m_shadersButton.addListener(this, &GUI::ShadersClicked);
	m_curvesButton.addListener(this, &GUI::CurvesClicked);
}

void	GUI::Draw()
{
	m_mainPanel->draw();
	m_geometrybar->Draw();
	m_lightsbar->Draw();
	m_shadersbar->Draw();
	m_curvesbar->Draw();
}

void	GUI::GeometryClicked()
{
	m_geometrybar->Show();
	m_lightsbar->Hide();
	m_shadersbar->Hide();
	m_curvesbar->Hide();
	//hide other if needed
}

void	GUI::LightsClicked()
{
	m_geometrybar->Hide();
	m_lightsbar->Show();
	m_shadersbar->Hide();
	m_curvesbar->Hide();
}

void	GUI::ShadersClicked()
{
	m_geometrybar->Hide();
	m_lightsbar->Hide();
	m_shadersbar->Show();
	m_curvesbar->Hide();
}

void	GUI::CurvesClicked()
{
	m_geometrybar->Hide();
	m_lightsbar->Hide();
	m_shadersbar->Hide();
	m_curvesbar->Show();
}