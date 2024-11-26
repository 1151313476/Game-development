#include "Entity.h"

class Player :public Entity {
public:
	Player(double health, double move_speed)
	:Entity(health, move_speed)
	{
		//传送到屏幕中间
		Teleportation(Vector2D(640, 360));
	}

	~Player()
	{
	}
};
