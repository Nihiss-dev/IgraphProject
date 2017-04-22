#include "GUI.h"

GUI::GUI(Renderer *renderer) : m_renderer(renderer)
{
	m_geometrybar = new GeometryBar(m_renderer);
	m_mainPanel = new ofxPanel();
}

GUI::~GUI()
{
	delete m_geometrybar;
	delete m_mainPanel;
}

void	GUI::Setup()
{
	m_geometrybar->Setup();
	m_mainPanel->setup();

	// Add button
	m_mainPanel->add(m_geometryButton.setup("Geometry"));

	// Set listener
	m_geometryButton.addListener(this, &GUI::GeometryClicked);
}

void	GUI::Draw()
{
	m_mainPanel->draw();
	m_geometrybar->Draw();
}

void	GUI::GeometryClicked()
{
	m_geometrybar->Show();
	//hide other if needed
}