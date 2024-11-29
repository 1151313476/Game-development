#include "Atlas.h"

void Atlas::add_image(std::string path)
{
	std::shared_ptr<IMAGE> temp = std::make_shared<IMAGE>();
	std::wstring wstr(path.begin(), path.end()); // 将std::string转换为std::wstring
	LPCTSTR lpstr = wstr.c_str(); // 获取C风格字符串
	loadimage(&(*temp), lpstr); // 加载图像
	_images.push_back(temp);
}

std::vector<std::shared_ptr<IMAGE>> Atlas::get_images()
{
    return _images;
}

void Atlas::load_images(std::vector<std::shared_ptr<IMAGE>> images)
{
    _images = images;
}

int Atlas::get_size()
{
	return _images.size();
}

std::shared_ptr<IMAGE> Atlas::get_image(int index)
{
	return _images[index];
}


