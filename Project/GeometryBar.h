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

	void CreateCube();
	void CreateSphere();
private:
	// Main panel
	ofxPanel m_panel;
	ofxButton m_addCube;
	ofxButton m_addSphere;

	// Cube panel
	ofxPanel m_CubePanel;
	ofxFloatSlider m_CubeX;
	ofxFloatSlider m_CubeY;
	ofxFloatSlider m_CubeZ;
	ofxButton m_CreateCube;

	// Sphere panel
	ofxPanel m_SpherePanel;
	ofxFloatSlider m_SphereX;
	ofxFloatSlider m_SphereY;
	ofxFloatSlider m_SphereZ;
	ofxButton m_CreateSphere;

	Renderer *m_renderer;

	bool m_visible;
	bool m_cubeVisible;
	bool m_sphereVisible;
};

#endif //GEOMETRYBAR_H_