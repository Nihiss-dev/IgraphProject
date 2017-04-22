#include "ShadersBar.h"

ShadersBar::ShadersBar(Renderer *renderer) : m_renderer(renderer), m_visible(false)
{

}

ShadersBar::~ShadersBar()
{

}

void	ShadersBar::Setup()
{
	m_ShadersPanel.setup();
	m_ShadersPanel.setName("Shaders");
	m_ShadersPanel.setPosition(225,0);

	m_ShadersPanel.add(m_BlurButton.setup("Add blur"));
	m_ShadersPanel.add(m_NoShadersButton.setup("Don't use shaders"));

	m_BlurButton.addListener(this, &ShadersBar::EnableBlur);
	m_NoShadersButton.addListener(this, &ShadersBar::DisableShaders);
}

void	ShadersBar::Draw()
{
	if (m_visible)
		m_ShadersPanel.draw();
}

void	ShadersBar::Show()
{
	m_visible = true;
}

void	ShadersBar::Hide()
{
	m_visible = false;
}

void	ShadersBar::EnableBlur()
{
	m_renderer->EnableBlur();
}

void	ShadersBar::DisableShaders()
{
	m_renderer->DisableAll();
}