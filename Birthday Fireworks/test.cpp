#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<mmsystem.h>//多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")//多媒体设备接口库文件

#define PI 3.1415
#define WIDTH 960
#define HEIGHT 640
#define NUM 13    //烟花弹数量

struct Jet
{
	int x, y;        //坐标
	int hx, hy;     //最高点坐标
	bool isLaunch;  //烟花弹是否发射
	IMAGE img[2];
	byte n : 1;     //位段
}jet[NUM];

struct Fire
{
	int x;
	int y;
	int cen_x, cen_y;     //中心点坐标
	int r;                //当前绽放的半径
	int max_r;            //最大绽放半径
	int width, height;
	DWORD pixel[240][240];//图片像素数组
	bool isShow;          //烟花是否准备好
	bool isDraw;          //是否绘制烟花
}fire[NUM];


//绘制文字 播放音乐
void welcome()
{
	mciSendString(L"open ./assets/小幸运.mp3", 0, 0, 0);//播放音乐
	mciSendString(L"play ./assets/小幸运.mp3", 0, 0, 0);

	for (int i = 0; i < 50; i++)
	{
		cleardevice();//清屏

		int x = 500 + 180 * sin(2 * PI / 60 * i);//计算运动轨迹
		int y = 200 + 180 * cos(2 * PI / 60 * i);

		//设置字体
		settextstyle(i, 0, L"江城圆体");//样式
		settextcolor(RGB(0, 202, 0));//颜色
		setbkmode(TRANSPARENT);//设置透明背景
		outtextxy(x, y, L"生日烟花程序");//文本
		Sleep(20);
	}
	_getch();//按任意键继续(在控制窗口按)
	cleardevice();
	settextstyle(30, 0, L"楷体");
	outtextxy(250, 100, L"亲爱的XXX");
	outtextxy(300, 150, L"1111111");
	outtextxy(300, 200, L"2222222");
	outtextxy(300, 250, L"3333333");
	outtextxy(300, 300, L"4444444");
	outtextxy(300, 350, L"5555555");
	outtextxy(450, 400, L"--XXX");

}

void Init_fire(int i)
{
	//初始化烟花
	fire[i].cen_x = 120; //中心坐标
	fire[i].cen_y = 120;
	fire[i].max_r = 120; //最大绽放半径
	fire[i].r = 0;       //最开始绽放半径
	fire[i].width = 240;
	fire[i].height = 240;
	fire[i].isDraw = false;
	fire[i].isShow = false;
}

//图片
void loadImg()
{
	//初始化烟花弹
	IMAGE jetImg;
	loadimage(&jetImg, L"./assets/shoot.jpg", 200, 50);

	SetWorkingImage(&jetImg); //SetWorkingImage() 是 EasyX 中的一个函数，用于设置当前绘图设备（即后续绘图操作的目标）
	for (int i = 0; i < NUM; i++)
	{
		int n = rand() % 5;
		getimage(&jet[i].img[0], n * 20, 0, 20, 50);     //暗色
		getimage(&jet[i].img[1], n * 20 + 100, 0, 20, 50); //亮色

		jet[i].isLaunch = false;
	}
	SetWorkingImage();        // 恢复绘图目标为屏幕

	//初始化烟花绽放
	IMAGE bloomImg, tImg;
	loadimage(&bloomImg, L"./assets/flower.jpg", 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		Init_fire(i); //初始化烟花

		//获取数据
		SetWorkingImage(&bloomImg);
		getimage(&tImg, i * 240, 0, 240, 240l);//截取bloomImg中的图片的一块区域存放在临时图像tImg中
		SetWorkingImage(&tImg);
		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				// 获取 (a, b) 坐标的像素颜色，并保存到 fire[i].pixel 数组中
				fire[i].pixel[a][b] = getpixel(a, b);  //getpixel 用于获取指定坐标处的像素颜色，返回值是一个 COLORREF 类型的颜色值（包含 RGB 信息）
			}
		}
	}
	SetWorkingImage();        // 恢复绘图目标为屏幕

}

//生成烟花弹
void createJet()
{
	int i = rand() % NUM;//[0～13)
	if (jet[i].isLaunch == false)
	{
		jet[i].x = rand() % (WIDTH - 20);//烟花坐标
		jet[i].y = rand() % 100 + HEIGHT;
		jet[i].hx = jet[i].x;//烟花上升时坐标
		jet[i].hy = rand() % (HEIGHT / 3 * 2);

		jet[i].isLaunch = true;
	}
}

