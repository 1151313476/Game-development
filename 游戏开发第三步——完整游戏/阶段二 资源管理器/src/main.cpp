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
	for (int i = 1; i <= 8; i++) {		//���ﶯ������
		std::string path = std::string("resources/sunflower_idle_") + std::to_string(i) + std::string(".png");
		sunflower_idle->add_image(path);
	}
}


//��ʼ��
void GameInitialize() {
	initgraph(1280, 720,EW_SHOWCONSOLE);  // ��ʼ��ͼ�δ���

	//resources init
	load_resources();

	sunfloweridle.load_atlas(sunflower_idle);
	//scene init 
	gameplay_scene = std::make_shared<GameplayScene>();
	mainmenu_scene = std::make_shared<MainMenuScene>();
	characterselection_scene = std::make_shared<CharacterSelectionScene>();
	scene_manager = std::make_shared<SceneManager>();
	scene_manager->set_scene(mainmenu_scene);

	BeginBatchDraw();      // ��ʼ�������ƣ���ֹ��˸
}


//��׽����
void CaptureOperation() {
	scene_manager->on_input();
}

//��ֵ����
void NumericalComputation(){
	scene_manager->on_update();
}


//��Դ��Ⱦ
void ResourceRendering() {
	cleardevice();  // ��մ�������

	scene_manager->on_render();
	sunfloweridle.image_render(100, 100,GetTickCount());

	FlushBatchDraw();  // ˢ����������
}

//��Դ�ͷ�
void ResourceRelease() {
	EndBatchDraw();  // ������������
	closegraph();    // �ر�ͼ�δ���
}

int main() {
	//��Ϸ��ʼ��
	GameInitialize();

	while (true) {
		// ��ȡ��ǰʱ�䣨���룩
		DWORD start_time = GetTickCount();

		//�������\�߼�����
		CaptureOperation();

		//��ֵ����		
		NumericalComputation();

		//��Դ��Ⱦ
		ResourceRendering();

		DWORD end_time = GetTickCount();

		DWORD time_interval = end_time - start_time;

		if (time_interval < TIME_FRAME) {
			Sleep(TIME_FRAME - time_interval);
		}
	}

	//��Դ�ͷ�
	ResourceRelease();
	return 0;
}