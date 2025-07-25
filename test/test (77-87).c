// 77.  BC87-成绩统计

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	float score=0.0;
	//	float sum = 0.0;
	//	float max = 0.0;
	//	float min = 100.0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%f", &score);
	//		sum += score;
	//		if (score > max)
	//			max = score;
	//		if (score < min)
	//			min = score;
	//	}
	//	printf("%.2f %.2f %.2f\n", max, min,sum/n);
	//	return 0;
	//}


// 78. BC89-密码验证

//方法一：
	//#include<stdio.h>
	//#include<string.h>
	//int main()
	//{
	//	char password1[100] = { 0 };
	//	char password2[100] = { 0 };
	//	scanf_s("%99s %99s", password1,(unsigned)sizeof(password1), password2,(unsigned)sizeof(password2));
	//	//比较两个密码是否相同
	//	if (strcmp(password1, password2) == 0)
	//		printf("same\n");
	//	else
	//		printf("different\n");
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include <stdio.h>
	//#include <string.h>
	//
	//int main()
	//{
	//    char password1[100] = { 0 };
	//    char password2[100] = { 0 };
	//
	//    while (1) 
	//    {
	//        printf("请输入两个密码（用空格分隔，中间不能有换行）：");
	//
	//        // 使用scanf读取两个字符串
	//        if (scanf("%99s %99s", password1, password2) != 2) 
	//        {
	//            printf("输入错误：必须输入两个用空格分隔的字符串！\n");
	//
	//            // 彻底清除输入缓冲区
	//            while (getchar() != '\n');
	//            continue;
	//        }
	//
	//        // 检查是否有多余输入（第三个字符串）
	//        int c;
	//        int has_extra = 0;
	//        while ((c = getchar()) != '\n') 
	//        {
	//            if (c != ' ' && c != '\t') 
	//            {
	//                has_extra = 1;
	//                break;
	//            }
	//        }
	//
	//        if (has_extra) 
	//        {
	//            printf("输入错误：只能输入两个字符串！\n");
	//            // 清除剩余输入
	//            while (getchar() != '\n');
	//            continue;
	//        }
	//
	//        // 正常比较两个字符串
	//        if (strcmp(password1, password2) == 0) 
	//        {
	//            printf("same\n");
	//        }
	//        else 
	//        {
	//            printf("different\n");
	//        }
	//        break;  // 比较完成后退出循环
	//    }
	//
	//    return 0;
	//}


// 79. BC90-矩阵计算

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	int num = 0;
	//	int sum = 0;
	//	scanf_s("%d %d", &n, &m);
	//	//获取N行M列的矩阵
	//	int i = 0;
	//	
	//	for (i = 0; i < n; i++)
	//	{
	//		int j = 0;
	//		for (j = 0; j < m; j++)
	//		{
	//			scanf_s("%d", &num);
	//			if (num > 0)
	//				sum += num;
	//		}
	//	}
	//	printf("%d\n", sum);
	//	return 0;
	//}


// 80. BC91-逆序输出

	//#include<stdio.h>
	//int main()
	//{
	//	int arr[10] = { 0 };
	//	//输入
	//	int i = 0;
	//	for (i = 0; i < 10; i++)
	//	{
	//		scanf_s("%d", &arr[i]);
	//	}
	//	//输出
	//	for (i = 9; i >= 0; i--)
	//	{
	//		printf("%d ", arr[i]);
	//	}
	//	printf("\n");
	//	return 0;
	//}


// 81. BC93-统计数据正负个数

	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int num = 0;
	//	int positive = 0;
	//	int negative = 0;
	//	for (i = 0; i < 10; i++)
	//	{
	//		scanf_s("%d", &num);
	//		if (num >= 0)
	//			positive++;
	//		else
	//			negative++;
	//	}
	//	printf("positive:%d\n", positive);
	//	printf("negative:%d\n", negative);
	//
	//	return 0;
	//}


