//目标：   创建窗口 / 基本图形绘制 / 文字绘制 / 文字居中 / 消息处理

#include<stdio.h>

//包含easyx头文件.
#include<easyx.h>                        //只包含最新的API(程序接口函数).

//#include<graphics.h>   包含了<easyx.h>和已经不推荐使用了的函数.

ExMessage msg = { 0 };     //定义消息的结构体变量

void drawShape()
{
	//绘制点
	putpixel(50, 50, WHITE);         //putpixel(x,y,color);
	
	//设置线条颜色
	setlinecolor(GREEN);
	//设置线条样式
	setlinestyle(PS_SOLID, 3);
	//绘制线
	line(0, 0, getwidth(), getheight());      //getwidth()和getheight()是自动获取定义的窗口宽高(也可以不用函数手动输入宽高).

	//绘制矩形
	rectangle(100, 0, 100 + 50, 0 + 50);     //无填充矩形.
	setfillcolor(YELLOW);                    //设置填充颜色.
	fillrectangle(100, 50, 150, 100);        //填充矩形(默认为白色).
	solidrectangle(100, 100, 150, 150);      //无边框填充矩形.  

	//绘制圆角矩形
	roundrect(160, 0, 160 + 50, 0 + 50,10,10);                //无填充圆角矩形.
	fillroundrect(160, 50, 160 + 50, 50 + 50, 10, 10);        //填充圆角矩形.
	solidroundrect(160, 100, 160 + 50, 100 + 50, 10, 10);     //无边框填充圆角矩形.

	//绘制圆形
	setfillcolor(BLUE);
	circle(50, 50, 50);                     //无填充圆形
	fillcircle(50, 150, 50);                //填充圆形
	solidcircle(50, 250, 50);               //无边框填充圆形

	//绘制椭圆
	setfillcolor(RED);
	ellipse(200, 0, 200 + 50, 0 + 100);     //无填充
	fillellipse(200,200,250,300);           //填充
	solidellipse(200,300,250,400);          //无边框填充

	//绘制折线条
	POINT points[] = { {0,0},{20,20},{50,80},{10,60} };
	polyline(points, 4);


	// 注意：如果需要每个图形颜色不一样，则需要每次单独重新设置颜色.
	//       其它图形可以鼠标光标悬停于函数上，右键转到定义查看，也可以在easyx在线文档函数部分查看.
}


void drawText()
{
	printf("hello Easyx!\n");

	//设置字体大小样式
	settextstyle(30, 0, _T("江城圆体"));
	//设置字体颜色
	settextcolor(BROWN);
	//设置背景模式
	setbkmode(TRANSPARENT);
	//绘制文字
	outtextxy(10, 10, _T("hello Easyx!"));

	//Easyx 与字符串相关的函数都有字符集问题，UNICODE或多字节字符集
	//    三种解决方法：
	//                  1.在字符串前面使用大写字母L进行强制转换，如settextstyle(48, 0, L"江城圆体");
	//                  2.用代参宏(_T(),_TEXT())让字符串自适应转，如settextstyle(48, 0, _T("江城圆体"));
	//                  3.统一更改，顶部菜单栏->属性->高级->字符集->把UNICODE改为多字节字符集.
	
	//输出一个int类型的数到图形界面
	int score = 66;
	char str[50] = "";
	sprintf_s(str, "Score:%d", score);          //sprintf函数是把score格式化后保存到str中.
	outtextxy(getwidth() - 150, 0, str);
}


void centerText()
{
	//设计一个装文字的矩形
	int rx = 30;
	int ry = 380;
	int rw = 200;
	int rh = 60;
	setfillcolor(RGB(154, 24, 158));
	fillrectangle(rx,ry,rx+rw,ry+rh);

	//设置文字颜色
	settextcolor(WHITE);
	//设置文字在矩形中居中
	char str[] = "Center Text";
	int hShape = (rw - textwidth(str)) / 2;
	int vShape = (rh - textheight(str)) / 2;
	outtextxy(rx+hShape , ry+vShape , str);
}

//判断mx和my是否在指定的矩形区域
bool InArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx<x + w && my>y && my < y + h)
	{
		return true;
	}
	return false;
}
bool button(int x, int y, int w, int h, const char* text)
{
	//鼠标放在按钮上时方框变色.
	if (InArea(msg.x, msg.y, x, y, w, h))
	{
		setfillcolor(RGB(93, 107, 153));
	}
	else
	{
		setfillcolor(RGB(154, 24, 158));
	}

	//绘制按钮
	fillroundrect(x, y, x + w, y + h, 5, 5);
	//绘制按钮文本
	int hShape = (w - textwidth(text)) / 2;   //水平差距
	int vShape = (y - textheight(text)) / 2;  //垂直差距
	settextcolor(BLACK);
	outtextxy(x + hShape, y + vShape, text);

	//判断按钮是否被点击
	if (msg.message==WM_LBUTTONDOWN && InArea(msg.x,msg.y,x,y,w,h))
	{
		return true;
	}
	return false;
}


