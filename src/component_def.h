#ifndef _COMPONENTDEF_
#define _COMPONENTDEF_
#include "bits/stdc++.h"

#include "class_def.h"


enum CELL_DIRECTION{
    N = 0,
    FS = 1
};

class macro{
public:
    macro() {}
    void set_weight_height(int w,int h){
        weight = w;
        height = h;
    }
    void set_macro_x_y(int xx,int yy){
        x = xx;
        y = yy;
    }
    void set_macro_name(string s){
        name = s;
    }
private:
    string name;
    CELL_DIRECTION direction;
    string orientation;   
    int weight,height,x,y; 
};

#endif