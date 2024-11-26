#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector2D {
private:
	float x, y;

public:
	// 构造函数，接受两个点的坐标
	Vector2D(float _x, float _y) {
		x = _x; // 计算两个点之间的x坐标差值
		y = _y; // 计算两个点之间的y坐标差值
	}

	// 向量加法
	Vector2D operator+(const Vector2D& v) const {
		return Vector2D(x + v.x, y + v.y);
	}

	// 向量减法
	Vector2D operator-(const Vector2D& v) const {
		return Vector2D(x - v.x, y - v.y);
	}
	// 向量乘法
	Vector2D operator*(const float n) const {
		return Vector2D(x*n, y*n);
	}


	// 赋值
	Vector2D& operator=(const Vector2D& v) {
		if (this != &v) { // 防止自赋值
			x = v.x;
			y = v.y;
		}
		return *this;
	}

	float dot(const Vector2D& v) const {
		return x * v.x + y * v.y;
	}

	// 向量长度
	float magnitude() const {
		return sqrt(x * x + y * y);
	}

	// 向量归一化
	Vector2D normalize() const {
		float mag = magnitude();
		if (mag == 0) return *this; // 防止除以0
		return Vector2D(x / mag, y / mag);
	}

	// 设置向量值
	void set(float newX, float newY) {
		x = newX;
		y = newY;
	}

	// 获取x和y的值
	float getX() const { return x; }
	float getY() const { return y; }
	

	// 打印向量
	void print() const {
		std::cout << "(" << x << ", " << y << ")" ;
	}
};
#endif // !VECTOR_H
