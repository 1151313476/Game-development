#pragma once
#include "Scene.h"


class CharacterSelectionScene :
    public Scene
{
public:
	CharacterSelectionScene() = default;
	~CharacterSelectionScene() = default;

	void on_enter() override;	//����
	void on_exit() override;	//�˳�
	void on_update() override;	//�߼�����
	void on_render() override;	//��Ⱦ
	void on_input() override;	//�߼�����
};

