#include <stdio.h>

extern int maxSubSequence_n3(const int A[], int N);
extern int maxSubSequence_n2(const int A[], int N);

//���Ӷ�O(n3)
int maxSubSequence_n3(const int A[], int N)
{
	int thisSum, maxSum, i, j, k;
	maxSum = 0;
	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			thisSum = 0;
			for (k = i; k <= j; k++)
			{
				thisSum += A[k];
			}
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

//���Ӷ�O(n2)
int maxSubSequence_n2(const int A[], int N)
{
	int thisSum, maxSum, i, j;
	maxSum = 0;
	for (i = 0; i < N; i++)
	{
		thisSum = 0;
		for (j = i; j < N; j++)
		{
			thisSum += A[j];//����iд����j����ôͨ��vs���Գ���
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

//-------------------�ֶ���֮�ķ��� Starting----------------------------------------
//�����Ҫ�ٺúõ�����µݹ��ʹ�÷���
int maxSubSequence_n1(const int A[], int N);
int Max(int a, int b, int c);
static int maxSubSum(const int A[], int left, int right);

int Max(int a, int b, int c)
{
	if (a > b&&a > c)
		return a;
	else if (b > a&&b > c)
		return b;
	else
		return c;
}

//ָ����Χ�ļ���
static int maxSubSum(const int A[], int left, int right)
{
	int maxLeftSum, maxRightSum;
	int maxLeftBorderSum, maxRightBorderSum; //������������еĺ�
	int leftBorderSum, rightBorderSum;
	int center, i;

	if (left == right)
	{
		if (A[left] > 0)
			return A[left];
		else
			return 0;
	}

	center = (left + right) / 2;
	maxLeftSum = maxSubSum(A, left, center); //����ʹ�õݹ飬�ҳ��ֿ�֮������ֵ
	maxRightSum = maxSubSum(A, center+1, right);

	maxLeftBorderSum = 0;
	leftBorderSum = 0;
	for (i = center; i >= left; i--)
	{
		leftBorderSum += A[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}
	
	maxRightBorderSum = 0;
	rightBorderSum = 0;
	for (i = center + 1; i <= right; i++)
	{
		rightBorderSum += A[i];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}


	return Max(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

//�ݹ鷨���ֶ���֮�������Ӷ�O(NlogN)
int maxSubSequence_n1(const int A[], int N)
{
	return maxSubSum(A, 0, N - 1);
}
//-------------------�ֶ���֮�ķ��� End----------------------------------------

//��̬�滮��
//��̬�滮������׼�������ӽṹ���������ص����߽�������������
//�ҳ�״̬ת�Ʒ������������Ĺؼ�
int maxSubSequence_n0(const int A[], int N)
{
	int thisSum, maxSum, j;
	thisSum = maxSum = 0;

	for (j = 0; j < N; j++)
	{
		thisSum += A[j];
		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	return maxSum;
}

