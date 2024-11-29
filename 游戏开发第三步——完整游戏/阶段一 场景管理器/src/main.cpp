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

//��ʼ��
void GameInitialize() {
	initgraph(1280, 720,EW_SHOWCONSOLE);  // ��ʼ��ͼ�δ���

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

	scene_manager->on_render();

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