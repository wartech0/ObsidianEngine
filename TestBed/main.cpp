#include <Engine.h>
#include "TestScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Obsidian::Configuration config;
	config.SetWidth(1280);
	config.SetHeight(720);
	TestScene scene;
	Obsidian::Engine theEngine(config, &scene);

	theEngine.Run();

	return 0;
}