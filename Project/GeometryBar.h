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
	void AddSphere();
private:
	ofxPanel m_panel;
	ofxButton m_addCube;
	ofxButton m_addSphere;

	Renderer *m_renderer;

	bool m_visible;
};

#endif //GEOMETRYBAR_H_