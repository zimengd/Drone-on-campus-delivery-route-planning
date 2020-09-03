// Project Identifier: 1761414855B69983BD8035097EFBD312EB0527F0

#include "partB.h"

double nearest_neighbor(vector<Node> &nodes,vector<size_t> &path){
    size_t n= nodes.size();
    size_t temp = 0;
    double distance;
    double minDist;

    double sum = 0.0;
    path.reserve(n+1);

    //first three nodes
    sum = dist(nodes[0],nodes[1]) + dist(nodes[1],nodes[2])+
            dist(nodes[2],nodes[0]);

    path.push_back(0);
    path.push_back(1);
    path.push_back(2);
    path.push_back(0);

    for (size_t i = 3; i < n; ++i){
        minDist = numeric_limits<double>::infinity();
        for (size_t j = 0; j < path.size()-1; ++j){
            //insert nodes[i] into the path
            distance = dist(nodes[i], nodes[size_t(path[j])]);
            distance += dist(nodes[i],nodes[size_t(path[j+1])]) ;
            distance -= dist(nodes[size_t(path[j])],nodes[size_t(path[j+1])]);

            if (distance < minDist){
                minDist = distance;
                temp = j;
            }
        } // for
        sum += minDist;
        path.insert(path.begin() + int(temp) + 1, i);
    } // for

    //drop the last one in the path
    path.pop_back();
    return sum;
}

void printFASTTSP(vector<Node> &nodes) {
    vector<size_t> path;
    double sum = nearest_neighbor(nodes,path);
    size_t n= nodes.size();

    //output
    cout << setiosflags(ios::fixed)<<setprecision(2);
    cout <<  sum << "\n";
    //path

    for (size_t j = 1; j < n; ++j){
        cout << path[j] << " ";
    }
    cout << "\n";

}

