#include<stdio.h>
#include<graphics.h>       //图形界面库的头文件
#include"TransparentImage.h"
#include<time.h>
#include<mmsystem.h>       // 多媒体设备接口头文件
#pragma comment(lib, "winmm.lib")  // 链接多媒体库

int planeFrame = 0;          // 飞机动画帧计数器（0 或 1）
DWORD planeFrameTimer = 0;   // 飞机帧切换计时器
const int PLANE_FRAME_DELAY = 200;  // 帧切换间隔（毫秒）



#define WEAPON_NUM 3  // 空投道具最大数量

IMAGE bk;            //背景图片
IMAGE img_Start[5];  //开始图片
IMAGE img_plane[2];  //飞机图片
IMAGE img_bull[2];   //子弹图片
IMAGE img_enemy[3];  //敌机图片
IMAGE img_music[2];  // 音乐控制图片(正常和高光)
IMAGE img_pause[2];  // 暂停按钮图片(正常和高光)
IMAGE img_resume[2]; // 继续按钮图片(正常和高光)
IMAGE img_weapon[2];  // 空投道具图片

//爆炸动画图片
IMAGE img_enemy1_down[4];  // 小敌机爆炸动画(4帧)
IMAGE img_enemy2_down[4];  // 中敌机爆炸动画(4帧)
IMAGE img_enemy3_down[6];  // 大敌机爆炸动画(6帧)

IMAGE img_hero_blowup[4];  // 玩家飞机爆炸动画(4帧) 
IMAGE img_gameover;        // 游戏结束背景图片 
IMAGE img_dead;            // "您已阵亡"图片 
IMAGE img_restart[2];      // 重新开始按钮图片(正常和高光) 
IMAGE img_quit[2];         // 结束游戏按钮图片(正常和高光) 


bool isMusicPlaying = true;  // 音乐播放状态，默认播放
bool isPaused = false;       // 游戏暂停状态，默认不暂停
bool isBulletType1 = true;   // 子弹类型状态（true为第一种子弹，false为第二种）
bool isGameOver = false;     // 游戏结束状态 
bool isPlayerExploding = false; // 玩家是否正在爆炸 

int score = 0;  // 添加分数变量，记录玩家得分

ExMessage msg = { 0 };//定义消息的结构体变量

enum My
{
	WIDTH = 480,     //游戏窗口宽高.
	HEIGHT = 850,
	BULLET_NUM = 15, //子弹数量
	BIG = 0,         //大敌机
	MEDIUM = 1,      //中敌机
	SMALL = 2,       //小敌机
	ENEMY_NUM = 10   //敌机数量
};

//定义飞机属性
struct Plane
{
	int x;
	int y;
	bool live;  //玩家是否死亡.

	int width;
	int height;
	int hp;     //敌机血量/玩家血量 
	int type;   //敌机类型/子弹类型

	//爆炸相关属性
	bool exploding;     // 是否正在爆炸
	int explodeFrame;   // 当前爆炸帧
	DWORD explodeTimer; // 爆炸动画计时器

}player, bull[BULLET_NUM], enemy[ENEMY_NUM];

// 定义空投道具属性
struct Weapon
{
	int x;
	int y;
	bool live;  // 是否存在
	int type;   // 0为weapon1，1为weapon2
	int width;
	int height;
};
Weapon weapon[WEAPON_NUM];  // 空投道具数组

// 加载开始/结束界面图片
void loadImg_start()
{
	//背景图片
	loadimage(&bk, "./Resource/images/background.png");

	//开始游戏 结束游戏按钮图片
	loadimage(&img_Start[0], "./Resource/images/title.png");        //标题
	loadimage(&img_Start[1], "./Resource/images/开始游戏.png");     //开始游戏
	loadimage(&img_Start[2], "./Resource/images/结束游戏.png");     //结束游戏
	loadimage(&img_Start[3], "./Resource/images/开始游戏2.png");    //开始游戏2
	loadimage(&img_Start[4], "./Resource/images/结束游戏2.png");    //结束游戏2

	// 加载游戏结束相关图片 
	loadimage(&img_gameover, "./Resource/images/background.png");       //结束背景
	loadimage(&img_dead, "./Resource/images/titleover.png");            //结束标题
	loadimage(&img_restart[0], "./Resource/images/重新开始.png");       //重新开始正常
	loadimage(&img_restart[1], "./Resource/images/重新开始高光.png");   //重新开始高光
	loadimage(&img_quit[0], "./Resource/images/退出游戏.png");          //退出游戏正常
	loadimage(&img_quit[1], "./Resource/images/退出游戏高光.png");      //退出游戏高光
}

//判断鼠标是否在按钮区域
bool InArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx < x + w && my > y && my < y + h)
	{
		return true;
	}
	return false;
}

