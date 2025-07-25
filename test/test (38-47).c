// 38. BC41-你是天才吗？

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int iq = 0;
	//	while (scanf_s("%d", &iq)!=EOF)
	//	{
	//		if (iq >= 140)
	//			printf("Genius\n");
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int iq = 0;
	//	while (~scanf_s("%d", &iq))        // ~表示按位取反，对scanf输入的值按位取反，当输入EOF时跳出循环，因为EOF值为-1，按位取反为0，表示假跳出循环.
	//	{
	//		if (iq >= 140)
	//			printf("Genius\n");
	//	}
	//	return 0;
	//}



// 39. BC42-完美成绩

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int score = 0;
	//	while (scanf_s("%d",&score) != EOF)
	//	{
	//		if (score >= 90 && score <= 100)
	//			printf("Perfect\n");
	//	}
	//	return 0;
	//}


// 40. BC43-及格分数

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int score = 0;
	//	while (scanf_s("%d", &score) != EOF)
	//	{
	//		if (score >= 60)
	//			printf("Pass\n");
	//		else
	//			printf("Fall\n");
	//	}
	//	return 0;
	//}


// 41. BC44-判断整数的奇偶性

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int figure = 0;
	//	while (scanf("%d", &figure) != EOF)
	//	{
	//		if (figure % 2 == 1)
	//			printf("Odd\n", figure);
	//		else if ((figure % 2 == 0) || figure == 0)
	//			printf("Even\n", figure);
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int num = 0;
	//	while (scanf("%d", &num) != EOF)
	//	{
	//		if (num % 2 == 1)
	//			printf("Odd\n");
	//		else
	//			printf("Even\n");
	//	}
	//	return 0;
	//}


// 42. BC45-最高分数

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int score[3] = { 0 };
	//	while (scanf_s("%d %d %d",&score[0],&score[1],&score[2])!=EOF)
	//	{
	//		int max = 0;
	//		int i = 0;
	//		for (i = 0; i < 3; i++)
	//		{
	//			if (score[i] > max)
	//				max = score[i];
	//		}
	//		printf("%d\n", max);
	//	}
	//	
	//	return 0;
	//}


// 43. BC46-判断元音还是辅音

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	while ((ch=getchar()) != EOF)       //getchar,读取输入的第一个字符(注意是输入的，printf输出的不会读取).
	//	{
	//		
	//		if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
	//		{
	//			printf("Vowel\n");
	//			
	//		}
	//		else
	//		{
	//			printf("Consonant\n");
	//			
	//		}
	//		getchar();
	//		
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include <stdio.h>
	//
	//int main()
	//{
	//	char ch = 0;
	//	while ((ch = getchar()) != EOF)
	//	{
	//		// 过滤掉换行符
	//		if (ch == '\n')
	//			continue;
	//		if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
	//		{
	//			printf("Vowel\n");
	//		}
	//		else
	//		{
	//			printf("Consonant\n");
	//		}
	//	}
	//	return 0;
	//}

//方法三：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	char arr[] = "AEIOUaeiou";
	//	while ((ch = getchar()) != EOF)
	//	{
	//		int i = 0;
	//		for (i = 0; i < 10; i++)
	//		{
	//			if (ch == arr[i])
	//			{
	//				printf("Vowel\n");
	//				break;
	//			}
	//		}
	//		if (i == 10)
	//			printf("Consonant\n");
	//		getchar();
	//	}
	//	return 0;
	//}

//方法四：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	char arr[] = "AEIOUaeiou";
	//	while (scanf_s(" %c",&ch) != EOF)       //在%c的前面写一个空格会消化掉前面所有的空白字符，然后读取一个字符.
	//	{
	//		int i = 0;
	//		for (i = 0; i < 10; i++)
	//		{
	//			if (ch == arr[i])
	//			{
	//				printf("Vowel\n");
	//				break;
	//			}
	//		}
	//		if (i == 10)
	//			printf("Consonant\n");
	//		
	//	}
	//	return 0;
	//}

//方法五：       这个方法有问题，写scanf时尽量别加\n.
	//#include <stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	char arr[] = "AEIOUaeiou";             //在%c的后边发给一个'\n'，其实在输入时候就会消化掉这个\n字符
	//	while (scanf_s("%c\n", &ch) != EOF)    //不会为下次留下空白字符的隐患
	//	{
	//		if (strchr(arr, ch))               //strchr(const* string,int c)是一个库函数，在string这个字符串里边去找c这个字符
	//		{                                  //如果找到返回字符在字符串中的位置，不再返回空指针.
	//			printf("Vowel\n");
	//		}
	//		else
	//		{
	//			printf("Consonant\n");
	//		}
	//		
	//	}
	//	return 0;
	//}


// 44. BC47-判断是不是字母

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	while ((ch=getchar())!=EOF)
	//	{
	//		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	//		{
	//			printf("%c is an phabet.\n", ch);
	//		}
	//		else
	//			printf("%c is not an alphabet.\n", ch);
	//		getchar();
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	while ((ch = getchar()) != EOF)
	//	{
	//		if (isalpha(ch))                             //isalpha( )，是一个库函数，括号里是字母返回非0，不是字母返回0.
	//		{
	//			printf("%c is an phabet.\n", ch);
	//		}
	//		else
	//			printf("%c is not an alphabet.\n", ch);
	//		getchar();
	//	}
	//	return 0;
	//}


// 45. BC48-字母的大小写转换

//方法一：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	while (scanf_s(" %c", &ch) != EOF)
	//	{
	//		if (ch >= 'a' && ch <= 'z')
	//			printf("%c\n", ch - 32);
	//		else if (ch >= 'A' && ch <= 'Z')
	//			printf("%c\n", ch + 32);
	//	}
	//	return 0;
	//}

//方法二：
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//#include<ctype.h>
	//int main()
	//{
	//	char ch = 0;
	//	while (scanf_s(" %c", &ch) != EOF)
	//	{
	//		if (isupper(ch))                      //isupper是一个库函数，判断一个字母是不是大写.
	//			printf("%c\n", tolower(ch));      //toupper是一个库函数，把一个大写字母改成小写.
	//		else if (islower(ch))                 //isupper是一个库函数，判断一个字母是不是小写.
	//			printf("%c\n", toupper(ch));      //isupper是一个库函数，把一个小写字母改成大写.
	//	}                                         //头文件均为#incluide<ctype.h>.
	//	return 0;
	//}


// 46. BC50-计算单位阶跃函数

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int t = 0;
	//	while (scanf_s("%d", &t) != EOF)
	//	{
	//		if (t > 0)
	//			printf("1\n");
	//		else if (t ==0 )
	//			printf("0.5\n");
	//		else
	//			printf("0\n");
	//	}
	//	return 0;
	//}


// 47. BC51-三角形判断

	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	double a = 0;
	//	double b = 0;
	//	double c = 0;
	//	while (~scanf_s("%lf %lf %lf", &a, &b, &c))
	//	{
	//		if ((a + b>c) && (a + c>b) && (b + c>b))
	//		{
	//			if (a == b && b == c)
	//				printf("Equilateral triangle!\n");
	//			else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
	//				printf("Isosceles triangle!\n");
	//			else
	//				printf("Oridinary triangle!\n");
	//		}
	//		else
	//			printf("Not a triangle!\n");
	//	}
	//	return 0;
	//}