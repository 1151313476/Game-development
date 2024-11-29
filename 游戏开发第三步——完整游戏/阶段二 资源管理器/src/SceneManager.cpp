#include "SceneManager.h"

extern std::shared_ptr<Scene> gameplay_scene;
extern std::shared_ptr<Scene> mainmenu_scene;
extern std::shared_ptr<Scene> characterselection_scene;

void SceneManager::set_scene(std::shared_ptr<Scene> scene)
{
	_current_scene = scene;
}

void SceneManager::on_update()
{
	_current_scene->on_update();
}

void SceneManager::on_render()
{
	_current_scene->on_render();
}

void SceneManager::on_input()
{
	_current_scene->on_input();
}

void SceneManager::switch_to(SceneType scene)
{
	_current_scene->on_exit();

	switch (scene)
	{
	case SceneManager::SceneType::MainMenu:
		_current_scene = mainmenu_scene;
		break;
	case SceneManager::SceneType::Gameplay:
		_current_scene = gameplay_scene;
		break;
	case SceneManager::SceneType::CharacterSelection:
		_current_scene = characterselection_scene;
		break;
	default:
		break;
	}

	_current_scene->on_enter();
}
