// 98. BC111-小乐乐与进制转换

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<Stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[40] = { 0 };
	//	scanf("%d", &n);
	//	int i = 0;
	//	while (n)
	//	{
	//		arr[i] = n % 6;
	//		i++;
	//		n = n / 6;
	//	}
	//	for (i--; i >= 0; i--)
	//	{
	//		printf("%d", arr[i]);
	//	}
	//	return 0;
	//}


// 99. BC112-小乐乐求和

//方法一：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	long long sum = 0;
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	for (i = 1; i <= n; i++)
	//	{
	//		sum += i;
	//	}
	//	printf("%lld", sum);
	//	return 0;
	//}

//方法二：
	//#include<stdio.h>
	//int main()
	//{
	//	long long n = 0;
	//	long long sum = 0;
	//	scanf_s("%lld", &n);         //%lld是对应long long类型
	//	sum = (1 + n) * n / 2;       //这里(1+n)*n可能会溢出，所以n也要用long long.
	//	printf("%lld", sum);
	//	return 0;
	//}


// 100.  BC113-小乐乐定闹钟

	//#include<stdio.h>
	//int main()
	//{
	//	int h = 0;
	//	int m = 0;
	//	int k = 0;
	//	scanf_s("%d:%d %d", &h, &m, &k);
	//	h = (h + ( m + k )/ 60) % 24;
	//	m = (m + k ) % 60;
	//	printf("%02d:%02d\n", h, m);
	//	return 0;
	//}


// 101. BC114-小乐乐排电梯

	//#include<Stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	printf("%d\n", (n / 12) * 4 + 2);
	//	return 0;
	//}


// 102. BC115-小乐乐与欧几里得

//方法一：
	//#include<stdio.h>
	//int main()
	//{
	//	long long n = 0;
	//	long long m = 0;
	//	scanf_s("%lld %lld", &n, &m);
	//	long long max = n > m ? m : n;
	//	long long min = n > m ? n : m;
	//	while (1)
	//	{
	//		if (n % max == 0 && m % max == 0)
	//		{
	//			break;
	//		}
	//		max--;
	//	}
	//	while (1)
	//	{
	//		if (min % n == 0 && min % m == 0)
	//		{
	//			break;
	//		}
	//		min++;
	//	}
	//	printf("%lld\n", max + min);
	//	return 0;
	//}

//方法二：
	//#include<stdio.h>
	//int main()
	//{
	//	long long n = 0;
	//	long long m = 0;
	//	scanf_s("%lld %lld", &n, &m);
	//	long long n2 = n;
	//	long long m2 = m;
	//	long long tmp;
	//	long long min = 0;
	//	long long max = 0;
	//	while (tmp = n % m)            //辗转相除法求最大公约数.
	//	{
	//		n = m;
	//		m = tmp;
	//	}
	//	max = m;
	//	min = n2 * m2 / max;          //最小公倍数公式.
	//
	//	printf("%lld\n", max + min);
	//	return 0;
	//}


// 103. BC116-小乐乐改数字

	//#include<stdio.h>
	//#include<math.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	int sum = 0;
	//	while (n)
	//	{
	//		int m = n % 10;
	//		if (m % 2 == 1)
	//			m = 1;
	//		else
	//			m = 0;
	//		sum += m * pow(10, i);
	//		i++;
	//		n /= 10;
	//	}
	//	printf("%d\n", sum);
	//	return 0;
	//}


// 104. BC107-小乐乐走台阶

	//#include<stdio.h>
	//int f(int n)
	//{
	//	if (n <= 2)
	//		return n;
	//	else
	//		return f(n - 1) + f(n - 2);
	//}
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	int ret = f(n);
	//	printf("%d\n", ret);
	//	return 0;
	//}


// 105. BC118-小乐乐和序列

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[100001] = { 0 };
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	int tmp = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &tmp);
	//		arr[tmp] = tmp;
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		if (arr[i]!= 0)
	//		{
	//			printf("%d ", arr[i]);
	//		}
	//	}
	//	return 0;
	//}


// 106. BC119-小乐乐与字符串

	//#include<stdio.h>
	//int main()
	//{
	//	char arr[8000] = { 0 };
	//	scanf_s("%s", &arr,8000);
	//	long long c = 0;
	//	long long ch = 0;
	//	long long chn = 0;
	//	char* p = arr;
	//	while (*p)
	//	{
	//		if (*p == 'C')
	//			c++;
	//		else if (*p == 'H')
	//			ch += c;
	//		else if (*p == 'N')
	//			chn += ch;
	//		p++;
	//	}
	//	printf("%lld\n", chn);
	//	return 0;
	//}


// 107. BC123-小乐乐找最大数

	//#include<stdio.h>
	//int main()
	//{
	//	int arr[4] = { 0 };
	//	int i = 0;
	//	for (i = 0; i < 4; i++)
	//	{
	//		scanf_s("%d", &arr[i]);
	//	}
	//	int max = arr[0];
	//	for (i = 1; i < 4; i++)
	//	{
	//		if (arr[i] > max)
	//			max = arr[i];
	//	}
	//	printf("%d\n", max);
	//	return 0;
	//}


// 108. BC125-小乐乐转换成绩

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	if (n >= 90 && n <= 100)
	//		printf("A\n");
	//	else if (n >= 80 && n < 90)
	//		printf("B\n");
	//	else if (n >= 70 && n < 80)
	//		printf("C\n");
	//	else if (n >= 60 && n < 70)
	//		printf("D\n");
	//	else if (n < 60)
	//		printf("E\n");
	//	else
	//		printf("F\n");
	//	return 0;
	//}


// 109. BC129-小乐乐计算函数

	//#include<stdio.h>
	//max3(int a, int b, int c)
	//{
	//	int max = a > b ? a : b;
	//	max = max > c ? max : c;
	//	return max;
	//}
	//int main()
	//{
	//	int a = 0;
	//	int b = 0;
	//	int c = 0;
	//	scanf_s("%d %d %d", &a, &b, &c);
	//	float m = (float)max3(a + b, b, c) / (max3(a, b + c, c) + max3(a, b, b + c));
	//	printf("%.2f\n", m);
	//	return 0;
	//}