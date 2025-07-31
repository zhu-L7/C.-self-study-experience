//  绘制 动态爱心



//  Easyx版
// 
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <graphics.h>
//#include <time.h>
//#include <math.h>
//#include <stdlib.h>
//#include <conio.h>
//
//// 点结构体，包含坐标和颜色信息
//struct Point 
//{
//    double x, y;
//    COLORREF color;
//};
//
//// 定义一组颜色，用于绘制心形
//COLORREF colors[7] = { RGB(255,32,83),RGB(252,222,250), RGB(255,0,0), RGB(255,0,0), RGB(255,2,2), RGB(255,0,8),  RGB(255,5,5) };
//const int xScreen = 1200;    // 屏幕宽度
//const int yScreen = 800;     // 屏幕高度
//const double PI = 3.1426535159;  // π值
//const double e = 2.71828;    // 自然常数e
//const double averag_distance = 0.162;  // 点之间的平均距离
//const int quantity = 506;    // 基础点数量
//const int circles = 210;     // 圆的数量（用于动画效果）
//const int frames = 20;       // 动画帧数
//Point origin_points[quantity];  // 存储心形的基础点
//Point points[circles * quantity];  // 存储所有动画点
//IMAGE images[frames];        // 存储每一帧的图像
//
//// 将数学坐标系X坐标转换为屏幕坐标系
//double screen_x(double x)
//{
//    x += xScreen / 2;
//    return x;
//}
//
//// 将数学坐标系Y坐标转换为屏幕坐标系
//double screen_y(double y)
//{
//    y = -y + yScreen / 2;
//    return y;
//}
//
//// 生成指定范围内的随机整数
//int creat_random(int x1, int x2)
//{
//    if (x2 > x1)
//        return rand() % (x2 - x1 + 1) + x1;
//}
//
//// 创建心形数据并生成动画帧
//void creat_data()
//{
//    int index = 0;
//    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//
//    // 生成心形基础点
//    for (double radian = 0.1; radian <= 2 * PI; radian += 0.005)
//    {
//        // 心形线的参数方程
//        x2 = 16 * pow(sin(radian), 3);
//        y2 = 13 * cos(radian) - 5 * cos(2 * radian) - 2 * cos(3 * radian) - cos(4 * radian);
//        
//        // 计算距离，控制基础点密度
//        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//        if (distance > averag_distance)
//        {
//            x1 = x2, y1 = y2;
//            origin_points[index].x = x2;
//            origin_points[index++].y = y2;
//        }
//    }
//
//    // 生成动画点
//    index = 0;
//    for (double size = 0.1, lightness = 1.5; size <= 20; size += 0.1)
//    {
//        // 计算点出现的概率，随size增大而增大
//        double success_p = 1 / (1 + pow(e, 8 - size / 2));
//        if (lightness > 1)lightness -= 0.0025;
//
//        // 为每个基础点生成动画点
//        for (int i = 0; i < quantity; ++i)
//        {
//            if (success_p > creat_random(0, 100) / 100.0)
//            {
//                points[index].color = colors[creat_random(0, 6)];
//                
//                // 随机偏移生成动画点
//                points[index].x = size * origin_points[i].x + creat_random(-4, 4);
//                points[index++].y = size * origin_points[i].y + creat_random(-4, 4);
//            }
//        }
//    }
//
//    int points_size = index;
//
//    // 生成动画帧
//    for (int frame = 0; frame < frames; ++frame)
//    {
//        images[frame] = IMAGE(xScreen, yScreen);
//        SetWorkingImage(&images[frame]);
//
//        // 绘制所有动画点
//        for (index = 0; index < points_size; ++index)
//        {
//            double x = points[index].x, y = points[index].y;
//            double distance = sqrt(pow(x, 2) + pow(y, 2));
//            
//            // 计算点的移动距离
//            double diatance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;
//            double x_increase = diatance_increase * x / distance / frames;
//            double y_increase = diatance_increase * y / distance / frames;
//            
//            // 更新点位置并绘制
//            points[index].x += x_increase;
//            points[index].y += y_increase;
//            setfillcolor(points[index].color);
//            solidcircle(screen_x(points[index].x), screen_y(points[index].y), 1);
//
//        }
//
//        // 在特定大小范围内随机生成点，增强动画效果
//        for (double size = 17; size < 23; size += 0.3)
//        {
//            for (index = 0; index < quantity; ++index)
//            {
//                if ((creat_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && creat_random(0, 100) / 100.0 > 0.95))
//                {
//                    double x, y;
//                    if (size >= 20)
//                    {
//                        // 大尺寸下更大的随机偏移
//                        x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
//                        y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
//                    }
//                    else
//                    {
//                        // 小尺寸下较小的随机偏移
//                        x = origin_points[index].x * size + creat_random(-5, 5);
//                        y = origin_points[index].y * size + creat_random(-5, 5);
//                    }
//
//                    setfillcolor(colors[creat_random(0, 6)]);
//                    solidcircle(screen_x(x), screen_y(y), 1);
//                }
//
//
//                for (double size = 17; size < 23; size += 0.3)
//                {
//                    for (index = 0; index < quantity; ++index)
//                    {
//                        if ((creat_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && creat_random(0, 100) / 100.0 > 0.95))
//                        {
//                            double x, y;
//                            if (size >= 20)
//                            {
//                                x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
//                                y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
//                            }
//                            else
//                            {
//                                x = origin_points[index].x * size + creat_random(-5, 5);
//                                y = origin_points[index].y * size + creat_random(-5, 5);
//                            }
//                            setfillcolor(colors[creat_random(0, 6)]);
//                            solidcircle(screen_x(x), screen_y(y), 1);
//                        }
//                    }
//                }
//            }
//        }
//    }
//}
//
////主函数
//int main()
//{
//    initgraph(xScreen, yScreen);      // 初始化图形窗口
//    BeginBatchDraw();                 // 开始批量绘图
//    srand(time(0));                   // 设置随机数种子
//    creat_data();                     // 创建动画数据
//    SetWorkingImage();                // 设置当前工作图像
//
//    bool extend = true, shrink = false;  // 控制动画扩展/收缩状态
//
//    // 循环播放动画，按任意键退出
//    for (int frame = 0; !_kbhit();)
//    {
//        putimage(0, 0, &images[frame]); // 显示当前帧
//        FlushBatchDraw();               // 刷新屏幕
//        Sleep(20);                      // 延时20毫秒
//        cleardevice();                  // 清除当前图像
//
//        // 控制动画播放方向
//        if (extend)
//            frame == 19 ? (shrink = true, extend = false) : ++frame;
//        else
//            frame == 0 ? (shrink = false, extend = true) : --frame;
//
//    }
//    EndBatchDraw();  // 结束批量绘图
//    closegraph();    // 关闭图形窗口
//    return 0;
//
//}
////用的VS2022，上面显示的easyX是cpp文件才能用，所以需得定义源文件为.cpp文件


//  Raylib版

#define _CRT_SECURE_NO_WARNINGS 1
#include <raylib.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

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

// 主函数
int main()
{
    // 初始化窗口和图形库
    InitWindow(X_SCREEN, Y_SCREEN, "Heart Animation");
    SetTargetFPS(30);  // 设置帧率
    srand((unsigned int)time(0));    // 设置随机数种子
    creat_data();      // 创建动画数据

    bool extend = true;
    int frame = 0;

    // 主循环
    while (!WindowShouldClose())  // 检测窗口是否需要关闭
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

        // 开始绘制
        BeginDrawing();
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

        EndDrawing();
    }

    // 释放资源
    for (int i = 0; i < FRAMES; i++)
    {
        UnloadRenderTexture(frames_texture[i]);
    }
    CloseWindow();  // 关闭窗口
    return 0;
}
