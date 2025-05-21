#ifndef _COMPONENTDEF_
#define _COMPONENTDEF_
#include "bits/stdc++.h"

#include "class_def.h"

enum CELL_DIRECTION{
    N = 0,
    FS = 1
};

class component{
public:
    component() {}
private:
    string name;
    CELL_DIRECTION direction;    
};

#endif