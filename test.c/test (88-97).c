// 88. BC101-班级成绩输入输出

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	double score[5] = { 0 };
	//	for (i = 0; i < 5; i++)
	//	{
	//		int j = 0;
	//		double sum = 0.0;
	//		for (j = 0; j < 5; j++)
	//		{
	//			scanf_s("%lf", &score[j]);
	//			sum += score[j];
	//		}
	//		for (j = 0; j < 5; j++)
	//		{
	//			printf("%.1lf ",score[j]);
	//		}
	//		printf("%.1lf\n", sum);
	//		
	//	}
	//	return 0;
	//}


// 89. BC102-矩阵元素定位

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	int arr[10][10] = { 0 };
	//	scanf("%d %d", &n, &m);
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf("%d", &arr[i][j]);
	//		}
	//	}
	//	int x = 0;
	//	int y = 0;
	//	scanf("%d %d", &x, &y);
	//	printf("%d\n", arr[x - 1][y - 1]);
	//	return 0;
	//}


// 90. BC103-序列重组矩阵

//方法一：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	int arr[10][10] = {0};
	//	scanf_s("%d %d", &n, &m);
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &arr[i][j]);
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			printf("%d ", arr[i][j]);
	//		}
	//		printf("\n");
	//	}
	//	return 0;
	//}

//方法二：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	int arr[10][10] = {0};
	//	scanf_s("%d %d", &n, &m);
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &arr[i][j]);
	//			printf("%d ", arr[i][j]);
	//		}
	//		printf("\n");
	//	}
	//	return 0;
	//}

//方法三：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	int arr[10][10] = {0};
	//	scanf_s("%d %d", &n, &m);
	//	int i = 0;
	//	int j = 0;
	//	int num = 0;
	//	for (i = 1; i <= n*m; i++)
	//	{
	//		scanf_s("%d", &num);
	//		printf("%d ", num);
	//		if (i % m == 0)
	//		{
	//			printf("\n");
	//		}
	//	}
	//	return 0;
	//}

// 91. BC104-最高身高

	//#include<Stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	scanf_s("%d %d", &n, &m);
	//	int i = 0;
	//	int j = 0;
	//	int num = 0;
	//	int max = 0;
	//	int x = 0;
	//	int y = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &num);
	//			if (num > max)
	//			{
	//				max = num;
	//				x = i;
	//				y = j;
	//			}
	//		}
	//	}
	//	printf("%d %d\n", x+1, y+1);
	//	return 0;
	//}


// 92. BC105-矩阵相等判断

//方法一：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	scanf_s("%d %d", &n, &m);
	//	int arr1[10][10] = {0};
	//	int arr2[10][10] = {0};
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &arr1[i][j]);
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &arr2[i][j]);
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			if (arr1[i][j] != arr2[i][j])
	//			{
	//				printf("No\n");
	//				return 0;                 //此处的return 0表示整个main函数结束，之后代码都不执行，
	//			}                             //如果换成break的话，只是跳出当前的for循环.
	//		}
	//	}
	//	printf("Yes\n");
	//	return 0;
	//}

//方法二：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	scanf_s("%d %d", &n, &m);
	//	int arr1[10][10] = { 0 };
	//	int arr2[10][10] = { 0 };
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &arr1[i][j]);
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &arr2[i][j]);
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			if (arr1[i][j] != arr2[i][j])
	//			{
	//				printf("No\n");
	//				break;
	//			}                    
	//		}
	//		if (arr1[i][j] != arr2[i][j])
	//		{
	//			break;
	//		}
	//	}
	//	if (i == n)
	//	{
	//		printf("Yes\n");
	//	}
	//	return 0;
	//}


// 93. BC106-上三角矩阵判断

//方法一：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[10][10] = { 0 };
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			scanf_s("%d", &arr[i][j]);
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			if (i > j)
	//			{
	//				if (arr[i][j] != 0)
	//				{
	//					printf("NO\n");
	//					return 0;
	//				}
	//			}
	//		}
	//	}
	//	printf("YES\n");
	//	return 0;
	//}

//方法二：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[10][10] = { 0 };
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			scanf_s("%d", &arr[i][j]);
	//			if (i > j)
	//			{
	//				if (arr[i][j] != 0)
	//				{
	//					printf("NO\n");
	//					return 0;
	//				}
	//			}
	//		}
	//	}
	//	printf("YES\n");
	//	return 0;
	//}


// 94. BC107-矩阵转置

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	int arr[10][10] = { 0 };
	//	scanf_s("%d %d", &n, &m);
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &arr[i][j]);
	//		}
	//	}
	//	for (i = 0; i < m; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			printf("%d ", arr[j][i]);
	//		}
	//		printf("\n");
	//	}
	//	return 0;
	//}


// 95. BC108-矩阵交换

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	int arr[10][10] = { 0 };
	//	int k = 0;
	//	scanf_s("%d %d", &n, &m);
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &arr[i][j]);
	//		}
	//	}
	//	scanf_s("%d", &k);
	//	char t = 0;
	//	int a = 0;
	//	int b = 0;
	//	for (i = 0; i < k; i++)
	//	{
	//		scanf_s(" %c %d %d", &t,1, &a, &b);    //在 %c前面加一个空格，可以消化掉前
	//		if (t == 'r')                          //面的空白字符(就可以不写getchar了).
	//		{                                      //这里的1是指缓冲区大小.
	//			for (j = 0; j < m; j++)
	//			{
	//				int tmp = arr[a-1][j];
	//				arr[a - 1][j] = arr[b - 1][j];
	//				arr[b - 1][j] = tmp;
	//			}
	//		}
	//		else if (t == 'c')
	//		{
	//			for (j = 0; j < n; j++)
	//			{
	//				int tmp = arr[j][a - 1];
	//				arr[j][a - 1] = arr[j][b - 1];
	//				arr[j][b - 1] = tmp;
	//			}
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			printf("%d ", arr[i][j]);
	//		}
	//		printf("\n");
	//	}
	//	return 0;
	//}


// 96. BC109-杨辉三角

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[30][30] = { 0 };
	//	scanf_s("%d", & n);
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			if (j == 0)
	//				arr[i][j] = 1;
	//			if (i == j)
	//				arr[i][j] = 1;
	//			if (i >= 2 && j >= 1)
	//			{
	//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
	//			}
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j <= i; j++)
	//		{
	//			printf("%5d", arr[i][j]);
	//		}
	//		printf("\n");
	//	}
	//	return 0;
	//}


// 97. BC110-井字棋

	//#include<stdio.h>
	//int main()
	//{
	//	char arr[3][3] = { 0 };
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < 3; i++)
	//	{
	//		for (j = 0; j < 3; j++)
	//		{
	//			scanf_s("%c", &arr[i][j]);
	//			getchar();
	//		}
	//	}
	//	char flag = 'O';
	//	for (i = 0; i < 3; i++)
	//	{
	//		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != 'O')
	//		{
	//			flag = arr[i][1];
	//			break;
	//		}
	//		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != 'O')
	//		{
	//			flag = arr[1][i];
	//			break;
	//		}
	//		if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != 'O')
	//		{
	//			flag = arr[0][0];
	//			break;
	//		}
	//		if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != 'O')
	//		{
	//			flag = arr[0][2];
	//			break;
	//		}
	//	}
	//	if (flag == 'K')
	//	{
	//		printf("KiKi wins!\n");
	//	}
	//	else if (flag == 'B')
	//	{
	//		printf("BoBo wins!\n");
	//	}
	//	else
	//	{
	//		printf("No winner!\n");
	//	}
	//	return 0;
	//}