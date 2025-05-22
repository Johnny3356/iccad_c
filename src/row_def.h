#ifndef _ROWDEF_H
#define _ROWDEF_H
#include "bits/stdc++.h"

#include "class_def.h"

class row{
public:
    row() {}
    void get_row_site_name(string r,string s,string so){
        rowname = r;
        sitename = s;
        siteorient = so;
    }
    void get_orig_xy(int x,int y){
        origX = x;
        origY = y;
    }
    void get_num_xy(int x,int y){
        numX = x;
        numY = y;       
    }
    void get_step_xy(int x,int y){
        stepX = x;
        stepY = y;
    }
private:
    vector<site> sites;
    string rowname,sitename,siteorient;
    int origX,origY,numX,numY,stepX,stepY;
};

class site{
public:
    site() {}
private:
    string name;
};
enum ROW_DIRECTION{
    N = 0,
    FS = 1
};

#endif