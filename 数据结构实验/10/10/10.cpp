#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
inline void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void bubbleSort(int *source, int size, int *ans, int swaptime, clock_t time)
{
	ans = new int[size];
	memcpy(ans, source, size * sizeof(int));
	swaptime = 0;
	clock_t startTime, endTime;
	startTime = clock();


	for (int sizeNow = size; sizeNow >= 2; sizeNow--)
		for (int idx = 0; idx < sizeNow - 1; idx++)
			if (ans[idx] > ans[idx + 1])
			{
				swap(ans[idx], ans[idx + 1]);
				swaptime++;
			}
	endTime = clock();
	time = startTime - endTime;
}
void selectSort(int *source, int size, int *ans, int swaptime, clock_t time)
{
	ans = new int[size];
	memcpy(ans, source, size * sizeof(int));
	swaptime = 0;
	clock_t startTime, endTime;
	startTime = clock();

	int minIndex;
	for (int startPos = 0; startPos < size - 1; startPos++)
	{
		minIndex = startPos;
		for (int idx = startPos + 1; idx < size; idx++)
			if (ans[idx] < ans[minIndex])
				minIndex = idx;
		if (minIndex != startPos)
		{
			swap(ans[minIndex], ans[startPos]);
			swaptime++;
		}
	}

	endTime = clock();
	time = startTime - endTime;
}
void selectSort(int *source, int size, int *ans, int swaptime, clock_t time)
{
	ans = new int[size];
	swaptime = 0;
	clock_t startTime, endTime;
	startTime = clock();

	for (int newArraySize = 0; newArraySize < size; newArraySize++)
	{
		int idxToInsert = newArraySize;
		for (; idxToInsert > 0; idxToInsert--)
		{
			if (source[newArraySize] < ans[idxToInsert - 1])
				ans[idxToInsert] = ans[idxToInsert - 1];
			else break;
		}
		ans[idxToInsert] = source[newArraySize];
	}

	endTime = clock();
	time = startTime - endTime;
}
void shellSort(int *source,int size,int *ans,int swaptime,clock_t time)
{
	ans = new int[size];
	memcpy(ans, source, size * sizeof(int));
	swaptime = 0;
	clock_t startTime, endTime;
	startTime = clock();

	for(int gap=size/2; gap>0; gap=gap/3+1)
	{

		
		if(gap==1) break;
	}
	
	endTime = clock();
	time = startTime - endTime;
}
void mergeSort(int *a,int startidx,int length)
{
	if(length<=1) return;
	mergeSort(a,startidx,length/2);
	mergeSort(a,startidx+length/2,length-length/2);

	int *ans=new int[length];
	int left=0,right=length/2,ansidx=0;
	while(left!=length/2&&right!=length)
	{
		if(a[startidx+left]<=a[startidx+right])
		{
			ans[ansidx]=a[startidx+left];
			left++;
			ansidx++;
		}
		//两个if就要判断循环条件
		if(left!=length/2&&a[startidx+left]>=a[startidx+right])
		{
			ans[ansidx]=a[startidx+right];
			right++;
			ansidx++;
		}
	}
	for(; left!=length/2; left++)
		ans[ansidx++]=a[startidx+left];
	for(; right!=length; right++)
		ans[ansidx++]=a[startidx+right];

	for(int i=0; i<length;i++)
		a[startidx+i]=ans[i];
	delete[] ans;
}
void mergeSort(int *source,int size,int *ans,int swaptime,clock_t time)
{
	ans = new int[size];
	memcpy(ans, source, size * sizeof(int));
	swaptime = 0;
	clock_t startTime, endTime;
	startTime = clock();

	mergeSort(ans,0,size);

	endTime = clock();
	time = startTime - endTime;
}

int* numProducting(int size)
{
	srand((unsigned)time(NULL));
	int *ans = new int[size];
	for (int i = 0; i < size; i++)
		ans[i] = rand();
	return ans;
}
bool arrayIsSorted(int *a, int size)
{
	for (int idx = 0; idx < size - 1; idx++)
		if (a[idx] > a[idx + 1])
			return false;
	return true;
}
bool sortIsValid(int *ans, int size, int *source)
{
	if (arrayIsSorted(ans, size) == false)
		return false;
	int idx = 0;
	while (idx < size)
	{
		int equalsize = 1;
		while (idx + equalsize < size)
		{
			if (ans[idx] == ans[idx + equalsize])
				equalsize++;
			else break;
		}
		
		int numcount = 0;
		for (int i = 0; i < size; i++)
			if (source[i] == ans[idx])
				numcount++;
		if (numcount != equalsize)
			return false;

		idx += equalsize;
	}
	return true;
}
int main()
{
    std::cout << "Hello World!\n"; 
}