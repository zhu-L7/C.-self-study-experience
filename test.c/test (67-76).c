// 67. BC72-平均身高

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	double h[5] = { 0 };
	//	int i = 0;
	//	for (i = 0; i < 5; i++)
	//	{
	//		scanf("%lf", &h[i]);
	//	}
	//	double average = 0.0;
	//	average = (h[0] + h[1] + h[2] + h[3] + h[4]) / 5.0;
	//	printf("%.2lf", average);
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	double h = 0.0;
	//	double sum = 0.0;
	//	int i = 0;
	//	for (i = 0; i < 5; i++)
	//	{
	//		scanf("%lf", &h);
	//		sum += h;
	//	}
	//	printf("%.2lf", sum / 5);
	//	return 0;
	//}


// 68. BC74-HTTP状态码

	//#include<stdio.h>
	//int main()
	//{
	//	int HTTP = 0;
	//	while(scanf_s("%d", &HTTP) != EOF)
	//	{
	//		switch (HTTP)
	//		{
	//		case 200:
	//			printf("OK\n");
	//			break;
	//		case 202:
	//			printf("Accepted\n");
	//			break;
	//		case 400:
	//			printf("Bad Request\n");
	//			break;
	//		case 403:
	//			printf("Forbidden\n");
	//			break;
	//		case 404:
	//			printf("Not Found\n");
	//			break;
	//		case 500:
	//			printf("Internal Server Error\n");
	//			break;
	//		case 502:
	//			printf("Bad Gateway\n");
	//			break;
	//		}
	//	}
	//	return 0;
	//}


// 69. BC75-数字三角形

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		int j = 0;
	//		for (i = 1; i <= n; i++)
	//		{
	//			for (j = 1; j <= i; j++)
	//			{
	//				printf("%d ", j);
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 70. BC76-公务员面试

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int Max(int score[],int size)
	//{
	//	int i = 0;
	//	int max = score[0];
	//	for (i = 1; i < size; i++)
	//	{
	//		if (score[i] > max)
	//			max = score[i];
	//	}
	//	return max;
	//}
	//int Min(int score[], int size)
	//{
	//	int i = 0;
	//	int min = score[0];
	//	for (i = 1; i < size; i++)
	//	{
	//		if (score[i] < min)
	//			min = score[i];
	//	}
	//	return min;
	//}
	//int main()
	//{
	//	int score[7] = { 0 };
	//	int i = 0;
	//	int sum = 0;
	//	for (i = 0; i < 7; i++)
	//	{
	//		scanf("%d", &score[i]);
	//		sum += score[i];
	//	}
	//	int Max_score = Max(score, 7);
	//	int Min_score = Min(score, 7);
	//	double average = 0.0;
	//	average = (sum - Max_score - Min_score) / 5.0;
	//	printf("%.2lf", average);
	//	return 0;
	//}

//方法二：
	//#include<stdio.h>
	//int main()
	//{
	//	int score[7] = { 0 };
	//	int sum = 0;
	//	int i = 0;
	//	
	//	for (i = 0; i < 7; i++)
	//	{
	//		scanf_s("%d", &score[i]);
	//		sum += score[i];
	//	}
	//	int min = score[0];
	//	int max = score[0];
	//	for (i=0;i<7;i++)
	//	{
	//		if (score[i] > max)
	//			max = score[i];
	//		if (score[i] < min)
	//			min = score[i];
	//	}
	//	double average = (sum - min - max) / 5.0;
	//	printf("%.2lf\n", average);
	//	return 0;
	//}

//方法三：
	//#include <stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int sum = 0;
	//	int min = 100;//假设最小值是100
	//	int max = 0;//假设最大值是0
	//	int score = 0;
	//	for (i = 0; i < 7; i++)
	//	{
	//		scanf_s("%d", &score);
	//		sum += score;
	//		if (score > max)
	//			max = score;
	//		if (score < min)
	//			min = score;
	//	}
	//	printf("%.2lf\n", (sum - min - max) / 5.0);
	//	return 0;
	//}


// 71. BC77-有序序列插入一个数

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[51] = { 0 };
	//	int m = 0;
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &arr[i]);
	//	}
	//	scanf_s("%d", & m);
	//	for (i = n - 1; i >= 0; i--)
	//	{
	//		if (arr[i] > m)
	//		{
	//			arr[i + 1] = arr[i];
	//		}
	//		else
	//		{
	//			arr[i + 1] = m;
	//			break;
	//		}
	//	}
	//	if (i < 0)
	//	{
	//		arr[0] = m;
	//	}
	//	for (i = 0; i < n + 1; i++)
	//	{
	//		printf("%d ", arr[i]);
	//	}
	//	return 0;
	//}


