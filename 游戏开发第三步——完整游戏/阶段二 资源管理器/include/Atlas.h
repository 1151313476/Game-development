#pragma once
#include <graphics.h>
#include <vector>
#include <string>
#include <memory>

class Atlas
{
public:
	Atlas() {
	//	_images.resize(10);
	};

	~Atlas() = default;

public:
	void add_image(std::string path);

	std::vector<std::shared_ptr<IMAGE>> get_images(); //��ȡͼ������Чʹ��
	void load_images(std::vector<std::shared_ptr<IMAGE>> images);

	int get_size();
	std::shared_ptr<IMAGE> get_image(int index);

private:
	std::vector<std::shared_ptr<IMAGE>> _images;
};

