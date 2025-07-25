// 58. BC62-翻转金字塔图案

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (~scanf("%d", &n))
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < i; j++)
	//			{
	//				printf(" ");
	//			}
	//			for (j = 0; j < n - i; j++)
	//			{
	//				printf("* ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 59. BC63-菱形图案

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (~scanf_s("%d", &n))
	//	{
	//		int i = 0;
	//		int j = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			for (j = 0; j < n - i; j++)
	//			{
	//				printf(" ");
	//			}
	//			for (j = 0; j <= i; j++)
	//			{
	//				printf("* ");
	//			}
	//			printf("\n");
	//		}
	//		for (i = 0; i < n+1; i++)
	//		{
	//			for (j = 0; j < i; j++)
	//			{
	//				printf(" ");
	//			}
	//			for (j = 0; j <= n-i; j++)
	//			{
	//				printf("* ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 60. BC64-K形图案

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j <= n - i; j++)
	//			{
	//				printf("* ");
	//			}
	//			for (j = 0; j < i; j++)
	//			{
	//				printf(" ");
	//			}
	//			printf("\n");
	//		}
	//		for (i = 0; i < n + 1; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j <= i; j++)
	//			{
	//				printf("* ");
	//			}
	//			for (j = 0; j < n - i; j++)
	//			{
	//				printf(" ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 61. BC65-箭形图案

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = n; i > 0; i--)
	//		{
	//			int j = 0;
	//			for (j = 0; j < i; j++)
	//			{
	//				printf("  ");
	//			}
	//			for (j = 0; j <= n - i; j++)
	//			{
	//				printf("*");
	//			}
	//			printf("\n");
	//		}
	//		for (i = n + 1; i > 0; i--)
	//		{
	//			int j = 0;
	//			for (j = 0; j < n + 1 - i; j++)
	//			{
	//				printf("  ");
	//			}
	//			for (j = 0; j < i; j++)
	//			{
	//				printf("*");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 62. BC66-反斜线形图案

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < i; j++)
	//			{
	//				printf(" ");
	//			}
	//			printf("*");
	//			for (j = 0; j < n-i-1; j++)
	//			{
	//				printf(" ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < n; j++)
	//			{
	//				if (i == j)
	//					printf("*");
	//				else
	//					printf(" ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 63. BC67-正斜线形图案

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (~scanf("%d", &n))
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < n; j++)
	//			{
	//				if (i + j == n - 1)
	//					printf("*");
	//				else
	//					printf(" ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (~scanf("%d", &n))
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < n-i; j++)
	//			{
	//				printf(" ");
	//			}
	//			printf("*");
	//			for (j = 0; j <= i; j++)
	//			{
	//				printf(" ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 64. BC68-X形图案

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		int j = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			for (j = 0; j < n; j++)
	//			{
	//				if (i == j)
	//				{
	//					printf("*");
	//				}
	//				else if (i + j == n - 1)
	//				{
	//					printf("*");
	//				}
	//				else
	//					printf(" ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 65. BC69-空心正方形图案

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf_s("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		int j = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			for (j = 0; j < n; j++)
	//			{
	//				if (i == 0 || i == n - 1)
	//				{
	//					printf("* ");
	//				}
	//				else if (j == 0 || j == n - 1)
	//				{
	//					printf("* ");
	//				}
	//				else
	//				{
	//					printf("  ");
	//				}
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 66. BC70-空心三角形图案

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		int j = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			for (j = 0; j < n; j++)
	//			{
	//				if (i == j)
	//					printf("* ");
	//				else if ((i == n-1)||(j==0))
	//					printf("* ");
	//				else
	//					printf("  ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}