// 初始化背景音乐
void initMusic()
{
	// 打开并播放背景音乐，循环播放
	mciSendString("open ./Resource/sound/game_music.mp3 alias bgm", NULL, 0, NULL); //打开
	mciSendString("play bgm repeat", NULL, 0, NULL);  //循环播放
}

// 切换音乐播放状态
void toggleMusic()
{
	if (isMusicPlaying)
	{
		mciSendString("pause bgm", NULL, 0, NULL);  // 暂停音乐
	}
	else
	{
		mciSendString("resume bgm", NULL, 0, NULL);  // 继续播放
	}
	isMusicPlaying = !isMusicPlaying;
}

// 切换游戏暂停状态
void togglePause()
{
	isPaused = !isPaused;
	// 如果暂停游戏，同时暂停音乐；继续游戏，同时继续音乐
	if (isPaused)
	{
		if (isMusicPlaying)   //防止玩家已经主动点击音乐开关暂停了音乐后，点击暂停按钮又一次暂停音乐(已经暂停后又一次暂停->无用功),以此减少CPU使用率
		{
			mciSendString("pause bgm", NULL, 0, NULL);  // 暂停音乐
		}
	}
	else
	{
		if (isMusicPlaying)
		{
			mciSendString("resume bgm", NULL, 0, NULL);  // 继续播放
		}
	}
}

// 绘制并处理音乐控制图标
void drawMusicControl()
{
	int x = 0;  // 左上角位置
	int y = 0;
	int w = img_music[0].getwidth();  //获取音乐图标宽高
	int h = img_music[0].getheight();

	// 处理鼠标交互
	if (InArea(msg.x, msg.y, x, y, w, h))
	{
		drawImg(x, y, &img_music[1]);  // 鼠标悬停显示高光图片

		// 处理鼠标点击
		if (msg.message == WM_LBUTTONDOWN)
		{
			toggleMusic();
			msg.message = 0;  // 重置消息，避免重复处理
		}
	}
	else
	{
		drawImg(x, y, &img_music[0]);  // 正常显示
	}
}

// 绘制并处理暂停/继续控制图标
void drawPauseControl()
{
	// 右上角位置
	int x = WIDTH - img_pause[0].getwidth();
	int y = 0;
	int w, h;

	// 根据当前状态选择显示的图片
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

	// 处理鼠标交互
	if (InArea(msg.x, msg.y, x, y, w, h))
	{
		drawImg(x, y, hoverImg);  // 鼠标悬停显示高光图片

		// 处理鼠标点击
		if (msg.message == WM_LBUTTONDOWN)
		{
			togglePause();
			msg.message = 0;  // 重置消息，避免重复处理
		}
	}
	else
	{
		drawImg(x, y, normalImg);  // 正常显示
	}
}

//输出打印开始界面
void putImg_Start()
{
	putimage(0, 0, &bk);//背景
	drawImg(WIDTH / 2 - 441 / 2, HEIGHT / 2 - 200, &img_Start[0]);  //标题
	drawImg(WIDTH / 2 - 300 / 2, HEIGHT / 2, &img_Start[1]);        //开始游戏
	drawImg(WIDTH / 2 - 300 / 2, HEIGHT / 2 + 82, &img_Start[2]);   //结束游戏
}

//判断鼠标是否悬停
bool isHover(int x, int y, int w, int h, IMAGE* img_Normal, IMAGE* img_Hover)  // 根据鼠标是否悬停选择显示的图片
{
	if (InArea(msg.x, msg.y, x, y, w, h))
	{
		drawImg(x, y, img_Hover);  //鼠标悬停时打印高亮图片
		return true;
	}
	else
	{
		drawImg(x, y, img_Normal);//鼠标没有悬停时打印正常图片
		return false;
	}
}

//改变颜色  点击判断
bool Img_switch(int x, int y, int w, int h, IMAGE* img_Normal, IMAGE* img_Hover)
{
	isHover(x, y, w, h, img_Normal, img_Hover);

	//点击按钮
	if (msg.message == WM_LBUTTONDOWN && InArea(msg.x, msg.y, x, y, w, h))
	{
		return true;
	}
	return false;
}

void gameInit();
void putImg_Music();

