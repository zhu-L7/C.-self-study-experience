#include<stdio.h>
#include<graphics.h>       //ͼ�ν�����ͷ�ļ�
#include"TransparentImage.h"
#include<time.h>
#include<mmsystem.h>       // ��ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib, "winmm.lib")  // ���Ӷ�ý���

int planeFrame = 0;          // �ɻ�����֡��������0 �� 1��
DWORD planeFrameTimer = 0;   // �ɻ�֡�л���ʱ��
const int PLANE_FRAME_DELAY = 200;  // ֡�л���������룩



#define WEAPON_NUM 3  // ��Ͷ�����������

IMAGE bk;            //����ͼƬ
IMAGE img_Start[5];  //��ʼͼƬ
IMAGE img_plane[2];  //�ɻ�ͼƬ
IMAGE img_bull[2];   //�ӵ�ͼƬ
IMAGE img_enemy[3];  //�л�ͼƬ
IMAGE img_music[2];  // ���ֿ���ͼƬ(�����͸߹�)
IMAGE img_pause[2];  // ��ͣ��ťͼƬ(�����͸߹�)
IMAGE img_resume[2]; // ������ťͼƬ(�����͸߹�)
IMAGE img_weapon[2];  // ��Ͷ����ͼƬ

//��ը����ͼƬ
IMAGE img_enemy1_down[4];  // С�л���ը����(4֡)
IMAGE img_enemy2_down[4];  // �ел���ը����(4֡)
IMAGE img_enemy3_down[6];  // ��л���ը����(6֡)

IMAGE img_hero_blowup[4];  // ��ҷɻ���ը����(4֡) 
IMAGE img_gameover;        // ��Ϸ��������ͼƬ 
IMAGE img_dead;            // "��������"ͼƬ 
IMAGE img_restart[2];      // ���¿�ʼ��ťͼƬ(�����͸߹�) 
IMAGE img_quit[2];         // ������Ϸ��ťͼƬ(�����͸߹�) 


bool isMusicPlaying = true;  // ���ֲ���״̬��Ĭ�ϲ���
bool isPaused = false;       // ��Ϸ��ͣ״̬��Ĭ�ϲ���ͣ
bool isBulletType1 = true;   // �ӵ�����״̬��trueΪ��һ���ӵ���falseΪ�ڶ��֣�
bool isGameOver = false;     // ��Ϸ����״̬ 
bool isPlayerExploding = false; // ����Ƿ����ڱ�ը 

int score = 0;  // ��ӷ�����������¼��ҵ÷�

ExMessage msg = { 0 };//������Ϣ�Ľṹ�����

enum My
{
	WIDTH = 480,     //��Ϸ���ڿ��.
	HEIGHT = 850,
	BULLET_NUM = 15, //�ӵ�����
	BIG = 0,         //��л�
	MEDIUM = 1,      //�ел�
	SMALL = 2,       //С�л�
	ENEMY_NUM = 10   //�л�����
};

//����ɻ�����
struct Plane
{
	int x;
	int y;
	bool live;  //����Ƿ�����.

	int width;
	int height;
	int hp;     //�л�Ѫ��/���Ѫ�� 
	int type;   //�л�����/�ӵ�����

	//��ը�������
	bool exploding;     // �Ƿ����ڱ�ը
	int explodeFrame;   // ��ǰ��ը֡
	DWORD explodeTimer; // ��ը������ʱ��

}player, bull[BULLET_NUM], enemy[ENEMY_NUM];

// �����Ͷ��������
struct Weapon
{
	int x;
	int y;
	bool live;  // �Ƿ����
	int type;   // 0Ϊweapon1��1Ϊweapon2
	int width;
	int height;
};
Weapon weapon[WEAPON_NUM];  // ��Ͷ��������

// ���ؿ�ʼ/��������ͼƬ
void loadImg_start()
{
	//����ͼƬ
	loadimage(&bk, "./Resource/images/background.png");

	//��ʼ��Ϸ ������Ϸ��ťͼƬ
	loadimage(&img_Start[0], "./Resource/images/title.png");        //����
	loadimage(&img_Start[1], "./Resource/images/��ʼ��Ϸ.png");     //��ʼ��Ϸ
	loadimage(&img_Start[2], "./Resource/images/������Ϸ.png");     //������Ϸ
	loadimage(&img_Start[3], "./Resource/images/��ʼ��Ϸ2.png");    //��ʼ��Ϸ2
	loadimage(&img_Start[4], "./Resource/images/������Ϸ2.png");    //������Ϸ2

	// ������Ϸ�������ͼƬ 
	loadimage(&img_gameover, "./Resource/images/background.png");       //��������
	loadimage(&img_dead, "./Resource/images/titleover.png");            //��������
	loadimage(&img_restart[0], "./Resource/images/���¿�ʼ.png");       //���¿�ʼ����
	loadimage(&img_restart[1], "./Resource/images/���¿�ʼ�߹�.png");   //���¿�ʼ�߹�
	loadimage(&img_quit[0], "./Resource/images/�˳���Ϸ.png");          //�˳���Ϸ����
	loadimage(&img_quit[1], "./Resource/images/�˳���Ϸ�߹�.png");      //�˳���Ϸ�߹�
}

