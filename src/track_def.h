#ifndef _TRACKDEF_H
#define _TRACKDEF_H
#include "bits/stdc++.h"
#include "layer_def.h"
#include "class_def.h"

class track{
public:
    track() {}
    void get_layer_name(string s){
        lay.name = s;
    }
    void get_direction(string d){
        direction = d;
    }
    void get_start_num_space(int s,int n,int sp){
        start = s;
        numtracks = n;
        space = sp;
    }
private:
    layer lay;
    string direction;
    int start,numtracks,space;
};

#endif