int main()
{
	//创建图形窗口  宽*高
	initgraph(640, 480, EX_SHOWCONSOLE | EX_DBLCLKS);     //(int width,int height,flag)  其中flag可以转到定义里看具体的可执行布局操作

	//设置窗口的背景颜色
	setbkcolor(RGB(30,115,156));              //可以用windows自带的画图工具取色.
	//用设置的背景色填充整个窗口
	cleardevice();

	//窗口的坐标体系：窗口左上角是坐标原点，x轴向右增大，y轴向下增大，标题栏不计入其中.

	//设置背景模式
	setbkmode(TRANSPARENT);
	
	//绘制图形
	drawShape();

	//绘制文字
	drawText();

	//文字居中显示在指定区域
	centerText();
    
	//定义小球的属性
	int x = 50;
	int y = 50;
	int r = 20;
	int speed = 3;   //速度
	int vx = 0;
	int vy = 0;

	//消息处理(鼠标输入反馈)
	int i = 0;
	int j = 0;
	while (true)
	{
		//获取消息
		if (peekmessage(&msg, EX_MOUSE | EX_KEY))
		{
				//switch (msg.message)
				//{
				//case WM_LBUTTONDOWN:        //左键按下
				//	printf("左键点击  pos(%d %d)\n",msg.x,msg.y);
				//	break;
				//case WM_RBUTTONDOWN:        //右键按下
				//	printf("右键点击\n");
				//	break;
				//case WM_MBUTTONDOWN:        //中键按下
				//	printf("中键点击\n");
				//	break;
				//case WM_MOUSEWHEEL:         //滚轮滚动
				//	printf("滚轮滚动  dir(%d)\n",msg.wheel);      //正数是朝向屏幕，负数是朝向自己.
				//	break;
				//case WM_LBUTTONDBLCLK:      //左键双击
				//	printf("左键双击\n");
				//	break;
				//case WM_MOUSEMOVE:          //鼠标移动
				//	printf("鼠标移动\n");
				//	break;
				//}
		}

		//判断键盘按键消息
		if (msg.message == WM_KEYDOWN)
		{
			printf("keydown\n");
			//具体判断是哪个键按下，以及作出对应效果
			switch (msg.vkcode)                        //vk是virtual-key虚拟键
			{
			case VK_UP:                   //键盘“向上”方向键
				vy = -1;                  //垂直坐标减1
				break;
			case VK_DOWN:                 //键盘“向下”方向键
				vy = 1;                   //垂直坐标加1
				break;
			case VK_LEFT:                 //键盘“向左”方向键
				vx = -1;                  //水平坐标减1
				break;
			case VK_RIGHT:                //键盘“向右”方向键
				vx = 1;                   //水平坐标加1
				break;
			case VK_SPACE:
				break;
			case 'A':                      //字母需要大写，小写无法识别.
				printf("A键按下\n");
				break;
				//其他键以此类推
			}
		}
		else if (msg.message == WM_KEYUP)
		{
			switch (msg.vkcode)          
			{
			case VK_UP:
				vy = 0;             //坐标不加不减，可以看作速度变为0，小球停下来.
				break;
			case VK_DOWN:
				vy = 0;
				break;
			case VK_LEFT:
				vx = 0;
				break;
			case VK_RIGHT:
				vx = 0;
				break;
			}
		}

		//双缓冲绘图：所有的绘图代码都必须放在BeginBatchDraw和EndBatchDraw之间.
		BeginBatchDraw();
		cleardevice();       //清屏函数.

		if (button(20, 20, 150, 35, "Start Game"))
		{
			printf("Start Game!  %d\n",i++);
		}

		if (button(300, 20, 150, 35, "End Game"))
		{
			printf("End Game!  %d\n",j++);
		}

		//绘制小球
		setfillcolor(RGB(43, 145, 175));
		solidcircle(x, y, r);
		//更新小球位置
		x += speed * vx;
		y += speed * vy;



		EndBatchDraw();
		Sleep(10);       //延迟10秒

		//把消息类型设置为0
		msg.message = 0;
	}




	//防止程序退出
	getchar();

	return 0;
}