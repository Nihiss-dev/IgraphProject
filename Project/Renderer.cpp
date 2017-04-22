#include "Renderer.h"

Renderer::Renderer()
{
	//m_objects.push_back(new Primitive(PrimitiveType::CUBE));
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
	ofEnableLighting();
	m_cam->begin();

	// enable lights
	for (std::vector<ofLight*>::iterator it = m_lights.begin(); it != m_lights.end(); it++)
		(*it)->enable();

	for (std::vector<Object*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
		(*it)->Draw();

	m_cam->end();
	ofDisableDepthTest();
	ofDisableLighting();

	for (std::vector<ofLight*>::iterator it = m_lights.begin(); it != m_lights.end(); it++)
		(*it)->draw();

	fbo.end();
	fbo.draw(0,0);
}

void	Renderer::Update()
{

}

void	Renderer::AddObject(Object *object)
{
	object->Setup();
	m_objects.push_back(object);
}

void	Renderer::AddLight(ofLight *light)
{
	m_lights.push_back(light);
}