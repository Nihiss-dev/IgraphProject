#include "GeometryBar.h"

GeometryBar::GeometryBar(Renderer *renderer) : m_renderer(renderer), m_visible(false), m_cubeVisible(false), m_sphereVisible(false)
{

}

GeometryBar::~GeometryBar()
{

}

void	GeometryBar::Setup()
{
	m_panel.setup();
	m_panel.setName("Geometry");
	m_panel.setPosition(225,0);

	m_CubePanel.setup();
	m_CubePanel.setName("Cube");
	m_CubePanel.setPosition(440,0);

	m_SpherePanel.setup();
	m_SpherePanel.setName("Sphere");
	m_SpherePanel.setPosition(440,0);

	//Add buttons
	m_panel.add(m_addCube.setup("Cube"));
	m_panel.add(m_addSphere.setup("Sphere"));

	m_CubePanel.add(m_CubeX.setup("CubeX", 0, -500, 500));
	m_CubePanel.add(m_CubeY.setup("CubeY", 0, -500, 500));
	m_CubePanel.add(m_CubeZ.setup("CubeZ", 0, -500, 500));
	m_CubePanel.add(m_CreateCube.setup("Create Cube"));

	m_SpherePanel.add(m_SphereX.setup("SphereX", 0, -500, 500));
	m_SpherePanel.add(m_SphereY.setup("SphereY", 0, -500, 500));
	m_SpherePanel.add(m_SphereZ.setup("SphereZ", 0, -500, 500));
	m_SpherePanel.add(m_CreateSphere.setup("Create Sphere"));

	//Add listeners
	m_addCube.addListener(this, &GeometryBar::AddCube);
	m_addSphere.addListener(this, &GeometryBar::AddSphere);

	m_CreateCube.addListener(this, &GeometryBar::CreateCube);
	m_CreateSphere.addListener(this, &GeometryBar::CreateSphere);
}

void	GeometryBar::Draw()
{
	if (m_visible)
		m_panel.draw();
	if (m_cubeVisible)
		m_CubePanel.draw();
	if (m_sphereVisible)
		m_SpherePanel.draw();
}

void	GeometryBar::Show()
{
	m_visible = true;
}

void	GeometryBar::Hide()
{
	m_visible = false;
	m_cubeVisible = false;
	m_sphereVisible = false;
}

void	GeometryBar::AddCube()
{
	m_cubeVisible = true;
	m_sphereVisible = false;
	//m_renderer->AddObject(new Primitive(PrimitiveType::CUBE));
}

void	GeometryBar::AddSphere()
{
	m_sphereVisible = true;
	m_cubeVisible = false;
	//m_renderer->AddObject(new Primitive(PrimitiveType::SPHERE));
}

void	GeometryBar::CreateCube()
{
	float x = m_CubeX;
	float y = m_CubeY;
	float z = m_CubeZ;

	Primitive *primitive = new Primitive(PrimitiveType::CUBE);
	primitive->Setup();
	primitive->SetPosition(x, y, z);
	m_renderer->AddObject(primitive);
}

void	GeometryBar::CreateSphere()
{
	float x = m_SphereX;
	float y = m_SphereY;
	float z = m_SphereZ;

	Primitive *primitive = new Primitive(PrimitiveType::SPHERE);
	primitive->Setup();
	primitive->SetPosition(x, y,z);
	m_renderer->AddObject(primitive);
}