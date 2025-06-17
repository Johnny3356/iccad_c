#ifndef _COMPONENTDEF_
#define _COMPONENTDEF_

#include "net_def.h"
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
    int get_macro_x(){
        return x;
    }
    int get_macro_y(){
        return y;
    }
    void set_macro_name(string s){
        name = s;
    }
    string get_macro_name(){
        return name;
    }
    void set_macro_type(string s){
        macro_type = s;
    }
    void set_macro_orientation(string s);
    string get_macro_orientation();

    // nets parser用
    void ADD_Pin_NETS(const string &pin_name,const pin p) {
        pin_map.emplace(pin_name, p);
    }

    pin* Find_Pin(const string &pin_name);

    bool is_terminal = false; // 是否為terminal
private:
    string name;
    string macro_type; // macro type
    DIRECTION direction;
    int weight,height,x,y; 

    unordered_map<string, pin> pin_map;     // pin name to pin mapping
};

#endif