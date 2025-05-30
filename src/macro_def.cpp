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

pin* macro::Find_Pin(const string &pin_name) {
    auto it = pin_map.find(pin_name);
    if (it != pin_map.end()) {
        return &it->second; // 返回找到的pin
    }
    return nullptr; // 如果找不到，返回nullptr
}