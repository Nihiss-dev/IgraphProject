#ifndef LIGHTSBAR_H_
#define LIGHTSBAR_H_

#include "ofxGui.h"
#include "Renderer.h"
#include "ToolBar.h"

typedef enum
{
	SPOTLIGHT,
	POINTLIGHT,
	DIRECTIONALLIGHT
} LightType;

class LightsBar : public ToolBar
{
public:
	explicit LightsBar(Renderer *);
	virtual ~LightsBar();

	void Setup();
	void Draw();
	void Show();
	void Hide();

	void AddSpotLight();
	void AddPointLight();
	void CreateSpotLight();
	void CreatePointLight();
private:
	// Main panel
	ofxPanel m_panel;
	ofxButton m_addSpotLight;
	ofxButton m_addPointLight;

	// Panel for spotlight
	ofxPanel m_SpotPanel;
	ofxFloatSlider m_SpotX;
	ofxFloatSlider m_SpotY;
	ofxFloatSlider m_SpotZ;
	ofxFloatSlider m_SpotColorR;
	ofxFloatSlider m_SpotColorG;
	ofxFloatSlider m_SpotColorB;
	ofxFloatSlider m_SpotCutOff;
	ofxFloatSlider m_SpotConcentration;
	ofxButton m_SpotCreate;

	// Panel for pointlight
	ofxPanel m_PointPanel;
	ofxFloatSlider m_PointX;
	ofxFloatSlider m_PointY;
	ofxFloatSlider m_PointZ;
	ofxFloatSlider m_PointColorR;
	ofxFloatSlider m_PointColorG;
	ofxFloatSlider m_PointColorB;
	ofxButton m_PointCreate;

	Renderer *m_renderer;

	bool m_visible;
	bool m_spotVisible;
	bool m_pointVisible;
};

#endif //LIGHTSBAR_H_