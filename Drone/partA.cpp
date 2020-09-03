// Project Identifier: 1761414855B69983BD8035097EFBD312EB0527F0

#include "partA.h"

using namespace std;

//step 2
size_t find_smallest(vector<Vertex> &nodes){
    size_t v = 0; // index of smallest kv is false
    size_t n = nodes.size();
    double d = numeric_limits<double>::infinity();

    for (size_t i = 0; i<n; ++i){
        if (!nodes[i].k){
            if (nodes[i].d <= d){
                v = i;
                d = nodes[i].d;
            }
        } // if
    } // for

    return v;
}

// D3
bool isD3(Node n){
    return n.y < 0 && n.x < 0;
}

// D3 border
bool isD3border(Node n){
    if (n.y< 0 && n.x == 0){
        return true;
    }
    else if (n.y == 0 && n.x < 0){
        return true;
    }
    return false;
}


void prim_output(vector< vector<int> > &path, double &distance){
    // print total distance
    cout << setiosflags(ios::fixed)<<setprecision(2);
    cout <<  distance << "\n";

    // print path
    for (auto v:path){
        cout << v[0] << " " << v[1] << "\n";
    }

}


double prim(vector<Node> &nodes, vector< vector<int> > &path) {
    size_t n = nodes.size();
    path.reserve(n);

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
                //only allow to enter medical campus through border
//                distance = dist(nodes[v], nodes[j]);
                if (isD3(nodes[j]) && isD3(nodes[v])){
                    distance = dist(nodes[v], nodes[j]);
                }
                else if (isD3(nodes[j]) && !isD3border(nodes[v])){
                    distance = numeric_limits<double>::infinity();
                }
                else if (!isD3border(nodes[j]) && isD3(nodes[v])){
                    distance = numeric_limits<double>::infinity();
                }
                else{
                    distance = dist(nodes[v], nodes[j]);
                }

                if (vertices[j].d > distance){
                    vertices[j].d = distance;
                    vertices[j].p = nodes[v].id;
                }


            } // if
        } // for

    } // for

    //calculate total weight and path
    for (size_t i = 0; i<n; ++i){
        path[i].reserve(2);

        if (vertices[i].k){
            //distance
            sum += vertices[i].d;

            //path
            if (vertices[i].p >= 0){
                vector<int> pair;
                if (vertices[i].p < int(i)){
                    pair.push_back(vertices[i].p);
                    pair.push_back(int(i));
                    path.push_back(pair);
                }
                else{
                    pair.push_back(int(i));
                    pair.push_back(vertices[i].p);
                    path.push_back(pair);
                } // if else

            } // if
        } // if reach
        else{
            sum = numeric_limits<double>::infinity();
        }
    } // for

    return sum;

}



