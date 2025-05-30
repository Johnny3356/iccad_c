#include "die_def.h"

int die::num_nodes = 0 ;
int die::num_nodes_terminal = 0;
int die::num_rows = 0;
int die::num_nets = 0;

// --- node parser 來建立向量，同時建立哈希表
void die::Add_Macro_map_Pl(const string &name, int x) {
    macroIndex.emplace(name,x);
}

// --- pl parser 用的 ---
void die::Update_Macro_mapPl(const string &name,const string &ori, int x, int y) {
    auto it = macroIndex.find(name);
    if (it != macroIndex.end()) {
        size_t idx = it->second;
        macros[idx].set_macro_x_y(x, y);
        macros[idx].set_macro_orientation(ori);
    } 
}

macro* die::Find_Macro(const string &name) {
    auto it = macroIndex.find(name);
    if (it != macroIndex.end()) {
        size_t idx = it->second;
        return &macros[idx]; 
    } 
    else return nullptr; // 如果找不到，返回nullptr
}

pin* die::Find_Pin(const string &macro_name, const string &pin_name) {
    macro* m = Find_Macro(macro_name);
    if (m) {
        return m->Find_Pin(pin_name);
    }
    return nullptr;
}