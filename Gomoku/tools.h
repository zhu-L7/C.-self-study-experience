// ʵ��PNG͸��������ͼ

#pragma once
#include <graphics.h>

//���ؾ�����һ�ε��ü����ʱ�䣨��λ��ms)����һ�ε���ʱ����0
int getDelay(); 

void putimagePNG(int  picture_x, int picture_y, IMAGE* picture);

// ������ y <0 �Լ�y>0���κ����
void putimagePNG2(int x, int y, IMAGE* picture);
void putimagePNG2(int x, int y, int winWidth, IMAGE* picture);