// 绘制游戏结束界面 
void drawGameOver()
{
	// 绘制游戏结束背景
	putimage(0, 0, &img_gameover);

	//绘制音乐图标
	putImg_Music();

	// 绘制得分
	TCHAR scoreText[20];
	_stprintf_s(scoreText, _T("得分： %d"), score);
	settextcolor(RGB(110, 104, 89));
	settextstyle(60, 0, _T("素材集市康康体"));
	setbkmode(TRANSPARENT);
	outtextxy(WIDTH / 2 - textwidth(scoreText) / 2 - 10, HEIGHT / 2 - 200, scoreText);

	// 绘制"您已阵亡"图片
	drawImg(WIDTH / 2 - img_dead.getwidth() / 2, HEIGHT / 2 - 150, &img_dead);

	// 绘制重新开始按钮
	if (Img_switch(WIDTH / 2 - 300 / 2, HEIGHT / 2, 300, 41, &img_restart[0], &img_restart[1]))
	{
		// 重新开始游戏
		isGameOver = false;
		score = 0;  // 重置分数
		gameInit(); // 重新初始化游戏
		msg.message = 0;
	}

	// 绘制退出游戏按钮
	if (Img_switch(WIDTH / 2 - 300 / 2, HEIGHT / 2 + 82, 300, 41, &img_quit[0], &img_quit[1]))
	{
		// 退出游戏
		mciSendString("close bgm", NULL, 0, NULL);
		closegraph();
		FreeConsole();
		exit(0);
	}
}

// 处理玩家爆炸动画 
void handlePlayerExplosion()
{
	if (!isPlayerExploding)
	{
		return;
	}

	DWORD currentTime = GetTickCount();

	// 控制爆炸动画帧率
	if (currentTime - player.explodeTimer > 100)
	{
		player.explodeFrame++;
		player.explodeTimer = currentTime;

		// 爆炸动画结束，游戏结束
		if (player.explodeFrame >= 4)
		{
			isPlayerExploding = false;
			isGameOver = true;
		}
	}
}

// 检测玩家与敌机碰撞 
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
			// 简单的矩形碰撞检测
			if (player.x + player.width > enemy[i].x &&
				player.x < enemy[i].x + enemy[i].width &&
				player.y + player.height > enemy[i].y &&
				player.y < enemy[i].y + enemy[i].height)
			{
				// 敌机爆炸
				enemy[i].exploding = true;
				enemy[i].explodeFrame = 0;
				enemy[i].explodeTimer = GetTickCount();

				// 玩家减血
				int damage = 0;
				switch (enemy[i].type)
				{
				case SMALL: damage = 1; break;
				case MEDIUM: damage = 2; break;
				case BIG: damage = 3; break;
				}
				player.hp -= damage;

				// 输出玩家血量信息
				printf("玩家受到 %d 点伤害，剩余血量: %d\n", damage, player.hp);

				// 判断玩家是否死亡
				if (player.hp <= 0)
				{
					player.live = false;
					isPlayerExploding = true;
					player.explodeFrame = 0;
					player.explodeTimer = GetTickCount();
				}

				// 标记敌机为非活动状态
				enemy[i].live = false;
				break;
			}
		}
	}
}

//初始化图片---加载图片.
void loadImg()
{
	//背景图片
	loadimage(&bk, "./Resource/images/background.png");           // ./代表在当前目录下(即源文件所在的目录)，相对路径时使用，可以省略.
	//玩家飞机图片
	loadimage(&img_plane[0], "./Resource/images/hero1.png");
	loadimage(&img_plane[1], "./Resource/images/hero2.png");
	//子弹图片
	loadimage(&img_bull[0], "./Resource/images/bullet1.png");
	loadimage(&img_bull[1], "./Resource/images/bullet2.png");

	//敌机图片---三种类型
	loadimage(&img_enemy[0], "./Resource/images/enemy1.png");     //小敌机
	loadimage(&img_enemy[1], "./Resource/images/enemy2.png");     //中敌机
	loadimage(&img_enemy[2], "./Resource/images/enemy3_n1.png");  //大敌机

	//加载爆炸动画图片
	loadimage(&img_enemy1_down[0], "./Resource/images/enemy1_down1.png"); //小敌机
	loadimage(&img_enemy1_down[1], "./Resource/images/enemy1_down2.png");
	loadimage(&img_enemy1_down[2], "./Resource/images/enemy1_down3.png");
	loadimage(&img_enemy1_down[3], "./Resource/images/enemy1_down4.png");

	loadimage(&img_enemy2_down[0], "./Resource/images/enemy2_down1.png"); //中敌机
	loadimage(&img_enemy2_down[1], "./Resource/images/enemy2_down2.png");
	loadimage(&img_enemy2_down[2], "./Resource/images/enemy2_down3.png");
	loadimage(&img_enemy2_down[3], "./Resource/images/enemy2_down4.png");

	loadimage(&img_enemy3_down[0], "./Resource/images/enemy3_down1.png"); //大敌机
	loadimage(&img_enemy3_down[1], "./Resource/images/enemy3_down2.png");
	loadimage(&img_enemy3_down[2], "./Resource/images/enemy3_down3.png");
	loadimage(&img_enemy3_down[3], "./Resource/images/enemy3_down4.png");
	loadimage(&img_enemy3_down[4], "./Resource/images/enemy3_down5.png");
	loadimage(&img_enemy3_down[5], "./Resource/images/enemy3_down6.png");

	// 加载音乐控制图片
	loadimage(&img_music[0], "./Resource/images/正常.png");
	loadimage(&img_music[1], "./Resource/images/高光.png");

	// 加载暂停/继续按钮图片
	loadimage(&img_pause[0], "./Resource/images/暂停.png");
	loadimage(&img_pause[1], "./Resource/images/暂停高光.png");
	loadimage(&img_resume[0], "./Resource/images/继续.png");
	loadimage(&img_resume[1], "./Resource/images/继续高光.png");

	// 加载玩家飞机爆炸图片
	loadimage(&img_hero_blowup[0], "./Resource/images/hero_blowup_n1.png");
	loadimage(&img_hero_blowup[1], "./Resource/images/hero_blowup_n2.png");
	loadimage(&img_hero_blowup[2], "./Resource/images/hero_blowup_n3.png");
	loadimage(&img_hero_blowup[3], "./Resource/images/hero_blowup_n4.png");

	//空投道具图片
	loadimage(&img_weapon[0], "./Resource/images/weapon1.png");
	loadimage(&img_weapon[1], "./Resource/images/weapon2.png");
}

