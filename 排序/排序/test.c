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

//ֱ�Ӳ�������
//�ȶ�
//ʱ�临�Ӷ�ΪO(N^2)
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

//ϣ������
//��һ����Ԥ����������ӽ�����
//�ڶ�������������
//ʱ�临�Ӷ�Ϊ0(log2N * N) �� O��log3N * N)
//���ȶ�����ͬ��ֵ���ֵܷ���ͬ����
void ShellSort(int* a, int n)
{  
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2; //log2N (��2Ϊ�ף�
		//gap = gap / 3 + 1; //log3N
		//gap > 1ʱ�� Ԥ����
		//gap == 1��ֱ�Ӳ�������

		//gap�ܴ�ʱ������Ԥ�����ʱ�临�Ӷ�ΪO(N)
		//gap��Сʱ������ܽӽ�������ʱҲ���ΪO(N)
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

//������
// �ѵ��߼��ṹ��һ�� ��ȫ������
//�ѵ�����ṹ��һ�� ����
// ͨ���±��ʾ���ӽڵ��ϵ
//leftchild = parent*2+1
//rightchild = parent*2+2
//parent = (child-1)/2

//���ȶ��������ʱ�����׸ı�˳��

//���Ҫ���������еĸ��׶����ڵ��ں��ӣ������
//С��Ҫ���������еĸ��׶�С�ڵ��ں��ӣ�����С

//���µ����㷨
//ǰ������������������С��/���
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//Ĭ������
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child]) //��������<��ΪС��
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

//����ʱ�临�Ӷ�ΪN*log2N
void HeapSort(int* a, int n)
{
	//����
	//ʱ�临�Ӷ�ΪO(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
		//���¶���ʹ�����µ����㷨
	{
		AdjustDown(a, n, i);
	}
	//������ �� ��ѣ���
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

//ֱ��ѡ������
//ʱ�临�Ӷ�ΪO(N^2)
//��������
//���ȶ� 4 9 5 9 8 5 6 5
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
		//���begin��max�ص�����Ҫ����һ��
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

//ð������
//ֱ�Ӳ����������
//�ȶ�
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

//��������
//ʱ�临�Ӷ�O(N * log2N)
//����������������� O(N^2)
//���ȶ�

//����ȡ��
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

//�ڿӷ�
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
		//�ұ���С
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[pivot] = a[end];
		pivot = end;


		//����Ҵ�
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

//�ڿӷ�2 ����ָ�뷨
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

//cur prev��
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

	//С�����Ż�
	//���ĵ��ô���ռ�ܴ�����Լ70~80%����
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

//�ݹ��ȱ�㣺1��ջ֡���̫�ջ�ռ䲻���ã����ܻ����
// �ݹ�ķǵݹ飺1��ֱ�Ӹ�ѭ�� 2���������ݽṹջ��ģ��ݹ����
//���� �ǵݹ�
void QuickSortNonR(int* a, int n)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, n - 1);//��ѹ��
	StackPush(&st, 0);//��ѹ��

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st); //��ȡ��
		StackPop(&st);

		int right = StackTop(&st);//��ȡ��
		StackPop(&st);

		int keyIndex = PartSort1(a, left, right);
		//[left, keyIndex-1] keyIndex [keyIndex+1, right]

		if (right > keyIndex + 1)
			//�Ȱ�������ѹ��ȥ
		{
			StackPush(&st, right);//��ѹ�ң���ȡ
			StackPush(&st, keyIndex + 1);//��ѹ����ȡ
		}
		if (left < keyIndex-1)
			//��ѹ�����䣬Ϊ����ȡ��������
			//ֱ��left >= keyIndex-1�� �൱��ֻʣ��һ��Ԫ�أ���Ϊ����������ѹ
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

//�鲢����
//ǰ�᣺�������������� 
//�ȷֽ��ٺϲ� 
//�ȶ�

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	//������������[left,mid] [mid+1,right]���򣬾Ϳ��Թ鲢
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//�鲢
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

	//������ȥ
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

//�鲢 �ǵݹ�
//ʱ�临�Ӷ�O(N* log2N)
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//�鲢
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i+gap-1;
			int begin2 = i+gap, end2 = i+2*gap-1;

			//�鲢�������Ұ�������ܾͲ�����
			if (begin2 >= n)
				break;

			//�鲢�������Ұ���������ˣ��������������޵���������
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

			//������ȥ
			//�鲢���� ��������
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

//��������
//�ǱȽ�����
//ʱ�临�Ӷ�O(N+range)
//�ռ临�Ӷ�O��range)
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