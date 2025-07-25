#include<stdio.h>
#include<graphics.h>       //ͼ�ν�����ͷ�ļ�
#include"TransparentImage.h"
#include<time.h>

IMAGE bk;            //����ͼƬ
IMAGE img_plane[2];  //�ɻ�ͼƬ
IMAGE img_bull[2];   //�ӵ�ͼƬ
IMAGE img_enemy[3];   //�л�ͼƬ

enum My
{
	WIDTH = 480,     //��Ϸ���ڿ��.
	HEIGHT = 850,
	BULLET_NUM = 15, //�ӵ�����
	BIG=0,             //��л�
	MEDIUM=1,          //�ел�
	SMALL=2,           //С�л�
	ENEMY_NUM=10     //�л�����
};

//����ɻ�����
struct Plane
{
	int x;
	int y;
	bool live;  //����Ƿ�����.
	
	int width;
	int height;
	int hp;     //�л�Ѫ��
	int type;   //�л�����

}player, bull[BULLET_NUM], enemy[ENEMY_NUM];


//��ʼ��ͼƬ---����ͼƬ.
void loadImg()
{
	//����ͼƬ
	loadimage(&bk, "./Resource/images/background.png");           // ./�����ڵ�ǰĿ¼��(��Դ�ļ����ڵ�Ŀ¼)�����·��ʱʹ�ã�����ʡ��.
	//��ҷɻ�ͼƬ
	loadimage(&img_plane[0], "./Resource/images/hero1.png");
	loadimage(&img_plane[1], "./Resource/images/hero2.png");
	//�ӵ�ͼƬ
	loadimage(&img_bull[0], "./Resource/images/bullet1.png");
	loadimage(&img_bull[1], "./Resource/images/bullet2.png");

	//�л�ͼƬ---��������
	loadimage(&img_enemy[0], "./Resource/images/enemy1.png");     //С�л�
	loadimage(&img_enemy[1], "./Resource/images/enemy2.png");     //�ел�
	loadimage(&img_enemy[2], "./Resource/images/enemy3_n1.png");  //��л�
	
}

//��ʼ���л�����
void enemyHP(int i)
{
	int ret = rand() % 100;
	//С�л�
	if (ret < 60)   //����0-99֮����������С��60����0-59(60����)����60%
	{
		enemy[i].type = SMALL;
		enemy[i].hp = 1;
		enemy[i].width = 57;
		enemy[i].height = 43;
	}
	//�ел�
	else if (ret < 84)  //��Ҫif������Ż����else if����������������60-83(24����)����24%
	{
		enemy[i].type = MEDIUM;
		enemy[i].hp = 3;
		enemy[i].width = 69;
		enemy[i].height = 99;
	}
	//��л�
	else                         //����������84-99(16����)����16%
	{
		enemy[i].type = BIG;
		enemy[i].hp = 5;
		enemy[i].width = 119;
		enemy[i].height = 208;
	}

	// ȷ���л�HP��ʼֵ��ȷ
	printf("��ʼ���л� %d: ����=%d, HP=%d\n",i, enemy[i].type, enemy[i].hp);
}

//��ʼ��
void gameInit()
{
	//����ͼƬ
	loadImg();

	//��ҷɻ�
	player.x = WIDTH / 2;
	player.y = HEIGHT - 120;
	player.live = true;       //true������ţ�false��������.

	//�ӵ�
	for (int i = 0; i < BULLET_NUM; i++)
	{
		bull[i].x = 0;
		bull[i].y = 0;
		bull[i].live = false;
	}

	//�л�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//��û�ел�
		enemy[i].live = false;
		//�����л�
		enemyHP(i);
	}

	
	
}

//��ͼ---��ӡ���ͼƬ����Ϸ����.
void gameDraw()
{
	putimage(0, 0, &bk);//����
	drawImg(player.x, player.y,&img_plane[0]);   //��ҷɻ�ͼƬ
	drawImg(player.x, player.y,&img_plane[1]);

	//�����ӵ�
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bull[i].live)
		{
		if (bull[i].live)
			drawImg(bull[i].x, bull[i].y, &img_bull[0]);
			//drawImg(bull[i].x, bull[i].y, &img_bull[1]);
		}
	}

	//���Ƶл�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live)
		{
			if (enemy[i].type == BIG)
			{
				drawImg(enemy[i].x, enemy[i].y, &img_enemy[2]);
			}
			else if (enemy[i].type == MEDIUM)
			{
				drawImg(enemy[i].x, enemy[i].y, &img_enemy[1]);
			}
			else
			{
				drawImg(enemy[i].x, enemy[i].y, &img_enemy[0]);
			}
		}
	}
}

//����һ���ӵ�.
void createBullte()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (!bull[i].live)  //�ӵ�������ʱ
		{
			bull[i].x = player.x + 51;  //�ӵ��ڷɻ��м䷢��
			bull[i].y = player.y;
			bull[i].live = true;
			break;
		}
	}
}

//�ӵ��ƶ�
void BullteMove()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bull[i].live)
		{
			bull[i].y -= 5;      //�ӵ��ٶ�
			if (bull[i].y < 0)
			{
				bull[i].live = false;
			}
		}
	}
}