//�ж�����Ƿ��ڰ�ť����
bool InArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx < x + w && my > y && my < y + h)
	{
		return true;
	}
	return false;
}

// ��ʼ����������
void initMusic()
{
	// �򿪲����ű������֣�ѭ������
	mciSendString("open ./Resource/sound/game_music.mp3 alias bgm", NULL, 0, NULL); //��
	mciSendString("play bgm repeat", NULL, 0, NULL);  //ѭ������
}

// �л����ֲ���״̬
void toggleMusic()
{
	if (isMusicPlaying)
	{
		mciSendString("pause bgm", NULL, 0, NULL);  // ��ͣ����
	}
	else
	{
		mciSendString("resume bgm", NULL, 0, NULL);  // ��������
	}
	isMusicPlaying = !isMusicPlaying;
}

// �л���Ϸ��ͣ״̬
void togglePause()
{
	isPaused = !isPaused;
	// �����ͣ��Ϸ��ͬʱ��ͣ���֣�������Ϸ��ͬʱ��������
	if (isPaused)
	{
		if (isMusicPlaying)   //��ֹ����Ѿ�����������ֿ�����ͣ�����ֺ󣬵����ͣ��ť��һ����ͣ����(�Ѿ���ͣ����һ����ͣ->���ù�),�Դ˼���CPUʹ����
		{
			mciSendString("pause bgm", NULL, 0, NULL);  // ��ͣ����
		}
	}
	else
	{
		if (isMusicPlaying)
		{
			mciSendString("resume bgm", NULL, 0, NULL);  // ��������
		}
	}
}

// ���Ʋ��������ֿ���ͼ��
void drawMusicControl()
{
	int x = 0;  // ���Ͻ�λ��
	int y = 0;
	int w = img_music[0].getwidth();  //��ȡ����ͼ����
	int h = img_music[0].getheight();

	// ������꽻��
	if (InArea(msg.x, msg.y, x, y, w, h))
	{
		drawImg(x, y, &img_music[1]);  // �����ͣ��ʾ�߹�ͼƬ

		// ���������
		if (msg.message == WM_LBUTTONDOWN)
		{
			toggleMusic();
			msg.message = 0;  // ������Ϣ�������ظ�����
		}
	}
	else
	{
		drawImg(x, y, &img_music[0]);  // ������ʾ
	}
}

// ���Ʋ�������ͣ/��������ͼ��
void drawPauseControl()
{
	// ���Ͻ�λ��
	int x = WIDTH - img_pause[0].getwidth();
	int y = 0;
	int w, h;

	// ���ݵ�ǰ״̬ѡ����ʾ��ͼƬ
	IMAGE* normalImg, * hoverImg;
	if (isPaused)
	{
		normalImg = &img_resume[0];
		hoverImg = &img_resume[1];
	}
	else
	{
		normalImg = &img_pause[0];
		hoverImg = &img_pause[1];
	}

	w = normalImg->getwidth();
	h = normalImg->getheight();

	// ������꽻��
	if (InArea(msg.x, msg.y, x, y, w, h))
	{
		drawImg(x, y, hoverImg);  // �����ͣ��ʾ�߹�ͼƬ

		// ���������
		if (msg.message == WM_LBUTTONDOWN)
		{
			togglePause();
			msg.message = 0;  // ������Ϣ�������ظ�����
		}
	}
	else
	{
		drawImg(x, y, normalImg);  // ������ʾ
	}
}

//�����ӡ��ʼ����
void putImg_Start()
{
	putimage(0, 0, &bk);//����
	drawImg(WIDTH / 2 - 441 / 2, HEIGHT / 2 - 200, &img_Start[0]);  //����
	drawImg(WIDTH / 2 - 300 / 2, HEIGHT / 2, &img_Start[1]);        //��ʼ��Ϸ
	drawImg(WIDTH / 2 - 300 / 2, HEIGHT / 2 + 82, &img_Start[2]);   //������Ϸ
}

//�ж�����Ƿ���ͣ
bool isHover(int x, int y, int w, int h, IMAGE* img_Normal, IMAGE* img_Hover)  // ��������Ƿ���ͣѡ����ʾ��ͼƬ
{
	if (InArea(msg.x, msg.y, x, y, w, h))
	{
		drawImg(x, y, img_Hover);  //�����ͣʱ��ӡ����ͼƬ
		return true;
	}
	else
	{
		drawImg(x, y, img_Normal);//���û����ͣʱ��ӡ����ͼƬ
		return false;
	}
}