//初始化敌机属性
void enemyHP(int i)
{
	int ret = rand() % 100;
	//小敌机
	if (ret < 60)   //生成0-99之间的随机数，小于60就是0-59(60个数)，即60%
	{
		enemy[i].type = SMALL;
		enemy[i].hp = 1;
		enemy[i].width = 57;
		enemy[i].height = 43;
	}
	//中敌机
	else if (ret < 84)  //需要if不满足才会进入else if，所以满足条件是60-83(24个数)，即24%
	{
		enemy[i].type = MEDIUM;
		enemy[i].hp = 3;
		enemy[i].width = 69;
		enemy[i].height = 99;
	}
	//大敌机
	else                         //满足条件是84-99(16个数)，即16%
	{
		enemy[i].type = BIG;
		enemy[i].hp = 5;
		enemy[i].width = 119;
		enemy[i].height = 208;
	}

	//初始化爆炸相关属性
	enemy[i].exploding = false;
	enemy[i].explodeFrame = 0;
	enemy[i].explodeTimer = 0;

	// 确保敌机HP初始值正确
	printf("初始化敌机 %d: 类型=%d, HP=%d\n", i, enemy[i].type, enemy[i].hp);
}

//处理爆炸动画
void handleExplosions()
{
	DWORD currentTime = GetTickCount();

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].exploding)
		{
			// 控制爆炸动画帧率，每100毫秒切换一帧
			if (currentTime - enemy[i].explodeTimer > 100)
			{
				enemy[i].explodeFrame++;
				enemy[i].explodeTimer = currentTime;

				// 根据敌机类型判断动画是否结束
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

//初始化
void gameInit()
{
	//加载图片
	loadImg();

	//玩家飞机
	player.x = WIDTH / 2;
	player.y = HEIGHT - 120;
	player.live = true;       //true代表活着，false代表死亡.
	player.width = 102;  // 玩家飞机宽度
	player.height = 126; // 玩家飞机高度
	player.hp = 10;      // 玩家初始血量 10

	// 初始化玩家爆炸属性 
	player.exploding = false;
	player.explodeFrame = 0;
	player.explodeTimer = 0;

	//子弹
	for (int i = 0; i < BULLET_NUM; i++)
	{
		bull[i].x = 0;
		bull[i].y = 0;
		bull[i].live = false;
	}

	//敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//还没有敌机
		enemy[i].live = false;
		//生产敌机
		enemyHP(i);
	}

	//空投道具
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		weapon[i].live = false;
		weapon[i].width = img_weapon[0].getwidth();
		weapon[i].height = img_weapon[0].getheight();
	}
}
  
//输出打印音乐图标
void putImg_Music()
{
	drawMusicControl();  // 绘制音乐控制图标
}

