//目标：   精灵表动画

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

	//动画
	IMAGE img_sheet;
	loadimage(&img_sheet, "assets/pikachu.png");

	int imgSize = 32;	//每帧的尺寸
	int frames = 7;		//总共有多少帧
	int speed = 200;	//多少毫秒切换一张
	int index = 6;		//初始时贴哪一张图，索引从0开始，0-6(index=6即表示开始时是贴第7张图片).

	while (true)
	{
		frameStart = clock();

		BeginBatchDraw();
		cleardevice();
		//void putimage(int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE *pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY); 这是putimage的另一种参数用法.
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