#ifndef _ROWDEF_H
#define _ROWDEF_H
#include "bits/stdc++.h"

#include "class_def.h"

class site;
class row{
public:
    row() {}
    row(int s,int c,int sym) {
        set_row_site_orient(s);
        set_row_coordinate(c);
        set_row_site_symmetry(sym);
        site_vector_init();
    }
    void set_row_site_orient(int o){
        siteorient = (o == 1) ? N : FS ; // 1: N, 0: S
    }
    void set_row_site_symmetry(int s){
        site_symmetry = bool(s);
    }
    void set_row_coordinate(int c){
        coordinate = c;
    }
    void site_vector_init(){
        sites.clear();
        sites.resize(site_nums);
    }

    static int row_height;
    static int site_width;
    static int site_spacing;
    static int sub_row_origin;
    static int site_nums;

private:
    vector<site> sites;
    DIRECTION siteorient;
    bool site_symmetry = true; // 是否為對稱
    int coordinate;
};



class site{
public:
    site() {}
private:
};
#endif