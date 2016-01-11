#include "Configuration.h"

Obsidian::Configuration::Configuration()
{
	_resWidth = 800;
	_resHeight = 600;
	_title = "Obsidian Engine";
}

void Obsidian::Configuration::SetWidth(unsigned int width)
{
	_resWidth = width;
}

void Obsidian::Configuration::SetHeight(unsigned int height)
{
	_resHeight = height;
}

void Obsidian::Configuration::SetTitle(const char * title)
{
	_title = title;
}

unsigned int Obsidian::Configuration::GetWidth() const
{
	return _resWidth;
}

unsigned int Obsidian::Configuration::GetHeight() const
{
	return _resHeight;
}

const char * Obsidian::Configuration::GetTitle() const
{
	return _title;
}
