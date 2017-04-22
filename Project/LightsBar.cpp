#include "LightsBar.h"

LightsBar::LightsBar(Renderer *renderer) : m_renderer(renderer), m_visible(false), m_spotVisible(false), m_pointVisible(false)
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
	m_SpotPanel.setPosition(440,0);

	m_PointPanel.setup();
	m_PointPanel.setName("PointLight");
	m_PointPanel.setPosition(440,0);

	// Add buttons
	m_panel.add(m_addSpotLight.setup("SpotLight"));
	m_panel.add(m_addPointLight.setup("PointLight"));

	m_SpotPanel.add(m_SpotX.setup("SpotX", 0, -500, 500));
	m_SpotPanel.add(m_SpotY.setup("SpotY", 0, -500, 500));
	m_SpotPanel.add(m_SpotZ.setup("SpotZ", 0, -500, 500));
	m_SpotPanel.add(m_SpotColorR.setup("Spot Color R", 255, 0, 255));
	m_SpotPanel.add(m_SpotColorG.setup("Spot Color G", 255, 0, 255));
	m_SpotPanel.add(m_SpotColorB.setup("Spot Color B", 255, 0, 255));
	m_SpotPanel.add(m_SpotCutOff.setup("Spot cut off", 50, 0, 100));
	m_SpotPanel.add(m_SpotConcentration.setup("Spot concentration", 45, 0, 100));
	m_SpotPanel.add(m_SpotCreate.setup("Create Spot Light"));

	m_PointPanel.add(m_PointX.setup("PointX", 0, -500, 500));
	m_PointPanel.add(m_PointY.setup("PointY", 0, -500, 500));
	m_PointPanel.add(m_PointZ.setup("PointZ", 0, -500, 500));
	m_PointPanel.add(m_PointColorR.setup("Point Color R", 255, 0, 255));
	m_PointPanel.add(m_PointColorG.setup("Point Color G", 255, 0, 255));
	m_PointPanel.add(m_PointColorB.setup("Point Color B", 255, 0, 255));
	m_PointPanel.add(m_PointCreate.setup("Create Point Light"));

	m_addSpotLight.addListener(this, &LightsBar::AddSpotLight);
	m_addPointLight.addListener(this, &LightsBar::AddPointLight);
	m_SpotCreate.addListener(this, &LightsBar::CreateSpotLight);
	m_PointCreate.addListener(this, &LightsBar::CreatePointLight);
}

void	LightsBar::Draw()
{
	if (m_visible)
		m_panel.draw();
	if (m_spotVisible)
		m_SpotPanel.draw();
	if (m_pointVisible)
		m_PointPanel.draw();
}

void	LightsBar::Show()
{
	m_visible = true;
}

void	LightsBar::Hide()
{
	m_visible = false;
	m_spotVisible = false;
	m_pointVisible = false;
}

void	LightsBar::AddSpotLight()
{
	m_spotVisible = true;
	m_pointVisible = false;
}

void	LightsBar::AddPointLight()
{
	m_spotVisible = false;
	m_pointVisible = true;
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

void	LightsBar::CreatePointLight()
{
	float x = m_PointX;
	float y = m_PointY;
	float z = m_PointZ;

	float r = m_PointColorR;
	float g = m_PointColorG;
	float b = m_PointColorB;

	ofLight *light = new ofLight();
	light->setDiffuseColor(ofColor(r, g, b));
	light->setSpecularColor(ofColor(r, g, b));
	light->setPointLight();
	light->setPosition(x, y, z);

	m_renderer->AddLight(light);
}