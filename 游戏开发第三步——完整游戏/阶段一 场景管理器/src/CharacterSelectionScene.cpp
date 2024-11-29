#include "CharacterSelectionScene.h"

#include "SceneManager.h"
extern std::shared_ptr<SceneManager> scene_manager;

void CharacterSelectionScene::on_enter()
{
}

void CharacterSelectionScene::on_exit()
{
}

void CharacterSelectionScene::on_update()
{
}

void CharacterSelectionScene::on_render()
{
	std::cout << "Select \n";
}

void CharacterSelectionScene::on_input()
{
	while (peekmessage(&msg)) {
		if (msg.message == WM_KEYDOWN) {//°´¼ü°´ÏÂ
			scene_manager->switch_to(SceneManager::SceneType::MainMenu);
		}
	}
}
