//Ŀ�꣺   �������� / ����ͼ�λ��� / ���ֻ��� / ���־��� / ��Ϣ����

#include<stdio.h>

//����easyxͷ�ļ�.
#include<easyx.h>                        //ֻ�������µ�API(����ӿں���).

//#include<graphics.h>   ������<easyx.h>���Ѿ����Ƽ�ʹ���˵ĺ���.

ExMessage msg = { 0 };     //������Ϣ�Ľṹ�����

void drawShape()
{
	//���Ƶ�
	putpixel(50, 50, WHITE);         //putpixel(x,y,color);
	
	//����������ɫ
	setlinecolor(GREEN);
	//����������ʽ
	setlinestyle(PS_SOLID, 3);
	//������
	line(0, 0, getwidth(), getheight());      //getwidth()��getheight()���Զ���ȡ����Ĵ��ڿ��(Ҳ���Բ��ú����ֶ�������).

	//���ƾ���
	rectangle(100, 0, 100 + 50, 0 + 50);     //��������.
	setfillcolor(YELLOW);                    //���������ɫ.
	fillrectangle(100, 50, 150, 100);        //������(Ĭ��Ϊ��ɫ).
	solidrectangle(100, 100, 150, 150);      //�ޱ߿�������.  

	//����Բ�Ǿ���
	roundrect(160, 0, 160 + 50, 0 + 50,10,10);                //�����Բ�Ǿ���.
	fillroundrect(160, 50, 160 + 50, 50 + 50, 10, 10);        //���Բ�Ǿ���.
	solidroundrect(160, 100, 160 + 50, 100 + 50, 10, 10);     //�ޱ߿����Բ�Ǿ���.

	//����Բ��
	setfillcolor(BLUE);
	circle(50, 50, 50);                     //�����Բ��
	fillcircle(50, 150, 50);                //���Բ��
	solidcircle(50, 250, 50);               //�ޱ߿����Բ��

	//������Բ
	setfillcolor(RED);
	ellipse(200, 0, 200 + 50, 0 + 100);     //�����
	fillellipse(200,200,250,300);           //���
	solidellipse(200,300,250,400);          //�ޱ߿����

	//����������
	POINT points[] = { {0,0},{20,20},{50,80},{10,60} };
	polyline(points, 4);


	// ע�⣺�����Ҫÿ��ͼ����ɫ��һ��������Ҫÿ�ε�������������ɫ.
	//       ����ͼ�ο����������ͣ�ں����ϣ��Ҽ�ת������鿴��Ҳ������easyx�����ĵ��������ֲ鿴.
}


void drawText()
{
	printf("hello Easyx!\n");

	//���������С��ʽ
	settextstyle(30, 0, _T("����Բ��"));
	//����������ɫ
	settextcolor(BROWN);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//��������
	outtextxy(10, 10, _T("hello Easyx!"));

	//Easyx ���ַ�����صĺ��������ַ������⣬UNICODE����ֽ��ַ���
	//    ���ֽ��������
	//                  1.���ַ���ǰ��ʹ�ô�д��ĸL����ǿ��ת������settextstyle(48, 0, L"����Բ��");
	//                  2.�ô��κ�(_T(),_TEXT())���ַ�������Ӧת����settextstyle(48, 0, _T("����Բ��"));
	//                  3.ͳһ���ģ������˵���->����->�߼�->�ַ���->��UNICODE��Ϊ���ֽ��ַ���.
	
	//���һ��int���͵�����ͼ�ν���
	int score = 66;
	char str[50] = "";
	sprintf_s(str, "Score:%d", score);          //sprintf�����ǰ�score��ʽ���󱣴浽str��.
	outtextxy(getwidth() - 150, 0, str);
}


void centerText()
{
	//���һ��װ���ֵľ���
	int rx = 30;
	int ry = 380;
	int rw = 200;
	int rh = 60;
	setfillcolor(RGB(154, 24, 158));
	fillrectangle(rx,ry,rx+rw,ry+rh);

	//����������ɫ
	settextcolor(WHITE);
	//���������ھ����о���
	char str[] = "Center Text";
	int hShape = (rw - textwidth(str)) / 2;
	int vShape = (rh - textheight(str)) / 2;
	outtextxy(rx+hShape , ry+vShape , str);
}

