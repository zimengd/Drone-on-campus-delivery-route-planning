// Project Identifier: 1761414855B69983BD8035097EFBD312EB0527F0

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include "Node.h"
#include "distance.h"
#include "partA.h"
#include "partB.h"

#ifndef PROJECT4_PARTC_H
#define PROJECT4_PARTC_H

class OPTTSP {
public:

    size_t num;//num of nodes
    vector<Node> nodes;
    vector<size_t> unvisit;
    vector<size_t> path; // temp path = FASTTSP result
    vector<size_t> bestPath;
    double currBest;
    vector<vector <double>> matrix; //store distance matrix

    OPTTSP(vector<Node> &inNodes);

    void genPerms(size_t permLength);

    bool promising(size_t permLength);

    double primMatrix(); // calculate using Matrix on unvisited

    void printOPTTSP();
};

#endif //PROJECT4_PARTC_H
