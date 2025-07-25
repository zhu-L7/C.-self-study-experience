#include<stdio.h>
#include<graphics.h>       //图形界面库的头文件
#include"TransparentImage.h"
#include<time.h>

IMAGE bk;            //背景图片
IMAGE img_plane[2];  //飞机图片
IMAGE img_bull[2];   //子弹图片
IMAGE img_enemy[3];   //敌机图片

enum My
{
	WIDTH = 480,     //游戏窗口宽高.
	HEIGHT = 850,
	BULLET_NUM = 15, //子弹数量
	BIG=0,             //大敌机
	MEDIUM=1,          //中敌机
	SMALL=2,           //小敌机
	ENEMY_NUM=10     //敌机数量
};

//定义飞机属性
struct Plane
{
	int x;
	int y;
	bool live;  //玩家是否死亡.
	
	int width;
	int height;
	int hp;     //敌机血量
	int type;   //敌机类型

}player, bull[BULLET_NUM], enemy[ENEMY_NUM];


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

	// 确保敌机HP初始值正确
	printf("初始化敌机 %d: 类型=%d, HP=%d\n",i, enemy[i].type, enemy[i].hp);
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

	
	
}

//贴图---打印输出图片在游戏窗口.
void gameDraw()
{
	putimage(0, 0, &bk);//背景
	drawImg(player.x, player.y,&img_plane[0]);   //玩家飞机图片
	drawImg(player.x, player.y,&img_plane[1]);

	//绘制子弹
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bull[i].live)
		{
		if (bull[i].live)
			drawImg(bull[i].x, bull[i].y, &img_bull[0]);
			//drawImg(bull[i].x, bull[i].y, &img_bull[1]);
		}
	}

	//绘制敌机
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
			printf("生成敌机 %d: 类型=%d, HP=%d, x=%d, y=%d\n",i, enemy[i].type, enemy[i].hp,enemy[i].x, enemy[i].y);


			break;
		}
	}
}

//敌机移动
void enemyMove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live)
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
				printf("敌机 %d (类型=%d, HP=%d) 出界，y=%d\n",i, enemy[i].type, enemy[i].hp, enemy[i].y);
				
				
				enemy[i].live = false;
			}
		}
	}
}


//移动玩家飞机---操作键盘
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

	//加延迟效果，让子弹移动更丝滑，不至于按一下空格出现多个子弹.
	static DWORD t1 = 0;
	DWORD t2 = GetTickCount();   //更新t2为当前时间，GetTickCount()和clock()相似都是获取当前时间的函数(但是头文件、单位、返回类型和适用场景等都不相同).
	//按空格发射子弹.
	if (GetAsyncKeyState(VK_SPACE) && t2-t1 >200)     //t1表示上次发射子弹时间(毫秒),t2表示当前时间(毫秒),t2-t1就表示发射子弹的冷却时间(下一次按空格需要在上一次按空格后50毫秒才会生效，才会发射新的子弹).
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
		if (!enemy[i].live)
			continue;

		if (bull[k].x > enemy[i].x &&
			bull[k].x < enemy[i].x + enemy[i].width &&
			bull[k].y > enemy[i].y &&
			bull[k].y < enemy[i].y + enemy[i].height)
		{
			//检测
			printf("子弹 %d 击中敌机 %d (类型=%d, HP=%d)\n",k, i, enemy[i].type, enemy[i].hp);

			bull[k].live = false;
			enemy[i].hp--;          // 敌机减血

			if (enemy[i].hp <= 0)
			{
				//检测
				printf("敌机 %d (类型=%d) 被摧毁！\n", i, enemy[i].type);

				enemy[i].live = false;   // 敌机被摧毁
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


//延迟---创建定时器
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

//程序入口
int main()
{
	//创建游戏窗口
	initgraph(WIDTH,HEIGHT,1);

	//初始化随机数种子
	srand((unsigned int)time(NULL));    //确保每次游戏运行时敌机类型和生成位置的随机性

	gameInit();


	//双缓冲---防止闪屏.
	BeginBatchDraw();
	while (1)
	{
		//清屏(防止残影)
		cleardevice();

		playerMove(10);  //玩家飞机移动

		BullteMove();   //子弹移动

		//定时生成敌机
		if (Time(2000, 0))  //每2秒生成一次
		{
			createEnemy();  //生成飞机
		}

		enemyMove();   //敌机移动

		play();   //攻击

		//贴图
		gameDraw();   //这里如果是用的掩码图透明贴图的话，放在while循环里运行的时候回一闪一闪的(此时就需要加双缓冲).

		FlushBatchDraw(); //每次循环刷新一下页面.

		Sleep(16);  //控制帧率，约60帧每秒
	}

	closegraph();   //关闭游戏窗户
	return 0;
}