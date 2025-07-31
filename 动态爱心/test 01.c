#include<stdio.h>
#include"raylib.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

//绘制数字雨

//数字雨字符串
static const char* ILoveYou = "ILoveYouLIkeYou";

//数字雨字符串长度
#define ILoveYouLEN 16

//数字雨每个字符的大小
#define RAIN_CHAR_SIZE 15

//数字雨的个数
#define RAIN_NUM 80

//数字雨结构
typedef struct Rain        //typedef 是一个关键字，用于为已有的数据类型（包括结构体、枚举、指针等）定义一个新的别名（别名类型）
                           //目的是简化类型的使用，提高代码的可读性和可维护性
	                       //例如：后续可以声明Rain结构体变量时可以直接写  Rain m;
						   //                 如果没有typedef的话就需要写  struct Rain m;
{
	int x;
	int y;
	char str[ILoveYouLEN];
	int speed; //下落速度
}Rain;

//数字雨数组
Rain rains[RAIN_NUM];

//初始化
void init()
{
	//设置帧率
	//SetTargetFPS(60);

	//数字雨
	for (int i = 0; i < RAIN_NUM; i++)
	{
		rains[i].x = i * RAIN_CHAR_SIZE;//横向等距排列
		rains[i].y = GetRandomValue(-200, 700);//raylib自带的生成随机数的函数，生成随机坐标在-200到700之间.
		TextCopy(rains[i].str, ILoveYou);

		rains[i].speed = GetRandomValue(2, 4);//生成随机速度1到3之间.
	}
}

//绘制文本
void draw()
{
	//绘制
	char ch[2] = {0};
	for (int i = 0; i < RAIN_NUM;i++)
	{
		for (int k = 0; k < RAIN_CHAR_SIZE; k++)
		{
			ch[0] = rains[i].str[k];
			DrawText(ch, rains[i].x, rains[i].y + k * RAIN_CHAR_SIZE, RAIN_CHAR_SIZE, 
				CLITERAL(Color){255/ILoveYouLEN*k,130/ILoveYouLEN*k,255/ILoveYouLEN*k,255});//渐变色
		}
		
		//数字雨往下落
		rains[i].y += rains[i].speed;

		//循环下落
		if (rains[i].y > GetRenderHeight())
		{
			rains[i].y = -ILoveYouLEN * RAIN_CHAR_SIZE;
			rains[i].speed = GetRandomValue(2, 4);
		}

		//随机改变数字雨字符
		rains[i].str[GetRandomValue(0, ILoveYouLEN - 1)] = ILoveYou[GetRandomValue(0, ILoveYouLEN - 1)];
	}

}

//  绘制爱心

// 点结构体，包含坐标和颜色信息
typedef struct {
    double x, y;
    Color color;
} Point;

// 定义常量
#define X_SCREEN 1200
#define Y_SCREEN 800
#define PI 3.1426535159
#define E 2.71828
#define AVERAG_DISTANCE 0.162
#define QUANTITY 506
#define CIRCLES 210
#define FRAMES 20

// 定义一组颜色，用于绘制心形
Color colors[7] = {
    {255, 32, 83, 255},    // 粉红色
    {252, 222, 250, 255},  // 浅粉色
    {255, 0, 0, 255},      // 红色
    {255, 0, 0, 255},      // 红色
    {255, 2, 2, 255},      // 亮红色
    {255, 0, 8, 255},      // 深红色
    {255, 5, 5, 255}       // 深红色
};

// 全局数组
Point origin_points[QUANTITY];  // 存储心形的基础点
Point points[CIRCLES * QUANTITY];  // 存储所有动画点
RenderTexture2D frames_texture[FRAMES];  // 存储每一帧的图像

// 将数学坐标系X坐标转换为屏幕坐标系
double screen_x(double x)
{
    return x + X_SCREEN / 2;
}

// 将数学坐标系Y坐标转换为屏幕坐标系
double screen_y(double y)
{
    return -y + Y_SCREEN / 2;
}

// 生成指定范围内的随机整数
int creat_random(int x1, int x2)
{
    if (x2 > x1)
        return rand() % (x2 - x1 + 1) + x1;
    return x1;  // 处理x2 <= x1的情况
}

