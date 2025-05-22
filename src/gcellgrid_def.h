#ifndef _GCELLGRIDDEF_H
#define _GCELLGRIDDEF_H
#include "bits/stdc++.h"
#include "layer_def.h"
#include "class_def.h"

class gcellgrid{
public:
    gcellgrid() {}
    void get_direction(string d){
        direction = d;
    }
    void get_start_num_space(int s,int n,int sp){
        start = s;
        num_col_row = n - 1;
        space = sp;
    }
private:
    string direction;
    int start,num_col_row,space;
};

#endif