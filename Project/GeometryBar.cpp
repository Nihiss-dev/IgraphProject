#include "GeometryBar.h"

GeometryBar::GeometryBar(Renderer *renderer) : m_renderer(renderer), m_visible(false)
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

	//Add buttons
	m_panel.add(m_addCube.setup("Cube"));
	m_panel.add(m_addSphere.setup("Sphere"));

	//Add listeners
	m_addCube.addListener(this, &GeometryBar::AddCube);
	m_addSphere.addListener(this, &GeometryBar::AddSphere);
}

void	GeometryBar::Draw()
{
	if (m_visible)
		m_panel.draw();
}

void	GeometryBar::Show()
{
	m_visible = true;
}

void	GeometryBar::Hide()
{
	m_visible = false;
}

void	GeometryBar::AddCube()
{
	m_renderer->AddObject(new Primitive(PrimitiveType::CUBE));
}

void	GeometryBar::AddSphere()
{
	m_renderer->AddObject(new Primitive(PrimitiveType::SPHERE));
}