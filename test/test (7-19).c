// 7. BC6-С�ɻ�

	//#include<stdio.h>
	//int main()
	//{
	//	printf("     **\n");
	//	printf("     **\n");
	//	printf("************\n");
	//	printf("************\n");
	//	printf("    *  *\n");
	//	printf("    *  *\n");
	//	return 0;
	//}


// 8. BC8-ʮ������תʮ����

	//#include<stdio.h>
	//int main()
	//{
	//	printf("%15d\n", 0xABCDEF);     //%��d֮�����ֵ��ʾ���
	//	return 0;
	//}


// 9. BC9-printf�����ķ���ֵ

	//#include<stdio.h>
	//int main()
	//{
	//	int ret=printf("Hello world!");               //printf�����ķ���ֵ�Ǵ�ӡ����Ļ�ϵ��ַ�����
	//	printf("\n");
	//	printf("%d\n", ret);
	//	//printf("\n%d\n", printf("Hello world!"));
	//	return 0;
	//}


// 10. BC11-ѧ��������Ϣ�������

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int ID = 0;
	//	float C_score = 0.0;
	//	float Math_score = 0.0;
	//	float Eng_score = 0.0;
	//	scanf("%d%f%f%f", &ID, &C_score, &Math_score, &Eng_score);
	//	printf("The each subject score of No. %d is %.2f,%.2f,%.2f.\n",ID,C_score,Math_score,Eng_score);
	//	return 0;
	//}


// 11. BC35-�ж���ĸ

	//#include<stdio.h>
	//int main()
	//{
	//	int ch = 0;
	//	while ((ch = getchar())!=EOF)
	//	{
	//		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	//		{
	//			printf("YES");
	//		}
	//		//if(isalpha(ch))                //isalpha��ר�������ж�һ���ַ��ǲ�����ĸ�ĺ���������ĸ����ֵΪ��0��������ĸ
	//		   //printf("YES");              //����ֵΪ0
	//		else
	//		{
	//			printf("NO");
	//		}
	//		getchar();
	//		printf("\n");
	//	}
	//	return 0;
	//}


// 12. BC12-�ַ�������

	//#include<stdio.h>
	//int main()
	//{
	//	int ch = 0;
	//	int i = 0;
	//	ch = getchar();
	//	for (i = 0; i < 5; i++)
	//	{
	//		int j = 0;
	//		for (j=0;j<4-i;j++)
	//		{
	//			printf(" ");
	//		}
	//		for (j = 0; j <= i; j++)
	//		{
	//			printf("%c ",ch);
	//		}
	//		printf("\n");
	//	}
	//	return 0;
	//}


// 13. BC13-ASCII��

	//#include<stdio.h>
	//int main()
	//{
	//	//char arr[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33 };     //��char����ASCII��ֵ���Զ���ֵת��Ϊ�ַ����洢.
	//	//printf("%c%c%c%c%c%c%c%c%c%c%c%c\n",
	//	//73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33);

	//	char arr[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33 };
	//	int i = 0;
	//	int sz = sizeof(arr) / sizeof(arr[0]);
	//	for (i = 0; i < sz; i++)
	//	{
	//		printf("%c", arr[i]);
	//	}
	//	return 0;
	//}


// 14. BC14-���������������

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int year = 0;
	//	int month = 0;
	//	int day = 0;
	//	//����
	//	scanf("%4d%2d%2d", &year, &month, &day);                        //%4d%2d��ʾ��ȡ4λ����year,��ȡ2λ����month.
	//	//���
	//	printf("year=%4d\nmonth=%02d\nday=%02d\n", year, month, day);   //%02d��ʾ���Ϊ2����ֵ������λ��ʱǰ�油��0(�����%2d�Ͳ�����0,
	//																	//���ǲ���ո�.
	//	return 0;
	//}


// 15. BC29-2��n�η�����

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while((scanf("%d",&n)!=EOF))        //�˴�������getchar����Ϊgetcharֻ�ܶ�ȡ�ַ�.
	//	{                                   //��vs��scanf�Ķ���������Ҫ����ctrl+Z���ܽ�������.
	//		printf("%d\n", 1 << n);
	//	}
	//	return 0;
	//}


// 16. BC15-���ո�ʽ���벢�������

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int a = 0;
	//	int b = 0;
	//	int c = 0;
	//	scanf("a=%d,b=%d", &a, &b);
	//	c = a;
	//	a = b;
	//	b = c;
	//	printf("a=%d,b=%d\n", a, b);
	//	return 0;
	//}


// 17. BC16-�ַ�תASCII��

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	scanf("%c", &ch);
	//	printf("%d\n", ch);
	//	return 0;
	//}


// 18. BC17-��������ʽ��ֵ

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int a = 40;
	//	int c = 212;
	//	printf("%d", (-8 + 22)*a - 10 + c/2);
	//	return 0;
	//}


// 19. BC18-����������

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int a = 0;
	//	int b = 0;
	//	scanf("%d %d", &a, &b);
	//	printf("%d %d\n", a / b, a % b);
	//	return 0;
	//}