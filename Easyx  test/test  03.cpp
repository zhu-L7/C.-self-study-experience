//Ŀ�꣺   ͼƬ������� / ͸����ͼ

#include<stdio.h>
#include<easyx.h>
#include"TransparentImage.h"

int main()
{
	//��������
	initgraph(480, 500, EX_SHOWCONSOLE);
	setbkcolor(RGB(230, 231, 232));
	cleardevice();
    
	//---	
	//����ͼƬ����
	IMAGE img_tx;

	//����ͼƬ----ͼƬС������������鿴(��Ⱥ͸߶ȵ����ش�С).
	
	//1.����·��(���̷���·��)
	//loadimage(&img_tx, "E:\\visual studio\\Easyx  test\\Easy test 1\\assets\\tx.jpeg");
	
	//2.���·��--�Ƽ����ַ���(��Ϊ���Ը��õ�ת����������)
	loadimage(&img_tx, "assets/tx.jpeg",480,500);      //ע�⣺����б�ܺ�˫��б��Ч��һ��.
	                             //�����480��500��ָ��ͼƬ��С��СΪ���Ϊ480��500����.
	//���ͼƬ
	putimage(0, 0, &img_tx);
	cleardevice();
	////---
	
	//---
    //����ͼ͸����ͼ
	//IMAGE img_111;
	//IMAGE img_1111_mask;
	//�Ż����£�
	IMAGE img_plane[2];
	//����ͼƬ(˳��Ӱ��)
	//loadimage(&img_111, "assets/111.jpg",250,250);
	//loadimage(&img_1111_mask,"assets/1111.jpg", 250, 250);
	loadimage(img_plane+0,"assets/111.jpg", 250, 250);
	loadimage(img_plane+1,"assets/1111.jpg", 250, 250);
	//���ͼƬ
	//putimage(0, 0, &img_1111_mask,NOTSRCERASE);   
	//putimage(0, 0, &img_111, SRCINVERT);          
	putimage(0, 0, img_plane+1, NOTSRCERASE);       //�߻�������ͼ
	putimage(0, 0, img_plane, SRCINVERT);           //�ٻ���ԭͼ
	////---

	//PNGͼƬ͸����ͼ
	IMAGE img_png;
	loadimage(&img_png, "assets/enemy1.png");
	putimage(200, 100, &img_png);
	drawImg(200, 200, &img_png);

	getchar();
	return 0;
}