#ifndef _COMPONENTDEF_
#define _COMPONENTDEF_
#include "bits/stdc++.h"

#include "class_def.h"

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
    void set_macro_orientation(string s){
        if(s == "N") direction = DIRECTION::N;
        else if(s == "S") direction = DIRECTION::S;
        else if(s == "E") direction = DIRECTION::E;
        else if(s == "W") direction = DIRECTION::W;
        else if(s == "FN") direction = DIRECTION::FN;
        else if(s == "FS") direction = DIRECTION::FS;
        else if(s == "FE") direction = DIRECTION::FE;
        else if(s == "FW") direction = DIRECTION::FW;
    }
    // nets parser用
    void ADD_Pin_NETS(const string &name,const pin p) {
        pin_map.emplace(name, p);
    }


    bool is_terminal = false; // 是否為terminal
private:
    string name;
    DIRECTION direction;
    int weight,height,x,y; 

    unordered_map<string, pin> pin_map;     // pin name to pin mapping
};

#endif