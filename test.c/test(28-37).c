// 28. BC23-时间转换

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int sec = 0;
	//	scanf_s("%d", &sec);
	//	int hour = sec / 60 / 60;
	//	int min =sec/ 60 % 60;
	//	int seconds = sec % 60;
	//	printf("%d %d %d", hour, min, seconds);
	//	return 0;
	//}


// 29. BC24-总成绩和平均分计算

//方法一：
	//#define _CRT_SUCURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	double score[3] = { 0 };
	//	
	//	scanf_s("%lf %lf %lf", &score[0], &score[1], &score[2]);
	//	double sum = score[0] + score[1] + score[2];
	//	double average = sum / 3;
	//	printf("sum=%.2lf  average=%.2lf", sum, average);
	//	return 0;
	//}

//方法二：
	//#define _CRT_SUCURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	double score = 0;
	//	double sum = 0;
	//	int i = 0;
	//	for (i =0;i<3;i++)
	//	{
	//		scanf_s("%lf", &score);
	//		sum += score;
	//	}
	//	double average = sum / 3;
	//	printf("sum=%.2lf  average=%.2lf", sum, average);
	//	return 0;
	//}


// 30. BC30-kiki和酸奶

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int h = 0;
	//	int m = 0;
	//	scanf_s("%d %d %d", &n, &h, &m);
	//	int rest = n - (m / h);
	//	if (m / h == 0)
	//	{
	//		printf("%d", rest);
	//	}
	//	else
	//	{
	//		printf("%d", rest - 1);
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int h = 0;
	//	int m = 0;
	//	while (scanf_s("%d %d %d", &n, &h, &m)!=EOF)
	//	{
	//		if (m % h > 0)
	//		{
	//			printf("%d", n - m / h - 1);
	//		}
	//		else
	//		{
	//			printf("%d",n - m / h);
	//		}
	//	}
	//	return 0;
	//}


// 31. BC31-发布会信息

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	printf("I lost my cellphone\n");
	//	return 0;
	//}


// 32. BC32-输出学生信息

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	printf("Name    Age    Gender\n");
	//	printf("---------------------\n");
	//	printf("Jack    18     man\n");
	//	return 0;
	//}


// 33. BC33-计算平均成绩

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int score[5] = { 0 };
	//	int i = 0;
	//	int sum = 0;
	//	for (i = 0; i < 5; i++)
	//	{
	//		scanf_s("%d", &score[i]);
	//		sum += score[i];
	//	}
	//	double average = sum / 5.0;
	//	printf("%.1lf", average);
	//	return 0;
	//}


// 34. BC34-进制A+B

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int a = 0;
	//	int b = 0;
	//	scanf("%x %o", &a, &b);
	//	int sum = a+b;
	//	printf("%d\n", sum);
	//	return 0;
	//}


// 35. BC37-网购

	//#define _CRT_SECURE_NO_WARNING
	//#include<stdio.h>
	//int main()
	//{
	//	double price = 0.0;
	//	int month = 0;
	//	int day = 0;
	//	int flag = 0;
	//	double last = 0.0;
	//	scanf_s("%lf %d %d %d", &price, &month, &day, &flag);
	//	//方法一：
	//	if (month == 11 && day == 11)
	//	{
	//		if (flag == 1)
	//		{
	//			last = price * 0.7 - 50;
	//		}
	//		else
	//		{
	//			last = price * 0.7;
	//		}
	//	}
	//	else if (month == 12 && day == 12)
	//	{
	//		if (flag == 1)
	//		{
	//			last = price * 0.8 - 50;
	//		}
	//		else
	//		{
	//			last = price * 0.8;
	//		}
	//	}
	//
	//	//方法二：
	//
	//		/*if (month == 11 && day == 11)
	//		{
	//			last = price * 0.7;
	//			if (flag == 1)
	//				last -= 50;
	//		}
	//		else if (month == 12 && day == 12)
	//		{
	//			last = price * 0.8;
	//			if (flag == 1)
	//				last -= 50;
	//		}*/
	//
	//	//方法三：
	//
	//		/*double cut = 1.0;
	//		if (month == 11 && day == 11)
	//		{
	//			cut = 0.7;
	//		}
	//		else if (month == 12 && day == 12)
	//		{
	//			cut = 0.8;
	//		}
	//		last = price * cut - flag * 50.0;*/
	//
	//	if (last < 0.0)
	//	{
	//		printf("%.2lf", 0.0);
	//	}
	//	else
	//	{
	//		printf("%.2lf", last);
	//	}
	//
	//	return 0;
	//}


