// Project Identifier: 1761414855B69983BD8035097EFBD312EB0527F0

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <getopt.h>
#include <vector>
#include "Node.h"
#include "partA.h"
#include "partB.h"
#include "partC.h"
#include "distance.h"


using namespace std;

char getMode(int argc, char * argv[]) {
    // These are used with getopt_long()
    char mode = ' ';
    opterr = true; // Give us help with errors
    int choice;
    int option_index = 0;
    option long_options[] = {
            {"mode",  required_argument, nullptr, 'm'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, 0,           nullptr, '\0'}
    };

    while ((choice = getopt_long(argc, argv, "m:h", long_options,
                                 &option_index)) != -1) {
        switch (choice) {
            case 'h':
                // print help message
                cout << "DRONE DELIVERY \n";
                cout << "Users can choose mode: ";
                cout << "MST, FASTTSP, or OPTTSP \n";
                cout << "\n";
                exit(0);

            case 'm':
                if (!strcmp (optarg,"MST")){
                    mode = 'M';
                }
                else if (!strcmp (optarg,"FASTTSP")){
                    mode = 'F';
                }
                else if (!strcmp (optarg,"OPTTSP")){
                    mode = 'O';
                }
                else{
                    cerr << "invalid mode: " << optarg << endl;
                    exit(1);
                }
                break;

            default:
                cout << "Error: invalid option " << choice << "\n";
                break;
        }

    } // while
    return mode;
}

void readIn(vector<Node> &nodes){
    int num;
    cin >> num;
    nodes.reserve(size_t(num));

    for(int i = 0; i<num; ++i){
        int x;
        int y;
        cin >> x >> y;
        Node node(x,y,i);
        nodes.push_back(node);
    }
}


int main(int argc,char * argv[]){
    // insert code here...
    ios_base::sync_with_stdio(false);

    #ifdef __APPLE__
        freopen("/Users/apple/Documents/W20/403/Project4/P4-Samples-Mac-Unix"
                "/sample-ab.txt", "r",
                stdin);
        freopen("/Users/apple/Documents/W20/403/Project4/P4-Samples-Mac-Unix"
                "/1-ab-MST.txt", "w", stdout);
    #endif

    vector <Node> nodes;
    char mode = getMode(argc,argv);


    //read in data
    readIn(nodes);


    switch (mode){
        case('M'):{
            vector< vector<int> > path;
            double distance = prim(nodes,path);
            if (distance == numeric_limits<double>::infinity()){
                cerr << "Cannot construct MST \n";
                cerr << flush;
                exit(1);
            }
            else{
                prim_output(path,distance);
            }

            break;
        } // case M

        case('F'):{
            printFASTTSP(nodes);
            break;
        }


        case('O'):{
            OPTTSP opt(nodes);
            opt.printOPTTSP();
            break;
        }

        default:{
            cout << "invalid mode: " << mode << "\n";
            break;
        }


    }
    return 0;
}


