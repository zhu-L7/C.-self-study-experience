#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<mmsystem.h>//��ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��ý���豸�ӿڿ��ļ�

#define PI 3.1415
#define WIDTH 960
#define HEIGHT 640
#define NUM 13    //�̻�������

struct Jet
{
	int x, y;        //����
	int hx, hy;     //��ߵ�����
	bool isLaunch;  //�̻����Ƿ���
	IMAGE img[2];
	byte n : 1;     //λ��
}jet[NUM];

struct Fire
{
	int x;
	int y;
	int cen_x, cen_y;     //���ĵ�����
	int r;                //��ǰ���ŵİ뾶
	int max_r;            //������Ű뾶
	int width, height;
	DWORD pixel[240][240];//ͼƬ��������
	bool isShow;          //�̻��Ƿ�׼����
	bool isDraw;          //�Ƿ�����̻�
}fire[NUM];


//�������� ��������
void welcome()
{
	mciSendString(L"open ./assets/С����.mp3", 0, 0, 0);//��������
	mciSendString(L"play ./assets/С����.mp3", 0, 0, 0);

	for (int i = 0; i < 50; i++)
	{
		cleardevice();//����

		int x = 500 + 180 * sin(2 * PI / 60 * i);//�����˶��켣
		int y = 200 + 180 * cos(2 * PI / 60 * i);

		//��������
		settextstyle(i, 0, L"����Բ��");//��ʽ
		settextcolor(RGB(0, 202, 0));//��ɫ
		setbkmode(TRANSPARENT);//����͸������
		outtextxy(x, y, L"�����̻�����");//�ı�
		Sleep(20);
	}
	_getch();//�����������(�ڿ��ƴ��ڰ�)
	cleardevice();
	settextstyle(30, 0, L"����");
	outtextxy(250, 100, L"�װ���XXX");
	outtextxy(300, 150, L"1111111");
	outtextxy(300, 200, L"2222222");
	outtextxy(300, 250, L"3333333");
	outtextxy(300, 300, L"4444444");
	outtextxy(300, 350, L"5555555");
	outtextxy(450, 400, L"--XXX");

}

void Init_fire(int i)
{
	//��ʼ���̻�
	fire[i].cen_x = 120; //��������
	fire[i].cen_y = 120;
	fire[i].max_r = 120; //������Ű뾶
	fire[i].r = 0;       //�ʼ���Ű뾶
	fire[i].width = 240;
	fire[i].height = 240;
	fire[i].isDraw = false;
	fire[i].isShow = false;
}

//ͼƬ
void loadImg()
{
	//��ʼ���̻���
	IMAGE jetImg;
	loadimage(&jetImg, L"./assets/shoot.jpg", 200, 50);

	SetWorkingImage(&jetImg); //SetWorkingImage() �� EasyX �е�һ���������������õ�ǰ��ͼ�豸����������ͼ������Ŀ�꣩
	for (int i = 0; i < NUM; i++)
	{
		int n = rand() % 5;
		getimage(&jet[i].img[0], n * 20, 0, 20, 50);     //��ɫ
		getimage(&jet[i].img[1], n * 20 + 100, 0, 20, 50); //��ɫ

		jet[i].isLaunch = false;
	}
	SetWorkingImage();        // �ָ���ͼĿ��Ϊ��Ļ

	//��ʼ���̻�����
	IMAGE bloomImg, tImg;
	loadimage(&bloomImg, L"./assets/flower.jpg", 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		Init_fire(i); //��ʼ���̻�

		//��ȡ����
		SetWorkingImage(&bloomImg);
		getimage(&tImg, i * 240, 0, 240, 240l);//��ȡbloomImg�е�ͼƬ��һ������������ʱͼ��tImg��
		SetWorkingImage(&tImg);
		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				// ��ȡ (a, b) �����������ɫ�������浽 fire[i].pixel ������
				fire[i].pixel[a][b] = getpixel(a, b);  //getpixel ���ڻ�ȡָ�����괦��������ɫ������ֵ��һ�� COLORREF ���͵���ɫֵ������ RGB ��Ϣ��
			}
		}
	}
	SetWorkingImage();        // �ָ���ͼĿ��Ϊ��Ļ

}

//�����̻���
void createJet()
{
	int i = rand() % NUM;//[0��13)
	if (jet[i].isLaunch == false)
	{
		jet[i].x = rand() % (WIDTH - 20);//�̻�����
		jet[i].y = rand() % 100 + HEIGHT;
		jet[i].hx = jet[i].x;//�̻�����ʱ����
		jet[i].hy = rand() % (HEIGHT / 3 * 2);

		jet[i].isLaunch = true;
	}
}

