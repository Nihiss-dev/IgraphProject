#ifndef OBJECT_H_
#define OBJECT_H_

typedef enum
{
	X,
	Y,
	Z
} Axis;

class Object
{
public:
	virtual void Setup() = 0;
	virtual void Draw() = 0;

	virtual void Translate(Axis, float) = 0;
	virtual void Scale(float) = 0;
	virtual void SetPosition(float, float, float) = 0;
};

#endif //OBJECT_H_