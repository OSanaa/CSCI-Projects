#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct patient
{
	string nameS;
	int priorityS;
	int treatmentS;
	patient(){};
	patient(string xName, int xPriority, int xTreatment)
	{
		nameS = xName;
		priorityS = xPriority;
		treatmentS = xTreatment;
	}
	vector<patient> v;
};

struct compare
{
	bool operator()(const patient&a, const patient&b)
	{
		if (a.priorityS == b.priorityS)
		{
			return a.treatmentS > b.treatmentS;
		}
		return a.priorityS > b.priorityS;
	}
};
