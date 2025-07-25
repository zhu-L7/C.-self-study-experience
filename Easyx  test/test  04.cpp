//目标：   单帧多图动画

#include<stdio.h>
#include<easyx.h>
#include"TransparentImage.h"
#include<time.h>

int main()
{
	initgraph(480, 800, EX_SHOWCONSOLE);
	setbkcolor(RGB(230, 231, 232));
	cleardevice();

	//动画
	IMAGE img_enemy[4];
	
	/*loadimage(img_enemy + 0, "assets/enemy1_down1.png");
	loadimage(img_enemy + 1, "assets/enemy1_down2.png");
	loadimage(img_enemy + 2, "assets/enemy1_down3.png");
	loadimage(img_enemy + 3, "assets/enemy1_down4.png");*/
	//优化
	char path[100] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		sprintf(path, "assets/enemy1_down%d.png", i + 1);
		loadimage(img_enemy + i, path);
	}


	const int frameDelay = 1000 / 60;   //延迟时间(FPS)
	int frameStart = 0;
	int frameTime = 0;

	int index = 0;
	int frames = 4;     //记录动画的总帧数（即动画序列中包含的图片总数）
	int speed = 200;    //每隔200毫秒切换一帧
	while (true)
	{
		frameStart = clock();

		BeginBatchDraw();
		cleardevice();

		drawImg(0, 0, img_enemy+index);

		EndBatchDraw();

		/*index++;
		if (index >= 4)
		{
			index = 0;
		}*/
		//优化
		//index = (index + 1) % 4;
		
		index = (clock() / speed) % frames;        //每隔speed毫秒index增加1.
		                                           //因为clock是从程序开始到被调用的时间(毫秒)
		                                           //比如 从0-200，需要200毫秒，index才会加1.
		                                           //所以动画速度可以被如此控制
		 
		frameTime = clock() - frameStart;
		if (frameDelay - frameStart > 0)
		{
			Sleep(frameDelay - frameTime);
		}
	}
	

	getchar();
	return 0;
}
