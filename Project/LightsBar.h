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
	void CreateSpotLight();
private:
	// Main panel
	ofxPanel m_panel;
	ofxButton m_addSpotLight;

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

	Renderer *m_renderer;

	bool m_visible;
	bool m_spotVisible;
};

#endif //LIGHTSBAR_H_