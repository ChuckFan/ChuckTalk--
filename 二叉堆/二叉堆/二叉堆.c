#include <stdio.h>
#include <string.h>
//�����
typedef struct Heap
{
	int array[1000];
	int size;
}Heap;
//�ѵĳ�ʼ��

//���µ�����С��
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
		index = mindex;//ʵ�ֽ�һ������
	}
}
//����(��С��������)
void CreateHeap(int array[], int size)
{
	//С���������𲽽�С��
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
//���ϵ�������С��
//indexΪҶ�ӽ���±�,���ÿ���indexΪ����������������
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
		index = parentdex;//��Ϊ����������һ�����Ƚ�
	}
}

// ����һ������������Ȼ���ֶѵ�����
void HeapPush(Heap *heap, int v)
{
	heap->array[heap->size] = v;
	AdjustUp(heap->array, heap->size + 1, heap->size);//ע��˴����һ����������Ϊ���һ������±꣨����ֵv��
	heap->size++;
}
// ���ض�����С��һ����������ɾ������������ֶѵ�����
//��ΪС��
int HeapPop(Heap *heap)
{
	heap->array[0] = heap->array[heap->size-1];
	heap->size--;
	AdjustDown(heap->array, heap->size, 0);
	return v;
}
// ���ض�����С��һ����
//��ΪС��
int HeapTop(Heap *heap) {
	return heap->array[0];
}
void Swap(int array[], int i, int j) {
	int t = array[i];
	array[i] = array[j];
	array[j] = t;
}
//��ѡ������
// 1.�ŵ��ǽ���,������С��
// 2.�ŵ�������,�����Ǵ��
void Sort(int array[], int size)
{
	CreateHeap(array, size);
	for (int i = 0; i < size; i++)
	{
		swap(array, 0, size - 1 - i);
		AdjustDown(array, size - 1 - i, 0);//�˴����µ���Ϊ��С��
	}
}
