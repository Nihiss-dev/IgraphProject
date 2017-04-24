#include "GUI.h"

GUI::GUI(Renderer *renderer) : m_renderer(renderer)
{
	m_geometrybar = new GeometryBar(m_renderer);
	m_lightsbar = new LightsBar(m_renderer);
	m_mainPanel = new ofxPanel();
	m_shadersbar = new ShadersBar(m_renderer);
	m_curvesbar = new CurvesBar(m_renderer);

	m_rt = false;
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
	m_mainPanel->add(m_raytracingButton.setup("Raytracing"));

	// Set listener
	m_geometryButton.addListener(this, &GUI::GeometryClicked);
	m_lightsButton.addListener(this, &GUI::LightsClicked);
	m_shadersButton.addListener(this, &GUI::ShadersClicked);
	m_curvesButton.addListener(this, &GUI::CurvesClicked);
	m_raytracingButton.addListener(this, &GUI::RaytracingClicked);
}

void	GUI::Draw()
{
	m_mainPanel->draw();
	m_geometrybar->Draw();
	m_lightsbar->Draw();
	m_shadersbar->Draw();
	m_curvesbar->Draw();

	if (m_rt)
		m_raytracing.Draw();
}

void	GUI::GeometryClicked()
{
	m_geometrybar->Show();
	m_lightsbar->Hide();
	m_shadersbar->Hide();
	m_curvesbar->Hide();
	m_rt = false;
	//hide other if needed
}

void	GUI::LightsClicked()
{
	m_geometrybar->Hide();
	m_lightsbar->Show();
	m_shadersbar->Hide();
	m_curvesbar->Hide();
	m_rt = false;
}

void	GUI::ShadersClicked()
{
	m_geometrybar->Hide();
	m_lightsbar->Hide();
	m_shadersbar->Show();
	m_curvesbar->Hide();
	m_rt = false;
}

void	GUI::CurvesClicked()
{
	m_geometrybar->Hide();
	m_lightsbar->Hide();
	m_shadersbar->Hide();
	m_curvesbar->Show();
	m_rt = false;
}

void	GUI::RaytracingClicked()
{
	m_geometrybar->Hide();
	m_lightsbar->Hide();
	m_shadersbar->Hide();
	m_curvesbar->Hide();
	m_rt = true;

	
	m_raytracing.Setup(500, 500);
	m_raytracing.Compute();
}