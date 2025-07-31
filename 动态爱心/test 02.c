//  ���� ��̬����



//  Easyx��
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
//// ��ṹ�壬�����������ɫ��Ϣ
//struct Point 
//{
//    double x, y;
//    COLORREF color;
//};
//
//// ����һ����ɫ�����ڻ�������
//COLORREF colors[7] = { RGB(255,32,83),RGB(252,222,250), RGB(255,0,0), RGB(255,0,0), RGB(255,2,2), RGB(255,0,8),  RGB(255,5,5) };
//const int xScreen = 1200;    // ��Ļ���
//const int yScreen = 800;     // ��Ļ�߶�
//const double PI = 3.1426535159;  // ��ֵ
//const double e = 2.71828;    // ��Ȼ����e
//const double averag_distance = 0.162;  // ��֮���ƽ������
//const int quantity = 506;    // ����������
//const int circles = 210;     // Բ�����������ڶ���Ч����
//const int frames = 20;       // ����֡��
//Point origin_points[quantity];  // �洢���εĻ�����
//Point points[circles * quantity];  // �洢���ж�����
//IMAGE images[frames];        // �洢ÿһ֡��ͼ��
//
//// ����ѧ����ϵX����ת��Ϊ��Ļ����ϵ
//double screen_x(double x)
//{
//    x += xScreen / 2;
//    return x;
//}
//
//// ����ѧ����ϵY����ת��Ϊ��Ļ����ϵ
//double screen_y(double y)
//{
//    y = -y + yScreen / 2;
//    return y;
//}
//
//// ����ָ����Χ�ڵ��������
//int creat_random(int x1, int x2)
//{
//    if (x2 > x1)
//        return rand() % (x2 - x1 + 1) + x1;
//}
//
//// �����������ݲ����ɶ���֡
//void creat_data()
//{
//    int index = 0;
//    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//
//    // �������λ�����
//    for (double radian = 0.1; radian <= 2 * PI; radian += 0.005)
//    {
//        // �����ߵĲ�������
//        x2 = 16 * pow(sin(radian), 3);
//        y2 = 13 * cos(radian) - 5 * cos(2 * radian) - 2 * cos(3 * radian) - cos(4 * radian);
//        
//        // ������룬���ƻ������ܶ�
//        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//        if (distance > averag_distance)
//        {
//            x1 = x2, y1 = y2;
//            origin_points[index].x = x2;
//            origin_points[index++].y = y2;
//        }
//    }
//
//    // ���ɶ�����
//    index = 0;
//    for (double size = 0.1, lightness = 1.5; size <= 20; size += 0.1)
//    {
//        // �������ֵĸ��ʣ���size���������
//        double success_p = 1 / (1 + pow(e, 8 - size / 2));
//        if (lightness > 1)lightness -= 0.0025;
//
//        // Ϊÿ�����������ɶ�����
//        for (int i = 0; i < quantity; ++i)
//        {
//            if (success_p > creat_random(0, 100) / 100.0)
//            {
//                points[index].color = colors[creat_random(0, 6)];
//                
//                // ���ƫ�����ɶ�����
//                points[index].x = size * origin_points[i].x + creat_random(-4, 4);
//                points[index++].y = size * origin_points[i].y + creat_random(-4, 4);
//            }
//        }
//    }
//
//    int points_size = index;
//
//    // ���ɶ���֡
//    for (int frame = 0; frame < frames; ++frame)
//    {
//        images[frame] = IMAGE(xScreen, yScreen);
//        SetWorkingImage(&images[frame]);
//
//        // �������ж�����
//        for (index = 0; index < points_size; ++index)
//        {
//            double x = points[index].x, y = points[index].y;
//            double distance = sqrt(pow(x, 2) + pow(y, 2));
//            
//            // �������ƶ�����
//            double diatance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;
//            double x_increase = diatance_increase * x / distance / frames;
//            double y_increase = diatance_increase * y / distance / frames;
//            
//            // ���µ�λ�ò�����
//            points[index].x += x_increase;
//            points[index].y += y_increase;
//            setfillcolor(points[index].color);
//            solidcircle(screen_x(points[index].x), screen_y(points[index].y), 1);
//
//        }
//
//        // ���ض���С��Χ��������ɵ㣬��ǿ����Ч��
//        for (double size = 17; size < 23; size += 0.3)
//        {
//            for (index = 0; index < quantity; ++index)
//            {
//                if ((creat_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && creat_random(0, 100) / 100.0 > 0.95))
//                {
//                    double x, y;
//                    if (size >= 20)
//                    {
//                        // ��ߴ��¸�������ƫ��
//                        x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
//                        y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
//                    }
//                    else
//                    {
//                        // С�ߴ��½�С�����ƫ��
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
////������
//int main()
//{
//    initgraph(xScreen, yScreen);      // ��ʼ��ͼ�δ���
//    BeginBatchDraw();                 // ��ʼ������ͼ
//    srand(time(0));                   // �������������
//    creat_data();                     // ������������
//    SetWorkingImage();                // ���õ�ǰ����ͼ��
//
//    bool extend = true, shrink = false;  // ���ƶ�����չ/����״̬
//
//    // ѭ�����Ŷ�������������˳�
//    for (int frame = 0; !_kbhit();)
//    {
//        putimage(0, 0, &images[frame]); // ��ʾ��ǰ֡
//        FlushBatchDraw();               // ˢ����Ļ
//        Sleep(20);                      // ��ʱ20����
//        cleardevice();                  // �����ǰͼ��
//
//        // ���ƶ������ŷ���
//        if (extend)
//            frame == 19 ? (shrink = true, extend = false) : ++frame;
//        else
//            frame == 0 ? (shrink = false, extend = true) : --frame;
//
//    }
//    EndBatchDraw();  // ����������ͼ
//    closegraph();    // �ر�ͼ�δ���
//    return 0;
//
//}
////�õ�VS2022��������ʾ��easyX��cpp�ļ������ã�������ö���Դ�ļ�Ϊ.cpp�ļ�


