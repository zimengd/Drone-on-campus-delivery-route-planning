// Project Identifier: 1761414855B69983BD8035097EFBD312EB0527F0

#include "distance.h"

//calculatedistance
double dist(Node n1, Node n2){
    double d;
    double d2;
    double x2;
    double y2;
    x2 = pow(n1.x-n2.x,2.0);
    y2 = pow(n1.y-n2.y,2.0);
    d2 = x2 + y2;
    d = sqrt(d2);
    return d;
}

vector<vector <double>> calculate_distance_matrix(vector<Node> &nodes) {
    size_t n = nodes.size();
    vector<vector <double>> matrix;
    matrix.resize(n);

    for (size_t i = 0; i<n; ++i){
        matrix[i].resize(n);
        for (size_t j = 0; j<n; ++j){
            matrix[i][j]  = dist(nodes[i],nodes[j]);
        } // for col
    } // for row

    return matrix;

}

