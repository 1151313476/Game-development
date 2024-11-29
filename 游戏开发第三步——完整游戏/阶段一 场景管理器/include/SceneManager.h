#pragma once
#include "Scene.h"
#include <memory>

class SceneManager
{
public:
	enum class SceneType
	{
		MainMenu,
		Gameplay,
		CharacterSelection
	};

	SceneManager() = default;
	~SceneManager() = default;


public:
	void set_scene(std::shared_ptr<Scene> scene);

	void on_update(); //Âß¼­¼ÆËã
	void on_render(); //äÖÈ¾
	void on_input();  //Âß¼­¼ÆËã

	void switch_to(SceneType scene);
private:
	std::shared_ptr<Scene> _current_scene;
};

