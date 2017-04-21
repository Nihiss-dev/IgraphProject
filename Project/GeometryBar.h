#ifndef GEOMETRYBAR_H_
#define GEOMETRYBAR_H_

#include "ofxGui.h"
#include "Renderer.h"
#include "ToolBar.h"

class GeometryBar : public ToolBar
{
public:
	explicit GeometryBar(Renderer *);
	virtual ~GeometryBar();

	void Setup();
	void Draw();
	void Show();
	void Hide();

	void AddCube();
private:
	ofxPanel m_panel;
	ofxButton m_addCube;

	Renderer *m_renderer;
};

#endif //GEOMETRYBAR_H_