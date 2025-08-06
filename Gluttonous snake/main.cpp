#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>// 包含 mmsystem.h 以使用多媒体功能
#pragma comment(lib, "winmm.lib") // 链接 winmm.lib 库
#include<conio.h>// 包含 conio.h 以使用 getch() 函数
#include<time.h>// 包含 time.h 以使用 time() 函数
#include<stdlib.h>// 包含 stdlib.h 以使用 rand() 函数
#include<windows.h>  // 用于MessageBox

//----常量 声明 定义

#define NUM 200// 蛇身的最大长度
#define SIZE 13// 蛇身每节的大小
#define START 13*10// 蛇头的初始坐标(13的倍数)，窗口左上角(0,0)位置是(0,0)，所以蛇头坐标是(13*10,13*10)
#define NORMAL_SPEED 100  // 正常速度
#define FAST_SPEED 50     // 加速时的速度
int currentSpeed = NORMAL_SPEED;  // 当前速度

// 方向键虚拟键码（用于GetAsyncKeyState检测）
#define VK_UP 0x26    // 上方向键
#define VK_DOWN 0x28  // 下方向键
#define VK_LEFT 0x25  // 左方向键
#define VK_RIGHT 0x27 // 右方向键

bool isPaused = false;  // 暂停状态标记（false=运行，true=暂停）

// 枚举方向
enum Ch
{
	up=72,
	down=80,
	left=75,
	right = 77,
};

// 坐标结构体
struct Coor
{
	int x;
	int y;
};

// 蛇的属性
struct Snake
{
	int n;// 蛇的长度(多少节)
	Ch ch;// 蛇头的方向
	Coor szb[NUM];// 蛇身的坐标数组
};
Snake snake;// 定义一条蛇

// 食物的属性
struct Food
{
	int x;// 食物的坐标
	int y;
	bool iseat; // 是否被吃掉
};
Food food;// 定义食物


//----函数 定义

// 游戏初始化
void GameInit()
{
	srand((unsigned int)time(NULL)); // 设置随机种子

	snake.n = 3;// 蛇的长度为3
	snake.ch = right;// 蛇头方向向右
	snake.szb[0].x = START;// 蛇头坐标 13的倍数（13×10）
	snake.szb[0].y = START;
	snake.szb[1].x = START - SIZE;// 蛇身第一节坐标 与前一节相差SIZE（13）
	snake.szb[1].y = START;
	snake.szb[2].x = START - 2 * SIZE;// 蛇身第二节坐标 第三节再减一个SIZE
	snake.szb[2].y = START;

	// 初始化食物
	food.iseat = true; // 默认食物被吃掉

	// 重置速度
	currentSpeed = NORMAL_SPEED;
}

// 绘制游戏
void DrawGame()
{
	BeginBatchDraw();
	setbkcolor(RGB(20, 152, 224)); // 设置背景色（可自定义）
	cleardevice(); // 清屏

	setfillcolor(RED); // 设置填充颜色为红色
	fillrectangle(snake.szb[0].x, snake.szb[0].y, snake.szb[0].x + SIZE,
		snake.szb[0].y + SIZE);// 绘制蛇头(矩形表示)

	//circle(snake.szb[0].x, snake.szb[0].y, 6);// 绘制蛇头(圆形表示)

	// 绘制蛇
	setfillcolor(YELLOW);  // 蛇身用黄色区分
	for (int i = 1; i < snake.n; i++)// int i在C语言里需要写在外面(不能写在条件判断里)，在C++中可以写在里面.
	{
		//putimage(100,100,&image);// 绘制蛇身的每一节(图片表示)

		 fillrectangle(snake.szb[i].x, snake.szb[i].y, snake.szb[i].x + SIZE,
			snake.szb[i].y + SIZE);// 绘制蛇身的每一节(矩形表示)

		//circle(snake.szb[i].x, snake.szb[i].y, 6);// 绘制蛇身的每一节(圆形表示)
	}

	// 绘制食物
	setfillcolor(YELLOW); // 设置填充颜色为黄色
	fillrectangle(food.x, food.y, food.x+SIZE,food.y+SIZE);// 绘制食物

	// 显示速度状态（可选，方便观察）
	settextcolor(WHITE);
	settextstyle(16, 0, _T("宋体"));
	outtextxy(10, 10, currentSpeed == FAST_SPEED ? _T("加速中") : _T("正常速度"));

	// 暂停时显示提示文字
	if (isPaused) {
		settextcolor(RED);
		settextstyle(30, 0, _T("宋体"));
		outtextxy(200, 350, _T("游戏暂停（按P继续）"));
	}

	EndBatchDraw();
}

