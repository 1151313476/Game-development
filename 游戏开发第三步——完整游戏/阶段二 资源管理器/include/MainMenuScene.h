#pragma once
#include "Scene.h"

class MainMenuScene :
    public Scene
{
public:
	MainMenuScene() = default;
	~MainMenuScene() = default;

	void on_enter() override;	//½øÈë
	void on_exit() override;	//ÍË³ö
	void on_update() override;	//Âß¼­¼ÆËã
	void on_render() override;	//äÖÈ¾
	void on_input() override;	//Âß¼­¼ÆËã
};

