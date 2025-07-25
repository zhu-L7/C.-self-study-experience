//目标；   播放音乐

#include<stdio.h>
#include<Windows.h>                       //引入Windows操作系统的核心API库
#include<mmsystem.h>                      //引入Windows多媒体系统接口，用于音频播放等功能
#pragma comment(lib,"winmm.lib")          //链接多媒体库，确保相关函数能正常调用

//void playBackgroundMusic(const char* music, bool repeat = false, int volume = -1)   //-1代表默认的
//{
//	static int i = 0;
//	char cmd[100] = { 0 };
//	sprintf(cmd, "open %s alias bgm%d", music, i);         //i是为了改变播放的音乐，循环改变i值进而改变bgm名称，进而实现同时播放多首音乐.
//	MCIERROR ret = mciSendString(cmd, NULL, 0, NULL);
//	if (ret != 0)
//	{
//		//获取一下错误信息
//		char err[100] = { 0 };
//		mciGetErrorString(ret, err, sizeof(err));
//		printf("[open]:%s", err);
//	}
//	sprintf(cmd, "play  bgm%d %s", i, repeat ? "repeat" : "");
//	ret = mciSendString(cmd, NULL, 0, NULL);
//	if (ret != 0)
//	{
//		//获取一下错误信息
//		char err[100] = { 0 };
//		mciGetErrorString(ret, err, sizeof(err));
//		printf("[play]:%s", err);
//	}
//	if (volume != -1)
//	{
//		sprintf(cmd, "setaudio bgm%d volume to %d", i, volume);
//		ret = mciSendString(cmd, NULL, 0, NULL);	//音量范围[0-1000]
//		if (ret != 0)
//		{
//			//获取一下错误信息
//			char err[100] = { 0 };
//			mciGetErrorString(ret, err, sizeof(err));
//			puts(err);
//		}
//	}
//
//	i++;
//}

int main()
{
	//播放音乐 m media c control i interface
	//无法播放音乐：
	//1，路径错误
	//2，系统驱动不支持
	//3，音乐格式错误，网易云下载的，不能播放

	//MCIERROR ret = mciSendString("open assets/That-Girl.mp3 alias bgm", NULL, 0, NULL);    //alias自定义别名，把assets/That-Girl.mp3命名为bgm.
	//if (ret != 0)
	//{
	//	//获取一下错误信息
	//	char err[100] = { 0 };
	//	mciGetErrorString(ret, err, sizeof(err));
	//	puts(err);
	//}
	//mciSendString("play bgm", NULL, 0, NULL);
	////如果失败返回非0值，成功返回0
	//ret = mciSendString("setaudio bgm volume  50",NULL,0,NULL);	//音量范围[0-1000]
	//if (ret != 0)
	//{
	//	//获取一下错误信息
	//	char err[100] = { 0 };
	//	mciGetErrorString(ret, err, sizeof(err));
	//	puts(err);
	//}

	//playBackgroundMusic("assets/That-Girl.mp3",true,50);
	//playBackgroundMusic("assets/video_call.wav",true);

	//专门用来播放音效的函数---PlaySound
	while (true)
	{
		//PlaySound("assets/That-Girl.mp3", NULL, SND_FILENAME | SND_ASYNC);     //PlatSound是专门用来播放wav的，mp3不能播放.
		PlaySound("assets/video_call.wav", NULL, SND_FILENAME | SND_ASYNC);
		//playBackgroundMusic("assets/video_call.wav");       //这种方法肯呢个会有卡顿.
		getchar();
	}

	getchar();
	return 0;
}