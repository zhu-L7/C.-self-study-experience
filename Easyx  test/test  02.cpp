//Ŀ�꣺   ���� / ˫���� / ֡�ʿ���.

#include<stdio.h>
#include<easyx.h>
#include<time.h>

int main()
{
	//��������
	initgraph(640, 480, EX_SHOWCONSOLE);
	setbkcolor(RGB(230, 231, 232));
	cleardevice();                  //����--�����õı�����ɫ�����������.
	setbkmode(TRANSPARENT);


	//FPS--֡��
	const clock_t FPS = 1000 / 60;    //1��=1000���룬1000/60��ʾ�ľ���ÿһ֡���ѵĺ��룬��Լ����16.7����(���ξ���16����).
	int startTime = 0;
	int freamTime = 0;              

	int score = 0;
	char str[50] = "";              //һ��Ҫ�Ѵ�С�����һ�㣬��Ȼ���׵��³������(��һ��Ǳ�ڵ�bug).
	while (true)
	{
		startTime = clock();        //�������е�����������������ѵ�ʱ��(����).

		sprintf(str, "Score:%d", score++);
		settextcolor(BLACK);

		//˫����--��ֹ����(ԭ�����Ȱ����ݷŽ�����������һ���԰�ȫ�����ݴ�������).
		BeginBatchDraw();
		cleardevice();
		outtextxy(20, 20, str);

		EndBatchDraw();

		freamTime = clock()- startTime;        //��ǰ֡ʵ��ִ�е�ʱ��(����).
		if (freamTime > 0)
		{
			Sleep(FPS - freamTime);
		}

	}
	
	return 0;
}