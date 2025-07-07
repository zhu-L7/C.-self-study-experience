// 7. BC6-小飞机

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


// 8. BC8-十六进制转十进制

	//#include<stdio.h>
	//int main()
	//{
	//	printf("%15d\n", 0xABCDEF);     //%与d之间的数值表示域宽
	//	return 0;
	//}


// 9. BC9-printf函数的返回值

	//#include<stdio.h>
	//int main()
	//{
	//	int ret=printf("Hello world!");               //printf函数的返回值是打印到屏幕上的字符个数
	//	printf("\n");
	//	printf("%d\n", ret);
	//	//printf("\n%d\n", printf("Hello world!"));
	//	return 0;
	//}


// 10. BC11-学生基本信息输入输出

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


// 11. BC35-判断字母

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
	//		//if(isalpha(ch))                //isalpha是专门用来判断一个字符是不是字母的函数，是字母返回值为非0，不是字母
	//		   //printf("YES");              //返回值为0
	//		else
	//		{
	//			printf("NO");
	//		}
	//		getchar();
	//		printf("\n");
	//	}
	//	return 0;
	//}


// 12. BC12-字符金字塔

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


// 13. BC13-ASCII码

	//#include<stdio.h>
	//int main()
	//{
	//	//char arr[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33 };     //用char接收ASCII码值会自动将值转化为字符来存储.
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


// 14. BC14-出生日期输入输出

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int year = 0;
	//	int month = 0;
	//	int day = 0;
	//	//输入
	//	scanf("%4d%2d%2d", &year, &month, &day);                        //%4d%2d表示读取4位数给year,读取2位数给month.
	//	//输出
	//	printf("year=%4d\nmonth=%02d\nday=%02d\n", year, month, day);   //%02d表示域宽为2，数值不足两位数时前面补充0(如果是%2d就不补充0,
	//																	//而是补充空格.
	//	return 0;
	//}


// 15. BC29-2的n次方计算

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while((scanf("%d",&n)!=EOF))        //此处不能用getchar，因为getchar只能读取字符.
	//	{                                   //在vs中scanf的多组输入需要三个ctrl+Z才能结束程序.
	//		printf("%d\n", 1 << n);
	//	}
	//	return 0;
	//}


// 16. BC15-按照格式输入并交换输出

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


// 17. BC16-字符转ASCII码

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	scanf("%c", &ch);
	//	printf("%d\n", ch);
	//	return 0;
	//}


// 18. BC17-计算机表达式的值

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int a = 40;
	//	int c = 212;
	//	printf("%d", (-8 + 22)*a - 10 + c/2);
	//	return 0;
	//}


// 19. BC18-计算带余除法

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