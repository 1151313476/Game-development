#include "../include/Entity.h"

//数值
//	double _health;		//生命值
//	double _move_speed;	//移动速度
//	double _x,_y;		//位置坐标


//移动
void Entity::Move(Vector2D direction)
{
	if (direction.getX() > 0) {
		_current_animation = &_animation_right;
	}

	if (direction.getX() < 0) {
		_current_animation = &_animation_left;
	}
	_vector = _vector + direction * _move_speed;
}

void Entity::Teleportation(Vector2D vector)		//传送，位置坐标修改
{
	_vector = vector;
}

//生命值修改
void Entity::Health_Modification(double value)
{
	_health += value;
}

//移动速度修改
void Entity::Move_Speed_Modification(double speed)
{
	_move_speed = speed;
}

//动画资源加载
void Entity::Image_Load(std::string path)
{
	_animation_left.Resource_Loading(path);

	_current_animation = &_animation_left;
}

//动画翻转
void Entity::Image_Flip()
{
	_animation_left.Put_Flip_Resource(&_animation_right);
}

//动画资源渲染
void Entity::Resource_Rendering()
{
	_current_animation->Resource_Rendering(_vector.getX(), _vector.getY());
}