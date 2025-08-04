#include<stdio.h>
#include<graphics.h>
#include <windows.h>
#include<time.h>
#include<stdlib.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib") //链接winmm.lib库


//----定义声明
#define METEOR_NUM 100 //流星雨数量

IMAGE img_bk;	//流星图片
IMAGE img_meteor[2];//流星图片数组

//流星  坐标 速度
struct Meteor
{
	int x;		//x坐标
	int y;		//y坐标
	int speed;	//速度
};


//----函数声明

//播放音乐
void Music()
{
	mciSendString(L"open ./assets/心愿便利贴(清甜女声版)-昕儿.mp3 alias bgm", NULL, 0, NULL); //打开音乐文件
	mciSendString(L"play bgm repeat", NULL, 0, NULL); //播放音乐
}

//加载图片
void loadImage()
{
	//加载背景图片
	loadimage(&img_bk, L"./assets/bk.jpg", getwidth(), getheight());

	//加载流星图片
	loadimage(&img_meteor[0], L"./assets/1.png",32,32);
	loadimage(&img_meteor[1], L"./assets/2.png",32,32);
}

//流星雨初始化
void meteor_init(Meteor* pthis, int x, int y, int speed)
{
	pthis->x = x;
	pthis->y = y;
	pthis->speed = speed;
}

//绘制流星雨
void meteor_draw(Meteor* pthis)
{
	putimage(pthis->x, pthis->y, img_meteor + rand() % 2, SRCPAINT);
}

//流星雨移动
void meteor_update(Meteor* pthis)
{
	pthis->x += pthis->speed; //x坐标增加
	pthis->y += pthis->speed; //y坐标增加

	if (pthis->y > 600)
	{
		pthis->x = rand() % 1100 - 300;
		pthis->y = rand() % 840 - 300;
	}

}
//主程序
int main()
{
	//创建窗口
	initgraph(1200, 800,EW_SHOWCONSOLE);
	// 让图形窗口置顶---需要包含 <windows.h> 并且放在创建窗口之后
    HWND hwnd = GetHWnd(); // EasyX 提供的获取窗口句柄的函数
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	//设置背景颜色
	setbkcolor(WHITE);
	cleardevice();


	//加载图片
	loadImage();
	
	//播放音乐
	Music();

	//绘制
	Meteor meteors[METEOR_NUM];
	for (int i = 0; i < METEOR_NUM; i++)
	{
		int x = rand() % 1100 - 300;//-300~800
		int y = rand() % 840 - 300;//-300~540
		meteor_init(meteors + i, x, y, rand() % 2 + 1);
	}
	while (true)
	{
		//防止闪屏---双缓冲
		BeginBatchDraw();
		putimage(0, 0, &img_bk);//背景

		for(int i=0;i<METEOR_NUM;i++)
		{
			meteor_draw(meteors + i);//绘制流星
			meteor_update(meteors + i);//更新流星位置
		}
		EndBatchDraw();
		Sleep(10); //延时10毫秒
	}

	getchar();//等待用户输入,防止窗口闪退
	return 0;
}