// 蛇移动函数
void SnakeMove()
{
	// 先遍历整条蛇，再把前一节的坐标赋值给后一节
	for(int i=snake.n-1; i > 0; i--)// n是身体节数(没有算头)
	{
		snake.szb[i].x = snake.szb[i - 1].x;
		snake.szb[i].y = snake.szb[i - 1].y;
	}

	switch (snake.ch)// 根据蛇头的方向来移动蛇
	{
	case up:
		snake.szb[0].y -= SIZE; // 蛇头向上移动
		break;
	case down:
		snake.szb[0].y += SIZE; // 蛇头向下移动
		break;
	case left:
		snake.szb[0].x -= SIZE; // 蛇头向左移动
		break;
	case right:
		snake.szb[0].x += SIZE; // 蛇头向右移动
		break;
	}
}

// 检查按键状态（长按检测）
void CheckKeyPress() {
	bool isKeyDown = false;  // 标记是否有方向键被按下

	// 检测暂停键（P键）：确保单次按下只切换一次状态
	static bool pPressed = false;  // 记录P键是否已处理
	if (GetAsyncKeyState('P') & 0x8000) {
		if (!pPressed) {  // 仅在P键从"未按下"变为"按下"时触发
			isPaused = !isPaused;  // 切换暂停/继续状态
			pPressed = true;       // 标记为已处理
		}
	}
	else {
		pPressed = false;  // 松开P键后允许下次触发
	}

	// 如果处于暂停状态，返回到主函数中
	if (isPaused) return;

	// 检测上方向键（长按有效）
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		if (snake.ch != down) snake.ch = up;
		isKeyDown = true;
	}
	// 检测下方向键（长按有效）
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		if (snake.ch != up) snake.ch = down;
		isKeyDown = true;
	}
	// 检测左方向键（长按有效）
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		if (snake.ch != right) snake.ch = left;
		isKeyDown = true;
	}
	// 检测右方向键（长按有效）
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		if (snake.ch != left) snake.ch = right;
		isKeyDown = true;
	}

	// 根据按键状态设置速度
	currentSpeed = isKeyDown ? FAST_SPEED : NORMAL_SPEED;
}

// 产生食物
void createFood()
{
	bool isValid = false;// 用于检查食物位置是否有效，默认没有重叠
	if (food.iseat == true) // 如果食物被吃掉
	{
		while (1)
		{
			isValid = false;

			food.x = (rand() % (640 / SIZE)) * SIZE;  // 640是窗口宽度
			food.y = (rand() % (800 / SIZE)) * SIZE;  // 800是窗口高度

			for (int i = 0; i < snake.n; i++) // 检查食物是否与蛇身重叠
			{
				if (food.x == snake.szb[i].x && food.y == snake.szb[i].y)
				{
					isValid = true;// 食物位置无效(与蛇身重叠)
					break;
				}
			}
			if (!isValid)
			{
				food.iseat = false; // 食物位置有效，设置食物未被吃掉
				break; // 如果食物位置有效，跳出循环
			}
		}
	}
}

// 吃食物
void eatFood()
{
	if (food.x == snake.szb[0].x && food.y == snake.szb[0].y) // 如果蛇头与食物重叠
	{
		food.iseat = true; // 设置食物被吃掉
		snake.n++; // 蛇的长度增加
	}
}

// 边界检测
int GameOver()
{
	// 检测蛇头是否碰到边界
	if (snake.szb[0].x < 0 || snake.szb[0].x >= 640 || // 窗口宽度为640
		snake.szb[0].y < 0 || snake.szb[0].y >= 800) // 窗口高度为800
	{
		return 1; // 游戏结束
	}

	// 检测蛇头是否碰到蛇身
	for (int i = 1; i < snake.n; i++) // 从蛇身第一节开始检查
	{
		if (snake.szb[0].x == snake.szb[i].x && snake.szb[0].y == snake.szb[i].y)// 蛇头和蛇身某一节重叠
		{
			return 1; // 游戏结束
		}
	}
	return 0; // 游戏未结束
}

