#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include "Renderer.h"

class ToolBar
{
public:
	virtual void Setup() = 0;
	virtual void Draw() = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
};

#endif //TOOLBAR_H_