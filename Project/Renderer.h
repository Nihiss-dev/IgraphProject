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

	ofFbo fbo;
private:
	std::vector<Object*> m_objects;
	ofEasyCam *m_cam;
};

#endif //RENDERER_H_