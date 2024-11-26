#include "../include/EnemyPool.h"

// EnemyPool.cpp
#include <iostream>

EnemyPool::EnemyPool(size_t size) {
    // Ԥ�ȴ���������ӵ�δ�����б�
    for (size_t i = 0; i < size; ++i) {
        //��������
		std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(100,5);
		for (int i = 0; i < 6; i++) {//���˶�������
			std::string path = std::string("resources/img/enemy_left_") + std::to_string(i) + std::string(".png");
			enemy->Image_Load(path);
		}
		enemy->Image_Flip();			//��ȡ��ת��Դ
		enemy->CollisionLoad(20, 20); //��ײ�����

        inactiveEnemies.push_back(enemy);
	}
}

void EnemyPool::getEnemy() {
    if (inactiveEnemies.empty()) {
        // ���û��δ������󣬴���һ���µĵ��˶�����ӵ��Ѽ����б�
        activeEnemies.emplace_back(std::make_shared<Enemy>());
    }
    else {
        // ��δ�����б���ȡ��һ�����˶��󣬲���������Ѽ����б�
        std::shared_ptr<Enemy> enemy = inactiveEnemies.front();
        
        //�������λ��
        enemy->	SpawnLocation();
        
        inactiveEnemies.pop_front();
        activeEnemies.push_back(enemy);
    }
}

void EnemyPool::returnEnemy(std::shared_ptr<Enemy> enemy ) {
    //����δ�����б�
    inactiveEnemies.push_back(enemy);
}

//��Ⱦ�Ѽ������
void EnemyPool:: ActiveEnemies_Rendering() {
    for (std::shared_ptr<Enemy> enemy : activeEnemies) {
        enemy->Resource_Rendering();
    }
}

//�Ѽ������ҵ���߼�
void  EnemyPool:: ActiveEnemies_Pursuit(std::shared_ptr<Entity> target, DWORD time) {
	for (std::shared_ptr<Enemy> enemy : activeEnemies) {
        enemy->Pursuit(target,time);
    }
}

//�Ѽ��������ײ���
void  EnemyPool:: ActiveEnemies_CollisionDetection(std::shared_ptr<Entity> target) {
    // ʹ�õ�����������ɾ��ֵΪ2��Ԫ��
    for (std::list<std::shared_ptr<Enemy>>::iterator enemy = activeEnemies.begin(); enemy != activeEnemies.end(); ) {
        if ((*enemy)->CollisionDetection(target)) {
            returnEnemy(*enemy);
            enemy = activeEnemies.erase(enemy); // ɾ����ǰԪ�أ������µ�����
        }
        else {
            ++enemy; // ֻ�е���ɾ��Ԫ��ʱ�ŵ���������
        }
    }
}

