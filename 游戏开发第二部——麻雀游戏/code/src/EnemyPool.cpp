#include "../include/EnemyPool.h"

// EnemyPool.cpp
#include <iostream>

EnemyPool::EnemyPool(size_t size) {
    // 预先创建对象并添加到未激活列表
    for (size_t i = 0; i < size; ++i) {
        //动画加载
		std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(100,5);
		for (int i = 0; i < 6; i++) {//敌人动画加载
			std::string path = std::string("resources/img/enemy_left_") + std::to_string(i) + std::string(".png");
			enemy->Image_Load(path);
		}
		enemy->Image_Flip();			//获取翻转资源
		enemy->CollisionLoad(20, 20); //碰撞体加载

        inactiveEnemies.push_back(enemy);
	}
}

void EnemyPool::getEnemy() {
    if (inactiveEnemies.empty()) {
        // 如果没有未激活对象，创建一个新的敌人对象并添加到已激活列表
        activeEnemies.emplace_back(std::make_shared<Enemy>());
    }
    else {
        // 从未激活列表中取出一个敌人对象，并将其放入已激活列表
        std::shared_ptr<Enemy> enemy = inactiveEnemies.front();
        
        //随机生成位置
        enemy->	SpawnLocation();
        
        inactiveEnemies.pop_front();
        activeEnemies.push_back(enemy);
    }
}

void EnemyPool::returnEnemy(std::shared_ptr<Enemy> enemy ) {
    //加入未激活列表
    inactiveEnemies.push_back(enemy);
}

//渲染已激活对象
void EnemyPool:: ActiveEnemies_Rendering() {
    for (std::shared_ptr<Enemy> enemy : activeEnemies) {
        enemy->Resource_Rendering();
    }
}

//已激活对象，业务逻辑
void  EnemyPool:: ActiveEnemies_Pursuit(std::shared_ptr<Entity> target, DWORD time) {
	for (std::shared_ptr<Enemy> enemy : activeEnemies) {
        enemy->Pursuit(target,time);
    }
}

//已激活对象，碰撞检测
void  EnemyPool:: ActiveEnemies_CollisionDetection(std::shared_ptr<Entity> target) {
    // 使用迭代器遍历并删除值为2的元素
    for (std::list<std::shared_ptr<Enemy>>::iterator enemy = activeEnemies.begin(); enemy != activeEnemies.end(); ) {
        if ((*enemy)->CollisionDetection(target)) {
            returnEnemy(*enemy);
            enemy = activeEnemies.erase(enemy); // 删除当前元素，并更新迭代器
        }
        else {
            ++enemy; // 只有当不删除元素时才递增迭代器
        }
    }
}

