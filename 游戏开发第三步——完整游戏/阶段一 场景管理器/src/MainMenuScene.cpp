#include "MainMenuScene.h"
#include "SceneManager.h"

extern std::shared_ptr<SceneManager> scene_manager;

void MainMenuScene::on_enter()
{
}

void MainMenuScene::on_exit()
{
}

void MainMenuScene::on_update()
{
}

void MainMenuScene::on_render()
{
	std::cout << "Main \n";
}

void MainMenuScene::on_input()
{
	while (peekmessage(&msg)) {
		if (msg.message == WM_KEYDOWN) {//°´¼ü°´ÏÂ
			scene_manager->switch_to(SceneManager::SceneType::CharacterSelection);
		}
	}
}
