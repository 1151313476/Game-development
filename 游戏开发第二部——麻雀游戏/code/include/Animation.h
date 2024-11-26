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

	//��Դ����
	void Resource_Loading(std::string resource_path);

	//��Դ��Ⱦ
	void Resource_Rendering(double x, double y);

	//���ܺ���
	void Put_Flip_Resource(Animation* target);				//��ȡ��ת��Դ

private:
	void Set_Image_Resource(int num, IMAGE* resources);	//����ͼƬ��Դ
private:
	//��Դ
	int _image_num = 0;			//ͼƬ����
	std::vector<IMAGE> _image_resources;		//ͼƬ��Դ

	int _current_frame = 0;

	DWORD _last_time = 0;


};


#endif // !ANIMATION_H