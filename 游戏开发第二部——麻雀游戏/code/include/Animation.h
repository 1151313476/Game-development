#ifndef ANIMATION_H
#define ANIMATION_H
#include <string>
#include <graphics.h>
#include <easyx.h>
#include <vector>

class Animation
{
public:
	Animation();

	~Animation()
	{
	}

	//资源加载
	void Resource_Loading(std::string resource_path);

	//资源渲染
	void Resource_Rendering(double x, double y);

	//功能函数
	void Put_Flip_Resource(Animation* target);				//获取翻转资源

private:
	void Set_Image_Resource(int num, IMAGE* resources);	//设置图片资源
private:
	//资源
	int _image_num = 0;			//图片数量
	std::vector<IMAGE> _image_resources;		//图片资源

	int _current_frame = 0;

	DWORD _last_time = 0;


};


#endif // !ANIMATION_H