#ifndef _ENTITY_H
#define _ENTITY_H

#include "Animation.h"
#include "vector.h"


class Entity
{
public:
	Entity(double health = 100, double move_speed = 50)
		:_health(health)
		, _move_speed(move_speed)
		, _vector(0, 0)
		, _width(0)
		, _height(0)
		, _current_animation(nullptr)
	{
	}

	~Entity()
	{
	}

	//数值操作
	void Move(Vector2D vector);					//移动，位置坐标修改
	void Health_Modification(double value);		//生命值修改
	void Move_Speed_Modification(double speed);	//移动速度修改
	void Teleportation(Vector2D vector);		//传送，位置坐标修改

	//动画资源加载
	void Image_Load(std::string path);

	//动画资源渲染
	void Resource_Rendering();
	void Image_Flip();


	double Get_X()
	{
		return _vector.getX();
	}

	double Get_Y()
	{
		return _vector.getY();
	}
	double Get_W()
	{
		return _width;
	}

	double Get_H()
	{
		return _height;
	}

	void CollisionLoad(double width, double height) {
		_width = width;
		_height = height;
	}
private:
	//数值
	double _health;		//生命值
	double _move_speed;	//移动速度
	Vector2D _vector;		//位置坐标

	double _width, _height;	//碰撞高度，碰撞宽度 


	//资源
	Animation _animation_left;		//向左 动画资源
	Animation _animation_right;		//向右 动画资源

	Animation* _current_animation;
};

#endif