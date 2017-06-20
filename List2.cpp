#include<stdio.h>
#include<stdlib.h>

typedef int elementType;

typedef struct Node
{
	elementType Data;
	struct Node* next;
}List;

//求表长
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

//位置查找
List* findKth(int k, List* ptrL)
{
	List* p = ptrL;
	int i = 1;
	while (p != NULL && i < k)
	{
		p = p->next;
		i++;
	}
	//退出循环建议查看破坏条件在判断
	if (i == k)
		return p;
	else
		return NULL;
}

//按值查找
List* find(elementType x, List* ptrL)
{
	List* p = ptrL;
	while (p != NULL && p->Data != x)
	{
		p = p->next;
	}
	return p;
}

//插入
List* insert(elementType x, int i, List* ptrL)
{
	List* p, * s;
	if (i == 1) //新节点插入在表头需要单独处理
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

//删除，需要注意free空间
List* del(int i, List* ptrL)
{
	List* p, *s;
	if (i == 1) //删除头节点的情况
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




