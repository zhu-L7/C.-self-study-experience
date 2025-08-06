#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>// ���� mmsystem.h ��ʹ�ö�ý�幦��
#pragma comment(lib, "winmm.lib") // ���� winmm.lib ��
#include<conio.h>// ���� conio.h ��ʹ�� getch() ����
#include<time.h>// ���� time.h ��ʹ�� time() ����
#include<stdlib.h>// ���� stdlib.h ��ʹ�� rand() ����
#include<windows.h>  // ����MessageBox

//----���� ���� ����

#define NUM 200// �������󳤶�
#define SIZE 13// ����ÿ�ڵĴ�С
#define START 13*10// ��ͷ�ĳ�ʼ����(13�ı���)���������Ͻ�(0,0)λ����(0,0)��������ͷ������(13*10,13*10)
#define NORMAL_SPEED 100  // �����ٶ�
#define FAST_SPEED 50     // ����ʱ���ٶ�
int currentSpeed = NORMAL_SPEED;  // ��ǰ�ٶ�

// �����������루����GetAsyncKeyState��⣩
#define VK_UP 0x26    // �Ϸ����
#define VK_DOWN 0x28  // �·����
#define VK_LEFT 0x25  // �����
#define VK_RIGHT 0x27 // �ҷ����

bool isPaused = false;  // ��ͣ״̬��ǣ�false=���У�true=��ͣ��

// ö�ٷ���
enum Ch
{
	up=72,
	down=80,
	left=75,
	right = 77,
};

// ����ṹ��
struct Coor
{
	int x;
	int y;
};

// �ߵ�����
struct Snake
{
	int n;// �ߵĳ���(���ٽ�)
	Ch ch;// ��ͷ�ķ���
	Coor szb[NUM];// �������������
};
Snake snake;// ����һ����

// ʳ�������
struct Food
{
	int x;// ʳ�������
	int y;
	bool iseat; // �Ƿ񱻳Ե�
};
Food food;// ����ʳ��


//----���� ����

// ��Ϸ��ʼ��
void GameInit()
{
	srand((unsigned int)time(NULL)); // �����������

	snake.n = 3;// �ߵĳ���Ϊ3
	snake.ch = right;// ��ͷ��������
	snake.szb[0].x = START;// ��ͷ���� 13�ı�����13��10��
	snake.szb[0].y = START;
	snake.szb[1].x = START - SIZE;// �����һ������ ��ǰһ�����SIZE��13��
	snake.szb[1].y = START;
	snake.szb[2].x = START - 2 * SIZE;// ����ڶ������� �������ټ�һ��SIZE
	snake.szb[2].y = START;

	// ��ʼ��ʳ��
	food.iseat = true; // Ĭ��ʳ�ﱻ�Ե�

	// �����ٶ�
	currentSpeed = NORMAL_SPEED;
}

// ������Ϸ
void DrawGame()
{
	BeginBatchDraw();
	setbkcolor(RGB(20, 152, 224)); // ���ñ���ɫ�����Զ��壩
	cleardevice(); // ����

	setfillcolor(RED); // ���������ɫΪ��ɫ
	fillrectangle(snake.szb[0].x, snake.szb[0].y, snake.szb[0].x + SIZE,
		snake.szb[0].y + SIZE);// ������ͷ(���α�ʾ)

	//circle(snake.szb[0].x, snake.szb[0].y, 6);// ������ͷ(Բ�α�ʾ)

	// ������
	setfillcolor(YELLOW);  // �����û�ɫ����
	for (int i = 1; i < snake.n; i++)// int i��C��������Ҫд������(����д�������ж���)����C++�п���д������.
	{
		//putimage(100,100,&image);// ���������ÿһ��(ͼƬ��ʾ)

		 fillrectangle(snake.szb[i].x, snake.szb[i].y, snake.szb[i].x + SIZE,
			snake.szb[i].y + SIZE);// ���������ÿһ��(���α�ʾ)

		//circle(snake.szb[i].x, snake.szb[i].y, 6);// ���������ÿһ��(Բ�α�ʾ)
	}

	// ����ʳ��
	setfillcolor(YELLOW); // ���������ɫΪ��ɫ
	fillrectangle(food.x, food.y, food.x+SIZE,food.y+SIZE);// ����ʳ��

	// ��ʾ�ٶ�״̬����ѡ������۲죩
	settextcolor(WHITE);
	settextstyle(16, 0, _T("����"));
	outtextxy(10, 10, currentSpeed == FAST_SPEED ? _T("������") : _T("�����ٶ�"));

	// ��ͣʱ��ʾ��ʾ����
	if (isPaused) {
		settextcolor(RED);
		settextstyle(30, 0, _T("����"));
		outtextxy(200, 350, _T("��Ϸ��ͣ����P������"));
	}

	EndBatchDraw();
}

