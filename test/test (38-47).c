// 38. BC41-���������

//����һ��
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

//��������
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	int iq = 0;
	//	while (~scanf_s("%d", &iq))        // ~��ʾ��λȡ������scanf�����ֵ��λȡ����������EOFʱ����ѭ������ΪEOFֵΪ-1����λȡ��Ϊ0����ʾ������ѭ��.
	//	{
	//		if (iq >= 140)
	//			printf("Genius\n");
	//	}
	//	return 0;
	//}



// 39. BC42-�����ɼ�

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


// 40. BC43-�������

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


// 41. BC44-�ж���������ż��

//����һ��
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

//��������
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


// 42. BC45-��߷���

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


// 43. BC46-�ж�Ԫ�����Ǹ���

//����һ��
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	while ((ch=getchar()) != EOF)       //getchar,��ȡ����ĵ�һ���ַ�(ע��������ģ�printf����Ĳ����ȡ).
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

//��������
	//#define _CRT_SECURE_NO_WARNINGS
	//#include <stdio.h>
	//
	//int main()
	//{
	//	char ch = 0;
	//	while ((ch = getchar()) != EOF)
	//	{
	//		// ���˵����з�
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

//��������
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

//�����ģ�
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	char arr[] = "AEIOUaeiou";
	//	while (scanf_s(" %c",&ch) != EOF)       //��%c��ǰ��дһ���ո��������ǰ�����еĿհ��ַ���Ȼ���ȡһ���ַ�.
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

//�����壺       ������������⣬дscanfʱ�������\n.
	//#include <stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	char arr[] = "AEIOUaeiou";             //��%c�ĺ�߷���һ��'\n'����ʵ������ʱ��ͻ����������\n�ַ�
	//	while (scanf_s("%c\n", &ch) != EOF)    //����Ϊ�´����¿հ��ַ�������
	//	{
	//		if (strchr(arr, ch))               //strchr(const* string,int c)��һ���⺯������string����ַ������ȥ��c����ַ�
	//		{                                  //����ҵ������ַ����ַ����е�λ�ã����ٷ��ؿ�ָ��.
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


// 44. BC47-�ж��ǲ�����ĸ

//����һ��
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

//��������
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//int main()
	//{
	//	char ch = 0;
	//	while ((ch = getchar()) != EOF)
	//	{
	//		if (isalpha(ch))                             //isalpha( )����һ���⺯��������������ĸ���ط�0��������ĸ����0.
	//		{
	//			printf("%c is an phabet.\n", ch);
	//		}
	//		else
	//			printf("%c is not an alphabet.\n", ch);
	//		getchar();
	//	}
	//	return 0;
	//}


// 45. BC48-��ĸ�Ĵ�Сдת��

//����һ��
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

//��������
	//#define _CRT_SECURE_NO_WARNINGS
	//#include<stdio.h>
	//#include<ctype.h>
	//int main()
	//{
	//	char ch = 0;
	//	while (scanf_s(" %c", &ch) != EOF)
	//	{
	//		if (isupper(ch))                      //isupper��һ���⺯�����ж�һ����ĸ�ǲ��Ǵ�д.
	//			printf("%c\n", tolower(ch));      //toupper��һ���⺯������һ����д��ĸ�ĳ�Сд.
	//		else if (islower(ch))                 //isupper��һ���⺯�����ж�һ����ĸ�ǲ���Сд.
	//			printf("%c\n", toupper(ch));      //isupper��һ���⺯������һ��Сд��ĸ�ĳɴ�д.
	//	}                                         //ͷ�ļ���Ϊ#incluide<ctype.h>.
	//	return 0;
	//}


// 46. BC50-���㵥λ��Ծ����

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


// 47. BC51-�������ж�

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