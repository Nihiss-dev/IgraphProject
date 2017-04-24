#ifndef RAYTRACING_H_
#define RAYTRACING_H_

#include "Renderer.h"
//#include "src/ofApp.h"

class Raytracing
{
public:
	explicit Raytracing();
	virtual ~Raytracing();

	void Setup(int, int);
	void Draw();
	void Compute();
private:
	ofImage img;

	int m_width;
	int m_height;

	int m_isDone;

	std::vector<of3dPrimitive*> m_objects;

	int getIntersectSphere(std::vector<of3dPrimitive*>::iterator, int x, int y);
	int getIntersectPlane(int x, int y);
};

#endif //RAYTRACING_H_