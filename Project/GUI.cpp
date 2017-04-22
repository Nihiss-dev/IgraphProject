#include "GUI.h"

GUI::GUI(Renderer *renderer) : m_renderer(renderer)
{
	m_geometrybar = new GeometryBar(m_renderer);
	m_lightsbar = new LightsBar(m_renderer);
	m_mainPanel = new ofxPanel();
}

GUI::~GUI()
{
	delete m_geometrybar;
	delete m_lightsbar;
	delete m_mainPanel;
}

void	GUI::Setup()
{
	m_geometrybar->Setup();
	m_lightsbar->Setup();
	m_mainPanel->setup();

	// Add button
	m_mainPanel->add(m_geometryButton.setup("Geometry"));
	m_mainPanel->add(m_lightsButton.setup("Lights"));

	// Set listener
	m_geometryButton.addListener(this, &GUI::GeometryClicked);
	m_lightsButton.addListener(this, &GUI::LightsClicked);
}

void	GUI::Draw()
{
	m_mainPanel->draw();
	m_geometrybar->Draw();
	m_lightsbar->Draw();
}

void	GUI::GeometryClicked()
{
	m_geometrybar->Show();
	m_lightsbar->Hide();
	//hide other if needed
}

void	GUI::LightsClicked()
{
	m_geometrybar->Hide();
	m_lightsbar->Show();
}