// ���ƶ�����
void SnakeMove()
{
	// �ȱ��������ߣ��ٰ�ǰһ�ڵ����긳ֵ����һ��
	for(int i=snake.n-1; i > 0; i--)// n���������(û����ͷ)
	{
		snake.szb[i].x = snake.szb[i - 1].x;
		snake.szb[i].y = snake.szb[i - 1].y;
	}

	switch (snake.ch)// ������ͷ�ķ������ƶ���
	{
	case up:
		snake.szb[0].y -= SIZE; // ��ͷ�����ƶ�
		break;
	case down:
		snake.szb[0].y += SIZE; // ��ͷ�����ƶ�
		break;
	case left:
		snake.szb[0].x -= SIZE; // ��ͷ�����ƶ�
		break;
	case right:
		snake.szb[0].x += SIZE; // ��ͷ�����ƶ�
		break;
	}
}

// ��鰴��״̬��������⣩
void CheckKeyPress() {
	bool isKeyDown = false;  // ����Ƿ��з����������

	// �����ͣ����P������ȷ�����ΰ���ֻ�л�һ��״̬
	static bool pPressed = false;  // ��¼P���Ƿ��Ѵ���
	if (GetAsyncKeyState('P') & 0x8000) {
		if (!pPressed) {  // ����P����"δ����"��Ϊ"����"ʱ����
			isPaused = !isPaused;  // �л���ͣ/����״̬
			pPressed = true;       // ���Ϊ�Ѵ���
		}
	}
	else {
		pPressed = false;  // �ɿ�P���������´δ���
	}

	// ���������ͣ״̬�����ص���������
	if (isPaused) return;

	// ����Ϸ������������Ч��
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		if (snake.ch != down) snake.ch = up;
		isKeyDown = true;
	}
	// ����·������������Ч��
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		if (snake.ch != up) snake.ch = down;
		isKeyDown = true;
	}
	// ����������������Ч��
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		if (snake.ch != right) snake.ch = left;
		isKeyDown = true;
	}
	// ����ҷ������������Ч��
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		if (snake.ch != left) snake.ch = right;
		isKeyDown = true;
	}

	// ���ݰ���״̬�����ٶ�
	currentSpeed = isKeyDown ? FAST_SPEED : NORMAL_SPEED;
}

// ����ʳ��
void createFood()
{
	bool isValid = false;// ���ڼ��ʳ��λ���Ƿ���Ч��Ĭ��û���ص�
	if (food.iseat == true) // ���ʳ�ﱻ�Ե�
	{
		while (1)
		{
			isValid = false;

			food.x = (rand() % (640 / SIZE)) * SIZE;  // 640�Ǵ��ڿ��
			food.y = (rand() % (800 / SIZE)) * SIZE;  // 800�Ǵ��ڸ߶�

			for (int i = 0; i < snake.n; i++) // ���ʳ���Ƿ��������ص�
			{
				if (food.x == snake.szb[i].x && food.y == snake.szb[i].y)
				{
					isValid = true;// ʳ��λ����Ч(�������ص�)
					break;
				}
			}
			if (!isValid)
			{
				food.iseat = false; // ʳ��λ����Ч������ʳ��δ���Ե�
				break; // ���ʳ��λ����Ч������ѭ��
			}
		}
	}
}

// ��ʳ��
void eatFood()
{
	if (food.x == snake.szb[0].x && food.y == snake.szb[0].y) // �����ͷ��ʳ���ص�
	{
		food.iseat = true; // ����ʳ�ﱻ�Ե�
		snake.n++; // �ߵĳ�������
	}
}

// �߽���
int GameOver()
{
	// �����ͷ�Ƿ������߽�
	if (snake.szb[0].x < 0 || snake.szb[0].x >= 640 || // ���ڿ��Ϊ640
		snake.szb[0].y < 0 || snake.szb[0].y >= 800) // ���ڸ߶�Ϊ800
	{
		return 1; // ��Ϸ����
	}

	// �����ͷ�Ƿ���������
	for (int i = 1; i < snake.n; i++) // �������һ�ڿ�ʼ���
	{
		if (snake.szb[0].x == snake.szb[i].x && snake.szb[0].y == snake.szb[i].y)// ��ͷ������ĳһ���ص�
		{
			return 1; // ��Ϸ����
		}
	}
	return 0; // ��Ϸδ����
}

