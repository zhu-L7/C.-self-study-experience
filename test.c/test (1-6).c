// 1. BC1-实践出真知

	//#define _CRT_SECURE_NO_WARNINGS 1
	//#include<stdio.h>
	//int main()
	//{
	//	printf("Practice makes perfect!");
	//	return 0;
	//}


// 2. BC2-我是大V

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


// 3. BC3-有容乃大

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


// 4. BC7-缩短2进制

	//#include<stdio.h>
	//int main()
	//{
	//	printf("%#o %#X %#x", 1234, 1234, 1234);        // #表示加前导(自动加前导)
	//	printf("\n");
	//	printf("0%o 0X%X 0x%x", 1234, 1234, 1234);      // 这里的0 0X 0x表示前导(手动加前导)
	//	return 0;
	//}                                                   // %o表示打印8进制数，%x表示打印16进制数(其中x大小写表示打
	//													// 印大小写16进制数)


// 5. BC19-反向输出4位数

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


// 6. BC28-大小写转换

	//#define _CRT_SECURE_NO_WARNINGS 
	//#include<stdio.h>
	//int main()
	//{
	//	int ch = 0;                      //getchar读取的是ASCII码值，为整形
	//	while ((ch=getchar())!=EOF)      //输入ctrl+z表示输入一个EOF，EOF(end of file)是文件结束的标志
	//	{
	//		//putchar(ch + 32);
	//		//printf("\n");
	//		printf("%c\n", (ch+ 32));    //大小写字母的ASCII码值相差32
	//		getchar();                   //读取多余的\n(回车)
	//	}
	//	return 0;
	//}
