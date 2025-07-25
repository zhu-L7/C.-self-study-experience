//Ŀ�꣺   �������

#include<stdio.h>
#include<easyx.h>
#include"TransparentImage.h"
#include<time.h>
int main()
{
	initgraph(480, 800, EX_SHOWCONSOLE);
	setbkcolor(RGB(230, 231, 232));
	cleardevice();

	const int frameDelay = 1000 / 60;
	int frameStart = 0;
	int frameTime = 0;

	//����
	IMAGE img_sheet;
	loadimage(&img_sheet, "assets/pikachu.png");

	int imgSize = 32;	//ÿ֡�ĳߴ�
	int frames = 7;		//�ܹ��ж���֡
	int speed = 200;	//���ٺ����л�һ��
	int index = 6;		//��ʼʱ����һ��ͼ��������0��ʼ��0-6(index=6����ʾ��ʼʱ������7��ͼƬ).

	while (true)
	{
		frameStart = clock();

		BeginBatchDraw();
		cleardevice();
		//void putimage(int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE *pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY); ����putimage����һ�ֲ����÷�.
		drawImg(250, 250, imgSize, imgSize, &img_sheet, index * imgSize, 0);

		EndBatchDraw();

		index = (clock() / speed) % frames;

		frameTime = clock() - frameStart;
		if (frameDelay - frameTime > 0)
		{
			Sleep(frameDelay - frameTime);
		}

	}

	getchar();
	return 0;
}