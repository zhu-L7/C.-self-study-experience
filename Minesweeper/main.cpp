#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include"tools.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib") // 多媒体库，提供时间函数

//----常量 定义 声明
#define ROW 25// 行
#define COL 25// 列
#define NUM 100// 雷的个数(可以通过改变雷的个数来改变游戏难度)
#define SIZE 30// 格子图片的大小

int count = 0;// 计数器，记录已打开的格子数
int map[ROW][COL];

IMAGE img[12]; // 图片数组

//----函数 定义

void loadImg()
{
	loadimage(&img[0], L"./assets/images/cell.jpg", SIZE, SIZE);// 背景格子图片
	loadimage(&img[1], L"./assets/images/bomb.jpg", SIZE, SIZE);// 雷图片

	// 数字1-8图片
	loadimage(&img[2], L"./assets/images/1.jpg", SIZE, SIZE);
	loadimage(&img[3], L"./assets/images/2.jpg", SIZE, SIZE);
	loadimage(&img[4], L"./assets/images/3.jpg", SIZE, SIZE);
	loadimage(&img[5], L"./assets/images/4.jpg", SIZE, SIZE);
	loadimage(&img[6], L"./assets/images/5.jpg", SIZE, SIZE);
	loadimage(&img[7], L"./assets/images/6.jpg", SIZE, SIZE);
	loadimage(&img[8], L"./assets/images/7.jpg", SIZE, SIZE);
	loadimage(&img[9], L"./assets/images/8.jpg", SIZE, SIZE);

	loadimage(&img[10], L"./assets/images/blank.jpg", SIZE, SIZE);// 空白图片
	loadimage(&img[11], L"./assets/images/flag.jpg", SIZE, SIZE);// 旗子图片

}

void GameInit()// 游戏初始化
{
	srand((unsigned int)time(NULL));// 设置随机数种子

	count = 0; // 重置计数器为0

	// 初始化地图
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] = 0;
		}
	}
	int n = 0;
	while(n< NUM)
	{
		//随机得到行和列
		int r = rand() % ROW;// rand函数需要<stdlib.h>头文件
		int c = rand() % COL;
		if (map[r][c] == 0)// 该位置没有雷
		{
			map[r][c] = -1;// 设置为雷
			n++;
		}
	}

	// 设置雷周围的数字
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == -1) // 如果是雷
			{
				// 遍历周围的8个位置
				for (int x = -1; x <= 1; x++)
				{
					for (int y = -1; y <= 1; y++)
					{
						if (x == 0 && y == 0) continue; // 跳过自己
						int newX = i + x;// 新的位置 x和y是偏移量
						int newY = j + y;
						if (newX >= 0 && newX < ROW && newY >= 0 && newY < COL && map[newX][newY] != -1)
						{
							map[newX][newY]++; // 增加周围雷的计数
						}
					}
				}
			}
		}
	}

	// 覆盖每个格子
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] += 20; // 将每个格子的值加20，避免和雷的值冲突(加密覆盖格子)
		}
	}

	// 这种方法会越界访问数组，可能访问到游戏边界外围一圈，如果外围一圈被定义了雷，就会导致边界一圈格子的数值错误
	/*for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] != -1)
			{
				for(int m=i-1;m<=i+1;m++)
				{
					for(int n=j-1;n<=j+1;n++)
					{
						if(map[m][n]==-1)
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}*/
}

void GameDraw()// 游戏绘制
{

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%2d ", map[i][j]);// 控制台输出每个格子的值

			if(map[i][j] == -1) // 如果是雷
			{
				putimage(j * SIZE, i * SIZE, &img[1]); // 绘制雷图片
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				putimage(j * SIZE, i * SIZE, &img[0]); // 绘制背景格子图片
			}
			else if (map[i][j] == 0)
			{
				putimage(j * SIZE, i * SIZE, &img[10]); // 数字0图片
			}
			else if (map[i][j] >= 1 && map[i][j] <= 8) // 如果是数字1-8
			{
				putimage(j * SIZE, i * SIZE, &img[map[i][j] + 1]); // 绘制对应数字1-8图片
			}
			else if(map[i][j] > 30)
			{
				putimagePNG(j * SIZE, i * SIZE, &img[11]);// 绘制旗子图片
			}
		}
		printf("\n");
	}
}

