#include<stdio.h>
#include<graphics.h>
#include <windows.h>
#include<time.h>
#include<stdlib.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib") //����winmm.lib��


//----��������
#define METEOR_NUM 100 //����������

IMAGE img_bk;	//����ͼƬ
IMAGE img_meteor[2];//����ͼƬ����

//����  ���� �ٶ�
struct Meteor
{
	int x;		//x����
	int y;		//y����
	int speed;	//�ٶ�
};


//----��������

//��������
void Music()
{
	mciSendString(L"open ./assets/��Ը������(����Ů����)-꿶�.mp3 alias bgm", NULL, 0, NULL); //�������ļ�
	mciSendString(L"play bgm repeat", NULL, 0, NULL); //��������
}

//����ͼƬ
void loadImage()
{
	//���ر���ͼƬ
	loadimage(&img_bk, L"./assets/bk.jpg", getwidth(), getheight());

	//��������ͼƬ
	loadimage(&img_meteor[0], L"./assets/1.png",32,32);
	loadimage(&img_meteor[1], L"./assets/2.png",32,32);
}

//�������ʼ��
void meteor_init(Meteor* pthis, int x, int y, int speed)
{
	pthis->x = x;
	pthis->y = y;
	pthis->speed = speed;
}

//����������
void meteor_draw(Meteor* pthis)
{
	putimage(pthis->x, pthis->y, img_meteor + rand() % 2, SRCPAINT);
}

//�������ƶ�
void meteor_update(Meteor* pthis)
{
	pthis->x += pthis->speed; //x��������
	pthis->y += pthis->speed; //y��������

	if (pthis->y > 600)
	{
		pthis->x = rand() % 1100 - 300;
		pthis->y = rand() % 840 - 300;
	}

}
//������
int main()
{
	//��������
	initgraph(1200, 800,EW_SHOWCONSOLE);
	// ��ͼ�δ����ö�---��Ҫ���� <windows.h> ���ҷ��ڴ�������֮��
    HWND hwnd = GetHWnd(); // EasyX �ṩ�Ļ�ȡ���ھ���ĺ���
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	//���ñ�����ɫ
	setbkcolor(WHITE);
	cleardevice();


	//����ͼƬ
	loadImage();
	
	//��������
	Music();

	//����
	Meteor meteors[METEOR_NUM];
	for (int i = 0; i < METEOR_NUM; i++)
	{
		int x = rand() % 1100 - 300;//-300~800
		int y = rand() % 840 - 300;//-300~540
		meteor_init(meteors + i, x, y, rand() % 2 + 1);
	}
	while (true)
	{
		//��ֹ����---˫����
		BeginBatchDraw();
		putimage(0, 0, &img_bk);//����

		for(int i=0;i<METEOR_NUM;i++)
		{
			meteor_draw(meteors + i);//��������
			meteor_update(meteors + i);//��������λ��
		}
		EndBatchDraw();
		Sleep(10); //��ʱ10����
	}

	getchar();//�ȴ��û�����,��ֹ��������
	return 0;
}