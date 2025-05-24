#ifndef _ROWDEF_H
#define _ROWDEF_H
#include "bits/stdc++.h"

#include "class_def.h"



class row{
public:
    row() {}
    void set_row_site_name(string r,string s){
        rowname = r;
        sitename = s;
    }
    void set_row_site_orient(string s){
        if(s == "N") siteorient = DIRECTION::N;
        else if(s == "S") siteorient = DIRECTION::S;
        else if(s == "E") siteorient = DIRECTION::E;
        else if(s == "W") siteorient = DIRECTION::W;
        else if(s == "FN") siteorient = DIRECTION::FN;
        else if(s == "FS") siteorient = DIRECTION::FS;
        else if(s == "FE") siteorient = DIRECTION::FE;
        else if(s == "FW") siteorient = DIRECTION::FW;
    }
    void set_orig_xy(int x,int y){
        origX = x;
        origY = y;
    }
    void set_num_xy(int x,int y){
        numX = x;
        numY = y;
    }
    void set_step_xy(int x,int y){
        stepX = x;
        stepY = y;
    }
private:
    vector<site> sites;
    DIRECTION siteorient;
    string rowname,sitename;
    int origX,origY,numX,numY,stepX,stepY;
};



class site{
public:
    site() {}
private:
    string name;
};
#endif