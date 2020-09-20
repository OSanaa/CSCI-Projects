//	
//	priorityQueueLL.hpp
//	Final Project
//	CSCI 2700
//

#ifndef priorityQueueLL_hpp
#define priorityQueueLL_hpp

#include <stdio.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std ;


struct patient
{
	std::string name;
	int priority;
	int treatment;
	patient* next = NULL;
	patient* prev = NULL;

	patient(){};
	//patientLL(std::string n, int p, int t) : name(n), priority(p), treatment(t) {};
	patient(std::string n, int p, int t, patientLL* ne, patientLL* pre)
	{
		name = n;
		priority = p;
		treatment = t;
		next = ne;
		prev = pre;


	}
	// bool operator<(const patientLL & p)const{
	// 	if( this->priority < p.priority ) return true;
	// 	else if( this->priority > p.priority ) return false;
	// 	else if( this->treatment < p.treatment ) return true;
	// 	return false;
	// }
	// bool operator>(const patientLL & p)const{
	// 	if( this->priority > p.priority ) return true;
	// 	else if( this->priority < p.priority ) return false;
	// 	else if( this->treatment > p.treatment ) return true;
	// 	return false;
	// }
};

class priorityQueueLL{
	public:
		priorityQueueLL();
		~priorityQueueLL();
		void printLL();
		void sortLL(patientLL*);
		void enqueuePatient(string, int, int);
		void dequeuePatient();
		void dequeueAllPatient();
	private:
		patientLL *head;
		patientLL *tail;
		int size;
};

#endif // priorityQueueLL_H