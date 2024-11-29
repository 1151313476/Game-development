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

	void on_update(); //�߼�����
	void on_render(); //��Ⱦ
	void on_input();  //�߼�����

	void switch_to(SceneType scene);
private:
	std::shared_ptr<Scene> _current_scene;
};

