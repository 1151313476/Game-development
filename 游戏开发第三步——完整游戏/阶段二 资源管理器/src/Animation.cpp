#include "Animation.h"

#pragma comment( lib, "MSIMG32.LIB")

static const double FIXED_INTERVAL = 1000 / 10;		//固定时间帧

void transparentimage3(IMAGE* dstimg, double x, double y, IMAGE* srcimg) {
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

void Animation::load_atlas(std::shared_ptr<Atlas> atlas)
{
	_atlas = atlas;
	_atlas_num = _atlas->get_size();
}
void Animation::image_render(double x, double y, DWORD time)
{
	//当前时间帧
	if (time - _last_time >= FIXED_INTERVAL)
	{
		_current_frame++;
		_current_frame = _current_frame % _atlas_num;
		_last_time = time;
	}
	//播放
	//putimage(x, y, &_image_resources[_current_frame]);
	transparentimage3(NULL, x, y, &(*_atlas->get_image(_current_frame)));
}
