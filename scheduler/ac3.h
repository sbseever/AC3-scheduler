#ifndef _AC3_H
#define _AC3_H_

#include "person.h"
#include <utility>
#include <queue>
using namespace std;

class arcObj {
 public:
  arcObj();
  bool revise(vector<person>&, person&, person&);
  bool ac3(vector<person>&);
};

#endif
