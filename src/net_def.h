#ifndef _NETDEF_H
#define _NETDEF_H
#include "bits/stdc++.h"

#include "class_def.h"
#include "layer_def.h"

class net{
public:
    net() {}
    void set_net_name(string s){
        name = s;
    }
    void set_pin_amount(int x){
        pin_amount = x;
    }
    void set_output_macro_name(string s){
        output_macro_name = s;
    }
    void ADD_Pin_NETS(const string macro_name,const string pin_name) {
        pin_map.emplace(macro_name, pin_name);
    }
private:
    string name;
    string output_macro_name;
    int pin_amount;
    unordered_map<string,string> pin_map; // macro name to pin name
};

enum PIN_TYPE{
    input,
    output
};

class pin{
public:
    pin() {}    
    void set_pin_x_y(int x1,int y1){
        x = x1;
        y = y1;
    }
    void set_pin_offset(int x_offset1, int y_offset1){
        x_offset = x_offset1;
        y_offset = y_offset1;
    }
    void set_pin_type(string s){
        if(s == "I") type = PIN_TYPE::input;
        else if(s == "O") type = PIN_TYPE::output;
    }
    void set_pin_name(string s){
        name = s;
    }
private:
    string name;
    PIN_TYPE type;
    int x,y,x_offset,y_offset;
    layer layerr;
};

#endif