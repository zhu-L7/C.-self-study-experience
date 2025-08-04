// 实现PNG透明背景贴图

#pragma once
#include <graphics.h>

//返回距离上一次调用间隔的时间（单位：ms)，第一次调用时返回0
int getDelay(); 

void putimagePNG(int  picture_x, int picture_y, IMAGE* picture);

// 适用于 y <0 以及y>0的任何情况
void putimagePNG2(int x, int y, IMAGE* picture);
void putimagePNG2(int x, int y, int winWidth, IMAGE* picture);