// 110. BC130-小乐乐查找数字

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[100] = { 0 };
	//	scanf("%d", &n);
	//	int x = 0;
	//	int count = 0;
	//	int i = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf("%d", &arr[i]);
	//	}
	//	scanf("%d", &x);
	//	for (i = 0; i < n; i++)
	//	{
	//		if (arr[i] == x)
	//		{
	//			count++;
	//		}
	//	}
	//	printf("%d\n", count);
	//	return 0;
	//}


// 111. BC131-kiki学程序设计基础

	//#include<stdio.h>
	//int main()
	//{
	//	printf("printf(\"Hello world!\\n\");\n");
	//	printf("cout<<\"Hello world!\"<<end1;\n");
	//	return 0;
	//}


// 112. BC135-kiki求质数的个数

	//#include<stdio.h>
	//is_prime(int n)
	//{
	//	int j = 0;
	//	for (j = 2; j <= n-1; j++)      //试除法，用2到n-1的数字去试除n.
	//	{
	//		if (n % j == 0)
	//		{
	//			return 0;
	//		}
	//	}
	//	return 1;
	//}
	//int main()
	//{
	//	int i = 0;
	//	int count = 0;
	//	for (i = 100; i <= 999; i++)
	//	{
	//		if (is_prime(i) == 1)
	//		{
	//			count++;
	//		}
	//	}
	//	printf("%d\n", count);
	//	return 0;
	//}


// 113. BC136-kiki去重整数并排序

//方法一： 
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[1000] = { 0 };
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &arr[i]);
	//	}
	//	for (i = 0; i < n - 1; i++)
	//	{
	//		int j = 0;
	//		for (j = 0; j < n-1-i; j++)         //冒泡排序
	//		{
	//			if (arr[j] > arr[j + 1])
	//			{
	//				int tmp = arr[j];
	//				arr[j] = arr[j + 1];
	//				arr[j + 1] = tmp;
	//			}
	//		}
	//	}
	//	for (i = 0; i < n - 1; i++)
	//	{
	//		if (arr[i] == arr[i + 1])
	//		{
	//			int k = 0;
	//			for (k = i; k < n-1; k++)
	//			{
	//				arr[k] = arr[k + 1];
	//			}
	//			i--;
	//			n--;
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		printf("%d ", arr[i]);
	//	}
	//	return 0;
	//}

//方法二：
	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	int arr[1001] = { 0 };
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	int m = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &m);
	//		arr[m] = m;
	//	}
	//	for (i = 0; i < 1001; i++)
	//	{
	//		if (arr[i] != 0)
	//		{
	//			printf("%d ", arr[i]);
	//		}
	//	}
	//	return 0;
	//}


// 114. BC138-KIKI学结构体和指针

	//#include<stdio.h>
	//#include<stdlib.h>
	//struct Node
	//{
	//	int data;
	//	struct Node* next;
	//};
	//int main()
	//{
	//	struct Node* list = NULL;
	//	struct Node* tail = NULL;
	//	int n = 0;
	//	int k = 0;
	//	scanf_s("%d", &n);
	//	int i = 0;
	//	int m = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		scanf_s("%d", &k);
	//		struct Node* pn = (struct Node*)malloc(sizeof(struct Node));       //malloc开辟一块存储struct Node指针的空间
	//		pn->data = k;                                                      //因为malloc返回类型为void*(空指针)，所以要强制类型转换.
	//		pn->next = NULL;
	//		if (list == NULL)
	//		{
	//			list = pn;
	//			tail = pn;
	//		}
	//		else
	//		{
	//			tail->next = pn;
	//			tail = pn;
	//		}
	//	}
	//	scanf_s("%d", &m);
	//	struct Node* curt = list;
	//	struct Node* prev = NULL;
	//	while (curt)
	//	{
	//		if (curt->data == m)
	//		{
	//			struct Node* pd = curt;
	//			if (curt == list)
	//			{
	//				list = list->next;
	//				curt = list;
	//			}
	//			else
	//			{
	//				prev->next = curt->next;
	//				curt = prev->next;
	//			}
	//			free(pd);
	//			n--;
	//		}
	//		else
	//		{
	//			prev = curt;
	//			curt = curt->next;
	//		}
	//	}
	//	//输出
	//	printf("%d\n", n);
	//	curt = list;
	//	while (curt)
	//	{
	//		printf("%d ", curt->data);
	//		curt = curt->next;
	//	}
	//	//释放
	//	curt = list;
	//	struct Node* del = NULL;
	//	while (curt)
	//	{
	//		del = curt;
	//		curt = curt->next;
	//		free(del);
	//	}
	//	list = NULL;
	//	return 0;
	//}


// 115. BC139-KIKI定义电子日历类

	//#define _CRT_SECURE_NO_WARNINGS
	//#include <stdio.h>
	//#include <stdlib.h>
	//
	//typedef struct 
	//{
	//	int Month;
	//	int Day;
	//	int Year;
	//	void (*printDate)(struct TDate*);
	//	void (*setDate)(struct TDate*);
	//} TDate;
	//
	//// 打印日期函数
	//void printDate(TDate* this) 
	//{
	//	printf("%d/%d/%d\n", this->Day, this->Month, this->Year);
	//}
	//
	//// 设置日期函数
	//void setDate(TDate* this) 
	//{
	//	printf("请输入年、月、日（用空格分隔）：");
	//	scanf("%d %d %d", &this->Year, &this->Month, &this->Day);
	//}
	//
	//// 构造函数
	//TDate* createTDate(int m, int d, int y) 
	//{
	//	TDate* obj = (TDate*)malloc(sizeof(TDate));
	//	if (obj == NULL) {
	//		printf("内存分配失败！\n");
	//		exit(1);
	//	}
	//
	//	obj->Month = m;
	//	obj->Day = d;
	//	obj->Year = y;
	//	obj->printDate = printDate;
	//	obj->setDate = setDate;
	//
	//	return obj;
	//}
	//
	//// 析构函数
	//void destroyTDate(TDate* obj) 
	//{
	//	free(obj);
	//}
	//
	//int main() 
	//{
	//	// 使用默认参数创建对象
	//	TDate* date1 = createTDate(0, 0, 0);
	//	printf("默认日期: ");
	//	date1->printDate(date1);
	//
	//	// 设置新日期
	//	date1->setDate(date1);
	//	printf("更新后的日期: ");
	//	date1->printDate(date1);
	//
	//	// 释放内存
	//	destroyTDate(date1);
	//
	//	// 暂停程序，等待用户输入
	//#ifdef _WIN32
	//	system("pause");
	//#else
	//	printf("按任意键继续...");
	//	getchar();
	//	getchar();
	//#endif
	//
	//	return 0;
	//}