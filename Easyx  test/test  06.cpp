//Ŀ�ꣻ   ��������

#include<stdio.h>
#include<Windows.h>                       //����Windows����ϵͳ�ĺ���API��
#include<mmsystem.h>                      //����Windows��ý��ϵͳ�ӿڣ�������Ƶ���ŵȹ���
#pragma comment(lib,"winmm.lib")          //���Ӷ�ý��⣬ȷ����غ�������������

//void playBackgroundMusic(const char* music, bool repeat = false, int volume = -1)   //-1����Ĭ�ϵ�
//{
//	static int i = 0;
//	char cmd[100] = { 0 };
//	sprintf(cmd, "open %s alias bgm%d", music, i);         //i��Ϊ�˸ı䲥�ŵ����֣�ѭ���ı�iֵ�����ı�bgm���ƣ�����ʵ��ͬʱ���Ŷ�������.
//	MCIERROR ret = mciSendString(cmd, NULL, 0, NULL);
//	if (ret != 0)
//	{
//		//��ȡһ�´�����Ϣ
//		char err[100] = { 0 };
//		mciGetErrorString(ret, err, sizeof(err));
//		printf("[open]:%s", err);
//	}
//	sprintf(cmd, "play  bgm%d %s", i, repeat ? "repeat" : "");
//	ret = mciSendString(cmd, NULL, 0, NULL);
//	if (ret != 0)
//	{
//		//��ȡһ�´�����Ϣ
//		char err[100] = { 0 };
//		mciGetErrorString(ret, err, sizeof(err));
//		printf("[play]:%s", err);
//	}
//	if (volume != -1)
//	{
//		sprintf(cmd, "setaudio bgm%d volume to %d", i, volume);
//		ret = mciSendString(cmd, NULL, 0, NULL);	//������Χ[0-1000]
//		if (ret != 0)
//		{
//			//��ȡһ�´�����Ϣ
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
	//�������� m media c control i interface
	//�޷��������֣�
	//1��·������
	//2��ϵͳ������֧��
	//3�����ָ�ʽ�������������صģ����ܲ���

	//MCIERROR ret = mciSendString("open assets/That-Girl.mp3 alias bgm", NULL, 0, NULL);    //alias�Զ����������assets/That-Girl.mp3����Ϊbgm.
	//if (ret != 0)
	//{
	//	//��ȡһ�´�����Ϣ
	//	char err[100] = { 0 };
	//	mciGetErrorString(ret, err, sizeof(err));
	//	puts(err);
	//}
	//mciSendString("play bgm", NULL, 0, NULL);
	////���ʧ�ܷ��ط�0ֵ���ɹ�����0
	//ret = mciSendString("setaudio bgm volume  50",NULL,0,NULL);	//������Χ[0-1000]
	//if (ret != 0)
	//{
	//	//��ȡһ�´�����Ϣ
	//	char err[100] = { 0 };
	//	mciGetErrorString(ret, err, sizeof(err));
	//	puts(err);
	//}

	//playBackgroundMusic("assets/That-Girl.mp3",true,50);
	//playBackgroundMusic("assets/video_call.wav",true);

	//ר������������Ч�ĺ���---PlaySound
	while (true)
	{
		//PlaySound("assets/That-Girl.mp3", NULL, SND_FILENAME | SND_ASYNC);     //PlatSound��ר����������wav�ģ�mp3���ܲ���.
		PlaySound("assets/video_call.wav", NULL, SND_FILENAME | SND_ASYNC);
		//playBackgroundMusic("assets/video_call.wav");       //���ַ������ظ����п���.
		getchar();
	}

	getchar();
	return 0;
}