//开始界面总体
void game_start()
{
	while (1)
	{
		putImg_Music();

		while (peekmessage(&msg, EX_MOUSE))  //持续获取鼠标消息 进入循环 做出对应处理
		{
			// 处理音乐按钮点击
			if (InArea(msg.x, msg.y, 0, 0, img_music[0].getwidth(), img_music[0].getheight()) && msg.message == WM_LBUTTONDOWN)
			{
				toggleMusic();
				msg.message = 0;  //重置消息
			}

			//点击开始游戏 进入游戏
			if (Img_switch(WIDTH / 2 - 300 / 2, HEIGHT / 2, 300, 41, &img_Start[1], &img_Start[3]))
			{
				cleardevice();
				return;
			}
			//点击结束游戏 退出游戏和程序
			else if (Img_switch(WIDTH / 2 - 300 / 2, HEIGHT / 2 + 82, 300, 41, &img_Start[2], &img_Start[4]))
			{
				mciSendString("close bgm", NULL, 0, NULL);  // 关闭音乐

				closegraph();   //关闭游戏窗户 
				FreeConsole();  //关闭控制台窗口
				exit(0);        //退出程序
			}
		}
		EndBatchDraw();
		BeginBatchDraw();
	}
}

// 绘制暂停提示文字
void drawPauseText()
{
	if (isPaused)
	{
		settextcolor(RED);
		settextstyle(40, 0, _T("宋体"));
		outtextxy(WIDTH / 2 - 80, HEIGHT / 2 - 20, _T("游戏暂停"));
	}
}

// 绘制玩家血量 
void drawPlayerHP()
{
	TCHAR hpText[20];
	_stprintf_s(hpText, _T("血量: %d"), player.hp);
	settextcolor(GREEN);
	settextstyle(30, 0, _T("宋体"));
	setbkmode(TRANSPARENT);
	outtextxy(0, 60, hpText);
}

void drawWeapons();

//贴图---打印输出图片在游戏窗口.
void gameDraw()
{
	putimage(0, 0, &bk);//背景

	drawWeapons();  //绘制空投道具

	// 绘制玩家飞机或爆炸动画  
	if (player.live)
	{
		//drawImg(player.x, player.y, &img_plane[0]);   //玩家飞机图片
		//drawImg(player.x, player.y, &img_plane[1]);

		// 控制飞机动画帧切换（每 200 毫秒切换一次）
		DWORD currentTime = GetTickCount();
		if (currentTime - planeFrameTimer > PLANE_FRAME_DELAY)
		{
			planeFrame = 1 - planeFrame;  // 切换帧（0→1→0→...）
			planeFrameTimer = currentTime;  // 重置计时器
		}
		// 根据当前帧绘制对应的飞机图片
		drawImg(player.x, player.y, &img_plane[planeFrame]);
	}
	else if (isPlayerExploding && player.explodeFrame < 4)
	{
		// 绘制玩家爆炸动画
		drawImg(player.x, player.y, &img_hero_blowup[player.explodeFrame]);
	}

	drawWeapons();  //绘制空投道具

	//绘制暂停按钮 并实现点击
	drawPauseControl();  // 绘制暂停控制图标
	// 处理暂停按钮点击
	if (InArea(msg.x, msg.y, WIDTH - img_pause[0].getwidth(), 0,
		img_pause[0].getwidth(), img_pause[0].getheight()) && msg.message == WM_LBUTTONDOWN)
	{
		togglePause();
		msg.message = 0;  //重置消息
	}

	//绘制子弹
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bull[i].live)
		{
			drawImg(bull[i].x, bull[i].y, bull[i].type ? &img_bull[0] : &img_bull[1]);   //isBulletType1=true打印img_bull[0],是false打印img_bull[1]
			//drawImg(bull[i].x, bull[i].y, &img_bull[1]);
		}
	}

	//绘制敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live && !enemy[i].exploding)  //只绘制活着且不在爆炸状态的敌机
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

	//绘制爆炸动画
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].exploding)
		{
			// 根据敌机类型和当前帧绘制爆炸动画
			if (enemy[i].type == SMALL)
			{
				if (enemy[i].explodeFrame < 4)
				{
					drawImg(enemy[i].x, enemy[i].y, &img_enemy1_down[enemy[i].explodeFrame]);  //enemy[i].explodeFrame是一个帧计数器(是当前帧号,获取帧后把值传给[enemy[i].explodeFrame]作为数组索引)，用于控制敌机爆炸动画的播放进度。
				}                                                                              //它的作用是指定当前应该显示爆炸动画的哪一帧。
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

	// 绘制当前得分
	TCHAR scoreText[20];
	_stprintf_s(scoreText, _T("得分: %d"), score);
	settextcolor(RGB(6, 55, 207));
	settextstyle(30, 0, _T("宋体"));
	setbkmode(TRANSPARENT);
	outtextxy(0, 100, scoreText);

	drawMusicControl();  // 绘制音乐控制图标
	drawPauseControl();  // 绘制暂停控制图标
	drawPauseText();     // 绘制暂停提示文字
	drawPlayerHP();      // 绘制玩家血量 
}

// 生成空投道具
void createWeapon()
{
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		if (!weapon[i].live)  // 道具不存在时
		{
			weapon[i].x = rand() % (WIDTH - weapon[i].width);  // 随机x坐标
			weapon[i].y = -weapon[i].height;  // 从屏幕顶部外开始
			weapon[i].live = true;
			weapon[i].type = rand() % 2;  // 随机道具类型
			break;
		}
	}
}

