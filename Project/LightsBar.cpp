#include "LightsBar.h"

LightsBar::LightsBar(Renderer *renderer) : m_renderer(renderer), m_visible(false), m_spotVisible(false),
	m_pointVisible(false), m_directionalVisible(false), m_ambiantVisible(false)
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

	m_DirectionalPanel.setup();
	m_DirectionalPanel.setName("DirectionalLight");
	m_DirectionalPanel.setPosition(440,0);

	m_AmbiantPanel.setup();
	m_AmbiantPanel.setName("AmbiantLight");
	m_AmbiantPanel.setPosition(440,0);

	// Add buttons
	m_panel.add(m_addSpotLight.setup("SpotLight"));
	m_panel.add(m_addPointLight.setup("PointLight"));
	m_panel.add(m_addDirectionalLight.setup("DirectionalLight"));
	m_panel.add(m_addAmbiantLight.setup("AmbiantLight"));

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

	m_DirectionalPanel.add(m_DirectionalX.setup("DirectionalX", 0, -500, 500));
	m_DirectionalPanel.add(m_DirectionalY.setup("DirectionalY", 0, -500, 500));
	m_DirectionalPanel.add(m_DirectionalZ.setup("DirectionalZ", 0, -500, 500));
	m_DirectionalPanel.add(m_DirectionalDirectionX.setup("Directional Direction X", 0, -180, 180));
	m_DirectionalPanel.add(m_DirectionalDirectionY.setup("Directional Direction Y", 0, -180, 180));
	m_DirectionalPanel.add(m_DirectionalDirectionZ.setup("Directional Direction Z", 0, -180, 180));
	m_DirectionalPanel.add(m_DirectionalColorR.setup("Directional Color R", 255, 0, 255));
	m_DirectionalPanel.add(m_DirectionalColorG.setup("Directional Color G", 255, 0, 255));
	m_DirectionalPanel.add(m_DirectionalColorB.setup("Directional Color B", 255, 0, 255));
	m_DirectionalPanel.add(m_DirectionalCreate.setup("Create Directional light"));

	m_AmbiantPanel.add(m_AmbiantX.setup("AmbiantX", 0, -500, 500));
	m_AmbiantPanel.add(m_AmbiantY.setup("AmbiantY", 0, -500, 500));
	m_AmbiantPanel.add(m_AmbiantZ.setup("AmbiantZ", 0, -500, 500));
	m_AmbiantPanel.add(m_AmbiantColorR.setup("Ambiant Color R", 255, 0, 255));
	m_AmbiantPanel.add(m_AmbiantColorG.setup("Ambiant Color G", 255, 0, 255));
	m_AmbiantPanel.add(m_AmbiantColorB.setup("Ambiant Color B", 255, 0, 255));
	m_AmbiantPanel.add(m_AmbiantCreate.setup("Create Ambiant Light"));

	m_addSpotLight.addListener(this, &LightsBar::AddSpotLight);
	m_addPointLight.addListener(this, &LightsBar::AddPointLight);
	m_addDirectionalLight.addListener(this, &LightsBar::AddDirectionalLight);
	m_addAmbiantLight.addListener(this, &LightsBar::AddAmbiantLight);
	m_SpotCreate.addListener(this, &LightsBar::CreateSpotLight);
	m_PointCreate.addListener(this, &LightsBar::CreatePointLight);
	m_DirectionalCreate.addListener(this, &LightsBar::CreateDirectionalLight);
	m_AmbiantCreate.addListener(this, &LightsBar::CreateAmbiantLight);
}

void	LightsBar::Draw()
{
	if (m_visible)
		m_panel.draw();
	if (m_spotVisible)
		m_SpotPanel.draw();
	if (m_pointVisible)
		m_PointPanel.draw();
	if (m_directionalVisible)
		m_DirectionalPanel.draw();
	if (m_ambiantVisible)
		m_AmbiantPanel.draw();
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
	m_directionalVisible = false;
	m_ambiantVisible = false;
}

void	LightsBar::AddSpotLight()
{
	m_spotVisible = true;
	m_pointVisible = false;
	m_directionalVisible = false;
	m_ambiantVisible = false;
}

void	LightsBar::AddPointLight()
{
	m_spotVisible = false;
	m_pointVisible = true;
	m_directionalVisible = false;
	m_ambiantVisible = false;
}

void	LightsBar::AddDirectionalLight()
{
	m_directionalVisible = true;
	m_spotVisible = false;
	m_pointVisible = false;
	m_ambiantVisible = false;
}

void	LightsBar::AddAmbiantLight()
{
	m_directionalVisible = false;
	m_spotVisible = false;
	m_pointVisible = false;
	m_ambiantVisible = true;
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

void	LightsBar::CreateDirectionalLight()
{
	float x = m_DirectionalX;
	float y = m_DirectionalY;
	float z = m_DirectionalZ;

	float ox = m_DirectionalDirectionX;
	float oy = m_DirectionalDirectionY;
	float oz = m_DirectionalDirectionZ;

	float r = m_DirectionalColorR;
	float g = m_DirectionalColorG;
	float b = m_DirectionalColorB;

	ofLight *light = new ofLight();
	light->setDiffuseColor(ofColor(r, g, b));
	light->setSpecularColor(ofColor(r, g, b));
	light->setDirectional();
	light->setOrientation(ofVec3f(ox, oy, oz));
	light->setPosition(x, y, z);
	m_renderer->AddLight(light);
}

void	LightsBar::CreateAmbiantLight()
{
	float x = m_AmbiantX;
	float y = m_AmbiantY;
	float z = m_AmbiantZ;

	float r = m_AmbiantColorR;
	float g = m_AmbiantColorG;
	float b = m_AmbiantColorB;

	ofLight *light = new ofLight();
	//light->setDiffuseColor(ofColor(r, g, b));
	//light->setSpecularColor(ofColor(r, g, b));
	light->setAmbientColor(ofColor(r, g, b));
	//light->setPosition(x, y, z);
	m_renderer->AddLight(light);
}