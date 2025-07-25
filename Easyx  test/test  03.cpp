//目标：   图片加载输出 / 透明贴图

#include<stdio.h>
#include<easyx.h>
#include"TransparentImage.h"

int main()
{
	//创建窗口
	initgraph(480, 500, EX_SHOWCONSOLE);
	setbkcolor(RGB(230, 231, 232));
	cleardevice();
    
	//---	
	//定义图片变量
	IMAGE img_tx;

	//加载图片----图片小可以在属性里查看(宽度和高度的像素大小).
	
	//1.绝对路径(带盘符的路径)
	//loadimage(&img_tx, "E:\\visual studio\\Easyx  test\\Easy test 1\\assets\\tx.jpeg");
	
	//2.相对路径--推荐这种方法(因为可以更好的转载其它电脑)
	loadimage(&img_tx, "assets/tx.jpeg",480,500);      //注意：单正斜杠和双反斜杠效果一样.
	                             //这里的480和500是指把图片大小缩小为宽高为480和500像素.
	//输出图片
	putimage(0, 0, &img_tx);
	cleardevice();
	////---
	
	//---
    //掩码图透明贴图
	//IMAGE img_111;
	//IMAGE img_1111_mask;
	//优化如下：
	IMAGE img_plane[2];
	//加载图片(顺序不影响)
	//loadimage(&img_111, "assets/111.jpg",250,250);
	//loadimage(&img_1111_mask,"assets/1111.jpg", 250, 250);
	loadimage(img_plane+0,"assets/111.jpg", 250, 250);
	loadimage(img_plane+1,"assets/1111.jpg", 250, 250);
	//输出图片
	//putimage(0, 0, &img_1111_mask,NOTSRCERASE);   
	//putimage(0, 0, &img_111, SRCINVERT);          
	putimage(0, 0, img_plane+1, NOTSRCERASE);       //线绘制掩码图
	putimage(0, 0, img_plane, SRCINVERT);           //再绘制原图
	////---

	//PNG图片透明贴图
	IMAGE img_png;
	loadimage(&img_png, "assets/enemy1.png");
	putimage(200, 100, &img_png);
	drawImg(200, 200, &img_png);

	getchar();
	return 0;
}