//���ɵл�
void createEnemy()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live)
		{
			enemy[i].live = true;
			enemyHP(i);
			enemy[i].x = rand() % (WIDTH - enemy[i].width);   //��ֹ�л�������Ϸ����
			enemy[i].y = -enemy[i].height;    //�л�����Ļ�Ϸ�����

			//���
			printf("���ɵл� %d: ����=%d, HP=%d, x=%d, y=%d\n",i, enemy[i].type, enemy[i].hp,enemy[i].x, enemy[i].y);


			break;
		}
	}
}

//�л��ƶ�
void enemyMove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live)
		{
			//��ͬ���͵л��ٶȲ�ͬ
			int speed = 1;                                 //��л��ٶ�
			if (enemy[i].type == SMALL) speed = 3;         //С�л��ٶ�
			else if (enemy[i].type == MEDIUM) speed = 2;   //�ел��ٶ�
			//�ƶ�
			enemy[i].y += speed;
			//�жϵл��Ƿ����
			if (enemy[i].y > HEIGHT)
			{

				//���
				printf("�л� %d (����=%d, HP=%d) ���磬y=%d\n",i, enemy[i].type, enemy[i].hp, enemy[i].y);
				
				
				enemy[i].live = false;
			}
		}
	}
}


//�ƶ���ҷɻ�---��������
void playerMove(int speed)
{
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (player.y > 0)
		{
			player.y -= speed;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (player.y+126 < HEIGHT)
		{
			player.y += speed;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		if (player.x+51 > 0)
		{
			player.x -= speed;
		}		
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if (player.x+51 < WIDTH)
		{
			player.x += speed;
		}
	}

	//���ӳ�Ч�������ӵ��ƶ���˿���������ڰ�һ�¿ո���ֶ���ӵ�.
	static DWORD t1 = 0;
	DWORD t2 = GetTickCount();   //����t2Ϊ��ǰʱ�䣬GetTickCount()��clock()���ƶ��ǻ�ȡ��ǰʱ��ĺ���(����ͷ�ļ�����λ���������ͺ����ó����ȶ�����ͬ).
	//���ո����ӵ�.
	if (GetAsyncKeyState(VK_SPACE) && t2-t1 >200)     //t1��ʾ�ϴη����ӵ�ʱ��(����),t2��ʾ��ǰʱ��(����),t2-t1�ͱ�ʾ�����ӵ�����ȴʱ��(��һ�ΰ��ո���Ҫ����һ�ΰ��ո��50����Ż���Ч���Żᷢ���µ��ӵ�).
	{
		createBullte();
		t1 = t2;
	}
}


// ��ⵥ���ӵ���л�����ײ
bool checkBulletCollision(int k)
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live)
			continue;

		if (bull[k].x > enemy[i].x &&
			bull[k].x < enemy[i].x + enemy[i].width &&
			bull[k].y > enemy[i].y &&
			bull[k].y < enemy[i].y + enemy[i].height)
		{
			//���
			printf("�ӵ� %d ���ел� %d (����=%d, HP=%d)\n",k, i, enemy[i].type, enemy[i].hp);

			bull[k].live = false;
			enemy[i].hp--;          // �л���Ѫ

			if (enemy[i].hp <= 0)
			{
				//���
				printf("�л� %d (����=%d) ���ݻ٣�\n", i, enemy[i].type);

				enemy[i].live = false;   // �л����ݻ�
			}
			else
			{
				printf("�л� %d (����=%d) ʣ��HP=%d\n", i, enemy[i].type, enemy[i].hp);
			}
			return true;  // �ӵ��ѻ���Ŀ��
		}
	}
	return false;  // �ӵ�δ�����κεл�
}

// �������
void play()
{
	for (int k = 0; k < BULLET_NUM; k++)
	{
		if (!bull[k].live)
			continue;

		if (checkBulletCollision(k))  // ����ӵ�����Ŀ�꣬�����������
			continue;
	}
}


//�ӳ�---������ʱ��
bool Time(int ms,int id)
{
	static DWORD t[10] = { 0 };
	if (GetTickCount() - t[id] > ms)
	{
		t[id] = GetTickCount();
		return true;
	}
	return false;
}

//�������
int main()
{
	//������Ϸ����
	initgraph(WIDTH,HEIGHT,1);

	//��ʼ�����������
	srand((unsigned int)time(NULL));    //ȷ��ÿ����Ϸ����ʱ�л����ͺ�����λ�õ������

	gameInit();


	//˫����---��ֹ����.
	BeginBatchDraw();
	while (1)
	{
		//����(��ֹ��Ӱ)
		cleardevice();

		playerMove(10);  //��ҷɻ��ƶ�

		BullteMove();   //�ӵ��ƶ�

		//��ʱ���ɵл�
		if (Time(2000, 0))  //ÿ2������һ��
		{
			createEnemy();  //���ɷɻ�
		}

		enemyMove();   //�л��ƶ�

		play();   //����

		//��ͼ
		gameDraw();   //����������õ�����ͼ͸����ͼ�Ļ�������whileѭ�������е�ʱ���һ��һ����(��ʱ����Ҫ��˫����).

		FlushBatchDraw(); //ÿ��ѭ��ˢ��һ��ҳ��.

		Sleep(16);  //����֡�ʣ�Լ60֡ÿ��
	}

	closegraph();   //�ر���Ϸ����
	return 0;
}