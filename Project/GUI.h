#ifndef GUI_H_
#define GUI_H_

#include <vector>
#include "GeometryBar.h"

class GUI
{
public:
	explicit GUI(Renderer *);
	virtual ~GUI();

	void Setup();
	void Draw();

	void GeometryClicked();
private:
	Renderer *m_renderer;
	GeometryBar *m_geometrybar;

	ofxPanel *m_mainPanel;
	ofxButton m_geometryButton;
};

#endif //GUI_H_