// 36. BC39-争夺前五名

//方法一:
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int score[ 40 ] = { 0 };
	//	int i = 0;
	//	scanf_s("%d", &n);
	//	for (i=0;i <=n-1;i++)
	//	{
	//		scanf_s("%d", &score[i]);
	//	}
	//
	//	for (i = 0; i < n - 1; i++)
	//	{
	//		int j = 0;
	//		for (j = 0; j<n-1-i; j++)
	//		{
	//			if (score[j] > score[j + 1])
	//			{
	//				int temp = score[j];
	//				score[j] = score[j + 1];
	//				score[j + 1] = temp;
	//			}
	//		}
	//	}
	//
	//	for (i = n - 1; i > n - 6; i--)
	//	{
	//		printf("%d ", score[i]);
	//	}
	//	
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//#include<stdlib.h>
	//
	//int cmpare(const void* e1, const void* e2)
	//{
	//	return *(int*)e1 - *(int*)e2;
	//}                                           //不能对void类型的指针直接解引用.
	//
	//int main()
	//{
	//	int n = 0;
	//	int score[40] = { 0 };
	//	int i = 0;
	//	scanf_s("%d", &n);
	//	for (i = 0; i <= n - 1; i++)
	//	{
	//		scanf_s("%d", &score[i]);
	//	}
	//
	//	qsort(score, n, 4, cmpare);          //qsort是库函数，e1在前排升序(e1-e2)，在后排降序(e2-e1).
	//
	//	for (i = n - 1; i > n - 6; i--)
	//	{
	//		printf("%d ", score[i]);
	//	}
	//
	//	return 0;
	//}


// 37. BC40-竞选社长

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char arr[100] = { 0 };
	//	gets(arr);               //输入一串字符.
	//	int count_a = 0;
	//	int count_b = 0;
	//	int i = 0;
	//	while (arr[i] != '0')
	//	{
	//		if (arr[i] == 'A')
	//		{
	//			count_a++;
	//		}
	//		else if (arr[i] == 'B')
	//		{
	//			count_b++;
	//		}
	//		i++;
	//	}
	//	if (count_a > count_b)
	//	{
	//		printf("A\n");
	//	}
	//	else if (count_a < count_b)
	//	{
	//		printf("B\n");
	//	}
	//	else
	//	{
	//		printf("E\n");
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char arr[100] = { 0 };
	//	gets(arr);               
	//	int flag = 0;
	//	int i = 0;
	//	while (arr[i] != '0')
	//	{
	//		if (arr[i] == 'A')
	//		{
	//			flag++;
	//		}
	//		else if (arr[i] == 'B')
	//		{
	//			flag--;
	//		}
	//		i++;
	//	}
	//	if (flag>0)
	//	{
	//		printf("A\n");
	//	}
	//	else if(flag<0)
	//	{
	//		printf("B\n");
	//	}
	//	else
	//	{
	//		printf("E\n");
	//	}
	//	return 0;
	//}

//方法三：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	int flag = 0;
	//	while ((ch = getchar()) != '0' && ch != EOF)    //getchar()获取一个字符.
	//	{
	//		if (ch == 'A')
	//			flag++;
	//		if (ch == 'B')
	//			flag--;
	//	}
	//	if (flag > 0)
	//	{
	//		printf("A\n");
	//	}
	//	else if (flag < 0)
	//	{
	//		printf("B\n");
	//	}
	//	else
	//	{
	//		printf("E\n");
	//	}
	//	return 0;
	//}