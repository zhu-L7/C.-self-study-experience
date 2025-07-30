//  Ŀ�꣺  ���ڴ��� / ������ɫ / ����¼� / �����¼�

#include<stdio.h>
#include<raylib.h>  //����ת������鿴 ���� �ṹ�� ��ض���
#include<time.h>
#include<stdlib.h>

// �������ͼ������
#define MAX_SHAPES 1000

// ͼ������ö��
typedef enum 
{ 
	CIRCLE, RECTANGLE 
} ShapeType;

// ͼ�νṹ��
typedef struct 
{
	ShapeType type;
	int x, y;
	Color color;
} Shape;

// ͼ������
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
	srand((unsigned int)time(NULL));  //�����������Ӻ�ʱ�佨����ϵ������������ǹ̶���

	int x = 40;
	int y = 40;

	InitWindow(800, 600, "test_raylib");  //��������

	while (!WindowShouldClose())  //WindowShouldClose()����û��Ƿ�����رմ���
		                          //   ����ֵ�� true������رմ���(������ڹرհ�ť�����ض��ļ��̰�������esc)
								  //            false��û������رմ��ڣ�������Ȼ���ִ�״̬
	{
		//��ͼ
		BeginDrawing();               //����֡�Ŀ�ʼ
        //��ͼ����
		Color color = { 128,0,225 };  //������ɫ
		ClearBackground(BLACK);       //ˢ�±���(����)---���ñ�����ɫ

		//for (int i = 0; i < 1000; i++)
		//{
		//	x = rand() % 800;
		//	y = rand() % 600;
		//	DrawPixel(x, y, WHITE);  //���Ƶ�
		//}

		//�����Բ �Ҽ�����---���ַ���������ע�͵�ClearBackground(BLACK)
		//��Ȼ����ͨ��ע�͵� ClearBackground() ����ͼ�Σ�����ᵼ�£�
        //                 �������⣨ÿ֡�ۻ����Ƶ�ͼ��Խ��Խ�ࣩ
	    //                 �޷�ʵ�ֲ������޸�����ͼ�εĹ���
		//                 ���ܳ�����Ⱦ�쳣���細�ڱ��ڵ����ػ治������
		// 
		//if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		//{
		//	DrawCircle(GetMouseX(), GetMouseY(), 5, RED);
		//}
		//if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		//{
		//	DrawRectangle(GetMouseX()-5, GetMouseY()-5, 10,10, GREEN);
		//}

		// ���������ѱ����ͼ��---�Ȱ��û����Ƶ�ͼ����Ϣ�浽�����Ȼ����ÿһ֡��Ⱦʱ���������е�����ͼ�����»��Ƴ�����
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

		// �����������
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

		//����FPS
		SetTargetFPS(120);


		DrawCircle(100, 100, 10, RED);           //����Բ��
		DrawRectangle(200, 200, 50, 50, GREEN);  //���ƾ���

		DrawCircle(x, y, 30, GREEN);


		EndDrawing();                 //����֡�Ľ���

		//�¼�����--- ����¼� / ����ʱ��
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
	CloseWindow();  //�رմ���
	return 0;
}