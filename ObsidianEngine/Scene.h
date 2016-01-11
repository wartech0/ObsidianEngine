#pragma once

namespace Obsidian
{
	class Scene
	{
	public:
		explicit Scene() {};
		virtual ~Scene() {};

		virtual void Initialize() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw() = 0;
		virtual void Destroy() = 0;
	};
}