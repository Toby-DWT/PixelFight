#include "Map.h"
#include "Config.h"

#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

bool running = true;
ExMessage msg;
Map map_;

void Init();
void UpdateWithoutInput();
void UpdateWithInput();
void Draw();


int main() {
	Init();

	// 开始游戏
	BeginBatchDraw();
	while (running) {
		// 保证帧数最高位60帧
		DWORD start_time = GetTickCount();

		// 游戏主体
		UpdateWithoutInput();
		UpdateWithInput();
		Draw();

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / 60) {
			Sleep(1000 / 60 - delta_time);
		}
	}
	EndBatchDraw();

	return 0;
}

void Init() {
	initgraph(WIGHET_WIDTH, WIGHET_HEIGHT);
}

void UpdateWithoutInput() {

}

void UpdateWithInput() {
	// 一些键盘操作
	if (GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000) {
		map_.UpdatePos(10, 10);
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		map_.UpdatePos(-10, 10);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000) {
		map_.UpdatePos(10, -10);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		map_.UpdatePos(-10, -10);
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000) {
		map_.UpdatePos(0, 10);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		map_.UpdatePos(0, -10);
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		map_.UpdatePos(10, 0);
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		map_.UpdatePos(-10, 0);
	}
	if (GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('A') & 0x8000) {
		map_.UpdatePos(10, 10);
	}
	else if (GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('D') & 0x8000) {
		map_.UpdatePos(-10, 10);
	}
	else if (GetAsyncKeyState('S') & 0x8000 && GetAsyncKeyState('A') & 0x8000) {
		map_.UpdatePos(10, -10);
	}
	else if (GetAsyncKeyState('S') & 0x8000 && GetAsyncKeyState('D') & 0x8000) {
		map_.UpdatePos(-10, -10);
	}
	else if (GetAsyncKeyState('W') & 0x8000) {
		map_.UpdatePos(0, 10);
	}
	else if (GetAsyncKeyState('S') & 0x8000) {
		map_.UpdatePos(0, -10);
	}
	else if (GetAsyncKeyState('A') & 0x8000) {
		map_.UpdatePos(10, 0);
	}
	else if (GetAsyncKeyState('D') & 0x8000) {
		map_.UpdatePos(-10, 0);
	}
}

void Draw() {
	cleardevice();

	putimage(map_.GetPos_x(), map_.GetPos_y(), map_.GetIMAGEPtr());


	FlushBatchDraw();
}