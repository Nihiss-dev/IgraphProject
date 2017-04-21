#ifndef RENDERER_H_
#define RENDERER_H_

#include "ofMain.h"

class Renderer
{
public:
	explicit Renderer();
	virtual ~Renderer();

	void Draw();
private:
};

#endif //RENDERER_H_