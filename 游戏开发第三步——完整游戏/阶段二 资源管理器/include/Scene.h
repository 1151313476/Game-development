#pragma once


#include <iostream>
#include <graphics.h>
#include <memory>

class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void on_enter() = 0;	//����
	virtual void on_exit() = 0;		//�˳�
	virtual void on_update() = 0;	//�߼�����
	virtual void on_render() = 0;	//��Ⱦ
	virtual void on_input() = 0;	//�߼�����

protected:
	ExMessage msg;  // ������Ϣ����
};
