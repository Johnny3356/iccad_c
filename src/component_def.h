#ifndef _COMPONENTDEF_
#define _COMPONENTDEF_
#include "bits/stdc++.h"

#include "class_def.h"
#include "net_def.h"


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
    void set_macro_orientation(string s){
        name = s;
    }
    // nets parser用
    void UpdatePinNETS(const string &name, const string &ori, int x, int y) {
      auto it = pinIndex.find(name);
      if (it != pinIndex.end()) {
        // 已存在，只更新坐标
        size_t idx = it->second;
        pins[idx].set_pin_x_y(x, y);
        pins[idx].set_pin_orientation(ori);
      } 
    }
private:
    string name;
    CELL_DIRECTION direction;
    string orientation; 
    string input_or_output;  
    int weight,height,x,y; 

    vector<pin>pins;
    unordered_map<string, size_t> pinIndex;
};

#endif