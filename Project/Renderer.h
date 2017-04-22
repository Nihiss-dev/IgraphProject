#ifndef RENDERER_H_
#define RENDERER_H_

#include <vector>
#include "ofMain.h"
//#include "Object.h"
#include "Primitive.h"

class Renderer
{
public:
	explicit Renderer();
	virtual ~Renderer();

	void Setup();
	void Update();
	void Draw();

	void AddObject(Object *);
	void AddLight(ofLight *);

	inline std::vector<Object*> GetObjects() { return m_objects; }
	inline std::vector<ofLight*> GetLights() { return m_lights; }

	ofFbo fbo;
private:
	std::vector<Object*> m_objects;
	std::vector<ofLight*> m_lights;
	ofEasyCam *m_cam;
};

#endif //RENDERER_H_