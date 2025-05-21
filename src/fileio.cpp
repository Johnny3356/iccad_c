#include "fileio.h"

extern string input_file, output_file;
extern die DIE;

void parser(){
    def_file_in();
    nets_file_in();
    nodes_file_in();
    pl_file_in();
    scl_file_in();
    v_file_in();
}

void def_file_in(){
    ifstream ifile;
    ifile.open(input_file);

    if (!ifile.is_open()){
        cout << "Error opening file: " << input_file << endl;
        exit(1);
    }
    
    string word = "",word2,word3,word4;
    int x1,y1,x2,y2,width;

    while (word!="DIEAREA"){   // file in DIEAREA
        ifile>>word; 
    }

    ifile.close();
}

void nets_file_in(){
    ifstream ifile;
    ifile.open(input_file);

    if (!ifile.is_open()){
        cout << "Error opening file: " << input_file << endl;
        exit(1);
    }
    
    string word = "",word2,word3,word4;
    int x1,y1,x2,y2,width;

    while (word!="NETS"){   // file in NETS
        ifile>>word; 
    }

    ifile.close();
}