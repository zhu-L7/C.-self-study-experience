//  目标：  贴图

#include<stdio.h>
#include<raylib.h>  //可以转到定义查看 函数 结构体 相关定义
#include<time.h>
#include<stdlib.h>

int main()
{
	InitWindow(800, 600, "test_raylib");  //创建窗口

	//方法一：
	Texture img = LoadTexture("./assets/头像.jpeg");  //直接把路径加载到Texture纹理中
	//img.width=400;   和DrawTexture搭配使用
	//img.height=400;

	//方法二：
	//Image image = LoadImage("./assets/头像.jpeg");  //把路径加载到image中，再把image加载到Texture纹理中
	//Texture img = LoadTextureFromImage(image);

	//注意：纹理(Texture)是在有窗口的前提下才能创建，而Image不用窗口也能加载.

	while (!WindowShouldClose())
	{

		BeginDrawing();               //绘制帧的开始

		//DrawTexture(img, 0, 0, WHITE);  //贴图
		
		Vector2 pos = { 0,0 };
		//DrawTextureEx(img, pos, 0, 0.5, WHITE);  //贴图缩放版

		Rectangle src = { 0,0,400,400 };  //显示图片的某一部分
		DrawTextureRec(img, src, pos, WHITE);

		EndDrawing();                 //绘制帧的结束

	}

	UnloadTexture(img);  //释放
	CloseWindow();       //关闭窗口
	return 0;
}