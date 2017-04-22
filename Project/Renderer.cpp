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
	/*fbo.begin();
	for (std::vector<Object*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
		(*it)->Setup();
	fbo.end();*/
}

void	Renderer::Draw()
{
	fbo.begin();
	ofEnableDepthTest();
	ofEnableLighting();
	m_cam->begin();

	for (std::vector<ofLight*>::iterator it = m_lights.begin(); it != m_lights.end(); it++)
		(*it)->enable();
	
	for (std::vector<Object*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
	{
		(*it)->Draw();
	}
	ofDisableLighting();
	ofDisableDepthTest();

	for (std::vector<ofLight*>::iterator it = m_lights.begin(); it != m_lights.end(); it++)
		(*it)->disable();

	m_cam->end();

	fbo.end();
	fbo.draw(0,0);
}

void	Renderer::Update()
{

}

void	Renderer::AddObject(Object *object)
{
	//object->Setup();
	m_objects.push_back(object);
}

void	Renderer::AddLight(ofLight *light)
{
	if (m_lights.size() == 8)
	{
		ofDrawBitmapString(ofToString("You can't add more than 8 lights in scene"), ofPoint(30, 75));
		std::cout << "You can't add more than 8 lights in scene" << std::endl;
	}
	else
		m_lights.push_back(light);
}