
using namespace std;

#ifndef _PERSON_H
#define _PERSON_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "meeting.h"

const int NUM_OF_DAYS = 30;

class person {
    private:
        vector<meeting> schedule[NUM_OF_DAYS];
        int officeNo;
        string name;
	vector<int> free[NUM_OF_DAYS];
    public:
        person();
	person(string);
	person(string, int);
        person(vector<meeting>*, int, string);
        void getSchedule(vector<meeting>*);
        void getSchedule(vector<meeting>*, int);
        int getOffice() {return officeNo;};
        string getName() {return name;};
        string setName(string);
        void setSchedule(vector<meeting>*);
	void getFree(vector<int>*);
	void setFree(vector<int>, int);
	void setFree(vector<int>*);
	void reviseFree(int, int);
	void clear(int);
        void addMeeting(meeting);
        bool isEmpty();
	void findFree(bool);
	void printFree();
	void printSchedule();
        bool operator==(const person&);
};

#endif
