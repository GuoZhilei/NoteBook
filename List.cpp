#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 128
typedef int elementType;

typedef struct
{
	elementType Data[MAXLEN];
	int last;
}List;

//��ʼ���յ����Ա�
List* makeEmpty()
{
	List *ptrl;
	ptrl = (List*)malloc(sizeof(List));
	ptrl->last = -1;
	return ptrl;
}

//�ҵ�ĳ�������ڵڼ���
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

//��ĳ��λ�ò���һ��Ԫ��
void insert(elementType x, int i, List* ptrL)
{
	int j;
	if (ptrL->last == MAXLEN) //��Ĵ洢�ռ��Ѿ�����
	{
		printf("List is full\n");
		return;
	}

	if (i < 1 || i > ptrL->last + 2) //�������λ���Ƿ�Ϸ�,ע���2������Ϊ�±�͸���������
	{
		printf("invalid position\n");
		return;
	}

	for (j = ptrL->last; j >= i - 1; j--)
	{
		ptrL->Data[j + 1] = ptrL->Data[j];//����������ƶ�
	}
	ptrL->Data[i - 1] = x;
	ptrL->last++;
}

//ɾ����i��λ�õ�Ԫ��
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
		ptrL->Data[j - 1] = ptrL->Data[j]; //ai+1��an��ǰ�ƶ�
	}
	ptrL->last--;
}

