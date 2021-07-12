#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void ArrayPrint(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n"); 
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//********************************************************************************************//

//直接插入排序
//稳定
//时间复杂度为O(N^2)
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort(int* a, int n)
{
	InsertSort(a, n);
	ArrayPrint(a, n);
}

//********************************************************************************************//

//希尔排序
//第一步：预排序，让数组接近有序
//第二步：插入排序
//时间复杂度为0(log2N * N) 或 O（log3N * N)
//不稳定，相同的值可能分到不同的组
void ShellSort(int* a, int n)
{  
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2; //log2N (以2为底）
		//gap = gap / 3 + 1; //log3N
		//gap > 1时是 预排序
		//gap == 1是直接插入排序

		//gap很大时，下面预排序的时间复杂度为O(N)
		//gap很小时，数组很接近有序，这时也差不多为O(N)
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void TestShellSort(int* a, int n)
{
	ShellSort(a, n);
	ArrayPrint(a, n);
}

//********************************************************************************************//

//堆排序
// 堆的逻辑结构是一棵 完全二叉树
//堆的物理结构是一个 数组
// 通过下标表示父子节点关系
//leftchild = parent*2+1
//rightchild = parent*2+2
//parent = (child-1)/2

//不稳定，排序的时候容易改变顺序

//大堆要求：树中所有的父亲都大于等于孩子，根最大
//小堆要求：树种所有的父亲都小于等于孩子，根最小

//向下调整算法
//前提条件左右子树都是小堆/大堆
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//默认左孩子
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child]) //换个符号<变为小堆
		{
			child += 1;
		}
		if (a[child] > a[parent])//<
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{ 
			break;
		}
	}
}

//整体时间复杂度为N*log2N
void HeapSort(int* a, int n)
{
	//建堆
	//时间复杂度为O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
		//自下而上使用向下调整算法
	{
		AdjustDown(a, n, i);
	}
	//排升序 建 大堆！！
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0); 
		--end;
	}
}

void TestHeapSort(int* a, int n)
{
	HeapSort(a, n);
	ArrayPrint(a, n);
}
 
//*******************************************************************************************//

//直接选择排序
//时间复杂度为O(N^2)
//最差的排序
//不稳定 4 9 5 9 8 5 6 5
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		Swap(&a[begin], &a[min]);
		//如果begin跟max重叠，需要修正一下
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[max], &a[end]);
		++begin;
		--end;
	}
}

TestSelectSort(int* a, int n)
{
	SelectSort(a, 10);
	ArrayPrint(a, 10);
}

//********************************************************************************************//

//冒泡排序
//直接插入排序更好
//稳定
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int flag = 1;
		for (int j = 1; j < n-i; ++j)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}

void TestBubbleSort(int* a, int n)
{
	BubbleSort(a, 10);
	ArrayPrint(a, 10);
}

//********************************************************************************************//

//快速排序
//时间复杂度O(N * log2N)
//在有序的情况下是最差 O(N^2)
//不稳定

//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
			return right;
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
			return right;
	}
}

//挖坑法
int PartSort1(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int end = right;
	int begin = left;
	int pivot = begin;
	int key = a[begin];
	while (begin < end)
	{
		//右边找小
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[pivot] = a[end];
		pivot = end;


		//左边找大
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[pivot] = a[begin];
		pivot = begin;

	}
	pivot = begin;
	a[pivot] = key;

	return pivot;
}

//挖坑法2 左右指针法
int PartSort2(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int end = right;
	int begin = left;
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[key])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);

	return begin;
}

