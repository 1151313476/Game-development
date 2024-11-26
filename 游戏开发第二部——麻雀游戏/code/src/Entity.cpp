#include "../include/Entity.h"

//��ֵ
//	double _health;		//����ֵ
//	double _move_speed;	//�ƶ��ٶ�
//	double _x,_y;		//λ������


//�ƶ�
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

void Entity::Teleportation(Vector2D vector)		//���ͣ�λ�������޸�
{
	_vector = vector;
}

//����ֵ�޸�
void Entity::Health_Modification(double value)
{
	_health += value;
}

//�ƶ��ٶ��޸�
void Entity::Move_Speed_Modification(double speed)
{
	_move_speed = speed;
}

//������Դ����
void Entity::Image_Load(std::string path)
{
	_animation_left.Resource_Loading(path);

	_current_animation = &_animation_left;
}

//������ת
void Entity::Image_Flip()
{
	_animation_left.Put_Flip_Resource(&_animation_right);
}

//������Դ��Ⱦ
void Entity::Resource_Rendering()
{
	_current_animation->Resource_Rendering(_vector.getX(), _vector.getY());
}