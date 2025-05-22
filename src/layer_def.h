#ifndef _LAYERDEF_
#define _LAYERDEF_
#include "bits/stdc++.h"
#include "track_def.h"
#include "class_def.h"

class layer{
public:
    layer() {}
    void get_name(string n){
        name = n;
    }
private:
    friend class track;
    friend class via;
    string name;
    int x1,x2,y1,y2;

};

class via{
public:
    via() {}
    void get_name(string n){
        name = n;
    }
    void get_viarule_name(string n){
        viarule_name = n;
    }
    void get_layer_name(string b,string c,string t){
        top_layer.get_name(t);
        cut_layer.get_name(c);
        bottom_layer.get_name(b);
    }
    void get_size(int x,int y){
        xsize = x;
        ysize = y;
    }
    void get_cutspacing(int x,int y){
        x_cut_spacing = x;
        y_cut_spacing = y;
    }
    void get_enclosure(int x1,int y1,int x2,int y2){
        x_bottom_enclousure = x1;
        y_bottom_enclousure = y1;
        x_top_enclousure = x2;
        y_top_enclousure = y2;
    }
    void get_num_col_row(int x,int y){
        num_cut_rows = x;
        num_cut_columns = y;
    }
private:
    string name,viarule_name;
    layer top_layer,cut_layer,bottom_layer;
    int xsize,ysize;
    int x_cut_spacing,y_cut_spacing;
    int x_bottom_enclousure,y_bottom_enclousure,x_top_enclousure,y_top_enclousure;
    int num_cut_rows,num_cut_columns;

};

#endif