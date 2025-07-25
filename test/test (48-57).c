// 48. BC52-衡量人体胖瘦程度

	//#define _crt_secure_no_warnings
	//#include<stdio.h>
	//int main()
	//{
	//	double weight = 0;
	//	double height = 0;
	//	while (scanf_s("%lf %lf", &weight, &height) != EOF)
	//	{
	//		double bmi = weight / ((height / 100.0) * (height / 100.0));
	//		if (bmi < 18.5)
	//			printf("underweight\n");
	//		else if (bmi >= 18.5 && bmi <= 23.9)
	//			printf("normal\n");
	//		else if (bmi > 23.9 && bmi <= 27.9)
	//			printf("overweight\n");
	//		else
	//			printf("obese\n");
	//	}
	//	return 0;
	//}


// 49. BC53-计算一元二次方程

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//#include<math.h>
	//int main()
	//{
	//	double a = 0;
	//	double b = 0;
	//	double c = 0;
	//	while (scanf_s("%lf %lf %lf", &a, &b, &c) != EOF)
	//	{
	//		if (a != 0)
	//		{
	//			double disc = b * b - 4 * a * c;
	//			if (disc == 0.0)
	//				printf("x1=x2=%.2lf\n", -b / (2 * a));
	//			else if (disc > 0.0)
	//				printf("x1=%.2lf;x2=%.2lf\n",
	//					(-b - sqrt(disc)) / (2 * a), (-b + sqrt(disc)) / (2 * a));
	//			else
	//			{
	//				double real = -b / (2 * a);
	//				double image = sqrt(-disc) / (2 * a);
	//				printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi\n", real, image, real, image);
	//			}
	//		}
	//		else
	//			printf("Not quadratic equation\n");
	//	}
	//	return 0;
	//}


// 50. BC54-获得月份天数

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int year = 0;
	//	int month = 0;
	//	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//	while (scanf_s("%d %d", &year, &month) != EOF)
	//	{
	//		int day = days[month - 1];
	//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	//		{
	//			if (month == 2)
	//				day += 1;
	//		}
	//		printf("%d\n", day);
	//	}
	//	return 0;
	//}


// 51. BC55-简单计算器

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	double n1 = 0.0;
	//	double n2 = 0.0;
	//	char op = 0;
	//	while (scanf_s("%lf%c%lf", &n1, &op,1, &n2) != EOF)
	//	{
	//		switch (op)
	//		{
	//		case '+':
	//			printf("%.4lf+%.4lf=%.4lf\n",n1,n2,n1+n2);
	//			break;
	//		case '-':
	//			printf("%.4lf-%.4lf=%.4lf\n",n1,n2,n1-n2);
	//			break;
	//		case '*':
	//			printf("%.4lf*%.4lf=%.4lf\n",n1,n2,n1*n2);
	//			break;
	//		case '/':
	//			if (n2 == 0.0)
	//				printf("Wrong!Division by zero!\n");
	//			else
	//				printf("%.4lf/%.4lf=%.4lf\n",n1,n2,n1/n2);
	//			break;
	//		default:
	//			printf("Invalid operation!\n");
	//			break;
	//		}
	//	}
	//	return 0;
	//}


// 52. BC56-线段图案

	//#define _CRT_SECURE_NO_WARNING
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf_s("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			printf("*");
	//		}
	//		printf("\n");
	//	}
	//	return 0;
	//}


// 53. BC57-正方形图案

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf_s("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < n; j++)
	//			{
	//				printf("* ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//
	//	return 0;
	//}


// 54. BC58-直角三角形图案

	//#define _CRT_SECURE_NO_WARNIGNS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf_s("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j <= i; j++)
	//			{
	//				printf("* ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 55. BC59-翻转直角三角形图案

	//#define _CRT_SECURE_NO_WARNING
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf_s("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < n - i; j++)
	//			{
	//				printf("* ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 56. BC60-带空格的直角三角形

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf_s("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < n-1-i; j++)
	//			{
	//				printf("  ");
	//			}
	//			for (j = 0; j <= i; j++)
	//			{
	//				printf("* ");
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
	//	while (scanf_s("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		int j = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			for (j = 0; j < n; j++)
	//			{
	//				if (i + j < n - 1)
	//				{
	//					printf("  ");
	//				}
	//				else
	//				{
	//					printf("* ");
	//				}
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}


// 57. BC61-金字塔图案

	//#define _CRT_SECURE_NO_WARNING
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	while (scanf_s("%d", &n) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			int j = 0;
	//			for (j = 0; j < n-1-i; j++)
	//			{
	//				printf(" ");
	//			}
	//			for (j = 0; j <= i; j++)
	//			{
	//				printf("* ");
	//			}
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}