//�ı���ɫ  ����ж�
bool Img_switch(int x, int y, int w, int h, IMAGE* img_Normal, IMAGE* img_Hover)
{
	isHover(x, y, w, h, img_Normal, img_Hover);

	//�����ť
	if (msg.message == WM_LBUTTONDOWN && InArea(msg.x, msg.y, x, y, w, h))
	{
		return true;
	}
	return false;
}

void gameInit();
void putImg_Music();

// ������Ϸ�������� 
void drawGameOver()
{
	// ������Ϸ��������
	putimage(0, 0, &img_gameover);

	//��������ͼ��
	putImg_Music();

	// ���Ƶ÷�
	TCHAR scoreText[20];
	_stprintf_s(scoreText, _T("�÷֣� %d"), score);
	settextcolor(RGB(110, 104, 89));
	settextstyle(60, 0, _T("�زļ��п�����"));
	setbkmode(TRANSPARENT);
	outtextxy(WIDTH / 2 - textwidth(scoreText) / 2 - 10, HEIGHT / 2 - 200, scoreText);

	// ����"��������"ͼƬ
	drawImg(WIDTH / 2 - img_dead.getwidth() / 2, HEIGHT / 2 - 150, &img_dead);

	// �������¿�ʼ��ť
	if (Img_switch(WIDTH / 2 - 300 / 2, HEIGHT / 2, 300, 41, &img_restart[0], &img_restart[1]))
	{
		// ���¿�ʼ��Ϸ
		isGameOver = false;
		score = 0;  // ���÷���
		gameInit(); // ���³�ʼ����Ϸ
		msg.message = 0;
	}

	// �����˳���Ϸ��ť
	if (Img_switch(WIDTH / 2 - 300 / 2, HEIGHT / 2 + 82, 300, 41, &img_quit[0], &img_quit[1]))
	{
		// �˳���Ϸ
		mciSendString("close bgm", NULL, 0, NULL);
		closegraph();
		FreeConsole();
		exit(0);
	}
}

// ������ұ�ը���� 
void handlePlayerExplosion()
{
	if (!isPlayerExploding)
	{
		return;
	}

	DWORD currentTime = GetTickCount();

	// ���Ʊ�ը����֡��
	if (currentTime - player.explodeTimer > 100)
	{
		player.explodeFrame++;
		player.explodeTimer = currentTime;

		// ��ը������������Ϸ����
		if (player.explodeFrame >= 4)
		{
			isPlayerExploding = false;
			isGameOver = true;
		}
	}
}

// ��������л���ײ 
void checkPlayerCollision()
{
	if (isPlayerExploding || !player.live)
	{
		return;
	}

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live && !enemy[i].exploding)
		{
			// �򵥵ľ�����ײ���
			if (player.x + player.width > enemy[i].x &&
				player.x < enemy[i].x + enemy[i].width &&
				player.y + player.height > enemy[i].y &&
				player.y < enemy[i].y + enemy[i].height)
			{
				// �л���ը
				enemy[i].exploding = true;
				enemy[i].explodeFrame = 0;
				enemy[i].explodeTimer = GetTickCount();

				// ��Ҽ�Ѫ
				int damage = 0;
				switch (enemy[i].type)
				{
				case SMALL: damage = 1; break;
				case MEDIUM: damage = 2; break;
				case BIG: damage = 3; break;
				}
				player.hp -= damage;

				// ������Ѫ����Ϣ
				printf("����ܵ� %d ���˺���ʣ��Ѫ��: %d\n", damage, player.hp);

				// �ж�����Ƿ�����
				if (player.hp <= 0)
				{
					player.live = false;
					isPlayerExploding = true;
					player.explodeFrame = 0;
					player.explodeTimer = GetTickCount();
				}

				// ��ǵл�Ϊ�ǻ״̬
				enemy[i].live = false;
				break;
			}
		}
	}
}

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

	//���ر�ը����ͼƬ
	loadimage(&img_enemy1_down[0], "./Resource/images/enemy1_down1.png"); //С�л�
	loadimage(&img_enemy1_down[1], "./Resource/images/enemy1_down2.png");
	loadimage(&img_enemy1_down[2], "./Resource/images/enemy1_down3.png");
	loadimage(&img_enemy1_down[3], "./Resource/images/enemy1_down4.png");

	loadimage(&img_enemy2_down[0], "./Resource/images/enemy2_down1.png"); //�ел�
	loadimage(&img_enemy2_down[1], "./Resource/images/enemy2_down2.png");
	loadimage(&img_enemy2_down[2], "./Resource/images/enemy2_down3.png");
	loadimage(&img_enemy2_down[3], "./Resource/images/enemy2_down4.png");

	loadimage(&img_enemy3_down[0], "./Resource/images/enemy3_down1.png"); //��л�
	loadimage(&img_enemy3_down[1], "./Resource/images/enemy3_down2.png");
	loadimage(&img_enemy3_down[2], "./Resource/images/enemy3_down3.png");
	loadimage(&img_enemy3_down[3], "./Resource/images/enemy3_down4.png");
	loadimage(&img_enemy3_down[4], "./Resource/images/enemy3_down5.png");
	loadimage(&img_enemy3_down[5], "./Resource/images/enemy3_down6.png");

	// �������ֿ���ͼƬ
	loadimage(&img_music[0], "./Resource/images/����.png");
	loadimage(&img_music[1], "./Resource/images/�߹�.png");

	// ������ͣ/������ťͼƬ
	loadimage(&img_pause[0], "./Resource/images/��ͣ.png");
	loadimage(&img_pause[1], "./Resource/images/��ͣ�߹�.png");
	loadimage(&img_resume[0], "./Resource/images/����.png");
	loadimage(&img_resume[1], "./Resource/images/�����߹�.png");

	// ������ҷɻ���ըͼƬ
	loadimage(&img_hero_blowup[0], "./Resource/images/hero_blowup_n1.png");
	loadimage(&img_hero_blowup[1], "./Resource/images/hero_blowup_n2.png");
	loadimage(&img_hero_blowup[2], "./Resource/images/hero_blowup_n3.png");
	loadimage(&img_hero_blowup[3], "./Resource/images/hero_blowup_n4.png");

	//��Ͷ����ͼƬ
	loadimage(&img_weapon[0], "./Resource/images/weapon1.png");
	loadimage(&img_weapon[1], "./Resource/images/weapon2.png");
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

	//��ʼ����ը�������
	enemy[i].exploding = false;
	enemy[i].explodeFrame = 0;
	enemy[i].explodeTimer = 0;

	// ȷ���л�HP��ʼֵ��ȷ
	printf("��ʼ���л� %d: ����=%d, HP=%d\n", i, enemy[i].type, enemy[i].hp);
}

