#include "../include/Enemy.h"

#include <random>

void Enemy::Pursuit(std::shared_ptr<Entity> target,DWORD time) {
	Vector2D vec( target->Get_X() - this->Get_X(), target->Get_Y() - this->Get_Y());
	vec = vec.normalize();
	vec = vec * (GetTickCount() - time) * 0.02;

	this->Move(vec);
}


void Enemy::SpawnLocation() {

    // ��Ļ�ı߽�
    const int screenWidth = 1280;
    const int screenHeight = 720;

    // ���塰��Զ���ķ�Χ������100����
    const int closeRange = 100;

    // ������Ļ������x���꣬��������100����
    int x =(screenWidth) - rand() % screenWidth;

    int y;
    if (x > 1280 || x < 0) {
        y = (screenHeight - 100) - rand() % screenHeight;
    }
    else {
		// ������Ļ������y���꣬��������100����
		if (rand() % 2) { // 50%�ļ��������Ϸ���Ļ���λ��
			y = -rand() % closeRange - 100; // ��ֵ��С��0
		}
		else {
			y = screenHeight + rand() % closeRange; // ����720
		}
    }
   	Teleportation(Vector2D(x, y));

}


bool Enemy::CollisionDetection(std::shared_ptr<Entity> target) {


    // ����һ�����ε��ұ߽��Ƿ��ڵڶ������ε���߽�֮��
    if (this->Get_X() + this->Get_W() < target->Get_X()) return false;
    // ����һ�����ε���߽��Ƿ��ڵڶ������ε��ұ߽�֮��
    if (this->Get_X() > target->Get_X() + target->Get_W()) return false;
    // ����һ�����ε��±߽��Ƿ��ڵڶ������ε��ϱ߽�֮��
    if (this->Get_Y() + this->Get_H() < target->Get_Y()) return false;
    // ����һ�����ε��ϱ߽��Ƿ��ڵڶ������ε��±߽�֮��
    if (this->Get_Y() > target->Get_Y() + target->Get_H()) return false;

    // ���û�з���false��������ص�
    return true;
}
