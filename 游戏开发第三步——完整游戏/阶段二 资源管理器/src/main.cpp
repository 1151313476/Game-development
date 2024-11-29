#include "GameplayScene.h";
#include "MainMenuScene.h";
#include "SceneManager.h";
#include "CharacterSelectionScene.h"

#include "Atlas.h"
#include "Animation.h"

#include <memory>
#include <Windows.h>
#include <graphics.h>

const DWORD TIME_FRAME = 1000 / 60;

//temp
Animation sunfloweridle;

//resources
std::shared_ptr<Atlas> sunflower_idle;



//Scene
std::shared_ptr<Scene> gameplay_scene;
std::shared_ptr<Scene> mainmenu_scene;
std::shared_ptr<Scene> characterselection_scene;
std::shared_ptr<SceneManager> scene_manager;

void load_resources() {
	sunflower_idle = std::make_shared<Atlas>();
	for (int i = 1; i <= 8; i++) {		//人物动画加载
		std::string path = std::string("resources/sunflower_idle_") + std::to_string(i) + std::string(".png");
		sunflower_idle->add_image(path);
	}
}


//初始化
void GameInitialize() {
	initgraph(1280, 720,EW_SHOWCONSOLE);  // 初始化图形窗口

	//resources init
	load_resources();

	sunfloweridle.load_atlas(sunflower_idle);
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
	cleardevice();  // 清空窗口内容

	scene_manager->on_render();
	sunfloweridle.image_render(100, 100,GetTickCount());

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