// 空投道具移动
void weaponMove()
{
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		if (weapon[i].live)
		{
			weapon[i].y += 1;  // 空投移动速度

			// 判断是否出界
			if (weapon[i].y > HEIGHT)
			{
				weapon[i].live = false;
			}
		}
	}
}

// 空投道具与玩家碰撞检测
void checkWeaponCollision()
{
	for (int i = 0; i < WEAPON_NUM; i++)
	{
		if (weapon[i].live && player.live && !isPlayerExploding)
		{
			// 碰撞检测
			if (weapon[i].x < player.x + player.width &&
				weapon[i].x + weapon[i].width > player.x &&
				weapon[i].y < player.y + player.height &&
				weapon[i].y + weapon[i].height > player.y)
			{
				// 吃到道具，加分
				if (weapon[i].type == 0)
				{
					score += 4;  // weapon1加4分
				}
				else
				{
					score += 8;  // weapon2加8分
				}

				weapon[i].live = false;  // 道具消失
			}
		}
	}
}

// 绘制空投道具
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

//创建一个子弹.
void createBullte()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (!bull[i].live)  //子弹不存在时
		{
			bull[i].x = player.x + 51;  //子弹在飞机中间发出
			bull[i].y = player.y;
			bull[i].live = true;
			bull[i].type = isBulletType1;  // 记录当前子弹类型
			break;
		}
	}
}

//子弹移动
void BullteMove()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bull[i].live)
		{
			bull[i].y -= 5;      //子弹速度
			if (bull[i].y < 0)
			{
				bull[i].live = false;
			}
		}
	}
}

//生成敌机
void createEnemy()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live)
		{
			enemy[i].live = true;
			enemyHP(i);
			enemy[i].x = rand() % (WIDTH - enemy[i].width);   //防止敌机超出游戏窗口
			enemy[i].y = -enemy[i].height;    //敌机从屏幕上方进入

			//检测
			printf("生成敌机 %d: 类型=%d, HP=%d, x=%d, y=%d\n", i, enemy[i].type, enemy[i].hp, enemy[i].x, enemy[i].y);


			break;
		}
	}
}

//敌机移动
void enemyMove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live && !enemy[i].exploding)  //只有活着且没有在爆炸中的敌机移动
		{
			//不同类型敌机速度不同
			int speed = 1;                                 //大敌机速度
			if (enemy[i].type == SMALL) speed = 3;         //小敌机速度
			else if (enemy[i].type == MEDIUM) speed = 2;   //中敌机速度
			//移动
			enemy[i].y += speed;
			//判断敌机是否出界
			if (enemy[i].y > HEIGHT)
			{

				//检测
				printf("敌机 %d (类型=%d, HP=%d) 出界，y=%d\n", i, enemy[i].type, enemy[i].hp, enemy[i].y);


				enemy[i].live = false;
			}
		}
	}
}


