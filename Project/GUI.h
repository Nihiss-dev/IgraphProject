#ifndef GUI_H_
#define GUI_H_

#include <vector>
#include "ToolBar.h"

class GUI
{
public:
	explicit GUI();
	virtual ~GUI();

	void Setup();
	void Draw();
	void Add(ToolBar *);
private:
	std::vector<ToolBar*> m_toolbars;
};

#endif //GUI_H_