#include<stdio.h>
#include"raylib.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

//����������

//�������ַ���
static const char* ILoveYou = "ILoveYouLIkeYou";

//�������ַ�������
#define ILoveYouLEN 16

//������ÿ���ַ��Ĵ�С
#define RAIN_CHAR_SIZE 15

//������ĸ���
#define RAIN_NUM 80

//������ṹ
typedef struct Rain        //typedef ��һ���ؼ��֣�����Ϊ���е��������ͣ������ṹ�塢ö�١�ָ��ȣ�����һ���µı������������ͣ�
                           //Ŀ���Ǽ����͵�ʹ�ã���ߴ���Ŀɶ��ԺͿ�ά����
	                       //���磺������������Rain�ṹ�����ʱ����ֱ��д  Rain m;
						   //                 ���û��typedef�Ļ�����Ҫд  struct Rain m;
{
	int x;
	int y;
	char str[ILoveYouLEN];
	int speed; //�����ٶ�
}Rain;

//����������
Rain rains[RAIN_NUM];

//��ʼ��
void init()
{
	//����֡��
	//SetTargetFPS(60);

	//������
	for (int i = 0; i < RAIN_NUM; i++)
	{
		rains[i].x = i * RAIN_CHAR_SIZE;//����Ⱦ�����
		rains[i].y = GetRandomValue(-200, 700);//raylib�Դ�������������ĺ������������������-200��700֮��.
		TextCopy(rains[i].str, ILoveYou);

		rains[i].speed = GetRandomValue(2, 4);//��������ٶ�1��3֮��.
	}
}

//�����ı�
void draw()
{
	//����
	char ch[2] = {0};
	for (int i = 0; i < RAIN_NUM;i++)
	{
		for (int k = 0; k < RAIN_CHAR_SIZE; k++)
		{
			ch[0] = rains[i].str[k];
			DrawText(ch, rains[i].x, rains[i].y + k * RAIN_CHAR_SIZE, RAIN_CHAR_SIZE, 
				CLITERAL(Color){255/ILoveYouLEN*k,130/ILoveYouLEN*k,255/ILoveYouLEN*k,255});//����ɫ
		}
		
		//������������
		rains[i].y += rains[i].speed;

		//ѭ������
		if (rains[i].y > GetRenderHeight())
		{
			rains[i].y = -ILoveYouLEN * RAIN_CHAR_SIZE;
			rains[i].speed = GetRandomValue(2, 4);
		}

		//����ı��������ַ�
		rains[i].str[GetRandomValue(0, ILoveYouLEN - 1)] = ILoveYou[GetRandomValue(0, ILoveYouLEN - 1)];
	}

}

//  ���ư���

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

int main()
{
	//��ʼ��ͼ�δ���
	//InitWindow(1200, 800, "Dynamic love");
    InitWindow(X_SCREEN, Y_SCREEN, "Heart Animation");
   
    SetTargetFPS(30);  // ����֡��
    srand((unsigned int)time(0));    // �������������
    creat_data();      // ������������
	
    init();//��ʼ��

    bool extend = true;
    int frame = 0;

	//��ѭ��
	while (!WindowShouldClose())// ��ⴰ���Ƿ���Ҫ�ر�
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

		BeginDrawing();//��ʼ��ͼ
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

        draw();

		EndDrawing();//������ͼ
	}

    // �ͷ���Դ
    for (int i = 0; i < FRAMES; i++)
    {
        UnloadRenderTexture(frames_texture[i]);
    }

	CloseWindow();//�رմ���
	return 0;
}


