#pragma once
#include "Scene.h"


class CharacterSelectionScene :
    public Scene
{
public:
	CharacterSelectionScene() = default;
	~CharacterSelectionScene() = default;

	void on_enter() override;	//进入
	void on_exit() override;	//退出
	void on_update() override;	//逻辑计算
	void on_render() override;	//渲染
	void on_input() override;	//逻辑计算
};

