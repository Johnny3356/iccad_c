#ifndef _DIEDEF_
#define _DIEDEF_
#include "bits/stdc++.h"

#include "class_def.h"

class die{
public:
    die() {}
    void setDieArea(int _x1, int _y1, int _x2, int _y2) {
      x1 = _x1;  y1 = _y1;
      x2 = _x2;  y2 = _y2;
    }
    void set_num_nodes(int x){
      num_nodes = x;
    }
    void set_num_nodes_terminal(int x){
      num_nodes_terminal = x;
    }
    int get_num_nodes_terminal(){
      return num_nodes_terminal;
    }
    vector<macro> get_macros(){
      return macros;
    }
    void set_pin_vector(pin p){
      pins.push_back(p);
    }
    void set_macro_vector(macro m){
      macros.push_back(m);
    }

    // --- node parser 來建立向量，不用哈希表

    // --- pl parser 用的 ---
    void addOrUpdatePinPl(const string &name, const string &ori, int x, int y) {
      auto it = pinIndex.find(name);
      if (it != pinIndex.end()) {
        // 已存在，只更新坐标
        size_t idx = it->second;
        pins[idx].set_pin_x_y(x, y);
        pins[idx].set_pin_orientation(ori);
      } 
    }
    // 对 macro 同理
    void addOrUpdateMacroPl(const std::string &name, int x, int y) {
      auto it = macroIndex.find(name);
      if (it != macroIndex.end()) {
        size_t idx = it->second;
        macros[idx].set_macro_x_y(x, y);
      } 
    }

private:
    vector<macro> macros;
    vector<row> rows;
    vector<net> nets;
    vector<pin> pins;
    vector<layer> layers;
    vector<via> vias;
    int x1,y1,x2,y2;
    int num_nodes,num_nodes_terminal;

    unordered_map<string, size_t> pinIndex;
    unordered_map<string, size_t> macroIndex;
};

#endif