//�����̻���
void launch()
{
	for (int i = 0; i < NUM; i++)
	{
		if (jet[i].isLaunch)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);//��ʱ�̻���������һ֡��λ�ã����ú�������ģʽ �������� ��λ�õľ�ͼ�񣨻ָ�������

			//�ж��Ƿ񵽴���ߵ�
			if (jet[i].y > jet[i].hy)
			{
				jet[i].y -= 5;
				jet[i].n++;    //ʵ�ְ�ɫ����ɫ�Ĳ����л�����Ϊ n �� 1 λλ�Σ���ȡֵֻ���� 0 �� 1��
							   //�� n = 0 ʱ��n++ ��ʹ���Ϊ 1//��n = 1ʱ��n++�������(1λ�������������ֵ��1����1����λ����)��Ϊ0	   
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);//�̻������ƶ�����λ�ã����ú�������ģʽ����λ�û��Ƹ��º��ͼ����ͼƬ��
			if (jet[i].y <= jet[i].hy)
			{
				jet[i].isLaunch = false;

				//��ʼ���̻�
				fire[i].x = jet[i].x;
				fire[i].y = jet[i].y;
				fire[i].isShow = true;
			}
		}
	}
}

//�̻�����
void bloom(DWORD* pMem)
{
	for (int i = 0; i < NUM; i++)
	{
		if (fire[i].isShow)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].isDraw = true;//��ʼ�����̻�
			}
			if (fire[i].r >= fire[i].max_r)
			{
				Init_fire(i); //���³�ʼ���̻�
			}
		}
		if (fire[i].isDraw)//����
		{
			//��ǰ�뾶��Բ�ϵ�ÿ��������
			for (double a = 0; a <= 2 * PI; a += 0.01)
			{
				int img_x = fire[i].cen_x + fire[i].r * cos(a);//Բ�ϵ��x����
				int img_y = fire[i].cen_y + fire[i].r * sin(a);//Բ�ϵ��y����

				//�ж������Ƿ���ͼƬ��Χ��
				if(img_x>0 && img_x < fire[i].width && img_y > 0 && img_y < fire[i].height)
				{
					//���ŵ��Ӧ����Ļ����
					int win_x = fire[i].x + fire[i].r * cos(a);
					int win_y = fire[i].y + fire[i].r * sin(a);

					if (win_x > 0 && win_x < WIDTH && win_y > 0 && win_y < HEIGHT)
					{
						pMem[win_y * WIDTH + win_x] = BGR(fire[i].pixel[img_x][img_y]);//����ǰ���������ɫ������Ļ������
					}

					////��ȡ��ǰ���������ɫ
					//COLORREF color = fire[i].pixel[img_x][img_y];
					////�ж��Ƿ���͸��ɫ
					//if (color != RGB(0, 0, 0))//������Ǻ�ɫ(��ɫΪ͸��ɫ)
					//{
					//	//�����̻�
					//	putpixel(fire[i].x + img_x - fire[i].cen_x, fire[i].y + img_y - fire[i].cen_y, color);
					//}
				}
			}
		}
	}
}


int main()
{
	//��������
	initgraph(960, 640);

	//�������������
	srand((unsigned)time(NULL) + clock());

	welcome();
	loadImg();
	DWORD* pMem = GetImageBuffer();//��ȡ���ڵ��ڴ�(��Ļ������)ָ��

	while (1)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;//�ú�ɫ(����ɫ)���̻��������ǵ�
				}
			}
		}

		createJet();

		launch();
		bloom(pMem);       

		Sleep(10);
	}
	closegraph();
	return 0;
}


//SRCINVERT�ĺ������ã����XOR����ͼ
// 
//SRCINVERT�� EasyX �е�һ�����ػ��ģʽ�������Ƕ�Ŀ��λ�õ�������ͼ������ִ��������㣨XOR����
//  ��ĳ����ԭ������ɫ A(����ɫ)��������ɫ B ʱ�����ΪA XOR B��
//  ����ͬһλ������ͬ����ɫ B �ٻ���һ�Σ����Ϊ(A XOR B) XOR B = A(���ָ���ԭ������ɫ�����ָ�����ɫ)
//  ��һ����ʹ��ǳ��ʺ���ʱ���Ʋ������ĳ����������ƶ������壩����һ�λ���ʱ ����ʾ�� ͼ�񣬵ڶ��λ���ʱ �������� ͼ�񣬻ָ�����


//λ��
//��һ������Ľṹ���Ա���巽ʽ���������ݳ�Ա�洢��ָ���Ķ�����λ���У��Ӷ�����Ч�������ڴ�ռ�
//
//ע�⣺
//λ�εĳ�Ա��������ͨ���� int��unsigned int �� signed int��C99 Ҳ֧�������������ͣ��� _Bool����
//λ�� n �����ǷǸ��������Ҳ��ܳ�����Ӧ�������͵���λ�������� int ͨ���� 32 λ��n ���ܳ��� 32����
//��λ��Ϊ 0����ʾ��λ�ν�����������Ա���µĴ洢��Ԫ��ʼ��
// 
//���ã���ʡ�ڴ�,�����С���ݴ����һ���ֽ��У������ڴ�ռ�á