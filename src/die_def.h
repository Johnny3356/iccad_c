#ifndef _DIEDEF_
#define _DIEDEF_
#include "bits/stdc++.h"

#include "class_def.h"

class die{
public:
    die() {}
private:
    vector<component> components;
    vector<row> rows;
    vector<net> nets;
    vector<pin> pins;
    vector<layer> layers;
    vector<via> vias;
};

#endif