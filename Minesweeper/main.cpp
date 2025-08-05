#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include"tools.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib") // ��ý��⣬�ṩʱ�亯��

//----���� ���� ����
#define ROW 25// ��
#define COL 25// ��
#define NUM 100// �׵ĸ���(����ͨ���ı��׵ĸ������ı���Ϸ�Ѷ�)
#define SIZE 30// ����ͼƬ�Ĵ�С

int count = 0;// ����������¼�Ѵ򿪵ĸ�����
int map[ROW][COL];

IMAGE img[12]; // ͼƬ����

//----���� ����

void loadImg()
{
	loadimage(&img[0], L"./assets/images/cell.jpg", SIZE, SIZE);// ��������ͼƬ
	loadimage(&img[1], L"./assets/images/bomb.jpg", SIZE, SIZE);// ��ͼƬ

	// ����1-8ͼƬ
	loadimage(&img[2], L"./assets/images/1.jpg", SIZE, SIZE);
	loadimage(&img[3], L"./assets/images/2.jpg", SIZE, SIZE);
	loadimage(&img[4], L"./assets/images/3.jpg", SIZE, SIZE);
	loadimage(&img[5], L"./assets/images/4.jpg", SIZE, SIZE);
	loadimage(&img[6], L"./assets/images/5.jpg", SIZE, SIZE);
	loadimage(&img[7], L"./assets/images/6.jpg", SIZE, SIZE);
	loadimage(&img[8], L"./assets/images/7.jpg", SIZE, SIZE);
	loadimage(&img[9], L"./assets/images/8.jpg", SIZE, SIZE);

	loadimage(&img[10], L"./assets/images/blank.jpg", SIZE, SIZE);// �հ�ͼƬ
	loadimage(&img[11], L"./assets/images/flag.jpg", SIZE, SIZE);// ����ͼƬ

}

void GameInit()// ��Ϸ��ʼ��
{
	srand((unsigned int)time(NULL));// �������������

	count = 0; // ���ü�����Ϊ0

	// ��ʼ����ͼ
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] = 0;
		}
	}
	int n = 0;
	while(n< NUM)
	{
		//����õ��к���
		int r = rand() % ROW;// rand������Ҫ<stdlib.h>ͷ�ļ�
		int c = rand() % COL;
		if (map[r][c] == 0)// ��λ��û����
		{
			map[r][c] = -1;// ����Ϊ��
			n++;
		}
	}

	// ��������Χ������
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == -1) // �������
			{
				// ������Χ��8��λ��
				for (int x = -1; x <= 1; x++)
				{
					for (int y = -1; y <= 1; y++)
					{
						if (x == 0 && y == 0) continue; // �����Լ�
						int newX = i + x;// �µ�λ�� x��y��ƫ����
						int newY = j + y;
						if (newX >= 0 && newX < ROW && newY >= 0 && newY < COL && map[newX][newY] != -1)
						{
							map[newX][newY]++; // ������Χ�׵ļ���
						}
					}
				}
			}
		}
	}

	// ����ÿ������
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] += 20; // ��ÿ�����ӵ�ֵ��20��������׵�ֵ��ͻ(���ܸ��Ǹ���)
		}
	}

	// ���ַ�����Խ��������飬���ܷ��ʵ���Ϸ�߽���ΧһȦ�������ΧһȦ���������ף��ͻᵼ�±߽�һȦ���ӵ���ֵ����
	/*for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] != -1)
			{
				for(int m=i-1;m<=i+1;m++)
				{
					for(int n=j-1;n<=j+1;n++)
					{
						if(map[m][n]==-1)
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}*/
}

void GameDraw()// ��Ϸ����
{

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%2d ", map[i][j]);// ����̨���ÿ�����ӵ�ֵ

			if(map[i][j] == -1) // �������
			{
				putimage(j * SIZE, i * SIZE, &img[1]); // ������ͼƬ
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				putimage(j * SIZE, i * SIZE, &img[0]); // ���Ʊ�������ͼƬ
			}
			else if (map[i][j] == 0)
			{
				putimage(j * SIZE, i * SIZE, &img[10]); // ����0ͼƬ
			}
			else if (map[i][j] >= 1 && map[i][j] <= 8) // ���������1-8
			{
				putimage(j * SIZE, i * SIZE, &img[map[i][j] + 1]); // ���ƶ�Ӧ����1-8ͼƬ
			}
			else if(map[i][j] > 30)
			{
				putimagePNG(j * SIZE, i * SIZE, &img[11]);// ��������ͼƬ
			}
		}
		printf("\n");
	}
}

