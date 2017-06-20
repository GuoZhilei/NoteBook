#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 128
typedef int elementType;

typedef struct
{
	elementType Data[MAXLEN];
	int last;
}List;

//初始化空的线性表
List* makeEmpty()
{
	List *ptrl;
	ptrl = (List*)malloc(sizeof(List));
	ptrl->last = -1;
	return ptrl;
}

//找到某个变量在第几个
int find(elementType x, List* ptrL)
{
	int i = 0;
	while (i <= ptrL->last && ptrL->Data[i] != x)
		i++;
	if (i > ptrL->last)
		return -1;
	else
		return i;
}

//在某个位置插入一个元素
void insert(elementType x, int i, List* ptrL)
{
	int j;
	if (ptrL->last == MAXLEN) //表的存储空间已经满了
	{
		printf("List is full\n");
		return;
	}

	if (i < 1 || i > ptrL->last + 2) //检查插入的位置是否合法,注意加2，是因为下标和个数的区别。
	{
		printf("invalid position\n");
		return;
	}

	for (j = ptrL->last; j >= i - 1; j--)
	{
		ptrL->Data[j + 1] = ptrL->Data[j];//倒序的往后移动
	}
	ptrL->Data[i - 1] = x;
	ptrL->last++;
}

//删除第i个位置的元素
void del(int i, List* ptrL)
{
	int j;
	if (i < 1 || i>ptrL->last + 1)
	{
		printf("no %d position\n");
		return;
	}

	for (j = i; j <= ptrL->last; j++)
	{
		ptrL->Data[j - 1] = ptrL->Data[j]; //ai+1到an往前移动
	}
	ptrL->last--;
}

