// 1. BC1-ʵ������֪

	//#define _CRT_SECURE_NO_WARNINGS 1
	//#include<stdio.h>
	//int main()
	//{
	//	printf("Practice makes perfect!");
	//	return 0;
	//}


// 2. BC2-���Ǵ�V

	//#include<stdio.h>
	//int main()
	//{
	//	printf("v   v\n v v\n  v\n");
	//	return 0;
	//}

	//#include<stdio.h>
	//int main()
	//{
	//	printf("v   v\n");
	//	printf(" v v\n");
	//	printf("  v\n");
	//	return 0;
	//}


// 3. BC3-�����˴�

	//#include<stdio.h>
	//int main()
	//{
	//	printf("The size of int is %d bytes.\n", sizeof(int));
	//	printf("The size of char is %d bytes.\n", sizeof(char));
	//	printf("The size of short is %d bytes.\n", sizeof(short));
	//	printf("The size of long is %d bytes.\n", sizeof(long));
	//	printf("The size of long long is %d bytes.\n", sizeof(long long));
	//	printf("The size of float is %d bytes.\n", sizeof(float));
	//	printf("The size of double is %d bytes.\n", sizeof(double));
	//	printf("The size of unsigned int is %d bytes.\n", sizeof(unsigned int));
	//	printf("The size of unsigned char is %d bytes.\n", sizeof(unsigned char));
	//	printf("The size of unsigned long is %d bytes.\n", sizeof(unsigned long));
	//
	//	return 0;
	//}


// 4. BC7-����2����

	//#include<stdio.h>
	//int main()
	//{
	//	printf("%#o %#X %#x", 1234, 1234, 1234);        // #��ʾ��ǰ��(�Զ���ǰ��)
	//	printf("\n");
	//	printf("0%o 0X%X 0x%x", 1234, 1234, 1234);      // �����0 0X 0x��ʾǰ��(�ֶ���ǰ��)
	//	return 0;
	//}                                                   // %o��ʾ��ӡ8��������%x��ʾ��ӡ16������(����x��Сд��ʾ��
	//													// ӡ��Сд16������)


// 5. BC19-�������4λ��

	//#include<stdio.h>
	//int main()
	//{
	//	int n = 0;
	//	scanf_s("%d", &n);
	//	if (1000 <= n <= 9999)
	//	{
	//		while (n % 10)
	//		{
	//			printf("%d", n % 10);
	//			n /= 10;
	//		}
	//	}
	//	return 0;
	//}


// 6. BC28-��Сдת��

	//#define _CRT_SECURE_NO_WARNINGS 
	//#include<stdio.h>
	//int main()
	//{
	//	int ch = 0;                      //getchar��ȡ����ASCII��ֵ��Ϊ����
	//	while ((ch=getchar())!=EOF)      //����ctrl+z��ʾ����һ��EOF��EOF(end of file)���ļ������ı�־
	//	{
	//		//putchar(ch + 32);
	//		//printf("\n");
	//		printf("%c\n", (ch+ 32));    //��Сд��ĸ��ASCII��ֵ���32
	//		getchar();                   //��ȡ�����\n(�س�)
	//	}
	//	return 0;
	//}