//cur prev法
int PartSort3(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[right]);

	int cur = left+1;
	int prev = left;
	int key = prev;
	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[prev], &a[key]);

	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int ketIndex = PartSort3(a, left, right);

	//[left, pivot-1] pivot [pivot+1, right]
	//QuickSort(a, left, ketIndex - 1);
	//QuickSort(a, ketIndex + 1, right);

	//小区间优化
	//最后的调用次数占总次数大约70~80%以上
	if (ketIndex - 1 - left > 10)
	{
		QuickSort(a, left, ketIndex - 1);
	}
	else
	{
		InsertSort(a + left, ketIndex - 1 - left + 1);
	}

	if (ketIndex - 1 - left > 10)
	{
		QuickSort(a, ketIndex + 1, right);
	}
	else
	{
		InsertSort(a + ketIndex + 1, right - (ketIndex + 1) + 1);
	}

}

void TestQuickSort(int* a, int left, int right)
{
	QuickSort(a, left, right);
	ArrayPrint(a, 10);
}

//********************************************************************************************//

//递归的缺点：1、栈帧深度太深，栈空间不够用，可能会溢出
// 递归改非递归：1、直接改循环 2、借助数据结构栈来模拟递归过程
//快排 非递归
void QuickSortNonR(int* a, int n)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, n - 1);//先压右
	StackPush(&st, 0);//后压左

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st); //先取左
		StackPop(&st);

		int right = StackTop(&st);//后取右
		StackPop(&st);

		int keyIndex = PartSort1(a, left, right);
		//[left, keyIndex-1] keyIndex [keyIndex+1, right]

		if (right > keyIndex + 1)
			//先把右区间压进去
		{
			StackPush(&st, right);//先压右，后取
			StackPush(&st, keyIndex + 1);//后压左，先取
		}
		if (left < keyIndex-1)
			//再压左区间，为了先取出来处理
			//直到left >= keyIndex-1， 相当于只剩下一个元素，必为有序，无需再压
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}
	}
	StackDestory(&st);
}

void TestQuickSortNonR(int* a, int n)
{
	QuickSortNonR(a, n);
	ArrayPrint(a, 10);
}

//********************************************************************************************//

//归并排序
//前提：左右子区间有序 
//先分解再合并 
//稳定

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	//假设左右区间[left,mid] [mid+1,right]有序，就可以归并
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	//拷贝回去
	int i = 0;
	for (i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	_MergeSort(a, 0, n - 1, tmp); 

	free(tmp);
}

void TestMergeSort(int* a, int n)
{
	MergeSort(a, n);
	ArrayPrint(a, n);
}

//********************************************************************************************//

//归并 非递归
//时间复杂度O(N* log2N)
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//归并
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i+gap-1;
			int begin2 = i+gap, end2 = i+2*gap-1;

			//归并过程中右半区间可能就不存在
			if (begin2 >= n)
				break;

			//归并过程中右半区间算多了，修正右区间上限到数组上限
			if (end2 >= n)
				end2 = n - 1;

			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
				tmp[index++] = a[begin1++];
			while (begin2 <= end2)
				tmp[index++] = a[begin2++];

			//拷贝回去
			//归并多少 拷贝多少
			for (int j = i; j <= end2; ++j) 
			{
				a[j] = tmp[j];
			}
		}


		gap *= 2;
	}
}

void TestMergeSortNonR(int* a, int n)
{
	MergeSortNonR(a, n);
	ArrayPrint(a, n);
}


//********************************************************************************************//

//计数排序
//非比较排序
//时间复杂度O(N+range)
//空间复杂度O（range)
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i]-min]++;
	}
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;  
		}
	}
	free(count);
}

void TestCountSort(int* a, int n)
{
	CountSort(a, n);
	ArrayPrint(a, n);
}



//********************************************************************************************//

int main()
{
	int a[11] = { 5,3,8,9,7,4,1,2,6,0,10 };
	//TestInsertSort(a,10);
	//TestShellSort(a, 10);
	//TestHeapSort(a, 10);
	//TestSelectSort(a, 10);
	//TestBubbleSort(a, 10);
	//TestQuickSort(a, 0, 9);
	//TestQuickSortNonR(a, 10);
	//TestMergeSort(a, 10);
	//TestMergeSortNonR(a, 11);
	TestCountSort(a, 11);

	return 0;
}