int main()
{
	initgraph(640, 800);// ��ʼ��ͼ�δ���

	// ��������
	mciSendString(TEXT("open ./assets/˦�и�(�����ߥ�).wav alias music"), NULL, 0, NULL);
	mciSendString(TEXT("play music"), NULL, 0, NULL);

	GameInit(); // ������Ϸ��ʼ������
	while (1)
	{
		CheckKeyPress();  // ��鰴��״̬��������⣩
		
		// ���������ͣ״̬��ֻˢ�»��治ִ����Ϸ�߼�
		if (isPaused) {
			DrawGame();
			Sleep(100);  // ������ͣʱ��ˢ��Ƶ��
			continue;
		}

		SnakeMove(); // �������ƶ�����

		// ��Ҫ���ƶ��ߣ�Ȼ�������Ϸ����ΪDrawGame�����ߵ�n++�ĵ�3��֮���������(0,0)
		// ʹ�����ڳԵ�ʳ��(����һ�ڳ��ȵ���4��)ʱ����4�ڵ�������(0,0)��Ȼ���ڵ���SnakeMoveʱ
		// �����Ļص���������������Ϸ���߳Ե�ʳ��ʱ���ڴ������Ͻ�(0,0)λ�û���˸һ��(һ������).

		DrawGame(); // ���û�����Ϸ����
		createFood(); // ���ò���ʳ�ﺯ��
		eatFood();// ���ó�ʳ�ﺯ��
		Sleep(currentSpeed); // ������Ϸ�ٶ�

		if (GameOver())
		{
			// ��ʾ��
			int choice = MessageBox(
				GetHWnd(),
				L"��Ϸ�������Ƿ����¿�ʼ��",
				L"��Ϸ����",
				MB_YESNO | MB_ICONQUESTION
			);

			if (choice == IDYES)
			{
				GameInit();  // ���¿�ʼ
				isPaused = false;  // ���¿�ʼʱ������ͣ״̬
			}
			else
			{
				break;  // �˳���Ϸ
			}
		}
		else
		{
			// �����������δ������Ϸ�����ı䷽��
			CheckKeyPress();
		}
	}
	
	// ������Դ
	mciSendString(TEXT("stop music"), NULL, 0, NULL);
	mciSendString(TEXT("close music"), NULL, 0, NULL);
	closegraph(); // �ر�ͼ�δ���
	return 0;
}


// Ϊʲô�� & 0x8000��
//   GetAsyncKeyState() �����ķ���ֵ��һ�� 16 λ���������У�
//   ���λ���� 15 λ�� ��ʾ������ǰ�Ƿ񱻰��£�1 = ���£�0 = δ���£�
//   ����λ���ڼ�¼��������ʷ״̬�������Ƿ񱻰��¹���
//   0x8000 ��һ��ʮ�����Ƴ�����ת��Ϊ�������� 10000000 00000000��ֻ�����λΪ 1��
//   ͨ�� & �����뺯������ֵ��ϣ�������ȡ�����λ��ֵ(���� ���롱 �������ᱣ��ԭ����ֵ�����λ������λ����Ϊ 0)��
//   ������Ϊ 0x8000���� 0����˵�����λΪ 1 �� �������ڱ�����
//   ������Ϊ 0��˵�����λΪ 0 �� ����δ������
//   
//   �������Ϸ����ʱ��GetAsyncKeyState(VK_UP) & 0x8000 ��������ط� 0 ֵ
//   ����ֵ��ʵ�����ݣ�
//   �������Ϸ����ʱ��GetAsyncKeyState(VK_UP) �ķ���ֵ�У����λ(�� 15 λ)�ᱻ����Ϊ 1������λ���ܲ�ȷ��
//   ���� & 0x8000 ����󣬽���̶�Ϊ 0x8000(������ 10000000 00000000)������һ���� 0 ֵ(ʮ����Ϊ 32768)
//
// ���ȥ�� & 0x8000�����ܴ����������⣺
//   �����ɿ����Կ��ܴ�������ʹ�������ɿ��������λΪ 1(��ʾ֮ǰ�����¹�)������ֵ����� 0��������Ϊ ����ǰ���¡�
//   ״̬�жϻ��ң��޷����֡���ǰ���¡��͡��������¹����������ߵķ�������쳣(�����ɿ������󣬷����Կ��ܱ������޸�)


// ΪʲôGetAsyncKeyState()�� _getch() �ã�
//   _getch() ֻ�ܼ�ⵥ�ΰ���������һ�η���һ��ֵ�����������ظ����أ����� 
//   GetAsyncKeyState() ��� & 0x8000 ��ʵʱ��ⰴ���ĳ�������״̬���������� ���������١� ��������