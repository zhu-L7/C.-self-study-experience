//  目标：  音乐和音效

#include<stdio.h>
#include<raylib.h>  //可以转到定义查看 函数 结构体 相关定义
#include<time.h>
#include<stdlib.h>

int main()
{
	InitAudioDevice();  //初始化音频设备
	InitWindow(800, 600, "test_raylib");  //创建窗口

	Music m = LoadMusicStream("./assets/宋冬野 - 安和桥.ogg");  //加载音乐
	PlayMusicStream(m);  //播放音乐

	Sound s = LoadSound("./assets/button.wav");  //加载音效

	while (!WindowShouldClose())
	{

		BeginDrawing();               //绘制帧的开始

		EndDrawing();                 //绘制帧的结束
		UpdateMusicStream(m);  //不断更新音乐流

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			PlaySound(s);  //播放音效
		}
	}

	CloseWindow();       //关闭窗口
	CloseAudioDevice();  //关闭音频设备
	return 0;
}