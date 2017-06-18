#include <stdio.h>

extern int maxSubSequence_n3(const int A[], int N);
extern int maxSubSequence_n2(const int A[], int N);

//复杂度O(n3)
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

//复杂度O(n2)
int maxSubSequence_n2(const int A[], int N)
{
	int thisSum, maxSum, i, j;
	maxSum = 0;
	for (i = 0; i < N; i++)
	{
		thisSum = 0;
		for (j = i; j < N; j++)
		{
			thisSum += A[j];//这里i写成了j，怎么通过vs调试出来
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

//-------------------分而治之的方法 Starting----------------------------------------
//这个需要再好好的理解下递归的使用方法
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

//指定范围的计算
static int maxSubSum(const int A[], int left, int right)
{
	int maxLeftSum, maxRightSum;
	int maxLeftBorderSum, maxRightBorderSum; //左、右最大子序列的和
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
	maxLeftSum = maxSubSum(A, left, center); //这里使用递归，找出分开之后的最大值
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

//递归法（分而治之），复杂度O(NlogN)
int maxSubSequence_n1(const int A[], int N)
{
	return maxSubSum(A, 0, N - 1);
}
//-------------------分而治之的方法 End----------------------------------------

//动态规划法
//动态规划方法的准则：最优子结构，子问题重叠，边界和子问题独立。
//找出状态转移方程是求解问题的关键
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