// 72. BC78-筛选法求素数

//方法一：筛选法
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (~scanf_s("%d", &n))
	//	{
	//		int arr[101] = { 0 };
	//		int i = 0;
	//		//存储数据
	//		for (i = 2; i <= n; i++)
	//		{
	//			arr[i] = i;
	//		}
	//		//列举所有除数
	//		int j = 0;
	//		for (j = 2; j <= n; j++)
	//		{
	//			int k = 0;
	//			for (k = j + 1; k <= n; k++)
	//			{
	//				if (arr[k] % j == 0)
	//				{
	//					arr[k] = 0;
	//				}
	//			}
	//		}
	//		//输出并记录
	//		int count = 0;
	//		for (i = 2; i <= n; i++)
	//		{
	//			if (arr[i] != 0)
	//			{
	//				printf("%d ", arr[i]);
	//			}
	//			else
	//			{
	//				count++;
	//			}
	//		}
	//		printf("\n%d\n", count);
	//	}
	//	return 0;
	//}

//方法二：试除法
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (~scanf_s("%d", &n))
	//	{
	//		int i = 0;
	//		int count = 0;
	//		for (i = 2; i <= n; i++)
	//		{
	//			//判断i是否为素数
	//			int j = 0;
	//			for (j = 2; j < i; j++)
	//			{
	//				if (i % j == 0)
	//				{
	//					count++;
	//					break;
	//				}
	//			}
	//			if (j == i)
	//				printf("%d ", j);
	//		}
	//		printf("\n%d\n", count);
	//	}
	//	return 0;
	//}


// 73. BC79-图像相速度

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int m = 0;
	//	int n = 0;
	//	double count = 0;
	//	int arr1[100][100] = { 0 };
	//	int arr2[100][100] = { 0 };
	//	scanf("%d %d", &m, &n);
	//	//输入颜色
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < m; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			scanf("%d", &arr1[i][j]);
	//		}
	//	}
	//	for (i = 0; i < m; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			scanf("%d", &arr2[i][j]);
	//		}
	//	}
	//	//统计位置相同像素点个数
	//	for (i = 0; i < m; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			if (arr1[i][j] == arr2[i][j])
	//			{
	//				count++;
	//			}
	//		}
	//	}
	//	//计算输出
	//	printf("%.2lf\n", 100*count/(m*n));
	//	return 0;
	//}


// 74. BC80-验证登录

	//#define _CRT_SECURE_NO_WARNINGS
	//#include <stdio.h>
	//#include <string.h>
	//
	//#define MAX_LENGTH 100
	//
	//int main() {
	//	char name[MAX_LENGTH] = { 0 };
	//	char password[MAX_LENGTH] = { 0 };
	//
	//	while (1) {  // 无限循环
	//		printf("请输入用户名和密码（用空格分隔）：");
	//
	//		// 使用标准的scanf并指定最大读取长度，防止缓冲区溢出
	//		if (scanf("%99s %99s", name, password) != 2) {
	//			printf("输入格式错误，请重新输入！\n");
	//
	//			// 清除输入缓冲区中的错误数据
	//			while (getchar() != '\n');
	//			continue;
	//		}
	//
	//		// 清除输入缓冲区中的多余字符(清除scanf没有读取到的多余数据,比如超出99的后面的数据)
	//		while (getchar() != '\n');
	//
	//		if (strcmp(name, "admin") == 0 && strcmp(password, "admin") == 0) {
	//			printf("Login Success!\n");
	//			return 0;  // 登录成功后退出程序
	//		}
	//		else {
	//			printf("Login Fail! 请重试。\n");
	//		}
	//	}
	//	return 0;
	//}


// 75. BC85-包含数字9的数

	//#define _CRT_SECURE_NO_WARNINGS
	//#include <stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int count = 0;
	//	for (i = 1; i < 2020; i++)
	//	{
	//		int m = i;
	//		while (m)
	//		{
	//			if (m % 10 == 9)
	//			{
	//				count++;
	//				break;
	//			}
	//			m /= 10;
	//		}
	//	}
	//	printf("%d\n", count);
	//	return 0;
	//}


// 76. BC86-奇偶统计

//方法一：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	int odd = 0;
	//	int i = 0;
	//	for (i = 1; i <= n; i++)
	//	{
	//		if (i % 2 == 1)
	//			odd++;
	//	}
	//	printf("%d %d\n", odd, n - odd);
	//	return 0;
	//}

//方法二：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	if (n % 2 == 1)
	//		printf("%d %d\n", n / 2 + 1, n / 2);
	//	if (n % 2 == 0)
	//		printf("%d %d\n", n / 2, n / 2 );
	//	return 0;
	//}