//移动玩家飞机---操作键盘
void playerMove(int speed)
{
	// 检测Shift键按下，切换子弹类型（只在松开时切换一次，避免连续切换）
	static bool shiftPressed = false;
	if (GetAsyncKeyState(VK_SHIFT))
	{
		if (!shiftPressed)
		{
			isBulletType1 = !isBulletType1;  // 切换子弹图片状态
			shiftPressed = true;  //这段代码的作用是标记 Shift 键已被按下，从而确保子弹类型只在 Shift 键按下的瞬间切换一次，而不是持续切换。
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

	//处理音乐按钮点击
	if (msg.message == WM_LBUTTONDOWN)
	{
		if (InArea(msg.x, msg.y, 10, 10, img_music[0].getwidth(), img_music[0].getheight()))
		{
			toggleMusic();
			msg.message = 0;
		}

		// 处理暂停按钮点击
		if (InArea(msg.x, msg.y, WIDTH - img_pause[0].getwidth(), 0,
			img_pause[0].getwidth(), img_pause[0].getheight()))
		{
			togglePause();
			msg.message = 0;
		}
	}

	//加延迟效果，让子弹移动更丝滑，不至于按一下空格出现多个子弹.
	static DWORD t1 = 0;
	DWORD t2 = GetTickCount();   //更新t2为当前时间，GetTickCount()和clock()相似都是获取当前时间的函数(但是头文件、单位、返回类型和适用场景等都不相同).
	//按空格发射子弹.                              
	if (GetAsyncKeyState(VK_SPACE) && t2 - t1 > 200 && player.live && !isPaused && !isGameOver)     //t1表示上次发射子弹时间(毫秒),t2表示当前时间(毫秒),t2-t1就表示发射子弹的冷却时间(下一次按空格需要在上一次按空格后50毫秒才会生效，才会发射新的子弹).
	{
		createBullte();
		t1 = t2;
	}
}


// 检测单个子弹与敌机的碰撞
bool checkBulletCollision(int k)
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live || enemy[i].exploding)  //跳过已死亡或正在爆炸的敌机(子弹不与已死亡或者正在爆炸中的敌机碰撞).
			continue;

		if (bull[k].x > enemy[i].x &&
			bull[k].x < enemy[i].x + enemy[i].width &&
			bull[k].y > enemy[i].y &&
			bull[k].y < enemy[i].y + enemy[i].height)
		{
			//检测
			printf("子弹 %d 击中敌机 %d (类型=%d, HP=%d)\n", k, i, enemy[i].type, enemy[i].hp);

			bull[k].live = false;
			enemy[i].hp--;          // 敌机减血

			if (enemy[i].hp <= 0)
			{
				//检测
				printf("敌机 %d (类型=%d) 被摧毁！\n", i, enemy[i].type);

				// 根据敌机类型加分
				switch (enemy[i].type)
				{
				case SMALL:
					score += 1;  // 小敌机1分
					break;
				case MEDIUM:
					score += 2;  // 中敌机2分
					break;
				case BIG:
					score += 3;  // 大敌机3分
					break;
				}
				printf("得分: %d\n", score);  // 输出当前得分

				// 开始爆炸动画
				enemy[i].exploding = true;       // 标记为爆炸中
				enemy[i].explodeFrame = 0;       // 初始帧
				enemy[i].explodeTimer = GetTickCount();  // 记录爆炸开始时间
				// 注意：此时不设置enemy[i].live = false，保持live为true以显示爆炸

			}
			else
			{
				printf("敌机 %d (类型=%d) 剩余HP=%d\n", i, enemy[i].type, enemy[i].hp);			
			}
			return true;  // 子弹已击中目标
		}
	}
	return false;  // 子弹未击中任何敌机
}

// 攻击检测
void play()
{
	for (int k = 0; k < BULLET_NUM; k++)
	{
		if (!bull[k].live)
			continue;

		if (checkBulletCollision(k))  // 如果子弹击中目标，跳过后续检测
			continue;
	}
}



// 延迟---定时器函数，支持暂停功能
bool Time(int ms, int id, bool shouldCount = true)
{
	static DWORD t[10] = { 0 };
	static bool initialized[10] = { false };
	static DWORD pauseTime[10] = { 0 };
	static bool wasPaused[10] = { false };

	// 初始化计时器
	if (!initialized[id]) {
		t[id] = GetTickCount();
		initialized[id] = true;
		printf("初始化计时器 %d，当前时间: %lu\n", id, t[id]);
		return false;
	}

	// 处理暂停状态
	if (!shouldCount) {
		if (!wasPaused[id]) {
			pauseTime[id] = GetTickCount();
			wasPaused[id] = true;
			printf("暂停计时器 %d，暂停时间: %lu\n", id, pauseTime[id]);
		}
		return false;
	}

	// 恢复计时
	if (wasPaused[id]) {
		DWORD pauseDuration = GetTickCount() - pauseTime[id];
		t[id] += pauseDuration;  // 调整上次触发时间，忽略暂停期间
		wasPaused[id] = false;
		printf("恢复计时器 %d，调整后的时间: %lu，暂停了 %lu 毫秒\n", id, t[id], pauseDuration);
	}

	DWORD currentTime = GetTickCount();
	bool result = (currentTime - t[id] > ms);

	if (result) {
		t[id] = currentTime;
		printf("计时器 %d 触发，当前时间: %lu，间隔: %d 毫秒\n", id, currentTime, ms);
	}

	return result;
}

