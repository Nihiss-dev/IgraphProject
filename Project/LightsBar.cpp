#include "LightsBar.h"

LightsBar::LightsBar(Renderer *renderer) : m_renderer(renderer), m_visible(false), m_spotVisible(false)
{

}

LightsBar::~LightsBar()
{

}

void	LightsBar::Setup()
{
	m_panel.setup();
	m_panel.setName("Lights");
	m_panel.setPosition(225,0);

	m_SpotPanel.setup();
	m_SpotPanel.setName("SpotLight");
	m_SpotPanel.setPosition(400,0);

	// Add buttons
	m_panel.add(m_addSpotLight.setup("SpotLight"));

	m_SpotPanel.add(m_SpotX.setup("SpotX", 0, -500, 500));
	m_SpotPanel.add(m_SpotY.setup("SpotY", 0, -500, 500));
	m_SpotPanel.add(m_SpotZ.setup("SpotZ", 0, -500, 500));
	m_SpotPanel.add(m_SpotColorR.setup("Spot Color R", 255, 0, 255));
	m_SpotPanel.add(m_SpotColorG.setup("Spot Color G", 255, 0, 255));
	m_SpotPanel.add(m_SpotColorB.setup("Spot Color B", 255, 0, 255));
	m_SpotPanel.add(m_SpotCutOff.setup("Spot cut off", 50, 0, 100));
	m_SpotPanel.add(m_SpotConcentration.setup("Spot concentration", 45, 0, 100));
	m_SpotPanel.add(m_SpotCreate.setup("Create Spot Light"));
	
	m_addSpotLight.addListener(this, &LightsBar::AddSpotLight);
	m_SpotCreate.addListener(this, &LightsBar::CreateSpotLight);
}

void	LightsBar::Draw()
{
	if (m_visible)
		m_panel.draw();
	if (m_spotVisible)
		m_SpotPanel.draw();
}

void	LightsBar::Show()
{
	m_visible = true;
}

void	LightsBar::Hide()
{
	m_visible = false;
	m_spotVisible = false;
}

void	LightsBar::AddSpotLight()
{
	m_spotVisible = true;
}

void	LightsBar::CreateSpotLight()
{
	float x = m_SpotX;
	float y = m_SpotY;
	float z = m_SpotZ;

	float r = m_SpotColorR;
	float g = m_SpotColorG;
	float b = m_SpotColorB;

	float cut = m_SpotCutOff;

	float concentration = m_SpotConcentration;
	ofLight *light = new ofLight();
	light->setPosition(x, y, z);
	light->setDiffuseColor(ofColor(r, g, b));
	light->setSpecularColor(ofColor(r, g, b));
	light->setSpotlight();
	light->setSpotlightCutOff(cut);
	light->setSpotConcentration(concentration);

	m_renderer->AddLight(light);
}