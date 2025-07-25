// 20. BC25-计算体重指数

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int weight = 0;
	//	int height = 0;
	//	double BMI = 0;
	//	scanf("%d %d", &weight, &height);
	//	BMI = weight / ((height / 100.0) * (height / 100.0));
	//	//BMI = weight / ((double)(height * height) / (100 * 100));
	//	printf("%.2lf", BMI);
	//	return 0;
	//}


// 21. BC26- 计算三角形的周长和面积

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//#include<math.h>
	//int main()
	//{
	//	int a = 0;
	//	int b = 0;
	//	int c = 0;
	//	double circumference = 0;
	//	double area = 0;
	//	double p = 0;
	//	scanf("%d %d %d", &a, &b, &c);
	//	circumference = a + b + c;
	//	p = circumference / 2.0;
	//	area = sqrt(p * (p - a) * (p - b) * (p - c));
	//	printf("circumference=%.2lf area=%.2lf\n", circumference, area);
	//	return 0;
	//}


// 22. BC27-计算球体的体积

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	////#define pi 3.1415926
	//int main()
	//{   double pi=3.1415926;
	//	double v = 0;
	//	double r = 0;
	//	scanf("%lf", &r);
	//	v = (4.0 / 3) * pi * (r * r * r);
	//	printf("%.3lf", v);
	//	return 0;
	//}


// 23. BC10-成绩的输入输出

//方法一
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int score1 = 0;
	//	int score2 = 0;
	//	int score3 = 0;
	//	scanf("%d %d %d", &score1, &score2, &score3);
	//	printf("score1=%d,score2=%d,score3=%d", score1, score2, score3);
	//	return 0;
	//}

//方法二
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int score[3] = { 0 };
	//	for (i = 0; i < 3; i++)
	//	{
	//		scanf("%d", &score[i]);
	//	}
	//	printf("score1=%d,score2=%d,score3=%d", score[0], score[1], score[2]);
	//	return 0;
	//}

//方法三
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int score[3] = { 0 };
	//	for (i = 0; i < 3; i++)
	//	{
	//		scanf("%d", &score[i]);
	//	}
	//	for (i = 0; i < 3; i++)
	//	{
	//		printf("score%d=%d", i + 1, score[i]);
	//		if (i < 2)
	//		{
	//			printf(",");
	//		}
	//	}
	//	return 0;
	//}


// 24. BC38-变种水仙花数

//方法一
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	for (i = 10000; i <= 99999; i++)
	//	{
	//		if (i ==(i / 10000) * (i % 10000) + (i / 1000) * (i % 1000) + (i / 100) * (i % 100) + (i / 10) * (i % 10))
	//		{
	//			printf("%d ", i);
	//		}
	//	}
	//	return 0;
	//}

//方法二
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	for (i = 10000; i <= 99999; i++)
	//	{
	//		int j = 0;
	//		int sum = 0;
	//		for (j = 10; j <= 10000; j *= 10)
	//		{
	//			sum += (i / j) * (i % j);
	//		}
	//		if (sum == i)
	//		{
	//			printf("%d ", sum);
	//		}
	//	}
	//	return 0;
	//}


// 25. BC20-kiki算数

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int a = 0;
	//	int b = 0;
	//	int c = 0;
	//	scanf_s("%d %d", &a, &b);
	//	c = (a % 100 + b % 100) % 100;

	//	//c=(a+b)%100;

	//	printf("%d\n", c);
	//	return 0;
	//}


// 26. BC21-浮点数的个位数字

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	double a = 0;
	//	scanf_s("%lf", &a);
	//	int b = (int)a;
	//	printf("%d\n", b % 10);
	//	return 0;
	//}

//方法二：

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	printf("%d\n", n % 10);
	//	return 0;
	//}


// 27. BC22-你能活多少秒？

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int age = 0;
	//	scanf_s("%d", &age);
	//	long long second = age * 3.156e7;      //3.156e7表示3.156乘以10的7次方
	//	printf("%lld", second);
	//	return 0;
	//}




