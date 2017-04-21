#include "GUI.h"

GUI::GUI()
{

}

GUI::~GUI()
{

}

void	GUI::Setup()
{
	for (std::vector<ToolBar*>::iterator it = m_toolbars.begin(); it != m_toolbars.end(); it++)
		(*it)->Setup();
}

void	GUI::Draw()
{
	for (std::vector<ToolBar*>::iterator it = m_toolbars.begin(); it != m_toolbars.end(); it++)
		(*it)->Draw();
}

void	GUI::Add(ToolBar *toolbar)
{
	m_toolbars.push_back(toolbar);
}