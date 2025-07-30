//  目标：  窗口创建 / 设置颜色 / 鼠标事件 / 键盘事件

#include<stdio.h>
#include<raylib.h>  //可以转到定义查看 函数 结构体 相关定义
#include<time.h>
#include<stdlib.h>

// 定义最大图形数量
#define MAX_SHAPES 1000

// 图形类型枚举
typedef enum 
{ 
	CIRCLE, RECTANGLE 
} ShapeType;

// 图形结构体
typedef struct 
{
	ShapeType type;
	int x, y;
	Color color;
} Shape;

// 图形数组
Shape shapes[MAX_SHAPES];
int shapeCount = 0;


void test_raylib_datatype()
{
	Vector2 p;          
	p.x = 12;
	p.y = 12;

	Rectangle rect = { 10,10,100,100 };
}


int main()
{
	srand((unsigned int)time(NULL));  //把随机随机种子和时间建立联系，否则随机数是固定的

	int x = 40;
	int y = 40;

	InitWindow(800, 600, "test_raylib");  //创建窗口

	while (!WindowShouldClose())  //WindowShouldClose()检查用户是否请求关闭窗口
		                          //   返回值： true：请求关闭窗口(点击窗口关闭按钮或按下特定的键盘按键，如esc)
								  //            false：没有请求关闭窗口，窗口仍然保持打开状态
	{
		//绘图
		BeginDrawing();               //绘制帧的开始
        //绘图操作
		Color color = { 128,0,225 };  //定义颜色
		ClearBackground(BLACK);       //刷新背景(清屏)---设置背景颜色

		//for (int i = 0; i < 1000; i++)
		//{
		//	x = rand() % 800;
		//	y = rand() % 600;
		//	DrawPixel(x, y, WHITE);  //绘制点
		//}

		//左键画圆 右键画方---这种方法必须先注释掉ClearBackground(BLACK)
		//虽然可以通过注释掉 ClearBackground() 保留图形，但这会导致：
        //                 性能问题（每帧累积绘制的图形越来越多）
	    //                 无法实现擦除或修改已有图形的功能
		//                 可能出现渲染异常（如窗口被遮挡后重绘不完整）
		// 
		//if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		//{
		//	DrawCircle(GetMouseX(), GetMouseY(), 5, RED);
		//}
		//if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		//{
		//	DrawRectangle(GetMouseX()-5, GetMouseY()-5, 10,10, GREEN);
		//}

		// 绘制所有已保存的图形---先把用户绘制的图形信息存到数组里，然后在每一帧渲染时，把数组中的所有图形重新绘制出来。
		for (int i = 0; i < shapeCount; i++) 
		{
			if (shapes[i].type == CIRCLE) 
			{
				DrawCircle(shapes[i].x, shapes[i].y, 5, shapes[i].color);
			}
			else 
			{
				DrawRectangle(shapes[i].x - 5, shapes[i].y - 5, 10, 10, shapes[i].color);
			}
		}

		// 处理鼠标输入
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && shapeCount < MAX_SHAPES) 
		{
			shapes[shapeCount] = (Shape){ CIRCLE, GetMouseX(), GetMouseY(), RED };
			shapeCount++;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && shapeCount < MAX_SHAPES) 
		{
			shapes[shapeCount] = (Shape){ RECTANGLE, GetMouseX(), GetMouseY(), GREEN };
			shapeCount++;
		}

		//设置FPS
		SetTargetFPS(120);


		DrawCircle(100, 100, 10, RED);           //绘制圆形
		DrawRectangle(200, 200, 50, 50, GREEN);  //绘制矩形

		DrawCircle(x, y, 30, GREEN);


		EndDrawing();                 //绘制帧的结束

		//事件处理--- 鼠标事件 / 键盘时间
		if (IsKeyDown(KEY_LEFT) || IsKeyDown('A'))
		{
			x -= 1;
		}
		if (IsKeyDown(KEY_RIGHT) || IsKeyDown('D'))
		{
			x += 1;
		}
		if (IsKeyDown(KEY_UP) || IsKeyDown('W'))
		{
			y -= 1;
		}
		if (IsKeyDown(KEY_DOWN) || IsKeyDown('S'))
		{
			y += 1;
		}
		if (IsKeyDown(KEY_ESCAPE))
		{
			break;
		}



	}
	CloseWindow();  //关闭窗口
	return 0;
}