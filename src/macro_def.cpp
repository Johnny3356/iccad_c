#include "macro_def.h"

void macro::set_macro_orientation(string s){
    if(s == "N") direction = DIRECTION::N;
    else if(s == "S") direction = DIRECTION::S;
    else if(s == "E") direction = DIRECTION::E;
    else if(s == "W") direction = DIRECTION::W;
    else if(s == "FN") direction = DIRECTION::FN;
    else if(s == "FS") direction = DIRECTION::FS;
    else if(s == "FE") direction = DIRECTION::FE;
    else if(s == "FW") direction = DIRECTION::FW;
}
string macro::get_macro_orientation(){
    if(direction = DIRECTION::N) return "N";
    else if(direction = DIRECTION::S) return "S";
    else if(direction = DIRECTION::E) return "E";
    else if(direction = DIRECTION::W) return "W";
    else if(direction = DIRECTION::FN) return "FN";
    else if(direction = DIRECTION::FS) return "FS";
    else if(direction = DIRECTION::FE) return "FE";
    else if(direction = DIRECTION::FW) return "FW";
}

pin* macro::Find_Pin(const string &pin_name) {
    auto it = pin_map.find(pin_name);
    if (it != pin_map.end()) {
        return &it->second; // 返回找到的pin
    }
    return nullptr; // 如果找不到，返回nullptr
}