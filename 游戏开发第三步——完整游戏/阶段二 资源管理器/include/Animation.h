#pragma once

#include "Atlas.h"

class Animation
{
public:
	Animation() {
		_last_time = GetTickCount();
		_current_frame = 0;
	}
	~Animation() = default;

	void load_atlas(std::shared_ptr<Atlas> atlas);

	void image_render(double x, double y, DWORD time);
private:
	std::shared_ptr<Atlas> _atlas;

	DWORD _last_time;

	int _current_frame;
	int _atlas_num;
};