int main()
{
	initgraph(640, 800);// 初始化图形窗口

	// 播放音乐
	mciSendString(TEXT("open ./assets/甩葱歌(初音ミク).wav alias music"), NULL, 0, NULL);
	mciSendString(TEXT("play music"), NULL, 0, NULL);

	GameInit(); // 调用游戏初始化函数
	while (1)
	{
		CheckKeyPress();  // 检查按键状态（长按检测）
		
		// 如果处于暂停状态，只刷新画面不执行游戏逻辑
		if (isPaused) {
			DrawGame();
			Sleep(100);  // 降低暂停时的刷新频率
			continue;
		}

		SnakeMove(); // 调用蛇移动函数

		// 需要先移动蛇，然后绘制游戏，因为DrawGame里会把蛇的n++的第3节之后的坐标变成(0,0)
		// 使得蛇在吃到食物(增加一节长度到第4节)时，第4节的坐标变成(0,0)，然后在调用SnakeMove时
		// 坐标会改回到正常，所以在游戏中蛇吃到食物时，在窗口左上角(0,0)位置会闪烁一下(一节蛇身).

		DrawGame(); // 调用绘制游戏函数
		createFood(); // 调用产生食物函数
		eatFood();// 调用吃食物函数
		Sleep(currentSpeed); // 控制游戏速度

		if (GameOver())
		{
			// 提示框
			int choice = MessageBox(
				GetHWnd(),
				L"游戏结束！是否重新开始？",
				L"游戏结束",
				MB_YESNO | MB_ICONQUESTION
			);

			if (choice == IDYES)
			{
				GameInit();  // 重新开始
				isPaused = false;  // 重新开始时重置暂停状态
			}
			else
			{
				break;  // 退出游戏
			}
		}
		else
		{
			// 处理按键（如果未结束游戏，仅改变方向）
			CheckKeyPress();
		}
	}
	
	// 清理资源
	mciSendString(TEXT("stop music"), NULL, 0, NULL);
	mciSendString(TEXT("close music"), NULL, 0, NULL);
	closegraph(); // 关闭图形窗口
	return 0;
}


// 为什么用 & 0x8000？
//   GetAsyncKeyState() 函数的返回值是一个 16 位整数，其中：
//   最高位（第 15 位） 表示按键当前是否被按下（1 = 按下，0 = 未按下）
//   其他位用于记录按键的历史状态（比如是否被按下过）
//   0x8000 是一个十六进制常量，转换为二进制是 10000000 00000000（只有最高位为 1）
//   通过 & 运算与函数返回值结合，就能提取出最高位的值(进行 “与” 操作，会保留原返回值的最高位，其余位均变为 0)：
//   如果结果为 0x8000（非 0），说明最高位为 1 → 按键正在被按下
//   如果结果为 0，说明最高位为 0 → 按键未被按下
//   
//   当长按上方向键时，GetAsyncKeyState(VK_UP) & 0x8000 会持续返回非 0 值
//   返回值的实际内容：
//   当长按上方向键时，GetAsyncKeyState(VK_UP) 的返回值中，最高位(第 15 位)会被设置为 1，其他位可能不确定
//   经过 & 0x8000 运算后，结果固定为 0x8000(二进制 10000000 00000000)，这是一个非 0 值(十进制为 32768)
//
// 如果去掉 & 0x8000，可能触发以下问题：
//   按键松开后仍可能触发：即使按键已松开，若最低位为 1(表示之前被按下过)，返回值整体非 0，会误判为 “当前按下”
//   状态判断混乱：无法区分“当前按下”和“曾经按下过”，导致蛇的方向控制异常(比如松开按键后，方向仍可能被持续修改)


// 为什么GetAsyncKeyState()比 _getch() 好？
//   _getch() 只能检测单次按键（按下一次返回一次值，长按不会重复返回），而 
//   GetAsyncKeyState() 配合 & 0x8000 能实时检测按键的持续按下状态，完美适配 “长按加速” 这类需求。