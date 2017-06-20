#include<stdio.h>
#include<stdlib.h>

typedef int elementType;

typedef struct Node
{
	elementType Data;
	struct Node* next;
}List;

//���
int length(List* ptrL)
{
	List* p = ptrL;
	int j = 0;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j;
}

//λ�ò���
List* findKth(int k, List* ptrL)
{
	List* p = ptrL;
	int i = 1;
	while (p != NULL && i < k)
	{
		p = p->next;
		i++;
	}
	//�˳�ѭ������鿴�ƻ��������ж�
	if (i == k)
		return p;
	else
		return NULL;
}

//��ֵ����
List* find(elementType x, List* ptrL)
{
	List* p = ptrL;
	while (p != NULL && p->Data != x)
	{
		p = p->next;
	}
	return p;
}

//����
List* insert(elementType x, int i, List* ptrL)
{
	List* p, * s;
	if (i == 1) //�½ڵ�����ڱ�ͷ��Ҫ��������
	{
		s = (List*)malloc(sizeof(List));
		s->Data = x;
		s->next = ptrL;
		return s;
	}

	p = findKth(i - 1, ptrL);
	if (p == NULL)
	{
		printf("invalid param\n");
		return NULL;
	}
	else
	{
		s = (List*)malloc(sizeof(List));
		s->Data = x;
		s->next = p->next;
		p->next = s;
		return ptrL;
	}
}

//ɾ������Ҫע��free�ռ�
List* del(int i, List* ptrL)
{
	List* p, *s;
	if (i == 1) //ɾ��ͷ�ڵ�����
	{
		s = ptrL;
		if (ptrL != NULL)
			ptrL = ptrL->next;
		else
			return NULL;
		free(s);
		return ptrL;
	}

	p = findKth(i - 1, ptrL);
	if (p == NULL)
	{
		printf("Node %d not exit\n", i - 1);
		return NULL;
	}
	else if (p->next == NULL)
	{
		printf("Node %d not exit\n", i);
		return NULL;
	}
	else
	{
		s = p->next;
		p->next = s->next;
		free(s);
		return ptrL;
	}
}




