#include "Renderer.h"
#include "src/ofApp.h"

Renderer::Renderer() : m_blurEnabled(false), m_geometryEnabled(false), m_noiseEnabled(false)
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

	if (m_geometryEnabled)
		LoadGeometryShader();
	if (m_noiseEnabled)
		LoadNoiseShader();
}

void	Renderer::DrawBlur()
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

void	Renderer::DrawGeometry()
{
	ofPushMatrix();

	shaderGeometry.begin();
	shaderGeometry.setUniform1f("thickness", 20);
	shaderGeometry.setUniform3f("lightDir", sin(ofGetElapsedTimef() / 10), cos(ofGetElapsedTimef() / 10), 0);

	ofColor(255);

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofRotateX(ofGetMouseY());
	ofRotateY(ofGetMouseX());

	for (unsigned int i = 1; i < points.size(); i++)
		ofDrawLine(points[i - 1], points[i]);

	shaderGeometry.end();
	ofPopMatrix();
}

void	Renderer::DrawNoise()
{
	noiseImage.getTexture().bind();
	shaderNoise.begin();

	ofPushMatrix();
	float tx = ofGetWidth() / 2;
	float ty = ofGetHeight() / 2;
	ofTranslate(tx, ty);

	float percentY = ofGetMouseY() / (float)ofGetHeight();
	float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
	ofRotate(rotation, 1, 0, 0);

	plane.drawWireframe();
	ofPopMatrix();
	shaderNoise.end();
	ofSetColor(ofColor::white);
	noiseImage.draw(0,0);
}

void	Renderer::Draw()
{
	if (m_blurEnabled)
		DrawBlur();
	else if (m_geometryEnabled)
		DrawGeometry();
	else if (m_noiseEnabled)
		DrawNoise();
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
	if (m_noiseEnabled)
	{
		float noiseScale = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 0.1);
		float noiseVel = ofGetElapsedTimef();

		ofPixels &pixels = noiseImage.getPixels();
		int w = noiseImage.getWidth();
		int h = noiseImage.getHeight();
		for (int y = 0; y < h; y++)
			for (int x = 0; x < h; x++)
			{
				int i = y * w + x;
				float noiseValue = ofNoise(x * noiseScale, y * noiseScale, noiseVel);
				pixels[i] = 255 * noiseValue;
			}
		noiseImage.update();
	}
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
	m_geometryEnabled = false;
	m_noiseEnabled = false;
	Setup();
}

void	Renderer::EnableGeometry()
{
	m_geometryEnabled = true;
	m_blurEnabled = false;
	m_noiseEnabled = false;
	Setup();
}

void	Renderer::EnableNoise()
{
	m_noiseEnabled = true;
	m_geometryEnabled = false;
	m_blurEnabled = false;
	Setup();
}

void	Renderer::DisableBlur()
{
	m_blurEnabled = false;
}

void	Renderer::DisableGeometry()
{
	m_geometryEnabled = false;
}

void	Renderer::DisableNoise()
{
	m_noiseEnabled = false;
}

void	Renderer::DisableAll()
{
	m_blurEnabled = false;
	m_geometryEnabled = false;
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

void	Renderer::LoadGeometryShader()
{
	ofEnableAlphaBlending();
	shaderGeometry.setGeometryInputType(GL_LINES);
	shaderGeometry.setGeometryOutputType(GL_TRIANGLE_STRIP);
	shaderGeometry.setGeometryOutputCount(4);
	shaderGeometry.load("shaderGeometry/vert.glsl", "shaderGeometry/frag.glsl", "shaderGeometry/geom.glsl");

	float r = ofGetHeight() / 2;
	for (int i = 0; i < 100; i++)
		points.push_back(ofPoint(ofRandomf() * r, ofRandomf() * r, ofRandomf() * r));
	ofEnableDepthTest();
}

void	Renderer::LoadNoiseShader()
{
#ifdef TARGET_OPENGLES
	shaderNoise.load("shadersES2/Noise/shader");
#else
	if (ofIsGLProgrammableRenderer())
		shaderNoise.load("shadersGL3/Noise/shader");
	else
		shaderNoise.load("shadersGL2/Noise/shader");
#endif

	noiseImage.allocate(80, 60, OF_IMAGE_GRAYSCALE);

	plane.set(800, 600, 80, 60);
	plane.mapTexCoordsFromTexture(noiseImage.getTexture());
}