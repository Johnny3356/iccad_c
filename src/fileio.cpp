#include "fileio.h"

extern die bigdie;

ifstream ifile;

void parser(track trackk,gcellgrid &grid){
    // def_file_in(bigdie,rows,trackk,grid);
    string node_file = "",pl_file = "",scl_file = "",v_file = "",net_file = "";
    nets_file_in(net_file);
    nodes_file_in(node_file);
    pl_file_in(pl_file);
    scl_file_in(scl_file);
    v_file_in(v_file);
}

// void def_file_in(die &bigdie,vector<row>&rows,track trackk,gcellgrid &grid){
//     ifstream ifile;
//     // ifile.open(input_file);

//     if (!ifile.is_open()){
//         // cout << "Error opening file: " << input_file << endl;
//         exit(1);
//     }
    
//     string word = "",word2,word3,word4;
//     int x1,y1,x2,y2,width;

//     string label;
//     string temp;

//     while (ifile >> label) {
//         if (label == "DIEAREA") {
//             ifile >> temp >> x1 >>y1 >> temp >> temp >> x2 >> y2 >> temp;
//             bigdie.setDieArea(x1, y1, x2, y2);
//         }
//         else if(label == "TRACK"){
//             ifile >> word2 >> x1 >> temp >> x2 >> temp >> y1 >> temp >> word3;
//             trackk.get_direction(word2);
//             trackk.get_layer_name(word3);
//             trackk.get_start_num_space(x1,x2,y1);
//         }
//         else if(label == "GCELLGRID"){
//             ifile >> word2 >> x1 >> temp >> x2 >> temp >> y1;
//             grid.get_direction(word2);
//             grid.get_start_num_space(x1,x2,y1);
//         }
//         else if (label == "ROW") {
//             row r;
//             ifile >> word2 >> word3 >> x1 >> y1 >> word4;
//             r.get_row_site_name(word2,word3,word4);
//             r.get_orig_xy(x1,y1);
//             ifile >> temp >> x1 >> temp >> y1 >> temp >> x2 >> y2 >> temp;
//             r.get_num_xy(x1,y1);
//             r.get_step_xy(x2,y2);
//             rows.push_back(r);
//         }
//         else if (label == "VIAS"){
//             via v;
//             if (label == "-") {
//                 ifile >> word2;
//                 v.get_name(word2);
//             }
//             else if(label == "VIARULE"){
//                 ifile >> word2;;
//                 v.get_viarule_name(word2);
//             }
//             else if(label == "CUTSIZE"){
//                 ifile >> x1 >> y1;
//                 v.get_size(x1,y1);
//             }
//             else if(label == "LAYERS"){
//                 ifile >> word2 >> word3 >> word4;
//                 v.get_layer_name(word2,word3,word4);
//             }
//             else if(label == "CUTSPACING"){
//                 ifile >> x1 >> y1;
//                 v.get_cutspacing(x1,y1);
//             }
//             else if(label == "ENCLOSURE"){
//                 ifile >> x1 >> y1 >> x2 >> y2;
//                 v.get_enclosure(x1,y1,x2,y2);
//             }
//             else if(label == "ROWCOL"){
//                 ifile >> x1 >> y1;
//                 v.get_num_col_row(x1,y1);
//             }
//             else if(label == "RECT"){
                
//             }
//         }
      
        
//     }

//     ifile.close();
// }

void file_out(){

}
void nets_file_in(string input_file){

}
void nodes_file_in(string input_file){
    string word,word2,word3,word4;
    int x1,y1,x2,y2,width;

    string label;
    string temp;

    ifile.open(input_file);

    if (!ifile.is_open()){
        cout << "Error opening file: " << input_file << endl;
        exit(1);
    }

    while (ifile >> label) {
        if (label == "NumNodes") {
            ifile >> temp >> x1;
            bigdie.set_num_nodes(x1);
        }
        else if(label == "NumTerminals"){
            ifile >> temp >> x1;
            bigdie.set_num_nodes_terminal(x1);
            for(int i=0;i<bigdie.get_num_nodes_terminal();++i){
                ifile >> word >> x1 >> x2 >> temp;
                pin pi;
                pi.set_weight_height_zero(x1,x2);
                pi.set_pin_name(word);
                bigdie.set_pin_vector(pi);
            }
        }
        else{
            macro m;
            m.set_macro_name(label);
            ifile >> x1 >> x2;
            m.set_weight_height(x1,x2);
            bigdie.set_macro_vector(m);
        }
    }

    ifile.close();
}
void pl_file_in(string input_file){
    string word,word2,word3,word4;
    int x1,y1,x2,y2,width;

    string label;
    string temp;

    ifile.open(input_file);

    if (!ifile.is_open()){
        cout << "Error opening file: " << input_file << endl;
        exit(1);
    }

    while (ifile >> label) {
        ifile >> temp >> temp;
        for(int i=0;i<bigdie.get_num_nodes_terminal();++i){
                ifile >> word >> x1 >> y1 >> temp >> word2 >> temp;
                pin pi;
                pi.set_pin_x_y(x1,y1);
                pi.set_pin_name(word);
                bigdie.set_pin_vector(pi);
            }
        if (label == "NumNodes") {
            ifile >> temp >> x1;
            bigdie.set_num_nodes(x1);
        }
        else if(label == "NumTerminals"){
            ifile >> temp >> x1;
            bigdie.set_num_nodes_terminal(x1);
            for(int i=0;i<bigdie.get_num_nodes_terminal();++i){
                ifile >> word >> x1 >> x2 >> temp;
                pin pi;
                pi.set_weight_height_zero(x1,x2);
                pi.set_pin_name(word);
                bigdie.set_pin_vector(pi);
            }
        }
        else{
            macro m;
            m.set_macro_name(label);
            ifile >> x1 >> x2;
            m.set_weight_height(x1,x2);
            bigdie.set_macro_vector(m);
        }
    }
    ifile.close();

}
void scl_file_in(string input_file){

}
void v_file_in(string input_file){

}
