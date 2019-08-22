#include "room.h"
using namespace std;

room::room() {
  projector = false;
  number = 0;
  capacity = 0;
  deadline = NUM_OF_DAYS;
  score = 0;
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    for(int j = 9; j < 17; j++) {
      free[i].push_back(j);
    }
  }

}

room::room(int roomNo, int occupy, bool hasProject) {
  number = roomNo;
  capacity = occupy;
  projector = hasProject;
  deadline = NUM_OF_DAYS;
  score = 100;
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    for(int j = 9; j < 17; j++) {
      free[i].push_back(j);
    }
  }
}

void room::findFree() {
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    for(int j = 0; j < schedule[i].size(); j++) {
      for(int k = 0; k < free[i].size(); k++) {
	if(free[i][k] >= schedule[i][j].getStart()
	   &&free[i][k] <= schedule[i][j].getEnd())
	  {
	    free[i].erase(free[i].begin() + k); k--;
	  }
      }
    }
  }
}

void room::printFree() {
  cout << number << ":\n";
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    cout << i+1 << ": ";
    for(int j = 0; j < free[i].size(); j++) {
      if(free[i][j] > 12) cout << free[i][j]-12 << " ";
      else cout << free[i][j] << " ";
    }
    cout << endl;
  }
}

void room::addMeeting(meeting newMeeting) {
  cout << "Adding meeting to " << number << endl;
  schedule[newMeeting.getDay()].push_back(newMeeting);
  findFree();
}

void room::findOpen(vector<int>* freeSched, meeting consCheck) {
  int k = 0;
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    open[i] = free[i];
  }
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    if(i >= deadline) open[i].clear();
    else {
      for(int j = 0; j < open[i].size(); j++) {
	while(k < freeSched[i].size()) {
	  if(freeSched[i][k] == open[i][j]) {break;}
	  k++;
	}
	if(k >= freeSched[i].size()) { 
	  open[i].erase(open[i].begin()+j);
	  j--;
	}
	else if(consCheck.needEurope()) {
          if(open[i][j] > 9) {open[i].erase(open[i].begin()+j, open[i].end());}
        }
      }
      k = 0;
    }
    for(int l = i; l < NUM_OF_DAYS*(int)consCheck.isRecurring(); l += 7) {
      open[l] = open[i];
    }
  }
}

void room::printOpen() {
  cout << number << ":\n";
  for(int i = 0; i < NUM_OF_DAYS; i++) {
    cout << i+1 << ": ";
    for(int j = 0; j < open[i].size(); j++) {
      if(open[i][j] > 12) cout << open[i][j]-12 << " ";
      else cout << open[i][j] << " ";
    }
    cout << endl;
  }
  
}
  
bool room::isAvailable(meeting newMeeting) {
  if(projector!=newMeeting.hasProjector()) return false;
  if(isEmpty()) return false;
  if(capacity <= newMeeting.getNumberPeople()) return false;
  return true;
}

bool room::isEmpty() {
  bool empty = true;
  for(int i = 0; i < deadline; i++) {
    if(!open[i].empty()) empty = false;
  }
  return empty;
}

int room::getScore(int avgDist) {
  int j = 0;
  score = 100;
  score -= abs((long)(avgDist-number));
  while(open[j].empty()) j++;
  score += (deadline - j);
  for(int i = j; i < deadline; i++) {
    score -= open[i].size();
  }
  return score; 
}
