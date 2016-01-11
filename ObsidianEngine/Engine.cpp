#include "Engine.h"

Obsidian::Engine::Engine(const Configuration & config, Scene* initialScene) : _gameWindow(this)
{
	int desktopSizeX = GetSystemMetrics(SM_CXSCREEN);
	int desktopSizeY = GetSystemMetrics(SM_CYSCREEN);

	RECT dimensions;
	dimensions.left = (desktopSizeX / 2) - (config.GetWidth() / 2);
	dimensions.top = (desktopSizeY / 2) - (config.GetHeight() / 2);
	dimensions.bottom = (desktopSizeY / 2) + (config.GetHeight() / 2);
	dimensions.right = (desktopSizeX / 2) + (config.GetWidth() / 2);

	_gameWindow.Create(NULL, dimensions, config.GetTitle(), WS_OVERLAPPEDWINDOW | WS_VISIBLE);
	_activeScenes.push_back(initialScene);
}

void Obsidian::Engine::Run()
{
	_running = true;


	while (_running) {
		_gameWindow.PumpWindowsMessages();
	}
}

void Obsidian::Engine::Shutdown()
{
	_running = false;
}
