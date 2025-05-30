#ifndef _DIEDEF_
#define _DIEDEF_

#include "class_def.h"
#include "macro_def.h"
#include "row_def.h"
#include "net_def.h"
#include "layer_def.h"

class die{
public:
    die() {}
    void setDieArea(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1;  y1 = _y1;
        x2 = _x2;  y2 = _y2;
    }
    void set_num_nets(int x) { num_nets = x; }
    void set_num_rows(int x) { num_rows = x; }
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
    void Add_Macro_map_Pl(const string &name, int x);
    
    // --- pl parser 用的 ---
    void Update_Macro_mapPl(const string &name,const string &ori, int x, int y);

    macro* Find_Macro(const string &name);

    pin* Find_Pin(const string &macro_name, const string &pin_name);

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