//发射烟花弹
void launch()
{
	for (int i = 0; i < NUM; i++)
	{
		if (jet[i].isLaunch)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);//此时烟花弹还在上一帧的位置，调用后会用异或模式 “擦除” 该位置的旧图像（恢复背景）

			//判断是否到达最高点
			if (jet[i].y > jet[i].hy)
			{
				jet[i].y -= 5;
				jet[i].n++;    //实现暗色与亮色的不断切换，因为 n 是 1 位位段，其取值只能是 0 或 1：
							   //当 n = 0 时，n++ 会使其变为 1//当n = 1时，n++会因溢出(1位二进制数的最大值是1，加1后会进位归零)变为0	   
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);//烟花弹已移动到新位置，调用后会用异或模式在新位置绘制更新后的图像（新图片）
			if (jet[i].y <= jet[i].hy)
			{
				jet[i].isLaunch = false;

				//开始放烟花
				fire[i].x = jet[i].x;
				fire[i].y = jet[i].y;
				fire[i].isShow = true;
			}
		}
	}
}

//烟花绽放
void bloom(DWORD* pMem)
{
	for (int i = 0; i < NUM; i++)
	{
		if (fire[i].isShow)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].isDraw = true;//开始绘制烟花
			}
			if (fire[i].r >= fire[i].max_r)
			{
				Init_fire(i); //重新初始化烟花
			}
		}
		if (fire[i].isDraw)//绘制
		{
			//求当前半径下圆上的每个点坐标
			for (double a = 0; a <= 2 * PI; a += 0.01)
			{
				int img_x = fire[i].cen_x + fire[i].r * cos(a);//圆上点的x坐标
				int img_y = fire[i].cen_y + fire[i].r * sin(a);//圆上点的y坐标

				//判断坐标是否在图片范围内
				if(img_x>0 && img_x < fire[i].width && img_y > 0 && img_y < fire[i].height)
				{
					//绽放点对应的屏幕坐标
					int win_x = fire[i].x + fire[i].r * cos(a);
					int win_y = fire[i].y + fire[i].r * sin(a);

					if (win_x > 0 && win_x < WIDTH && win_y > 0 && win_y < HEIGHT)
					{
						pMem[win_y * WIDTH + win_x] = BGR(fire[i].pixel[img_x][img_y]);//将当前点的像素颜色存入屏幕缓冲区
					}

					////获取当前点的像素颜色
					//COLORREF color = fire[i].pixel[img_x][img_y];
					////判断是否是透明色
					//if (color != RGB(0, 0, 0))//如果不是黑色(黑色为透明色)
					//{
					//	//绘制烟花
					//	putpixel(fire[i].x + img_x - fire[i].cen_x, fire[i].y + img_y - fire[i].cen_y, color);
					//}
				}
			}
		}
	}
}


int main()
{
	//创建窗口
	initgraph(960, 640);

	//设置随机数种子
	srand((unsigned)time(NULL) + clock());

	welcome();
	loadImg();
	DWORD* pMem = GetImageBuffer();//获取窗口的内存(屏幕缓冲区)指针

	while (1)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;//用黑色(背景色)把烟花慢慢覆盖掉
				}
			}
		}

		createJet();

		launch();
		bloom(pMem);       

		Sleep(10);
	}
	closegraph();
	return 0;
}


//SRCINVERT的核心作用：异或（XOR）绘图
// 
//SRCINVERT是 EasyX 中的一种像素混合模式，本质是对目标位置的像素与图像像素执行异或运算（XOR）：
//  若某像素原本是颜色 A(背景色)，绘制颜色 B 时，结果为A XOR B；
//  若对同一位置用相同的颜色 B 再绘制一次，结果为(A XOR B) XOR B = A(即恢复成原来的颜色，即恢复背景色)
//  这一特性使其非常适合临时绘制并擦除的场景（比如移动的物体）：第一次绘制时 “显示” 图像，第二次绘制时 “擦除” 图像，恢复背景


//位段
//是一种特殊的结构体成员定义方式，允许将数据成员存储在指定的二进制位数中，从而更高效地利用内存空间
//
//注意：
//位段的成员数据类型通常是 int、unsigned int 或 signed int（C99 也支持其他整数类型，如 _Bool）。
//位数 n 必须是非负整数，且不能超过对应数据类型的总位数（例如 int 通常是 32 位，n 不能超过 32）。
//若位数为 0，表示该位段结束，后续成员从新的存储单元开始。
// 
//作用：节省内存,将多个小数据打包到一个字节中，减少内存占用。