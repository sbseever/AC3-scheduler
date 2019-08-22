#include "ac3.h"
using namespace std; 

arcObj::arcObj() {}

bool arcObj::revise(vector<person> &attendees, person &attend1, person &attend2) {
    bool revised = false;
    vector<int> firstSchedule[NUM_OF_DAYS];
    vector<int> secondSchedule[NUM_OF_DAYS];
    attend1.getFree(firstSchedule);
    attend2.getFree(secondSchedule);
    int i, j, k;
    i = 0;
    while(!revised && i < NUM_OF_DAYS) {
      j = 0;
      while(!revised && j < firstSchedule[i].size()) {
	k = 0;
	while(!revised && k < secondSchedule[i].size()){
	  if(secondSchedule[i][k] == firstSchedule[i][j]) {break;}
	  k++;
	}
	if(k >= secondSchedule[i].size()) {
	  cout << "Deleting " << i << " " << firstSchedule[i][j] << endl;
	  attend1.reviseFree(i, j);
	  revised = true;
	}
	j++; 
      }
      i++;
    }
    return revised;
}

bool arcObj::ac3(vector<person> &attendees) {
    queue<pair<int, int> > arcs;
    pair<int, int> tempArc;
    int person1, person2;
    vector<int> tempSchedule[NUM_OF_DAYS];
    //initialize queue to hold all the arcs
    for(int i = 0; i < attendees.size(); i++) {
        for(int j = 0; j < attendees.size(); j++) {
            if(j != i) {
	      arcs.push(pair<int, int>(i, j));
            }
        }
    }
    while(!arcs.empty()) {
        tempArc = arcs.front();
        person1 = tempArc.first;
        person2 = tempArc.second;
        arcs.pop();
	cout << "Examining " << person1 << " " << person2 << endl;
        if(revise(attendees, attendees[person1], attendees[person2])) {
	  attendees[person1].printFree();
	  if(attendees[person1].isEmpty()) { return false;}
	  //add every arc excluding current one to queue
	  for(int k = 0; k < attendees.size(); k++) {
	    if(k != person1 && k != person2) {
	      cout << "Adding " << k << " " << person1 << endl; 
	      arcs.push(pair<int, int>(k, person1));
	    }
	  }
        }
    }
    for(int i = 0; i < attendees.size(); i++) {
      attendees[i].printFree();
    }
    return true;
}

