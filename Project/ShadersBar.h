#ifndef SHADERS_BAR_H_
#define SHADERS_BAR_H_

#include "ofxGui.h"
#include "Renderer.h"
#include "ToolBar.h"

class ShadersBar : public ToolBar
{
public:
	explicit ShadersBar(Renderer *);
	virtual ~ShadersBar();

	void Setup();
	void Draw();
	void Show();
	void Hide();

	void EnableBlur();
	void EnableGeometry();
	void EnableNoise();
	void DisableShaders();
private:
	ofxPanel m_ShadersPanel;
	ofxButton m_BlurButton;
	ofxButton m_GeometryButton;
	ofxButton m_NoiseButton;
	ofxButton m_NoShadersButton;

	Renderer *m_renderer;
	
	bool m_visible;
};

#endif //SHADERS_BAR_H_