void Open_ZeroRound(int r, int c)
{
	//�ȴ����0
	map[r][c] -= 20; // �ҿ�����
	count++;
	printf("�򿪵ĸ�������%d\n", count);

	for (int m = r - 1; m <= r + 1; m++)// ������Χ�ĸ���
	{
		for (int n = c - 1; n <= c + 1; n++)
		{
			if (m >= 0 && m < ROW && n >= 0 && n < COL)// �߽��ж�
			{
				if (map[m][n] >= 19 && map[m][n] <= 28)// ����Ǹ���״̬
				{
					if (map[m][n] == 20)// �����0
					{
						Open_ZeroRound(m, n);// �ݹ����Χ��0
					}
					else
					{
						map[m][n] -= 20;// �ҿ�����
						count++;
						printf("�򿪵ĸ�������%d\n", count);
					}
				}
			}
		}
	}
}


int PlayGame()// ����Ϸ--������Ϣ
{
	// ����һ�������Ϣ
	MOUSEMSG msg = { 0 };
	int r, c;

	while (1)
	{
		msg = GetMouseMsg(); // ��ȡ�����Ϣ

		switch (msg.uMsg)
		{
		case WM_LBUTTONUP:  // ���̧�𣨽ҿ����ӣ�
			r = msg.y / SIZE;  // �� = ���y���� / ���Ӵ�С
			c = msg.x / SIZE;  // �� = ���x���� / ���Ӵ�С

			// ���ӱ߽��жϣ���ֹ��������⵼������Խ��
			if (r >= 0 && r < ROW && c >= 0 && c < COL)
			{
				if (map[r][c] >= 19 && map[r][c] <= 28)  // ����Ǹ���״̬
				{
					if (map[r][c] == 20)// �㵽0
					{
						Open_ZeroRound(r,c);
					}
					else
					{
						map[r][c] -= 20;  // �ҿ�����
						count++;  // ���Ӽ���
						printf("�򿪵ĸ�������%d\n", count);
					}
				}
			}
			return map[r][c];
			break;

		case WM_RBUTTONUP:  // �Ҽ�̧�𣨱��/ȡ�����ӣ�
			r = msg.y / SIZE;
			c = msg.x / SIZE;

			// �߽��ж�
			if (r >= 0 && r < ROW && c >= 0 && c < COL)
			{
				if (map[r][c] >= 19 && map[r][c] <= 28)  // ����״̬���������
				{
					map[r][c] += 50;
				}
				else if (map[r][c] > 30)  // ����״̬��ȡ�����
				{
					map[r][c] -= 50;
				}
			}
			return map[r][c];
			break;
		}
	}
}



// ������
int main()
{
	HWND hwnd = initgraph(750,750, SHOWCONSOLE);// ��ʼ�����ڣ���ʹ��Ϊ������

	mciSendString(L"open ./assets/musics/Doopravdy.mp3 alias bg", NULL, 0, NULL); // �������ļ�
	mciSendString(L"play bg repeat", NULL, 0, NULL); // ѭ����������

	loadImg();// ����ͼƬ
	GameInit();// ��Ϸ��ʼ��
	
	while (1)
	{
		GameDraw();// ��Ϸ����

		if(PlayGame() == -1)// �㵽��
		{
			GameDraw();
			int result = MessageBox(hwnd, L"Game Over!!\n���¿�ʼ(��)\n�˳���Ϸ(��)", L"��ʾ", MB_YESNO | MB_ICONINFORMATION);
			
			// �����û�����İ�ťִ�ж�Ӧ����
			if (result == IDYES)  // �û�������ǡ������¿�ʼ��
			{
				// ���³�ʼ����Ϸ�����ó�ʼ�����������õ�ͼ�ȣ�
				GameInit();
			}
			else if (result == IDNO)  // �û�������񡱣��˳���Ϸ��
			{
				// �ر�ͼ�δ��ڲ��˳�����
				closegraph();
				exit(0);
			}
		}

		if (ROW * COL - NUM == count)
		{
			GameDraw();
			int outcome = MessageBox(hwnd, L"Victory!!\n���¿�ʼ(��)\n�˳���Ϸ(��)", L"��ʾ", MB_YESNO | MB_ICONINFORMATION);

			// �����û�����İ�ťִ�ж�Ӧ����
			if (outcome == IDYES)  // �û�������ǡ������¿�ʼ��
			{
				// ���³�ʼ����Ϸ�����ó�ʼ�����������õ�ͼ�ȣ�
				GameInit();
			}
			else if (outcome == IDNO)  // �û�������񡱣��˳���Ϸ��
			{
				// �ر�ͼ�δ��ڲ��˳�����
				closegraph();
				exit(0);
			}
		}
	}

	closegraph(); // �ر�ͼ�δ���
	return 0;
}
