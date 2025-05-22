#ifndef _NETDEF_H
#define _NETDEF_H
#include "bits/stdc++.h"
#include "layer_def.h"
#include "class_def.h"

class net{
public:
    net() {}
private:
};

enum NODE_TYPE{
    node,
    IO
    
};
enum PIN_LOCATION{
    node,
    
};

class pin{
public:
    pin() {}
    void set_weight_height_zero(int x1,int x2){
        weight = x1;
        height = x2;
    }
    void set_pin_x_y(int x1,int y1){
        x = x1;
        y = y1;
    }
    void set_pin_name(string s){
        name = s;
    }
    void set_pin_orientation(string s){
        orientation = s;
    }
private:
    NODE_TYPE type;
    int weight,height,x,y;
    string name,orientation;
    layer layerr;
};

#endif