//����ը����
void handleExplosions()
{
	DWORD currentTime = GetTickCount();

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].exploding)
		{
			// ���Ʊ�ը����֡�ʣ�ÿ100�����л�һ֡
			if (currentTime - enemy[i].explodeTimer > 100)
			{
				enemy[i].explodeFrame++;
				enemy[i].explodeTimer = currentTime;

				// ���ݵл������ж϶����Ƿ����
				bool animationEnded = false;
				if (enemy[i].type == SMALL && enemy[i].explodeFrame >= 4)
				{
					animationEnded = true;
				}
				else if (enemy[i].type == MEDIUM && enemy[i].explodeFrame >= 4)
				{
					animationEnded = true;
				}
				else if (enemy[i].type == BIG && enemy[i].explodeFrame >= 6)
				{
					animationEnded = true;
				}

				if (animationEnded)
				{
					enemy[i].live = false;
					enemy[i].exploding = false;
					enemy[i].explodeFrame = 0;
				}
			}
		}
	}
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
	player.width = 102;  // ��ҷɻ����
	player.height = 126; // ��ҷɻ��߶�
	player.hp = 10;      // ��ҳ�ʼѪ�� 10

	// ��ʼ����ұ�ը���� 
	player.exploding = false;
	player.explodeFrame = 0;
	player.explodeTimer = 0;

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

	//��Ͷ����
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		weapon[i].live = false;
		weapon[i].width = img_weapon[0].getwidth();
		weapon[i].height = img_weapon[0].getheight();
	}
}
  
//�����ӡ����ͼ��
void putImg_Music()
{
	drawMusicControl();  // �������ֿ���ͼ��
}

//��ʼ��������
void game_start()
{
	while (1)
	{
		putImg_Music();

		while (peekmessage(&msg, EX_MOUSE))  //������ȡ�����Ϣ ����ѭ�� ������Ӧ����
		{
			// �������ְ�ť���
			if (InArea(msg.x, msg.y, 0, 0, img_music[0].getwidth(), img_music[0].getheight()) && msg.message == WM_LBUTTONDOWN)
			{
				toggleMusic();
				msg.message = 0;  //������Ϣ
			}

			//�����ʼ��Ϸ ������Ϸ
			if (Img_switch(WIDTH / 2 - 300 / 2, HEIGHT / 2, 300, 41, &img_Start[1], &img_Start[3]))
			{
				cleardevice();
				return;
			}
			//���������Ϸ �˳���Ϸ�ͳ���
			else if (Img_switch(WIDTH / 2 - 300 / 2, HEIGHT / 2 + 82, 300, 41, &img_Start[2], &img_Start[4]))
			{
				mciSendString("close bgm", NULL, 0, NULL);  // �ر�����

				closegraph();   //�ر���Ϸ���� 
				FreeConsole();  //�رտ���̨����
				exit(0);        //�˳�����
			}
		}
		EndBatchDraw();
		BeginBatchDraw();
	}
}

