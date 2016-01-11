#pragma once
#include <Engine.h>


class TestScene : public Obsidian::Scene
{
public:
	void Initialize();
	void Update(float dt);
	void Draw();
	void Destroy();
};