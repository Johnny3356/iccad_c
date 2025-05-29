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
    void set_macro_type(string s){
        macro_type = s;
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

    pin* Find_Pin(const string &pin_name) {
        auto it = pin_map.find(pin_name);
        if (it != pin_map.end()) {
            return &it->second; // 返回找到的pin
        }
        return nullptr; // 如果找不到，返回nullptr
    }

    bool is_terminal = false; // 是否為terminal
private:
    string name;
    string macro_type; // macro type
    DIRECTION direction;
    int weight,height,x,y; 

    unordered_map<string, pin> pin_map;     // pin name to pin mapping
};

#endif