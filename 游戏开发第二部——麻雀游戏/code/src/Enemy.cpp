#include "../include/Enemy.h"

#include <random>

void Enemy::Pursuit(std::shared_ptr<Entity> target,DWORD time) {
	Vector2D vec( target->Get_X() - this->Get_X(), target->Get_Y() - this->Get_Y());
	vec = vec.normalize();
	vec = vec * (GetTickCount() - time) * 0.02;

	this->Move(vec);
}


void Enemy::SpawnLocation() {

    // 屏幕的边界
    const int screenWidth = 1280;
    const int screenHeight = 720;

    // 定义“不远”的范围，比如100像素
    const int closeRange = 100;

    // 生成屏幕外的随机x坐标，但不超过100像素
    int x =(screenWidth) - rand() % screenWidth;

    int y;
    if (x > 1280 || x < 0) {
        y = (screenHeight - 100) - rand() % screenHeight;
    }
    else {
		// 生成屏幕外的随机y坐标，但不超过100像素
		if (rand() % 2) { // 50%的几率生成上方屏幕外的位置
			y = -rand() % closeRange - 100; // 负值，小于0
		}
		else {
			y = screenHeight + rand() % closeRange; // 大于720
		}
    }
   	Teleportation(Vector2D(x, y));

}


bool Enemy::CollisionDetection(std::shared_ptr<Entity> target) {


    // 检测第一个矩形的右边界是否在第二个矩形的左边界之外
    if (this->Get_X() + this->Get_W() < target->Get_X()) return false;
    // 检测第一个矩形的左边界是否在第二个矩形的右边界之外
    if (this->Get_X() > target->Get_X() + target->Get_W()) return false;
    // 检测第一个矩形的下边界是否在第二个矩形的上边界之上
    if (this->Get_Y() + this->Get_H() < target->Get_Y()) return false;
    // 检测第一个矩形的上边界是否在第二个矩形的下边界之下
    if (this->Get_Y() > target->Get_Y() + target->Get_H()) return false;

    // 如果没有返回false，则矩形重叠
    return true;
}
