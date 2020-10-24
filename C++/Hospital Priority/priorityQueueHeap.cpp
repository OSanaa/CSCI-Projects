//	
//	priorityQueueHeap.hpp
//	Final Project
//	CSCI 2700
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#include "priorityQueueHeap.hpp"

MinHeap::MinHeap(int cap){
	currentSize = 0;
	capacity = cap;
	heap = new patient[capacity];
}

MinHeap::~MinHeap(){
	//delete [] heap;
}

void MinHeap::MinHeapify(int i)
{
	int left = 2*i;
	int right = 2*i+1;
	int smallest = i;
	if(left <= currentSize && heap[left].priority < heap[i].priority)
	{
		smallest = left;
	}
	if (left <= currentSize && heap[left].priority == heap[i].priority)
	{
		if(heap[left].treatment < heap[i].treatment)
		{
			smallest = left;
		}
	}
	if(right <= currentSize && heap[right].priority < heap[smallest].priority)
	{
		smallest = right;
	}
	if(right <= currentSize && heap[right].priority == heap[smallest].priority)
	{
		if(heap[right].treatment < heap[smallest].treatment)
		{
			smallest = right;
		}
	}

	if(smallest!=i)
	{
		swap(i, smallest);
		MinHeapify(smallest);
	}
}

void MinHeap::swap(int root, int child)
{
	patient tmp = heap[root];
	heap[root] = heap[child];
	heap[child] = tmp;
}

patient MinHeap::pop(){
	if (currentSize == 0)
	{
		cout << "empty";
		return heap[0];
	}
	if (currentSize == 1)
	{
		currentSize --;
		return heap[1];
	}
	patient popVal = heap[1];
	heap[1] = heap[currentSize];
	currentSize--;
	MinHeapify(1);
	return popVal;
}

bool MinHeap::compare(int patient1, int patient2)
{
	patient x = heap[patient1];
	patient y = heap[patient2];
	if(x.priority != y.priority)
	{
		return x.priority > y.priority;
	}
	else
	{
		return x.treatment > y.treatment;
	}
}

void MinHeap::push(patient p)
{
	if(currentSize == capacity)
	{
		cout << "Full" << endl;
	}
	else 
	{
		currentSize++;
		int i = currentSize;
		heap[i] = p;
		while (i>1 && compare(i/2, i)) // Parent, 
		{
			swap(i, i/2);
			i = i/2;
		}
	}
}
