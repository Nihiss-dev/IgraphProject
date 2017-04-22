#ifndef RENDERER_H_
#define RENDERER_H_

#include <vector>
#include "ofMain.h"
#include "Primitive.h"

class Renderer
{
public:
	explicit Renderer();
	virtual ~Renderer();

	void Setup();
	void Update();
	void Draw();
	void DrawShaders();

	void AddObject(Object *);
	void AddLight(ofLight *);

	void EnableBlur();
	void DisableBlur();
	void DisableAll();

	void LoadBlurShader();

	inline std::vector<Object*> GetObjects() { return m_objects; }
	inline std::vector<ofLight*> GetLights() { return m_lights; }

	ofFbo fbo;
private:
	std::vector<Object*> m_objects;
	std::vector<ofLight*> m_lights;
	ofEasyCam *m_cam;

	// blur
	ofShader shaderBlurX;
	ofShader shaderBlurY;
	ofFbo fboBlurOnePass;
	ofFbo fboBlurTwoPass;

	bool m_blurEnabled;

};

#endif //RENDERER_H_