#pragma once
#include <graphics.h>
class Map
{
private:
	int pos_x;
	int pos_y;
	IMAGE map_image;
public:
	Map();
	void UpdatePos(int change_x, int change_y);
	int GetPos_x() { return pos_x; }
	int GetPos_y() { return pos_y; }
	IMAGE* GetIMAGEPtr() { return &map_image; }
};

