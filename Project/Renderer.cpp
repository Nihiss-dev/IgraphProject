#include "Renderer.h"

Renderer::Renderer()
{
	m_objects.push_back(new Primitive(PrimitiveType::CUBE));
	m_cam = new ofEasyCam();
	m_cam->setPosition(0,0,0);
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
	ofEnableDepthTest();
	m_cam->begin();

	for (std::vector<Object*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
		(*it)->Draw();

	m_cam->end();
	ofDisableDepthTest();
	fbo.end();
	fbo.draw(0,0);
}

void	Renderer::Update()
{
}