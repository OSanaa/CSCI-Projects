#include <iostream>

using namespace std;

#ifndef struct_H
#define struct_H

struct priority{
	int priority;
	string name;
	int treatment;
	priority* next = NULL;
	priority(){};

	bool operator()(const patient &a, const patient &b)
    {
        (this->patient)
        return a.x > b.x;
    }


};