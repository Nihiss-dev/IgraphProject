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
		m_primitive->setPosition(0,0,0);
		break;
	case SPHERE:
		m_primitive = new ofSpherePrimitive();
		m_primitive->setPosition(0,0,0);
	}
}

void	Primitive::Update()
{

}

void	Primitive::Draw()
{
	m_primitive->draw();
}

void	Primitive::Translate(Axis axis, float value)
{

}

void	Primitive::Scale(float value)
{

}