//�ж�mx��my�Ƿ���ָ���ľ�������
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
	//�����ڰ�ť��ʱ�����ɫ.
	if (InArea(msg.x, msg.y, x, y, w, h))
	{
		setfillcolor(RGB(93, 107, 153));
	}
	else
	{
		setfillcolor(RGB(154, 24, 158));
	}

	//���ư�ť
	fillroundrect(x, y, x + w, y + h, 5, 5);
	//���ư�ť�ı�
	int hShape = (w - textwidth(text)) / 2;   //ˮƽ���
	int vShape = (y - textheight(text)) / 2;  //��ֱ���
	settextcolor(BLACK);
	outtextxy(x + hShape, y + vShape, text);

	//�жϰ�ť�Ƿ񱻵��
	if (msg.message==WM_LBUTTONDOWN && InArea(msg.x,msg.y,x,y,w,h))
	{
		return true;
	}
	return false;
}


int main()
{
	//����ͼ�δ���  ��*��
	initgraph(640, 480, EX_SHOWCONSOLE | EX_DBLCLKS);     //(int width,int height,flag)  ����flag����ת�������￴����Ŀ�ִ�в��ֲ���

	//���ô��ڵı�����ɫ
	setbkcolor(RGB(30,115,156));              //������windows�Դ��Ļ�ͼ����ȡɫ.
	//�����õı���ɫ�����������
	cleardevice();

	//���ڵ�������ϵ���������Ͻ�������ԭ�㣬x����������y���������󣬱���������������.

	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	
	//����ͼ��
	drawShape();

	//��������
	drawText();

	//���־�����ʾ��ָ������
	centerText();
    
	//����С�������
	int x = 50;
	int y = 50;
	int r = 20;
	int speed = 3;   //�ٶ�
	int vx = 0;
	int vy = 0;

	//��Ϣ����(������뷴��)
	int i = 0;
	int j = 0;
	while (true)
	{
		//��ȡ��Ϣ
		if (peekmessage(&msg, EX_MOUSE | EX_KEY))
		{
				//switch (msg.message)
				//{
				//case WM_LBUTTONDOWN:        //�������
				//	printf("������  pos(%d %d)\n",msg.x,msg.y);
				//	break;
				//case WM_RBUTTONDOWN:        //�Ҽ�����
				//	printf("�Ҽ����\n");
				//	break;
				//case WM_MBUTTONDOWN:        //�м�����
				//	printf("�м����\n");
				//	break;
				//case WM_MOUSEWHEEL:         //���ֹ���
				//	printf("���ֹ���  dir(%d)\n",msg.wheel);      //�����ǳ�����Ļ�������ǳ����Լ�.
				//	break;
				//case WM_LBUTTONDBLCLK:      //���˫��
				//	printf("���˫��\n");
				//	break;
				//case WM_MOUSEMOVE:          //����ƶ�
				//	printf("����ƶ�\n");
				//	break;
				//}
		}

		//�жϼ��̰�����Ϣ
		if (msg.message == WM_KEYDOWN)
		{
			printf("keydown\n");
			//�����ж����ĸ������£��Լ�������ӦЧ��
			switch (msg.vkcode)                        //vk��virtual-key�����
			{
			case VK_UP:                   //���̡����ϡ������
				vy = -1;                  //��ֱ�����1
				break;
			case VK_DOWN:                 //���̡����¡������
				vy = 1;                   //��ֱ�����1
				break;
			case VK_LEFT:                 //���̡����󡱷����
				vx = -1;                  //ˮƽ�����1
				break;
			case VK_RIGHT:                //���̡����ҡ������
				vx = 1;                   //ˮƽ�����1
				break;
			case VK_SPACE:
				break;
			case 'A':                      //��ĸ��Ҫ��д��Сд�޷�ʶ��.
				printf("A������\n");
				break;
				//�������Դ�����
			}
		}
		else if (msg.message == WM_KEYUP)
		{
			switch (msg.vkcode)          
			{
			case VK_UP:
				vy = 0;             //���겻�Ӳ��������Կ����ٶȱ�Ϊ0��С��ͣ����.
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

		//˫�����ͼ�����еĻ�ͼ���붼�������BeginBatchDraw��EndBatchDraw֮��.
		BeginBatchDraw();
		cleardevice();       //��������.

		if (button(20, 20, 150, 35, "Start Game"))
		{
			printf("Start Game!  %d\n",i++);
		}

		if (button(300, 20, 150, 35, "End Game"))
		{
			printf("End Game!  %d\n",j++);
		}

		//����С��
		setfillcolor(RGB(43, 145, 175));
		solidcircle(x, y, r);
		//����С��λ��
		x += speed * vx;
		y += speed * vy;



		EndBatchDraw();
		Sleep(10);       //�ӳ�10��

		//����Ϣ��������Ϊ0
		msg.message = 0;
	}




	//��ֹ�����˳�
	getchar();

	return 0;
}