#include "Renderer.h"
#include "src/ofApp.h"

Renderer::Renderer() : m_blurEnabled(false)
{
	m_cam = new ofEasyCam();
	m_cam->setPosition(0,0,0);
}

Renderer::~Renderer()
{

}

void	Renderer::Setup()
{
	if (m_blurEnabled)
	{
		LoadBlurShader();
		fboBlurOnePass.allocate(1024,768);
		fboBlurTwoPass.allocate(1024,768);
	}
}

void	Renderer::DrawShaders()
{
	float blur = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 10, true);

	// Pass one
	fboBlurOnePass.begin();
	m_cam->begin();
	shaderBlurX.begin();
	shaderBlurX.setUniform1f("blurAmnt", blur);


	for (std::vector<ofLight*>::iterator it = m_lights.begin(); it != m_lights.end(); it++)
		(*it)->enable();

	for (std::vector<Object*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
	{
		(*it)->Draw();
	}

	for (std::vector<ofLight*>::iterator it = m_lights.begin(); it != m_lights.end(); it++)
		(*it)->disable();

	m_cam->end();
	shaderBlurX.end();
	fboBlurOnePass.end();

	// Pass two
	fboBlurTwoPass.begin();
	shaderBlurY.begin();

	shaderBlurY.setUniform1f("blurAmnt", blur);
	fboBlurOnePass.draw(0,0);
	shaderBlurY.end();
	fboBlurTwoPass.end();
	fboBlurTwoPass.draw(0,0);
}

void	Renderer::Draw()
{
	if (m_blurEnabled)
		DrawShaders();
	else
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
		fbo.draw(0, 0);
	}
}

void	Renderer::Update()
{

}

void	Renderer::AddObject(Object *object)
{
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

void	Renderer::EnableBlur()
{
	m_blurEnabled = true;
	Setup();
}

void	Renderer::DisableBlur()
{
	m_blurEnabled = false;
}

void	Renderer::DisableAll()
{
	m_blurEnabled = false;
}

void	Renderer::LoadBlurShader()
{
#ifdef TARGET_OPENGLES
	shaderBlurX.load("shadersES2/Blur/shaderBlurX");
	shaderBlurY.load("shadersES2/Blur/shaderBlurY");
#else
	if (ofIsGLProgrammableRenderer())
	{
		std::cout << "chargement des shaders" << std::endl;
		if (shaderBlurX.load("shadersGL3/Blur/shaderBlurX") == false)
			std::cout << "Nope" << std::endl;
		shaderBlurY.load("shadersGL3/Blur/shaderBlurY");
	}
	else
	{
		std::cout << "chargement des shaders" << std::endl;
		if (shaderBlurX.load("shadersGL2/Blur/shaderBlurX") == false)
			std::cout << "Nope" << std::endl;
		shaderBlurY.load("shadersGL2/Blur/shaderBlurY");
	}
#endif
}