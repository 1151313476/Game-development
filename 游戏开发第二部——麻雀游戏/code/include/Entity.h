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

	//��ֵ����
	void Move(Vector2D vector);					//�ƶ���λ�������޸�
	void Health_Modification(double value);		//����ֵ�޸�
	void Move_Speed_Modification(double speed);	//�ƶ��ٶ��޸�
	void Teleportation(Vector2D vector);		//���ͣ�λ�������޸�

	//������Դ����
	void Image_Load(std::string path);

	//������Դ��Ⱦ
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
	//��ֵ
	double _health;		//����ֵ
	double _move_speed;	//�ƶ��ٶ�
	Vector2D _vector;		//λ������

	double _width, _height;	//��ײ�߶ȣ���ײ��� 


	//��Դ
	Animation _animation_left;		//���� ������Դ
	Animation _animation_right;		//���� ������Դ

	Animation* _current_animation;
};

#endif