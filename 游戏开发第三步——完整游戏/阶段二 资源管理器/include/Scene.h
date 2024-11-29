#pragma once


#include <iostream>
#include <graphics.h>
#include <memory>

class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void on_enter() = 0;	//进入
	virtual void on_exit() = 0;		//退出
	virtual void on_update() = 0;	//逻辑计算
	virtual void on_render() = 0;	//渲染
	virtual void on_input() = 0;	//逻辑计算

protected:
	ExMessage msg;  // 定义消息变量
};
