//目标：   清屏 / 双缓冲 / 帧率控制.

#include<stdio.h>
#include<easyx.h>
#include<time.h>

int main()
{
	//创建窗口
	initgraph(640, 480, EX_SHOWCONSOLE);
	setbkcolor(RGB(230, 231, 232));
	cleardevice();                  //清屏--用设置的背景颜色填充整个窗口.
	setbkmode(TRANSPARENT);


	//FPS--帧率
	const clock_t FPS = 1000 / 60;    //1秒=1000毫秒，1000/60表示的就是每一帧花费的毫秒，即约等于16.7毫秒(整形就是16毫秒).
	int startTime = 0;
	int freamTime = 0;              

	int score = 0;
	char str[50] = "";              //一定要把大小定义大一点，不然容易导致程序崩溃(是一个潜在的bug).
	while (true)
	{
		startTime = clock();        //程序运行到调用这个函数所花费的时间(毫秒).

		sprintf(str, "Score:%d", score++);
		settextcolor(BLACK);

		//双缓冲--防止闪屏(原理是先把数据放进缓冲区，再一次性把全部数据传给窗口).
		BeginBatchDraw();
		cleardevice();
		outtextxy(20, 20, str);

		EndBatchDraw();

		freamTime = clock()- startTime;        //当前帧实际执行的时间(毫秒).
		if (freamTime > 0)
		{
			Sleep(FPS - freamTime);
		}

	}
	
	return 0;
}