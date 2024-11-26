#include "../include/Enemy.h"
#include <list>

class EnemyPool{
private:
    std::list<std::shared_ptr<Enemy>> activeEnemies; // 已激活的敌人列表
    std::list<std::shared_ptr<Enemy>> inactiveEnemies; // 未激活的敌人列表

public:
    EnemyPool(size_t size);
    void getEnemy(); // 获取一个可用的敌人对象
    void returnEnemy(std::shared_ptr<Enemy> enemy ); // 回收敌人对象

    //渲染已激活对象
  	void ActiveEnemies_Rendering();
    
    //已激活对象，业务逻辑
    void  ActiveEnemies_Pursuit(std::shared_ptr<Entity> target, DWORD time);

    //已激活对象，碰撞检测
    void  ActiveEnemies_CollisionDetection(std::shared_ptr<Entity> target);

};
