#pragma once

#include <vector>
#include "Configuration.h"
#include "Scene.h"
#include "Window.h"

namespace Obsidian
{
	class Engine
	{
	public:
		Engine(const Configuration& config, Scene* initialScene);

		void Run();

		void Shutdown();

	private:
		System::GameWindow _gameWindow;
		std::vector<Scene*> _activeScenes;
		bool _running;
	};
}