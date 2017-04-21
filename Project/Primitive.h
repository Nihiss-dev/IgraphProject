#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include "ofMain.h"
#include "Object.h"

typedef enum
{
	CUBE,
	SPHERE
} PrimitiveType;

class Primitive : public Object
{
public:
	explicit Primitive(PrimitiveType);
	virtual ~Primitive();

	void Setup();
	void Update();
	void Draw();

	void Translate(Axis, float);
	void Scale(float);
private:
	PrimitiveType m_type;
	of3dPrimitive *m_primitive;
};

#endif //PRIMITIVE_H_