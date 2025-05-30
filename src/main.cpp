/*
NTUST EE B11107047 Bi-Huei,Peng 
NTUST EE B11130024 Yao-An,Lo
*/
#include "class_def.h"
#include "die_def.h"
#include "fileio.h"
#include <chrono>

#define ARGC_NUMS 6
#define DEBUG 1 // 1: open debug mode

die bigdie;

string nodes_file,pl_file,nets_file,scl_file,v_file;

int main(int argc, char** argv) {
    auto start = chrono::high_resolution_clock::now();      // get the start time
    if(argc != ARGC_NUMS){
        cout<<"Something goes wrong!"<<endl;
        if(DEBUG) system("pause");
        exit(1);
    }
    nodes_file = argv[1];
    pl_file = argv[2];
    nets_file = argv[3];
    scl_file = argv[4];
    v_file = argv[5];

    parser();


    // output the program running time
    if(DEBUG) {
        auto end = chrono::high_resolution_clock::now();        // get the end time
        auto duration = chrono::duration_cast<chrono::seconds>(end - start);    // calculate the running time
        cout << "Running time: " << duration.count() << " seconds" << endl;     // output the running time
        system("pause");
    }

    return 0;

}