// 创建心形数据并生成动画帧
void creat_data()
{
    int index = 0;
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    // 生成心形基础点
    for (double radian = 0.1; radian <= 2 * PI; radian += 0.005)
    {
        // 心形线的参数方程
        x2 = 16 * pow(sin(radian), 3);
        y2 = 13 * cos(radian) - 5 * cos(2 * radian) - 2 * cos(3 * radian) - cos(4 * radian);

        // 计算距离，控制基础点密度
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if (distance > AVERAG_DISTANCE)
        {
            x1 = x2;
            y1 = y2;
            origin_points[index].x = x2;
            origin_points[index++].y = y2;
        }
    }

    // 生成动画点
    index = 0;
    for (double size = 0.1; size <= 20; size += 0.1)
    {
        // 计算点出现的概率，随size增大而增大
        double success_p = 1 / (1 + pow(E, 8 - size / 2));

        // 为每个基础点生成动画点
        for (int i = 0; i < QUANTITY; ++i)
        {
            if (success_p > (double)creat_random(0, 100) / 100.0)
            {
                points[index].color = colors[creat_random(0, 6)];

                // 随机偏移生成动画点
                points[index].x = size * origin_points[i].x + creat_random(-4, 4);
                points[index++].y = size * origin_points[i].y + creat_random(-4, 4);
            }
        }
    }

    int points_size = index;

    // 初始化所有帧的渲染纹理
    for (int frame = 0; frame < FRAMES; frame++)
    {
        frames_texture[frame] = LoadRenderTexture(X_SCREEN, Y_SCREEN);
    }

    // 生成动画帧
    for (int frame = 0; frame < FRAMES; ++frame)
    {
        // 开始渲染到纹理
        BeginTextureMode(frames_texture[frame]);
        ClearBackground(BLACK);  // 黑色背景

        // 绘制所有动画点
        for (index = 0; index < points_size; ++index)
        {
            double x = points[index].x, y = points[index].y;
            double distance = sqrt(pow(x, 2) + pow(y, 2));

            // 计算点的移动距离
            double distance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;
            double x_increase = distance_increase * x / distance / FRAMES;
            double y_increase = distance_increase * y / distance / FRAMES;

            // 更新点位置并绘制
            points[index].x += x_increase;
            points[index].y += y_increase;
            DrawPixelV(
                (Vector2) {
                (float)screen_x(points[index].x), (float)screen_y(points[index].y)
            },
                points[index].color
            );
        }

        // 在特定大小范围内随机生成点，增强动画效果
        for (double size = 17; size < 23; size += 0.3)
        {
            for (index = 0; index < QUANTITY; ++index)
            {
                if (((double)creat_random(0, 100) / 100.0 > 0.6 && size >= 20) ||
                    (size < 20 && (double)creat_random(0, 100) / 100.0 > 0.95))
                {
                    double x, y;
                    if (size >= 20)
                    {
                        // 大尺寸下更大的随机偏移
                        x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                        y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                    }
                    else
                    {
                        // 小尺寸下较小的随机偏移
                        x = origin_points[index].x * size + creat_random(-5, 5);
                        y = origin_points[index].y * size + creat_random(-5, 5);
                    }

                    DrawPixelV(
                        (Vector2) {
                        (float)screen_x(x), (float)screen_y(y)
                    },
                        colors[creat_random(0, 6)]
                    );
                }
            }
        }
        EndTextureMode();  // 结束渲染到纹理
    }
}

int main()
{
	//初始化图形窗口
	//InitWindow(1200, 800, "Dynamic love");
    InitWindow(X_SCREEN, Y_SCREEN, "Heart Animation");
   
    SetTargetFPS(30);  // 设置帧率
    srand((unsigned int)time(0));    // 设置随机数种子
    creat_data();      // 创建动画数据
	
    init();//初始化

    bool extend = true;
    int frame = 0;

	//主循环
	while (!WindowShouldClose())// 检测窗口是否需要关闭
	{
        // 控制动画播放方向（扩展和收缩）
        if (extend)
        {
            frame++;
            if (frame >= FRAMES - 1)
                extend = false;
        }
        else
        {
            frame--;
            if (frame <= 0)
                extend = true;
        }

		BeginDrawing();//开始绘图
        ClearBackground(BLACK);


        // 绘制当前帧（注意纹理需要翻转Y轴）
        DrawTexturePro(
            frames_texture[frame].texture,
            (Rectangle) {
            0, 0, (float)X_SCREEN, (float)-Y_SCREEN
        },  // 源矩形（翻转Y轴）
            (Rectangle) {
            0, 0, (float)X_SCREEN, (float)Y_SCREEN
        },   // 目标矩形
            (Vector2) {
            0, 0
        },  // 旋转中心
            0.0f,             // 旋转角度
            WHITE             //  tint颜色
        );

        draw();

		EndDrawing();//结束绘图
	}

    // 释放资源
    for (int i = 0; i < FRAMES; i++)
    {
        UnloadRenderTexture(frames_texture[i]);
    }

	CloseWindow();//关闭窗口
	return 0;
}