//程序入口
int main()
{
	//创建游戏窗口
	initgraph(WIDTH, HEIGHT, 1);

	//初始化并播放背景音乐
	initMusic();


	//加载开始界面图片
	loadImg_start();

	//输出打印开始界面
	BeginBatchDraw();
	putImg_Start();
	EndBatchDraw();

	//初始化随机数种子
	srand((unsigned int)time(NULL));    //确保每次游戏运行时敌机类型和生成位置的随机性

	//初始化
	gameInit();

	//开始界面效果
	game_start();

	//双缓冲---防止闪屏.
	BeginBatchDraw();  //在进入 game_start() 函数之前，主函数中已经调用了 BeginBatchDraw()，因此初始状态是处于批量绘图模式的。
	//在 game_start() 的循环中，先绘制界面内容（putImg_Start()），然后调用 EndBatchDraw() 将内存中的图像显示到屏幕上。
	//紧接着调用 BeginBatchDraw() 重新开启批量绘图模式，为下一次循环的绘制做准备。
	//也就是说主程序里的BeginBatchDraw和game_start里的第一个EndBatchDraw是一对，执行完后这个BeginBatchDraw(主程序里的)将不会对后续造成影响
	while (1)
	{
		//清屏(防止残影)
		cleardevice();

		// 处理鼠标消息
		while (peekmessage(&msg, EX_MOUSE))
		{

		}

		// 游戏结束时绘制游戏结束界面
		if (isGameOver)
		{
			drawGameOver();
		}
		// 只有在未暂停状态下才更新游戏状态
		else if (!isPaused)
		{
			playerMove(10);  //玩家飞机移动
			BullteMove();    //子弹移动

			//定时生成敌机
			if (Time(2000, 0,true))  //每2秒生成一次
			{
				createEnemy();  //生成飞机
			}

			if (Time(15000, 1,true))  // 每15秒生成一个空投  仅在游戏未暂停时计时
			{
				createWeapon();
			}

			enemyMove();   //敌机移动
			weaponMove();  //空投道具移动
			play();        //攻击
			checkWeaponCollision();  // 检测空投道具与玩家碰撞
			handleExplosions();  //处理爆炸动画
			checkPlayerCollision();    // 检测玩家与敌机碰撞 
			handlePlayerExplosion();   // 处理玩家爆炸动画 
		}
		else if (isPaused)
		{
			// 在暂停状态下，告诉计时器不要计数
			Time(0, 0, false);
			Time(0, 1, false);
		}

		if (!isGameOver)
		{
			gameDraw();
		}

		//无论是否暂停都需要绘制界面
		//gameDraw();   //这里如果是用的掩码图透明贴图的话，放在while循环里运行的时候回一闪一闪的(此时就需要加双缓冲).

		FlushBatchDraw(); //每次循环刷新一下页面.

		Sleep(16);  //控制帧率，约60帧每秒
	}

	mciSendString("close bgm", NULL, 0, NULL);  // 关闭音乐

	closegraph();   //关闭游戏窗户
	return 0;
}




//鼠标消息：
	//在 Windows 编程中，鼠标消息是一种事件驱动的机制。当用户移动鼠标、点击按钮时，系统会生成相应的消息并放入消息队列中.
	//程序需要从队列中获取这些消息并进行处理.
	// 
	//在 EasyX 图形库中，主要通过以下函数处理鼠标消息：
	//peekmessage(&msg, EX_MOUSE)检查消息队列中是否有鼠标消息（不等待）。如果有，将消息内容存入msg结构体，并返回true；否则返回false.
	//getmessage(&msg, EX_MOUSE)从消息队列中获取鼠标消息（如果没有则等待）。同样将消息存入msg结构体.
	//
	//消息结构体 ExMessage：
	//ExMessage 是 EasyX 定义的消息结构体，包含以下关键成员：
	//message：消息类型（如WM_LBUTTONDOWN表示左键按下）.
	//x, y：鼠标坐标.
	//lParam：额外参数（如鼠标按键状态）.
	//例如，当用户点击鼠标左键时，msg.message 的值为 WM_LBUTTONDOWN，同时 msg.x 和 msg.y 记录了点击位置.
	// 
    //消息的 "一次性" 特性：
    //鼠标消息一旦被处理，应该被标记为 "已处理"，否则可能被重复处理。
	// 
	// while (peekmessage(&msg, EX_MOUSE)) 
	// {
    //     处理消息...
	// }
    //消息循环的工作方式：
	//进入循环：程序遇到这个 while 循环时，开始检查消息队列。
	//获取一条消息：peekmessage 从队列中取出一条鼠标消息（如果有），存入 msg 结构体，并返回 true。
	//处理这条消息：执行循环体中的代码（例如检查鼠标是否点击了音乐图标）。
	//继续循环：处理完当前消息后，再次调用 peekmessage 检查队列中是否还有下一条消息。
	//退出条件：当消息队列中没有更多鼠标消息时，peekmessage 返回 false，循环终止，程序继续执行循环之后的代码。
	//如果不清零，同一个消息可能会被多次处理（例如，同时触发音乐图标和按钮的响应）。
	//消息循环的执行方式：
	//不是获取一条消息就跳出循环，而是循环处理完所有消息后才退出。
	//每次循环迭代处理一条消息，直到队列为空。
	// 
	//空循环常用来清空消息列表，使得在游戏主循环中，忽略鼠标消息以专注于键盘控制。
    //
