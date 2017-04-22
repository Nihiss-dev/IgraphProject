#include "Primitive.h"

Primitive::Primitive(PrimitiveType type) : m_type(type)
{

}

Primitive::~Primitive()
{

}

void	Primitive::Setup()
{
	switch (m_type)
	{
	case CUBE:
		m_primitive = new ofBoxPrimitive();
		break;
	case SPHERE:
		m_primitive = new ofSpherePrimitive();
	}
	if (img.load("img.jpg") == false)
		std::cout << "Can't open image" << std::endl;
}

void	Primitive::Update()
{

}

void	Primitive::Draw()
{
	ofPushMatrix();
	img.bind();
	m_primitive->draw();
	img.unbind();
	ofPopMatrix();
}

void	Primitive::Translate(Axis axis, float value)
{

}

void	Primitive::Scale(float value)
{

}

void	Primitive::SetPosition(float x, float y, float z)
{
	m_primitive->setPosition(x, y, z);
}