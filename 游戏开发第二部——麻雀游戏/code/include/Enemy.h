#include "Entity.h"
#include <memory>
#include <cstdlib> // 包含rand()和srand()
#include <ctime>   // 包含time()

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
	
	//生成位置
	//随机传送到屏幕外(1280,720)
	void SpawnLocation();

	//追击
	void Pursuit(std::shared_ptr<Entity> target,DWORD time);

	//碰撞检测
	bool CollisionDetection(std::shared_ptr<Entity> target);
private:

};
