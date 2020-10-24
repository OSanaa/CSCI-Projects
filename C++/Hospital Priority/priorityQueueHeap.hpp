//	
//	priorityQueueHeap.hpp
//	Final Project
//	CSCI 2700
//

#ifndef priorityQueueHeap_H
#define priorityQueueHeap_H

#include <string>

struct patient{
	string name;
	int priority;
	int treatment;
    patient(){};
	patient(string pName, int pPriority, int pTreatment)
    {
        name = pName;
        priority = pPriority;
        treatment = pTreatment;
    }

};

class MinHeap
{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push(patient k);
        patient pop();
        // void printHeap();
    private:
        patient *heap; // pointer to array of elements in heap
        int capacity; // maximum possible size of min heap
        int currentSize; // Current number of elements in min heap      
        void MinHeapify(int index);
        // int parent(int i) { return (i-1)/2; }
        // int left(int i) { return (2*i+1); }
        // int right(int i) { return (2*i + 2); }
        void swap(int x, int y);
        bool compare(int z, int k);
};

#endif