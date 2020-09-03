// Project Identifier: 1761414855B69983BD8035097EFBD312EB0527F0

#include "partC.h"

double OPTTSP::primMatrix() {
    size_t n = unvisit.size();
    double sum = 0.0;

    vector<Vertex> vertices(n);
    vertices[0].d = 0.0;

    for (size_t i = 0; i<n; ++i){
        //step 2
        size_t v = find_smallest(vertices);
        vertices[v].k = true;

        //step3
        for (size_t j = 0; j<n; ++j){
            if (!vertices[j].k){
                double distance;

                distance = matrix[unvisit[v]][unvisit[j]];

                if (vertices[j].d > distance){
                    vertices[j].d = distance;
                    vertices[j].p = int(v); //index in unvisit
                }


            } // if
        } // for

    } // for

    // total weight
    for (size_t i = 0; i<n; ++i){
        if (vertices[i].k){
            //distance
            sum += vertices[i].d;
            // if
        } // if reach
        else{
            sum = numeric_limits<double>::infinity();
        }
    } // for

    return sum;
}

OPTTSP::OPTTSP(vector<Node> &inNodes) {
    num = inNodes.size();
    nodes.reserve(num);
    nodes = inNodes;

    //matrix
    matrix = calculate_distance_matrix(nodes);
    //FASTTSP result
    currBest = nearest_neighbor(nodes,path);
    // PATH
    path.reserve(num+1);

    unvisit.reserve(num);
}


bool OPTTSP::promising(size_t permLength) {
    size_t n = path.size();
    //visited
    double visit_length = 0.0;
    for (size_t j= 0; j < permLength-1;++j){
        visit_length += matrix[path[j]][path[j+1]];
    }


    // get unvisited
    if (!unvisit.empty()){
        unvisit.clear();
    }

    //circle
    double min_front = numeric_limits<double>::infinity();
    double min_back = numeric_limits<double>::infinity();

    for(size_t i = permLength; i < n; ++i) {
        unvisit.push_back(path[i]);
        double front = matrix[path[i]][path[0]];
        double back = matrix[path[i]][path[permLength - 1]];
        if (front < min_front){
            min_front = front;
        }
        if (back < min_back) {
            min_back  = back;
        }

    }

    double MST = primMatrix();

    double sum = visit_length + min_front + min_back + MST;

    return sum < currBest;
}

void OPTTSP::genPerms(size_t permLength) {
    size_t n = path.size();
    double lastEdge;
    double total;
    if (permLength == path.size()) {
        // Do something with the path
        total = 0;
        for (size_t j = 1; j<n; ++j){
            total += matrix[path[j-1]][path[j]];
        }
        lastEdge = matrix[path[0]][path[n-1]];
        total += lastEdge;

        if (total < currBest){
            currBest = total;
            bestPath = path;
        }


        return;
    } // if
    if (!promising(permLength))
        return;
    else{
        total = 0;
        for (size_t j = 1; j<n; ++j){
            total += matrix[path[j-1]][path[j]];
        }
        lastEdge = matrix[path[0]][path[n-1]];
        total += lastEdge;

        if (total < currBest){
            currBest = total;
            bestPath = path;
        }
        total -= lastEdge;

        for (size_t i = permLength; i < n; ++i) {
            swap(path[permLength], path[i]);
            double newLength;
            newLength = matrix[path[permLength-1]][path[i]] +
                    matrix[path[permLength+1]][path[i]] +
                    matrix[path[i-1]][path[permLength]] +
                    matrix[path[i+1]][path[permLength]] -
                    matrix[path[permLength-1]][path[permLength]] -
                    matrix[path[permLength+1]][path[permLength]] -
                    matrix[path[i-1]][path[i]] - matrix[path[i+1]][path[i]];
            total += newLength;
            genPerms(permLength + 1);
            total -= newLength;
            swap(path[permLength], path[i]);
        } // for
    }

}

void OPTTSP::printOPTTSP() {
    genPerms(1);

    cout << setiosflags(ios::fixed)<<setprecision(2);
    cout << currBest << "\n";

    for (auto k:bestPath){
        cout << k << " ";
    }

}


