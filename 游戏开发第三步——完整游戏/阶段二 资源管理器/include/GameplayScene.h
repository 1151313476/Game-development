#pragma once
#include "Scene.h"
class GameplayScene :
    public Scene
{
public:
	GameplayScene() = default;
	~GameplayScene() = default;


	void on_enter() override;	//����
	void on_exit() override;	//�˳�
	void on_update() override;	//�߼�����
	void on_render() override;	//��Ⱦ
	void on_input() override;	//�߼�����
};

