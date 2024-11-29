#include "GameplayScene.h";
#include "MainMenuScene.h";
#include "SceneManager.h";
#include "CharacterSelectionScene.h"

#include <memory>
#include <Windows.h>
#include <graphics.h>

const DWORD TIME_FRAME = 1000 / 60;

//Scene
std::shared_ptr<Scene> gameplay_scene;
std::shared_ptr<Scene> mainmenu_scene;
std::shared_ptr<Scene> characterselection_scene;
std::shared_ptr<SceneManager> scene_manager;

//初始化
void GameInitialize() {
	initgraph(1280, 720,EW_SHOWCONSOLE);  // 初始化图形窗口

	//scene init 
	gameplay_scene = std::make_shared<GameplayScene>();
	mainmenu_scene = std::make_shared<MainMenuScene>();
	characterselection_scene = std::make_shared<CharacterSelectionScene>();
	scene_manager = std::make_shared<SceneManager>();
	scene_manager->set_scene(mainmenu_scene);



	BeginBatchDraw();      // 开始批量绘制，防止闪烁
}


//捕捉操作
void CaptureOperation() {
	scene_manager->on_input();
}

//数值计算
void NumericalComputation(){
	scene_manager->on_update();
}


//资源渲染
void ResourceRendering() {

	scene_manager->on_render();

	FlushBatchDraw();  // 刷新批量绘制
}

//资源释放
void ResourceRelease() {
	EndBatchDraw();  // 结束批量绘制
	closegraph();    // 关闭图形窗口
}

int main() {
	//游戏初始化
	GameInitialize();

	while (true) {
		// 获取当前时间（毫秒）
		DWORD start_time = GetTickCount();

		//捕获操作\逻辑处理
		CaptureOperation();

		//数值计算		
		NumericalComputation();

		//资源渲染
		ResourceRendering();

		DWORD end_time = GetTickCount();

		DWORD time_interval = end_time - start_time;

		if (time_interval < TIME_FRAME) {
			Sleep(TIME_FRAME - time_interval);
		}
	}

	//资源释放
	ResourceRelease();
	return 0;
}