// ������ͣ��ʾ����
void drawPauseText()
{
	if (isPaused)
	{
		settextcolor(RED);
		settextstyle(40, 0, _T("����"));
		outtextxy(WIDTH / 2 - 80, HEIGHT / 2 - 20, _T("��Ϸ��ͣ"));
	}
}

// �������Ѫ�� 
void drawPlayerHP()
{
	TCHAR hpText[20];
	_stprintf_s(hpText, _T("Ѫ��: %d"), player.hp);
	settextcolor(GREEN);
	settextstyle(30, 0, _T("����"));
	setbkmode(TRANSPARENT);
	outtextxy(0, 60, hpText);
}

void drawWeapons();

//��ͼ---��ӡ���ͼƬ����Ϸ����.
void gameDraw()
{
	putimage(0, 0, &bk);//����

	drawWeapons();  //���ƿ�Ͷ����

	// ������ҷɻ���ը����  
	if (player.live)
	{
		//drawImg(player.x, player.y, &img_plane[0]);   //��ҷɻ�ͼƬ
		//drawImg(player.x, player.y, &img_plane[1]);

		// ���Ʒɻ�����֡�л���ÿ 200 �����л�һ�Σ�
		DWORD currentTime = GetTickCount();
		if (currentTime - planeFrameTimer > PLANE_FRAME_DELAY)
		{
			planeFrame = 1 - planeFrame;  // �л�֡��0��1��0��...��
			planeFrameTimer = currentTime;  // ���ü�ʱ��
		}
		// ���ݵ�ǰ֡���ƶ�Ӧ�ķɻ�ͼƬ
		drawImg(player.x, player.y, &img_plane[planeFrame]);
	}
	else if (isPlayerExploding && player.explodeFrame < 4)
	{
		// ������ұ�ը����
		drawImg(player.x, player.y, &img_hero_blowup[player.explodeFrame]);
	}

	drawWeapons();  //���ƿ�Ͷ����

	//������ͣ��ť ��ʵ�ֵ��
	drawPauseControl();  // ������ͣ����ͼ��
	// ������ͣ��ť���
	if (InArea(msg.x, msg.y, WIDTH - img_pause[0].getwidth(), 0,
		img_pause[0].getwidth(), img_pause[0].getheight()) && msg.message == WM_LBUTTONDOWN)
	{
		togglePause();
		msg.message = 0;  //������Ϣ
	}

	//�����ӵ�
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bull[i].live)
		{
			drawImg(bull[i].x, bull[i].y, bull[i].type ? &img_bull[0] : &img_bull[1]);   //isBulletType1=true��ӡimg_bull[0],��false��ӡimg_bull[1]
			//drawImg(bull[i].x, bull[i].y, &img_bull[1]);
		}
	}

	//���Ƶл�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live && !enemy[i].exploding)  //ֻ���ƻ����Ҳ��ڱ�ը״̬�ĵл�
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

	//���Ʊ�ը����
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].exploding)
		{
			// ���ݵл����ͺ͵�ǰ֡���Ʊ�ը����
			if (enemy[i].type == SMALL)
			{
				if (enemy[i].explodeFrame < 4)
				{
					drawImg(enemy[i].x, enemy[i].y, &img_enemy1_down[enemy[i].explodeFrame]);  //enemy[i].explodeFrame��һ��֡������(�ǵ�ǰ֡��,��ȡ֡���ֵ����[enemy[i].explodeFrame]��Ϊ��������)�����ڿ��Ƶл���ը�����Ĳ��Ž��ȡ�
				}                                                                              //����������ָ����ǰӦ����ʾ��ը��������һ֡��
			}
			else if (enemy[i].type == MEDIUM)
			{
				if (enemy[i].explodeFrame < 4)
				{
					drawImg(enemy[i].x, enemy[i].y, &img_enemy2_down[enemy[i].explodeFrame]);
				}
			}
			else if (enemy[i].type == BIG)
			{
				if (enemy[i].explodeFrame < 6)
				{
					drawImg(enemy[i].x, enemy[i].y, &img_enemy3_down[enemy[i].explodeFrame]);
				}
			}
		}
	}

	// ���Ƶ�ǰ�÷�
	TCHAR scoreText[20];
	_stprintf_s(scoreText, _T("�÷�: %d"), score);
	settextcolor(RGB(6, 55, 207));
	settextstyle(30, 0, _T("����"));
	setbkmode(TRANSPARENT);
	outtextxy(0, 100, scoreText);

	drawMusicControl();  // �������ֿ���ͼ��
	drawPauseControl();  // ������ͣ����ͼ��
	drawPauseText();     // ������ͣ��ʾ����
	drawPlayerHP();      // �������Ѫ�� 
}

