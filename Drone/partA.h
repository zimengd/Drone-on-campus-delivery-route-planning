// Project Identifier: 1761414855B69983BD8035097EFBD312EB0527F0

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include "distance.h"


#ifndef PROJECT4_PARTA_H
#define PROJECT4_PARTA_H

struct Vertex{
    int id;
    bool k; // whether visited
    double d; // weight: distance
    int p; // what vertex precedes
    Vertex():k(false),d
            (numeric_limits<double>::infinity()),p(-1){};
};

size_t find_smallest(vector<Vertex> &nodes);

void prim_output(vector< vector<int> > &path, double &distance);

double prim(vector<Node> &nodes, vector< vector<int> > &path);

bool isD3(Node n);

bool isD3border(Node n);

#endif //PROJECT4_PARTA_H
