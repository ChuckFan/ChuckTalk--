#include <stdio.h>
#include <string.h>
//定义堆
typedef struct Heap
{
	int array[1000];
	int size;
}Heap;
//堆的初始化

//向下调整，小堆
void AdjustDown(int array[], int size, int index)
{
	while (1)
	{
		int leftdex = index * 2 + 1;
		int rightdex = index * 2 + 2;
		if (leftdex >= size)
		{
			return;
		}
		int mindex = leftdex;
		if (rightdex < size&&array[rightdex] < array[leftdex])
		{
			mindex = rightdex;
		}
		if (array[index] < array[mindex])
		{
			return;
		}
		int t = array[mindex];
		array[mindex] = array[index];
		array[index] = t;
		index = mindex;//实现进一步调整
	}
}
//建堆(从小树到大树)
void CreateHeap(int array[], int size)
{
	//小树到大树逐步建小堆
	for (int i = size / 2 - 1; i > 0; i--)
	{
		AdjustDown(array, size, i);
	}
}
void HeapInit(Heap *heap, int *array, int size)
{
	memcpy(heap->array, array, size*sizeof(int));
	heap->size = size;
	CreateHeap(heap->array, heap->size);

}
//向上调整，建小堆
//index为叶子结点下标,不用考虑index为左子树还是右子树
void AdjustUp(int array[], int size, int index)
{
	while (index > 0)
	{
		int parentdex = (index - 1) / 2;
		if (array[parentdex] <= array[index])
		{
			return;
		}
		int t = array[index];
		array[index] = array[parentdex];
		array[parentdex] = t;
		index = parentdex;//作为新子树向上一个根比较
	}
}

// 插入一个数，并且仍然保持堆的性质
void HeapPush(Heap *heap, int v)
{
	heap->array[heap->size] = v;
	AdjustUp(heap->array, heap->size + 1, heap->size);//注意此处最后一个函数变量为最后一个结点下标（并非值v）
	heap->size++;
}
// 返回堆里最小的一个数，并且删除这个数，保持堆的性质
//此为小堆
int HeapPop(Heap *heap)
{
	heap->array[0] = heap->array[heap->size-1];
	heap->size--;
	AdjustDown(heap->array, heap->size, 0);
	return v;
}
// 返回堆里最小的一个数
//此为小堆
int HeapTop(Heap *heap) {
	return heap->array[0];
}
void Swap(int array[], int i, int j) {
	int t = array[i];
	array[i] = array[j];
	array[j] = t;
}
//堆选择排序：
// 1.排的是降序,建的是小堆
// 2.排的是升序,建的是大堆
void Sort(int array[], int size)
{
	CreateHeap(array, size);
	for (int i = 0; i < size; i++)
	{
		swap(array, 0, size - 1 - i);
		AdjustDown(array, size - 1 - i, 0);//此处向下调整为建小堆
	}
}