// ���ɿ�Ͷ����
void createWeapon()
{
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		if (!weapon[i].live)  // ���߲�����ʱ
		{
			weapon[i].x = rand() % (WIDTH - weapon[i].width);  // ���x����
			weapon[i].y = -weapon[i].height;  // ����Ļ�����⿪ʼ
			weapon[i].live = true;
			weapon[i].type = rand() % 2;  // �����������
			break;
		}
	}
}

// ��Ͷ�����ƶ�
void weaponMove()
{
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		if (weapon[i].live)
		{
			weapon[i].y += 1;  // ��Ͷ�ƶ��ٶ�

			// �ж��Ƿ����
			if (weapon[i].y > HEIGHT)
			{
				weapon[i].live = false;
			}
		}
	}
}

// ��Ͷ�����������ײ���
void checkWeaponCollision()
{
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		if (weapon[i].live && player.live && !isPlayerExploding)
		{
			// ��ײ���
			if (weapon[i].x < player.x + player.width &&
				weapon[i].x + weapon[i].width > player.x &&
				weapon[i].y < player.y + player.height &&
				weapon[i].y + weapon[i].height > player.y)
			{
				// �Ե����ߣ��ӷ�
				if (weapon[i].type == 0)
				{
					score += 4;  // weapon1��4��
				}
				else
				{
					score += 8;  // weapon2��8��
				}

				weapon[i].live = false;  // ������ʧ
			}
		}
	}
}

// ���ƿ�Ͷ����
void drawWeapons()
{
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		if (weapon[i].live)
		{
			drawImg(weapon[i].x, weapon[i].y, &img_weapon[weapon[i].type]);
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
			bull[i].type = isBulletType1;  // ��¼��ǰ�ӵ�����
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
			printf("���ɵл� %d: ����=%d, HP=%d, x=%d, y=%d\n", i, enemy[i].type, enemy[i].hp, enemy[i].x, enemy[i].y);


			break;
		}
	}
}

//�л��ƶ�
void enemyMove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live && !enemy[i].exploding)  //ֻ�л�����û���ڱ�ը�еĵл��ƶ�
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
				printf("�л� %d (����=%d, HP=%d) ���磬y=%d\n", i, enemy[i].type, enemy[i].hp, enemy[i].y);


				enemy[i].live = false;
			}
		}
	}
}