void Open_ZeroRound(int r, int c)
{
	//先打开这个0
	map[r][c] -= 20; // 揭开覆盖
	count++;
	printf("打开的格子数：%d\n", count);

	for (int m = r - 1; m <= r + 1; m++)// 遍历周围的格子
	{
		for (int n = c - 1; n <= c + 1; n++)
		{
			if (m >= 0 && m < ROW && n >= 0 && n < COL)// 边界判断
			{
				if (map[m][n] >= 19 && map[m][n] <= 28)// 如果是覆盖状态
				{
					if (map[m][n] == 20)// 如果是0
					{
						Open_ZeroRound(m, n);// 递归打开周围的0
					}
					else
					{
						map[m][n] -= 20;// 揭开覆盖
						count++;
						printf("打开的格子数：%d\n", count);
					}
				}
			}
		}
	}
}


int PlayGame()// 玩游戏--处理消息
{
	// 定义一个鼠标消息
	MOUSEMSG msg = { 0 };
	int r, c;

	while (1)
	{
		msg = GetMouseMsg(); // 获取鼠标消息

		switch (msg.uMsg)
		{
		case WM_LBUTTONUP:  // 左键抬起（揭开格子）
			r = msg.y / SIZE;  // 行 = 鼠标y坐标 / 格子大小
			c = msg.x / SIZE;  // 列 = 鼠标x坐标 / 格子大小

			// 增加边界判断，防止点击窗口外导致数组越界
			if (r >= 0 && r < ROW && c >= 0 && c < COL)
			{
				if (map[r][c] >= 19 && map[r][c] <= 28)  // 如果是覆盖状态
				{
					if (map[r][c] == 20)// 点到0
					{
						Open_ZeroRound(r,c);
					}
					else
					{
						map[r][c] -= 20;  // 揭开覆盖
						count++;  // 增加计数
						printf("打开的格子数：%d\n", count);
					}
				}
			}
			return map[r][c];
			break;

		case WM_RBUTTONUP:  // 右键抬起（标记/取消旗子）
			r = msg.y / SIZE;
			c = msg.x / SIZE;

			// 边界判断
			if (r >= 0 && r < ROW && c >= 0 && c < COL)
			{
				if (map[r][c] >= 19 && map[r][c] <= 28)  // 覆盖状态→标记旗子
				{
					map[r][c] += 50;
				}
				else if (map[r][c] > 30)  // 旗子状态→取消标记
				{
					map[r][c] -= 50;
				}
			}
			return map[r][c];
			break;
		}
	}
}



// 主程序
int main()
{
	HWND hwnd = initgraph(750,750, SHOWCONSOLE);// 初始化窗口，并使其为父窗口

	mciSendString(L"open ./assets/musics/Doopravdy.mp3 alias bg", NULL, 0, NULL); // 打开音乐文件
	mciSendString(L"play bg repeat", NULL, 0, NULL); // 循环播放音乐

	loadImg();// 加载图片
	GameInit();// 游戏初始化
	
	while (1)
	{
		GameDraw();// 游戏绘制

		if(PlayGame() == -1)// 点到雷
		{
			GameDraw();
			int result = MessageBox(hwnd, L"Game Over!!\n重新开始(是)\n退出游戏(否)", L"提示", MB_YESNO | MB_ICONINFORMATION);
			
			// 根据用户点击的按钮执行对应操作
			if (result == IDYES)  // 用户点击“是”（重新开始）
			{
				// 重新初始化游戏（调用初始化函数，重置地图等）
				GameInit();
			}
			else if (result == IDNO)  // 用户点击“否”（退出游戏）
			{
				// 关闭图形窗口并退出程序
				closegraph();
				exit(0);
			}
		}

		if (ROW * COL - NUM == count)
		{
			GameDraw();
			int outcome = MessageBox(hwnd, L"Victory!!\n重新开始(是)\n退出游戏(否)", L"提示", MB_YESNO | MB_ICONINFORMATION);

			// 根据用户点击的按钮执行对应操作
			if (outcome == IDYES)  // 用户点击“是”（重新开始）
			{
				// 重新初始化游戏（调用初始化函数，重置地图等）
				GameInit();
			}
			else if (outcome == IDNO)  // 用户点击“否”（退出游戏）
			{
				// 关闭图形窗口并退出程序
				closegraph();
				exit(0);
			}
		}
	}

	closegraph(); // 关闭图形窗口
	return 0;
}
