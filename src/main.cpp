/*
NTUST EE B11107047 Bi-Huei,Peng 
NTUST EE B11130024 Yao-An,Lo
*/
#include "class_def.h"
#include "fileio.h"
#include <chrono>

#define ARGC_NUMS 5
#define DEBUG 1 // 1: open debug mode

die bigdie;

int main(int argc, char** argv) {
    auto start = chrono::high_resolution_clock::now();      // get the start time
    if(argc != ARGC_NUMS){
        cout<<"Something goes wrong!"<<endl;
        if(DEBUG) system("pause");
        exit(1);
    }

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