// 82. BC94-N个数之和

	//#include<stdio.h>
	//int main()
	//{
	//	int num = 0;
	//	int i = 0;
	//	int n = 0;
	//	int sum = 0;
	//	scanf_s("%d", &n);
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &num);
	//		sum += num;
	//	}
	//	printf("%d\n", sum);
	//	return 0;
	//}


// 83. BC95-最低分与最高分之差

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int score = 0;
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	int max = 0;
	//	int min = 100;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &score);
	//		if (score > max)
	//			max = score;
	//		if (score < min)
	//			min = score;
	//	}
	//	printf("%d\n", max - min);
	//	return 0;
	//}


// 84. BC96-有序序列判断

	//#include<stdio.h>
	//int main()
	//{
	//	int N = 0;
	//	int i = 0;
	//	int arr[50] = { 0 };
	//	int flag1 = 0;
	//	int flag2 = 0;
	//	scanf_s("%d", &N);
	//	for (i = 0; i < N; i++)
	//	{
	//		scanf_s("%d", &arr[i]);
	//		if (i > 0)
	//		{
	//			if (arr[i] > arr[i - 1])
	//				flag1 = 1;
	//			else
	//				flag2 = 1;
	//		}
	//	}
	//	if (flag1 + flag2 == 1)
	//		printf("sorted\n");
	//	else
	//		printf("unsorted\n");
	//	return 0;
	//}


// 85. BC98-序列中删除指定数字

	//#include<stdio.h>
	//int main()
	//{
	//	int N = 0;
	//	scanf_s("%d", &N);
	//	int i = 0;
	//	int arr[50] = { 0 };
	//	int delate = 0;
	//	//读取N个数字
	//	for (i = 0; i < N; i++)
	//	{
	//		scanf_s("%d", &arr[i]);
	//	}
	//	//读取要删除的数字
	//	scanf_s("%d", &delate);
	//	//删除
	//	int j = 0;
	//	for (i = 0; i < N; i++)
	//	{
	//		if (arr[i] != delate)
	//		{
	//			arr[j++] = arr[i];       //arr[j]=arr[i];j++.
	//		}
	//	}
	//	for (i = 0; i < j; i++)
	//	{
	//		printf("%d ", arr[i]);
	//	}
	//	return 0;
	//}


// 86. BC99-序列中整数去重

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	int arr[1000] = { 0 };
	//	int i = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &arr[i]);
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		int j = 0;
	//		for (j = i + 1; j < n; j++)
	//		{
	//			if (arr[i] == arr[j])
	//			{
	//				int k = 0;
	//				for (k = j; k < n-1; k++)
	//				{
	//					arr[k] = arr[k + 1];
	//				}
	//				n--;
	//				j--;
	//			}
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		printf("%d ", arr[i]);
	//	}
	//	return 0;
	//}


// 87. BC100-有序序列的合并

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int m = 0;
	//	scanf_s("%d %d", &n, &m);
	//	int num1[100] = { 0 };
	//	int num2[100] = { 0 };
	//	int arr[200] = { 0 };
	//	int i = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &num1[i]);
	//	}
	//	for (i = 0; i < m; i++)
	//	{
	//		scanf_s("%d", &num2[i]);
	//	}
	//	i = 0;
	//	int j = 0;
	//	int k = 0;
	//	while (i < n && j < m)
	//	{
	//		if (num1[i] < num2[j])
	//		{
	//			arr[k++] = num1[i++];
	//		}
	//		else
	//		{
	//			arr[k++] = num2[j++];
	//		}
	//	}
	//	if (i == n)
	//	{
	//		for (; j < m; j++)
	//		{
	//			arr[k++] = num2[j];
	//		}
	//	}
	//	else
	//	{
	//		for (; i < n; i++)
	//		{
	//			arr[k++] = num1[i];
	//		}
	//	}
	//	for (i = 0; i < k; i++)
	//	{
	//		printf("%d ", arr[i]);
	//	}
	//	printf("\n");
	//	return 0;
	//}