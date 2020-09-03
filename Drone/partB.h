// Project Identifier: 1761414855B69983BD8035097EFBD312EB0527F0

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include "Node.h"
#include "distance.h"
#include "partA.h"

using namespace std;

#ifndef PROJECT4_PARTB_H
#define PROJECT4_PARTB_H

double nearest_neighbor(vector<Node> &nodes,vector<size_t> &path);
void printFASTTSP(vector<Node> &nodes);


#endif //PROJECT4_PARTB_H