//  Raylib��

#define _CRT_SECURE_NO_WARNINGS 1
#include <raylib.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

// ��ṹ�壬�����������ɫ��Ϣ
typedef struct {
    double x, y;
    Color color;
} Point;

// ���峣��
#define X_SCREEN 1200
#define Y_SCREEN 800
#define PI 3.1426535159
#define E 2.71828
#define AVERAG_DISTANCE 0.162
#define QUANTITY 506
#define CIRCLES 210
#define FRAMES 20

// ����һ����ɫ�����ڻ�������
Color colors[7] = {
    {255, 32, 83, 255},    // �ۺ�ɫ
    {252, 222, 250, 255},  // ǳ��ɫ
    {255, 0, 0, 255},      // ��ɫ
    {255, 0, 0, 255},      // ��ɫ
    {255, 2, 2, 255},      // ����ɫ
    {255, 0, 8, 255},      // ���ɫ
    {255, 5, 5, 255}       // ���ɫ
};

// ȫ������
Point origin_points[QUANTITY];  // �洢���εĻ�����
Point points[CIRCLES * QUANTITY];  // �洢���ж�����
RenderTexture2D frames_texture[FRAMES];  // �洢ÿһ֡��ͼ��

// ����ѧ����ϵX����ת��Ϊ��Ļ����ϵ
double screen_x(double x)
{
    return x + X_SCREEN / 2;
}

// ����ѧ����ϵY����ת��Ϊ��Ļ����ϵ
double screen_y(double y)
{
    return -y + Y_SCREEN / 2;
}

// ����ָ����Χ�ڵ��������
int creat_random(int x1, int x2)
{
    if (x2 > x1)
        return rand() % (x2 - x1 + 1) + x1;
    return x1;  // ����x2 <= x1�����
}

