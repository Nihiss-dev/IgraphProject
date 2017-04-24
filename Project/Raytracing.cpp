#include "Raytracing.h"

Raytracing::Raytracing()
{

}

Raytracing::~Raytracing()
{

}

void	Raytracing::Setup(int width, int height)
{
	m_width = width;
	m_height = height;

	ofSpherePrimitive *sphere = new ofSpherePrimitive();
	sphere->setPosition(20,0,0);
	sphere->setRadius(10);
	m_objects.push_back(sphere);
	img.allocate(m_width, m_height, OF_IMAGE_COLOR);
	m_isDone = false;
}

void	Raytracing::Draw()
{
	if (m_isDone)
		img.draw(100,100);
}

void	Raytracing::Compute()
{
	for (int i = 0; i < img.getHeight(); i++)
		for (int j = 0; j < img.getWidth(); j++)
		{
			for (std::vector<of3dPrimitive*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
				if (getIntersectSphere(it, i, j) > 0)
					img.setColor(i % m_height, j % m_width, ofColor(255, 0, 0));
				else if (getIntersectPlane(i, j) > 0)
					img.setColor(i % m_height, j % m_width, ofColor(0, 0, 255));
				else
					img.setColor(i % m_height, j % m_width, ofColor(0,0,0));
		}
	img.update();
	m_isDone = true;
}

int		Raytracing::getIntersectSphere(std::vector<of3dPrimitive*>::iterator it, int x, int y)
{
	int x0 = 0;
	int y0 = 0;
	int z0 = 10;
	int cx = (*it)->getPosition().x;
	int cy = (*it)->getPosition().y;
	int cz = (*it)->getPosition().z;
	int dx = 100;
	int dy = (m_width / 2) - x;
	int dz = (m_width / 2) - y;
	int a = pow(dx, 2) + pow(dy, 2) + pow(dz, 2);
	int b = 2.0 * dx * (x0-cx) + 2.0 * dy * (y0-cy) + 2.0 * dz * (z0-cz);
	int c = pow(cx, 2) + pow(cy, 2) + pow(cz, 2) - pow(((ofSpherePrimitive*)(*it))->getRadius(), 2) + pow(x0, 2) + pow(y0, 2) + pow(z0, 2)
		- 2.0 * (cx * x0 + cy * y0 + cz * z0);

	return (pow(b, 2) - 4 * a * c);
}

int		Raytracing::getIntersectPlane(int x, int y)
{
	int z = 250;
	int dx = (m_width / 2) - y;
	if (dx == 0)
		dx += 1;
	return (-z/dx < 0 ? 0 : 1);
}