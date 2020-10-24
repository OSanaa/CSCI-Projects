//	
//	priorityQueueLL.cpp
//	Final Project
//	CSCI 2700
//

#include <iostream>

using namespace std;

#include "priorityQueueLL.hpp"

priorityQueueLL::priorityQueueLL(){
	patient *newPatientLL = new patient;
	head = NULL;
	tail = NULL;
	size = 0;
}

priorityQueueLL::~priorityQueueLL(){
	dequeuePatient();
	delete head;
	delete tail;
	size = 0;

}

void priorityQueueLL::enqueuePatient(string nameV, int priorityV, int treatmentV ){
	head = NULL;
	//patientLL* newPatientLL = new patientLL;

	//patientLL p; 
	if(head == NULL)
	{
		//head = new patientLL(nameV[i], priorityV[i], treatmentV[i]);
		head = new patient;
		head->name = nameV;
		head->priority = priorityV;
		head->treatment = treatmentV;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		//cout << head->name << " " ;
	}
	else 
	{
		sortLL(head);
		//patientLL *add = new patientLL;
		//swapLL(head);
		//cout << " Sadgas fa";
		// add = new patientLL;
		// head = add;
		// cout << i << ".";
		//patientLL *temp = new patientLL;
		// temp = new patientLL(nameV[i], priorityV[i], treatmentV[i]);
		// temp->name = nameV[i];
		// temp->priority = priorityV[i];
		// temp->treatment = treatmentV[i];
		// temp->prev = tail;
		// temp->next = NULL;
		// tail->next = temp;
		// tail = temp;
		// swapLL(temp);
	}
	size++;
}

void priorityQueueLL::sortLL(patient* tmp)
{
	patient *sorter = head;
	bool sorted = false;
	while(!sorted)
	{
		if(sorter != NULL)
		{
			if((sorter->priority) == (tmp->priority))
			{
				if((tmp->treatment) < (sorter->treatment))
				{
					if(sorter->prev == NULL)
					{
						tmp->next = head;
						head->prev = tmp;
						head = tmp;
					}
					else
					{
						tmp->prev = sorter->prev;
						tmp->next = sorter;

						sorter->prev->next = tmp;
						sorter->prev = tmp;
					}
					sorted = true;
				}
			}
		else if((tmp->priority) < (sorter->priority))
		{
			if(sorter->prev == NULL)
			{
				tmp->next = head;
				head->prev = tmp;
				head = tmp;
			}
			else
			{
				tmp->prev = sorter->prev;
				tmp->next = sorter;

				sorter->prev->next = tmp;
				sorter->prev = tmp;
				}
				sorted = true;
			}
			sorter = sorter->next;
		}
		else
		{
			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
			sorted = true;
		}
	}
}

void priorityQueueLL::dequeuePatient()
{
	patient* tmp = head;

	if(size == 1)
	{
		delete tmp;
		head = NULL;
		size--;
	}
	else
	{
		head->next->prev = NULL;
		head = head->next;
		delete tmp;
		size--;
	}
}

void priorityQueueLL::dequeueAllPatient()
{
	if(size == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		while(size>0)
		{
			dequeuePatient();
			if(size==0)
			{
				break;
			}
		}
	}
}

void priorityQueueLL::printLL(){
	patient* tmp = head;
	int num = 1;
	while (tmp !=NULL)
	{
		cout << tmp->name << " " << tmp->priority << " " << tmp->treatment << endl;
		tmp = tmp->next;
		num++;
	}
	
}
