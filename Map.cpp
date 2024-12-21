#include "Map.h"
#include "Config.h"
Map::Map() {
	pos_x = -(MAP_WIDTH - WIGHET_WIDTH) / 2;
	pos_y = -(MAP_HEIGHT - WIGHET_HEIGHT) / 2;
	loadimage(&map_image, _T("res/Map.png"));
}
void Map::UpdatePos(int change_x = 0, int change_y = 0) {
	// ע�����ﲻ�Ǿ���ֵ
	pos_x += change_x;
	pos_y += change_y;
	// �߽��ж�
	if (pos_x > WIGHET_WIDTH / 2 || pos_x + MAP_WIDTH <= WIGHET_WIDTH / 2) {
		pos_x -= change_x;
	}
	if (pos_y > WIGHET_HEIGHT / 2 || pos_y + MAP_HEIGHT <= WIGHET_HEIGHT / 2) {
		pos_y -= change_y;
	}
}