//�ƶ���ҷɻ�---��������
void playerMove(int speed)
{
	// ���Shift�����£��л��ӵ����ͣ�ֻ���ɿ�ʱ�л�һ�Σ����������л���
	static bool shiftPressed = false;
	if (GetAsyncKeyState(VK_SHIFT))
	{
		if (!shiftPressed)
		{
			isBulletType1 = !isBulletType1;  // �л��ӵ�ͼƬ״̬
			shiftPressed = true;  //��δ���������Ǳ�� Shift ���ѱ����£��Ӷ�ȷ���ӵ�����ֻ�� Shift �����µ�˲���л�һ�Σ������ǳ����л���
		}
	}
	else
	{
		shiftPressed = false;
	}

	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (player.y > 0)
		{
			player.y -= speed;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (player.y + 126 < HEIGHT)
		{
			player.y += speed;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		if (player.x + 51 > 0)
		{
			player.x -= speed;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if (player.x + 51 < WIDTH)
		{
			player.x += speed;
		}
	}

	//�������ְ�ť���
	if (msg.message == WM_LBUTTONDOWN)
	{
		if (InArea(msg.x, msg.y, 10, 10, img_music[0].getwidth(), img_music[0].getheight()))
		{
			toggleMusic();
			msg.message = 0;
		}

		// ������ͣ��ť���
		if (InArea(msg.x, msg.y, WIDTH - img_pause[0].getwidth(), 0,
			img_pause[0].getwidth(), img_pause[0].getheight()))
		{
			togglePause();
			msg.message = 0;
		}
	}

	//���ӳ�Ч�������ӵ��ƶ���˿���������ڰ�һ�¿ո���ֶ���ӵ�.
	static DWORD t1 = 0;
	DWORD t2 = GetTickCount();   //����t2Ϊ��ǰʱ�䣬GetTickCount()��clock()���ƶ��ǻ�ȡ��ǰʱ��ĺ���(����ͷ�ļ�����λ���������ͺ����ó����ȶ�����ͬ).
	//���ո����ӵ�.                              
	if (GetAsyncKeyState(VK_SPACE) && t2 - t1 > 200 && player.live && !isPaused && !isGameOver)     //t1��ʾ�ϴη����ӵ�ʱ��(����),t2��ʾ��ǰʱ��(����),t2-t1�ͱ�ʾ�����ӵ�����ȴʱ��(��һ�ΰ��ո���Ҫ����һ�ΰ��ո��50����Ż���Ч���Żᷢ���µ��ӵ�).
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
		if (!enemy[i].live || enemy[i].exploding)  //���������������ڱ�ը�ĵл�(�ӵ������������������ڱ�ը�еĵл���ײ).
			continue;

		if (bull[k].x > enemy[i].x &&
			bull[k].x < enemy[i].x + enemy[i].width &&
			bull[k].y > enemy[i].y &&
			bull[k].y < enemy[i].y + enemy[i].height)
		{
			//���
			printf("�ӵ� %d ���ел� %d (����=%d, HP=%d)\n", k, i, enemy[i].type, enemy[i].hp);

			bull[k].live = false;
			enemy[i].hp--;          // �л���Ѫ

			if (enemy[i].hp <= 0)
			{
				//���
				printf("�л� %d (����=%d) ���ݻ٣�\n", i, enemy[i].type);

				// ���ݵл����ͼӷ�
				switch (enemy[i].type)
				{
				case SMALL:
					score += 1;  // С�л�1��
					break;
				case MEDIUM:
					score += 2;  // �ел�2��
					break;
				case BIG:
					score += 3;  // ��л�3��
					break;
				}
				printf("�÷�: %d\n", score);  // �����ǰ�÷�

				// ��ʼ��ը����
				enemy[i].exploding = true;       // ���Ϊ��ը��
				enemy[i].explodeFrame = 0;       // ��ʼ֡
				enemy[i].explodeTimer = GetTickCount();  // ��¼��ը��ʼʱ��
				// ע�⣺��ʱ������enemy[i].live = false������liveΪtrue����ʾ��ը

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



// �ӳ�---��ʱ��������֧����ͣ����
bool Time(int ms, int id, bool shouldCount = true)
{
	static DWORD t[10] = { 0 };
	static bool initialized[10] = { false };
	static DWORD pauseTime[10] = { 0 };
	static bool wasPaused[10] = { false };

	// ��ʼ����ʱ��
	if (!initialized[id]) {
		t[id] = GetTickCount();
		initialized[id] = true;
		printf("��ʼ����ʱ�� %d����ǰʱ��: %lu\n", id, t[id]);
		return false;
	}

	// ������ͣ״̬
	if (!shouldCount) {
		if (!wasPaused[id]) {
			pauseTime[id] = GetTickCount();
			wasPaused[id] = true;
			printf("��ͣ��ʱ�� %d����ͣʱ��: %lu\n", id, pauseTime[id]);
		}
		return false;
	}

	// �ָ���ʱ
	if (wasPaused[id]) {
		DWORD pauseDuration = GetTickCount() - pauseTime[id];
		t[id] += pauseDuration;  // �����ϴδ���ʱ�䣬������ͣ�ڼ�
		wasPaused[id] = false;
		printf("�ָ���ʱ�� %d���������ʱ��: %lu����ͣ�� %lu ����\n", id, t[id], pauseDuration);
	}

	DWORD currentTime = GetTickCount();
	bool result = (currentTime - t[id] > ms);

	if (result) {
		t[id] = currentTime;
		printf("��ʱ�� %d ��������ǰʱ��: %lu�����: %d ����\n", id, currentTime, ms);
	}

	return result;
}

//�������
int main()
{
	//������Ϸ����
	initgraph(WIDTH, HEIGHT, 1);

	//��ʼ�������ű�������
	initMusic();


	//���ؿ�ʼ����ͼƬ
	loadImg_start();

	//�����ӡ��ʼ����
	BeginBatchDraw();
	putImg_Start();
	EndBatchDraw();

	//��ʼ�����������
	srand((unsigned int)time(NULL));    //ȷ��ÿ����Ϸ����ʱ�л����ͺ�����λ�õ������

	//��ʼ��
	gameInit();

	//��ʼ����Ч��
	game_start();

	//˫����---��ֹ����.
	BeginBatchDraw();  //�ڽ��� game_start() ����֮ǰ�����������Ѿ������� BeginBatchDraw()����˳�ʼ״̬�Ǵ���������ͼģʽ�ġ�
	//�� game_start() ��ѭ���У��Ȼ��ƽ������ݣ�putImg_Start()����Ȼ����� EndBatchDraw() ���ڴ��е�ͼ����ʾ����Ļ�ϡ�
	//�����ŵ��� BeginBatchDraw() ���¿���������ͼģʽ��Ϊ��һ��ѭ���Ļ�����׼����
	//Ҳ����˵���������BeginBatchDraw��game_start��ĵ�һ��EndBatchDraw��һ�ԣ�ִ��������BeginBatchDraw(���������)������Ժ������Ӱ��
	while (1)
	{
		//����(��ֹ��Ӱ)
		cleardevice();

		// ���������Ϣ
		while (peekmessage(&msg, EX_MOUSE))
		{

		}

		// ��Ϸ����ʱ������Ϸ��������
		if (isGameOver)
		{
			drawGameOver();
		}
		// ֻ����δ��ͣ״̬�²Ÿ�����Ϸ״̬
		else if (!isPaused)
		{
			playerMove(10);  //��ҷɻ��ƶ�
			BullteMove();    //�ӵ��ƶ�

			//��ʱ���ɵл�
			if (Time(2000, 0,true))  //ÿ2������һ��
			{
				createEnemy();  //���ɷɻ�
			}

			if (Time(15000, 1,true))  // ÿ15������һ����Ͷ  ������Ϸδ��ͣʱ��ʱ
			{
				createWeapon();
			}

			enemyMove();   //�л��ƶ�
			weaponMove();  //��Ͷ�����ƶ�
			play();        //����
			checkWeaponCollision();  // ����Ͷ�����������ײ
			handleExplosions();  //����ը����
			checkPlayerCollision();    // ��������л���ײ 
			handlePlayerExplosion();   // ������ұ�ը���� 
		}
		else if (isPaused)
		{
			// ����ͣ״̬�£����߼�ʱ����Ҫ����
			Time(0, 0, false);
			Time(0, 1, false);
		}

		if (!isGameOver)
		{
			gameDraw();
		}

		//�����Ƿ���ͣ����Ҫ���ƽ���
		//gameDraw();   //����������õ�����ͼ͸����ͼ�Ļ�������whileѭ�������е�ʱ���һ��һ����(��ʱ����Ҫ��˫����).

		FlushBatchDraw(); //ÿ��ѭ��ˢ��һ��ҳ��.

		Sleep(16);  //����֡�ʣ�Լ60֡ÿ��
	}

	mciSendString("close bgm", NULL, 0, NULL);  // �ر�����

	closegraph();   //�ر���Ϸ����
	return 0;
}




//�����Ϣ��
	//�� Windows ����У������Ϣ��һ���¼������Ļ��ơ����û��ƶ���ꡢ�����ťʱ��ϵͳ��������Ӧ����Ϣ��������Ϣ������.
	//������Ҫ�Ӷ����л�ȡ��Щ��Ϣ�����д���.
	// 
	//�� EasyX ͼ�ο��У���Ҫͨ�����º������������Ϣ��
	//peekmessage(&msg, EX_MOUSE)�����Ϣ�������Ƿ��������Ϣ�����ȴ���������У�����Ϣ���ݴ���msg�ṹ�壬������true�����򷵻�false.
	//getmessage(&msg, EX_MOUSE)����Ϣ�����л�ȡ�����Ϣ�����û����ȴ�����ͬ������Ϣ����msg�ṹ��.
	//
	//��Ϣ�ṹ�� ExMessage��
	//ExMessage �� EasyX �������Ϣ�ṹ�壬�������¹ؼ���Ա��
	//message����Ϣ���ͣ���WM_LBUTTONDOWN��ʾ������£�.
	//x, y���������.
	//lParam���������������갴��״̬��.
	//���磬���û����������ʱ��msg.message ��ֵΪ WM_LBUTTONDOWN��ͬʱ msg.x �� msg.y ��¼�˵��λ��.
	// 
    //��Ϣ�� "һ����" ���ԣ�
    //�����Ϣһ��������Ӧ�ñ����Ϊ "�Ѵ���"��������ܱ��ظ�����
	// 
	// while (peekmessage(&msg, EX_MOUSE)) 
	// {
    //     ������Ϣ...
	// }
    //��Ϣѭ���Ĺ�����ʽ��
	//����ѭ��������������� while ѭ��ʱ����ʼ�����Ϣ���С�
	//��ȡһ����Ϣ��peekmessage �Ӷ�����ȡ��һ�������Ϣ������У������� msg �ṹ�壬������ true��
	//����������Ϣ��ִ��ѭ�����еĴ��루����������Ƿ���������ͼ�꣩��
	//����ѭ���������굱ǰ��Ϣ���ٴε��� peekmessage ���������Ƿ�����һ����Ϣ��
	//�˳�����������Ϣ������û�и��������Ϣʱ��peekmessage ���� false��ѭ����ֹ���������ִ��ѭ��֮��Ĵ��롣
	//��������㣬ͬһ����Ϣ���ܻᱻ��δ������磬ͬʱ��������ͼ��Ͱ�ť����Ӧ����
	//��Ϣѭ����ִ�з�ʽ��
	//���ǻ�ȡһ����Ϣ������ѭ��������ѭ��������������Ϣ����˳���
	//ÿ��ѭ����������һ����Ϣ��ֱ������Ϊ�ա�
	// 
	//��ѭ�������������Ϣ�б�ʹ������Ϸ��ѭ���У����������Ϣ��רע�ڼ��̿��ơ�
    //
