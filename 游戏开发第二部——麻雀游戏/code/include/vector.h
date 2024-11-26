#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector2D {
private:
	float x, y;

public:
	// ���캯�������������������
	Vector2D(float _x, float _y) {
		x = _x; // ����������֮���x�����ֵ
		y = _y; // ����������֮���y�����ֵ
	}

	// �����ӷ�
	Vector2D operator+(const Vector2D& v) const {
		return Vector2D(x + v.x, y + v.y);
	}

	// ��������
	Vector2D operator-(const Vector2D& v) const {
		return Vector2D(x - v.x, y - v.y);
	}
	// �����˷�
	Vector2D operator*(const float n) const {
		return Vector2D(x*n, y*n);
	}


	// ��ֵ
	Vector2D& operator=(const Vector2D& v) {
		if (this != &v) { // ��ֹ�Ը�ֵ
			x = v.x;
			y = v.y;
		}
		return *this;
	}

	float dot(const Vector2D& v) const {
		return x * v.x + y * v.y;
	}

	// ��������
	float magnitude() const {
		return sqrt(x * x + y * y);
	}

	// ������һ��
	Vector2D normalize() const {
		float mag = magnitude();
		if (mag == 0) return *this; // ��ֹ����0
		return Vector2D(x / mag, y / mag);
	}

	// ��������ֵ
	void set(float newX, float newY) {
		x = newX;
		y = newY;
	}

	// ��ȡx��y��ֵ
	float getX() const { return x; }
	float getY() const { return y; }
	

	// ��ӡ����
	void print() const {
		std::cout << "(" << x << ", " << y << ")" ;
	}
};
#endif // !VECTOR_H
