#include <stdio.h>
#include <stdlib.h>

extern int maxSubSequence_n3(const int A[], int N);
extern int maxSubSequence_n2(const int A[], int N);
extern int maxSubSequence_n1(const int A[], int N);
extern int maxSubSequence_n0(const int A[], int N);

int main()
{
	printf("hello world\n");
	int a[6] = { -2,11,-4,13,-5,-2 };

	int result =  maxSubSequence_n3(a, 6);
	printf("result: %d\n", result);

	result = maxSubSequence_n2(a, 6);
	printf("result: %d\n", result); //这里吧%d写成了%s怎么调试出来?

	result = maxSubSequence_n1(a, 6);
	printf("result: %d\n", result); 

	result = maxSubSequence_n0(a, 6);
	printf("result: %d\n", result);

	system("pause");
}