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
    void set_nets_size(int x) {
        nets.resize(x);
        num_nets = x;
    }
    void set_rows_size(int x) {
        rows.resize(x);
        num_rows = x;
    }
    static int get_num_nodes() { return num_nodes; }
    static void set_num_nodes(int x) { num_nodes = x; }
    static void set_num_nodes_terminal(int x) { num_nodes_terminal = x; }
    
    static int get_num_nodes_terminal() { return num_nodes_terminal; }
    static int get_num_rows() { return num_rows; }
    static int get_num_nets() { return num_nets; }
    vector<macro> get_macros() const { return macros; }
    void set_macro_vector(macro m) { macros.push_back(m); }
    void set_rows_vector(row r) { rows.push_back(r); }
    void set_layers_vector(layer l) { layers.push_back(l); }
    void set_vias_vector(via v) { vias.push_back(v); }
    void set_nets_vector(net n) { nets.push_back(n); }

  // --- node parser 來建立向量，同時建立哈希表
  void Add_Macro_map_Pl(const string &name, int x) {
    macroIndex.emplace(name,x);
  }
    
  // --- pl parser 用的 ---
  void Update_Macro_mapPl(const string &name,const string &ori, int x, int y) {
    auto it = macroIndex.find(name);
    if (it != macroIndex.end()) {
      size_t idx = it->second;
      macros[idx].set_macro_x_y(x, y);
      macros[idx].set_macro_orientation(ori);
    } 
  }

  macro* Find_Macro(const string &name) {
    auto it = macroIndex.find(name);
    if (it != macroIndex.end()) {
      size_t idx = it->second;
      return &macros[idx]; 
    } 
    else return nullptr; // 如果找不到，返回nullptr
  }

  pin* Find_Pin(const string &macro_name, const string &pin_name) {
    macro* m = Find_Macro(macro_name);
    if (m) {
      return m->Find_Pin(pin_name);
    }
    return nullptr;
  }

  static int num_nodes;
  static int num_nodes_terminal;
  static int num_rows;
  static int num_nets;

private:
  vector<macro> macros;
  vector<row> rows;
  vector<net> nets;
  vector<layer> layers;
  vector<via> vias;
  int x1,y1,x2,y2;

  unordered_map<string, size_t> macroIndex;
};

#endif