// �����������ݲ����ɶ���֡
void creat_data()
{
    int index = 0;
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    // �������λ�����
    for (double radian = 0.1; radian <= 2 * PI; radian += 0.005)
    {
        // �����ߵĲ�������
        x2 = 16 * pow(sin(radian), 3);
        y2 = 13 * cos(radian) - 5 * cos(2 * radian) - 2 * cos(3 * radian) - cos(4 * radian);

        // ������룬���ƻ������ܶ�
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if (distance > AVERAG_DISTANCE)
        {
            x1 = x2;
            y1 = y2;
            origin_points[index].x = x2;
            origin_points[index++].y = y2;
        }
    }

    // ���ɶ�����
    index = 0;
    for (double size = 0.1; size <= 20; size += 0.1)
    {
        // �������ֵĸ��ʣ���size���������
        double success_p = 1 / (1 + pow(E, 8 - size / 2));

        // Ϊÿ�����������ɶ�����
        for (int i = 0; i < QUANTITY; ++i)
        {
            if (success_p > (double)creat_random(0, 100) / 100.0)
            {
                points[index].color = colors[creat_random(0, 6)];

                // ���ƫ�����ɶ�����
                points[index].x = size * origin_points[i].x + creat_random(-4, 4);
                points[index++].y = size * origin_points[i].y + creat_random(-4, 4);
            }
        }
    }

    int points_size = index;

    // ��ʼ������֡����Ⱦ����
    for (int frame = 0; frame < FRAMES; frame++)
    {
        frames_texture[frame] = LoadRenderTexture(X_SCREEN, Y_SCREEN);
    }

    // ���ɶ���֡
    for (int frame = 0; frame < FRAMES; ++frame)
    {
        // ��ʼ��Ⱦ������
        BeginTextureMode(frames_texture[frame]);
        ClearBackground(BLACK);  // ��ɫ����

        // �������ж�����
        for (index = 0; index < points_size; ++index)
        {
            double x = points[index].x, y = points[index].y;
            double distance = sqrt(pow(x, 2) + pow(y, 2));

            // �������ƶ�����
            double distance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;
            double x_increase = distance_increase * x / distance / FRAMES;
            double y_increase = distance_increase * y / distance / FRAMES;

            // ���µ�λ�ò�����
            points[index].x += x_increase;
            points[index].y += y_increase;
            DrawPixelV(
                (Vector2) {
                (float)screen_x(points[index].x), (float)screen_y(points[index].y)
            },
                points[index].color
            );
        }

        // ���ض���С��Χ��������ɵ㣬��ǿ����Ч��
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
                        // ��ߴ��¸�������ƫ��
                        x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                        y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                    }
                    else
                    {
                        // С�ߴ��½�С�����ƫ��
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
        EndTextureMode();  // ������Ⱦ������
    }
}

// ������
int main()
{
    // ��ʼ�����ں�ͼ�ο�
    InitWindow(X_SCREEN, Y_SCREEN, "Heart Animation");
    SetTargetFPS(30);  // ����֡��
    srand((unsigned int)time(0));    // �������������
    creat_data();      // ������������

    bool extend = true;
    int frame = 0;

    // ��ѭ��
    while (!WindowShouldClose())  // ��ⴰ���Ƿ���Ҫ�ر�
    {
        // ���ƶ������ŷ�����չ��������
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

        // ��ʼ����
        BeginDrawing();
        ClearBackground(BLACK);

        // ���Ƶ�ǰ֡��ע��������Ҫ��תY�ᣩ
        DrawTexturePro(
            frames_texture[frame].texture,
            (Rectangle) {
            0, 0, (float)X_SCREEN, (float)-Y_SCREEN
        },  // Դ���Σ���תY�ᣩ
            (Rectangle) {
            0, 0, (float)X_SCREEN, (float)Y_SCREEN
        },   // Ŀ�����
            (Vector2) {
            0, 0
        },  // ��ת����
            0.0f,             // ��ת�Ƕ�
            WHITE             //  tint��ɫ
        );

        EndDrawing();
    }

    // �ͷ���Դ
    for (int i = 0; i < FRAMES; i++)
    {
        UnloadRenderTexture(frames_texture[i]);
    }
    CloseWindow();  // �رմ���
    return 0;
}
