//	Name: 
//	Program: Final Project
//	CSCI 2700
//	FinalProject.cpp
//

#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// #include "priorityQueueHeap.cpp"
#include "priorityQueueLL.cpp"
// #include "priorityQueueSTL.cpp"


using namespace std;

int main(int argc, char* argv[1])
{
	ifstream myFile;
	myFile.open(argv[1]);
	
	int pConvert = 0;
	int treatmentConvert;
	string line;
	string exclude = "";
	int size = 880;
	patient arrP[size];
	int index = 0;
	// priorityQueueLL p; // Remove comments when using Linked List
	// MinHeap h; // Remove comments when using minheap
	int i = 0;
	getline(myFile, line, '\r');

	//priority_queue<patient, vector<patient>, compare > pq; // When using STL Priority queue remove comment

	while ( i != size)
	{
		getline(myFile, line, '\r');


		string priorityP;
		string treatmentP;
		string nameP;
		int pC;
		int tC;
		stringstream ss(line);
		getline(ss, nameP, ',');
		getline(ss, priorityP, ',');
		getline(ss, treatmentP, '\r');
		pC = stoi(priorityP);
		tC = stoi(treatmentP);
		
		patient currPatient(nameP, pC, tC);
		arrP[i] = currPatient;
		i++;
		
	}
	myFile.close();
	int x = 0;

	// STL Priority Queue

	/*
	while(x != 3){
		cout << "======Main Menu======" << endl;
		cout << "1. Build STL priority queue." << endl;
		cout << "2. Print STL and dequeue priority queue." << endl;
		cout << "3. Quit" << endl;
		cin >> x;

		if(x == 1)
		{
			for(int i = 0; i<880; i++)
			{
				string nameInsert = arrP[i].nameS;
				int priorityInsert = arrP[i].priorityS;
				int treatmentInsert = arrP[i].treatmentS;
				patient tempP(nameInsert, priorityInsert, treatmentInsert);
				pq.push(tempP);
			}
		}

		else if(x == 2)
		{
			int rank = 1;

			cout << "Rank Patient, Priority, Treatment" << endl;
			while (rank <= 880)
			{
				patient temp = pq.top();
				cout << rank << ". " << temp.nameS << " " << temp.priorityS << " " << temp.treatmentS << endl;
				rank ++;
				pq.pop();
			}
		}
	}
	*/

	// The implementation of Heap Priority Queue
	
	while(x != 4)
	{
		cout << "======Main Menu======" << endl;
		cout << "1. Build Heap Priority Queue." << endl;
		cout << "2. Print Heap priority Queue." << endl;
		cout << "3. Dequeue heap" << endl;
		cout << "3. Quit" << endl;
		cin >> x;
		// int z = 0;
		if(x == 1)
		{
			for(int k = 0; k<500; k++)
			{
				MinHeap patientHeap(size);
				int j = 0;
				while (j<size)
				{
					patientHeap.push(arrP[j]);
					j++;
				}
				int current = 0;
				int z = 1;
				while (current!= size)
				{
					patient p = patientHeap.pop();
					cout << z << ". " << p.name << ", " << p.priority << ", " << p.treatment << endl;
					z++;
					current++;
				}
			}
		}
	}

	/*
	while(x != 4)
	{
		cout << "======Main Menu======" << endl;
		cout << "1. Build Linked List Priority Queue." << endl;
		cout << "2. Print Linked List Priority Queue." << endl;
		cout << "3. Dequeue heap" << endl;
		cout << "3. Quit" << endl;
		cin >> x;
		// int z = 0;
		
		if(x == 1)
		{
	
			for(int k = 0; k<500; k++)
			{
				int j = 0;

				priorityQueueLL patientLL;
				
				while (j<size)
				{
					patientHeap.enqueuePatient(arrP[i].name, arrP[i].priority, arrP[i].treatment);
					j++;
				}
				patientLL.dequeueAllPatient();
			}
		}
	}
	*/
}