#include "../include/Animation.h"

//��Դ
//int _image_num;			//ͼƬ����
//IMAGE *_image_resources = nullptr;	//ͼƬ��Դ

//��ʱ��
//double _time_interval = 0;			//��ǰʱ��֡
//int _current_frame = 0; 

#pragma comment( lib, "MSIMG32.LIB")

void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg) {
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

static const double FIXED_INTERVAL = 1000 / 30;		//�̶�ʱ��֡

Animation::Animation()
{
	_last_time =  GetTickCount();
}


void Animation::Resource_Rendering(double x, double y)
{
	DWORD new_time = GetTickCount();
	//��ǰʱ��֡
	if ( new_time - _last_time >= FIXED_INTERVAL) 
	{	
		_current_frame++;
		_current_frame = _current_frame % _image_num;
		_last_time = new_time;
	}
	//����
	//putimage(x, y, &_image_resources[_current_frame]);
	transparentimage3(NULL, x, y, &_image_resources[_current_frame]);
}

//��Դ����.
void Animation::Resource_Loading(std::string resource_path)
{
	_image_num++;
	IMAGE temp;
	std::wstring wstr(resource_path.begin(), resource_path.end()); // ��std::stringת��Ϊstd::wstring
	LPCTSTR lpstr = wstr.c_str(); // ��ȡC����ַ���
	loadimage(&temp, lpstr); // ����ͼ��

	_image_resources.push_back(temp);
}

void Animation::Put_Flip_Resource(Animation* target)
{
	IMAGE* flip_resources = new IMAGE[_image_num];

	//ͼ��ת
	for (int i = 0; i < _image_num; i++)	//�����ڴ����
	{
		int width = _image_resources[i].getwidth();
		int height = _image_resources[i].getheight();
		Resize(flip_resources + i, width, height);
	}

	for (int i = 0; i < _image_num; i++)
	{
		DWORD* buffer = GetImageBuffer(&_image_resources[i]);
		DWORD* flip_buffer = GetImageBuffer(&flip_resources[i]);

		int width = _image_resources[i].getwidth();
		int height = _image_resources[i].getheight();

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int idx_left = y * width + x;				//left����
				int idx_right = y * width + (width - x - 1);		//right�������������Գ�
				flip_buffer[idx_right] = buffer[idx_left];
			}
		}
	}

	target->Set_Image_Resource(_image_num, flip_resources);

	delete[] flip_resources;
}

void Animation::Set_Image_Resource(int num, IMAGE* resources)
{
	_image_num = num;
	_image_resources.assign(resources, resources + num);
}