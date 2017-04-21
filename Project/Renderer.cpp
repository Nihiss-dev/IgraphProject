#include "Renderer.h"

Renderer::Renderer()
{
	m_objects.push_back(new Primitive(PrimitiveType::CUBE));
}

Renderer::~Renderer()
{

}

void	Renderer::Setup()
{
	fbo.begin();
	for (std::vector<Object*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
		(*it)->Setup();
	fbo.end();
}

void	Renderer::Draw()
{
	fbo.begin();

	for (std::vector<Object*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
		(*it)->Draw();

	fbo.end();
	fbo.draw(0,0);
}

void	Renderer::Update()
{

}