//  Ŀ�꣺  ��ͼ

#include<stdio.h>
#include<raylib.h>  //����ת������鿴 ���� �ṹ�� ��ض���
#include<time.h>
#include<stdlib.h>

int main()
{
	InitWindow(800, 600, "test_raylib");  //��������

	//����һ��
	Texture img = LoadTexture("./assets/ͷ��.jpeg");  //ֱ�Ӱ�·�����ص�Texture������
	//img.width=400;   ��DrawTexture����ʹ��
	//img.height=400;

	//��������
	//Image image = LoadImage("./assets/ͷ��.jpeg");  //��·�����ص�image�У��ٰ�image���ص�Texture������
	//Texture img = LoadTextureFromImage(image);

	//ע�⣺����(Texture)�����д��ڵ�ǰ���²��ܴ�������Image���ô���Ҳ�ܼ���.

	while (!WindowShouldClose())
	{

		BeginDrawing();               //����֡�Ŀ�ʼ

		//DrawTexture(img, 0, 0, WHITE);  //��ͼ
		
		Vector2 pos = { 0,0 };
		//DrawTextureEx(img, pos, 0, 0.5, WHITE);  //��ͼ���Ű�

		Rectangle src = { 0,0,400,400 };  //��ʾͼƬ��ĳһ����
		DrawTextureRec(img, src, pos, WHITE);

		EndDrawing();                 //����֡�Ľ���

	}

	UnloadTexture(img);  //�ͷ�
	CloseWindow();       //�رմ���
	return 0;
}