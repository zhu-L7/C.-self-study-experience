//  Ŀ�꣺  ���ֺ���Ч

#include<stdio.h>
#include<raylib.h>  //����ת������鿴 ���� �ṹ�� ��ض���
#include<time.h>
#include<stdlib.h>

int main()
{
	InitAudioDevice();  //��ʼ����Ƶ�豸
	InitWindow(800, 600, "test_raylib");  //��������

	Music m = LoadMusicStream("./assets/�ζ�Ұ - ������.ogg");  //��������
	PlayMusicStream(m);  //��������

	Sound s = LoadSound("./assets/button.wav");  //������Ч

	while (!WindowShouldClose())
	{

		BeginDrawing();               //����֡�Ŀ�ʼ

		EndDrawing();                 //����֡�Ľ���
		UpdateMusicStream(m);  //���ϸ���������

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			PlaySound(s);  //������Ч
		}
	}

	CloseWindow();       //�رմ���
	CloseAudioDevice();  //�ر���Ƶ�豸
	return 0;
}