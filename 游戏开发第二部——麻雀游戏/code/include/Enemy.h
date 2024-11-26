#include "Entity.h"
#include <memory>
#include <cstdlib> // ����rand()��srand()
#include <ctime>   // ����time()

class Enemy:public Entity {
public:
	Enemy(double health = 100, double move_speed = 50)
	:Entity(health, move_speed)
	{
		SpawnLocation();
		//Teleportation(Vector2D(640, 360));
	}

	~Enemy()
	{
	}
	
	//����λ��
	//������͵���Ļ��(1280,720)
	void SpawnLocation();

	//׷��
	void Pursuit(std::shared_ptr<Entity> target,DWORD time);

	//��ײ���
	bool CollisionDetection(std::shared_ptr<Entity> target);
private:

};
