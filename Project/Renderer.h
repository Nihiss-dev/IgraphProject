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
	void DrawBlur();
	void DrawGeometry();
	void DrawNoise();

	void AddObject(Object *);
	void AddLight(ofLight *);

	void EnableBlur();
	void EnableGeometry();
	void EnableNoise();
	void DisableBlur();
	void DisableGeometry();
	void DisableNoise();
	void DisableAll();

	void LoadBlurShader();
	void LoadGeometryShader();
	void LoadNoiseShader();

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

	// geometry
	ofShader shaderGeometry;
	std::vector<ofPoint> points;
	bool m_geometryEnabled;

	// noise
	ofShader shaderNoise;
	ofPlanePrimitive plane;
	ofImage noiseImage;
	bool m_noiseEnabled;

};

#endif //RENDERER_H_