#include "GeometryBar.h"

GeometryBar::GeometryBar(Renderer *renderer) : m_renderer(renderer)
{

}

GeometryBar::~GeometryBar()
{

}

void	GeometryBar::Setup()
{
	m_panel.setup();
	m_panel.setName("Geometry");
	m_panel.setPosition(0,0);

	//Add buttons
	m_panel.add(m_addCube.setup("Cube"));
	m_panel.add(m_addSphere.setup("Sphere"));

	//Add listeners
	m_addCube.addListener(this, &GeometryBar::AddCube);
}

void	GeometryBar::Draw()
{
	m_panel.draw();
}

void	GeometryBar::Show()
{

}

void	GeometryBar::Hide()
{

}

void	GeometryBar::AddCube()
{
	m_renderer->AddObject(new Primitive(PrimitiveType::CUBE));
}