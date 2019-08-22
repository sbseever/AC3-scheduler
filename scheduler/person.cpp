#include "person.h"

person::person() {
  officeNo = 0;
  name = "Default";
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    for(int j = 9; j < 17; j++) {
      free[i].push_back(j);
    }
  }
}

person::person(string newName) {
  officeNo = 0;
  name = newName;
  for (int i = 0; i < NUM_OF_DAYS; i++)
  {
    for(int j = 9; j < 17; j++) {
      free[i].push_back(j);
    }
  }
}

person::person(string newName, int newOffice) {
  officeNo = newOffice;
  name = newName;
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    for(int j = 9; j < 17; j++) {
      free[i].push_back(j);
    }
  }
}

person::person(vector<meeting>* newSchedule, int office, string newName) {
    officeNo = office;
    name = newName;
    for(int i = 0; i < NUM_OF_DAYS; i++) {
        schedule[i] = newSchedule[i];
    }
}

void person::getSchedule(vector<meeting>* refSchedule) {
    for(int i = 0; i < NUM_OF_DAYS; i++) {
        refSchedule[i] = schedule[i];
    }
}

void person::getSchedule(vector<meeting>* refSchedule, int day) {
  refSchedule[day] = schedule[day];
}

void person::getFree(vector<int>* refSchedule) {
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    refSchedule[i] = free[i];
  }
}

void person::reviseFree(int day, int spot) {
  free[day].erase(free[day].begin()+spot);
}

void person::clear(int day) {
  free[day].clear();
}

void person::setSchedule(vector<meeting>* newSchedule) {
    for(int i = 0; i < NUM_OF_DAYS; i++) {
        schedule[i] = newSchedule[i];
    }
}

void person::setFree(vector<int>* newFree) {
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    free[i] = newFree[i];
  }
}

void person::setFree(vector<int> newFree, int day) {
  free[day] = newFree;
}

bool person::isEmpty() {
  bool empty = true;
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    if(!free[i].empty()) {
      empty = false;
    }
  }
  return empty;
}

void person::addMeeting(meeting newMeet) {
  cout << "Adding meeting to " << name << endl;
  schedule[newMeet.getDay()].push_back(newMeet);
  findFree(false);
}

bool person::operator==(const person& other) {
    if(this->name != other.name) return false;
    if(this-> officeNo != other.officeNo) return false;
    for(int i = 0; i < NUM_OF_DAYS; i++) {
        if(this->schedule[i].size() != other.schedule[i].size()) return false;
        for(int j = 0; j < schedule[i].size(); j++) {
            if(!(this->schedule[i][j] == other.schedule[i][j])) return false;
        }
    }
    return true;
}

void person::findFree(bool hourBetween) {
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    if(schedule[i].size() == 3 && free[i].size() > 0) { free[i].clear(); }
    else {
      for(int j = 0; j < schedule[i].size(); j++) {
	for(int k = 0; k < free[i].size(); k++) {
	  if(free[i][k] >= schedule[i][j].getStart() - (int)hourBetween
	     &&free[i][k] <= schedule[i][j].getEnd() + (int)hourBetween) 
	    { 
	      free[i].erase(free[i].begin() + k); k--; 
	    }
	}
      }
    }
  }
}

void person::printFree() {
  cout << name << ":\n";
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    cout << i+1 << ": ";
    for(int j = 0; j < free[i].size(); j++) {
     if(free[i][j] > 12) cout << free[i][j]-12 << " ";
     else cout << free[i][j] << " ";
    }
    cout << endl;
  }
}
