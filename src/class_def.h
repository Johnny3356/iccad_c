#ifndef _CLASSDEF_
#define _CLASSDEF_
#include "bits/stdc++.h"

#include "component_def.h"
#include "die_def.h"
#include "row_def.h"
#include "track_def.h"
#include "gcellgrid_def.h"
#include "layer_def.h"
#include "net_def.h"

using namespace std;

enum DIRECTION{
    N = 0,
    S,
    E,
    W,
    FN,
    FS,
    FE,
    FW
};

// die_def.h
class die;

// component_def.h
class component;

// net_def.h
class net;

// net_def.h
class pin;

// row_def.h
class row;
class site;

//track_def.h
class track;
class gcellgrid;

// layer_def.h
class layer;
class via;


#endif