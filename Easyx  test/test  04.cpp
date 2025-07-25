//Ŀ�꣺   ��֡��ͼ����

#include<stdio.h>
#include<easyx.h>
#include"TransparentImage.h"
#include<time.h>

int main()
{
	initgraph(480, 800, EX_SHOWCONSOLE);
	setbkcolor(RGB(230, 231, 232));
	cleardevice();

	//����
	IMAGE img_enemy[4];
	
	/*loadimage(img_enemy + 0, "assets/enemy1_down1.png");
	loadimage(img_enemy + 1, "assets/enemy1_down2.png");
	loadimage(img_enemy + 2, "assets/enemy1_down3.png");
	loadimage(img_enemy + 3, "assets/enemy1_down4.png");*/
	//�Ż�
	char path[100] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		sprintf(path, "assets/enemy1_down%d.png", i + 1);
		loadimage(img_enemy + i, path);
	}


	const int frameDelay = 1000 / 60;   //�ӳ�ʱ��(FPS)
	int frameStart = 0;
	int frameTime = 0;

	int index = 0;
	int frames = 4;     //��¼��������֡���������������а�����ͼƬ������
	int speed = 200;    //ÿ��200�����л�һ֡
	while (true)
	{
		frameStart = clock();

		BeginBatchDraw();
		cleardevice();

		drawImg(0, 0, img_enemy+index);

		EndBatchDraw();

		/*index++;
		if (index >= 4)
		{
			index = 0;
		}*/
		//�Ż�
		//index = (index + 1) % 4;
		
		index = (clock() / speed) % frames;        //ÿ��speed����index����1.
		                                           //��Ϊclock�Ǵӳ���ʼ�������õ�ʱ��(����)
		                                           //���� ��0-200����Ҫ200���룬index�Ż��1.
		                                           //���Զ����ٶȿ��Ա���˿���
		 
		frameTime = clock() - frameStart;
		if (frameDelay - frameStart > 0)
		{
			Sleep(frameDelay - frameTime);
		}
	}
	

	getchar();
	return 0;
}
