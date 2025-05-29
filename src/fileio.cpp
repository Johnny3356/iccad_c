#include "fileio.h"

extern die bigdie;

ifstream ifile;
extern string node_file,pl_file,scl_file,v_file,net_file;

void parser(){
    // def_file_in(bigdie,rows,trackk,grid);
    nodes_file_in(node_file);
    pl_file_in(pl_file);
    nets_file_in(net_file);
    scl_file_in(scl_file);
    v_file_in(v_file);
}


void file_out(){

}

void nodes_file_in(string input_file){
    string word,word2,word3,word4;
    int x1,y1,x2,y2,width;
    int count = 0;
    string label;
    string temp;

    ifile.open(input_file);

    if (!ifile.is_open()){
        cout << "Error opening file: " << input_file << endl;
        exit(1);
    }

    ifile >> word >> word >> word;  // skip UCLA nodes 1.0
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
                macro mm;
                mm.is_terminal = true; // 設定為terminal
                mm.set_weight_height(x1,x2);
                mm.set_macro_name(word);
                bigdie.set_macro_vector(mm);
                bigdie.Add_Macro_map_Pl(word, count);
                count++;
            }
        }
        else{
            macro m;
            m.set_macro_name(label);
            ifile >> x1 >> x2;
            m.set_weight_height(x1,x2);
            bigdie.set_macro_vector(m);
            bigdie.Add_Macro_map_Pl(label, count);
            count++;
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

    ifile >> word >> word >> word;  // skip UCLA pl 1.0
    for(int i=0;i<bigdie.get_num_nodes_terminal();++i){
        ifile >> word >> x1 >> y1 >> temp >> word2 >> temp;
        bigdie.Update_Macro_mapPl(word,word2,x1,y1);
    }
    while (ifile >> label) {
        ifile >> word >> x1 >> y1 >> temp >> word2;
        bigdie.Update_Macro_mapPl(word,word2,x1,y1);
    }
    ifile.close();

}
void nets_file_in(string input_file){
    string IO,pin_name,name;
    int x1,y1,x2,y2,num;

    string label = "";
    string temp;

    ifile.open(input_file);

    if (!ifile.is_open()){
        cout << "Error opening file: " << input_file << endl;
        exit(1);
    }

    ifile >> temp >> temp >> temp;  // skip UCLA nets 1.0
    while (ifile >> label) {
        if(label == "NetDegree"){
            ifile >> temp >> num >> name;
            net n;
            n.set_net_name(name);
            n.set_pin_amount(num);

            for(int i=0;i<num;++i){     // all pins in this net
                ifile >> name >> IO >> temp >> x1 >> y1 >> temp >> x2 >> y2 >> pin_name;
                pin p;
                p.set_pin_name(pin_name);
                p.set_pin_type(IO);
                p.set_pin_offset(x1,y1);
                p.set_pin_x_y(x2,y2);

                if(IO == "O") n.set_output_pin_name(pin_name); // set output pin name
                
                if(pin_name.size() != 2) n.ADD_Pin_NETS(pin_name.erase(0,2));   //  terminal pin name is empty ( p_ )
                else n.ADD_Pin_NETS(NULL);

                bigdie.Find_Macro(name)->ADD_Pin_NETS(pin_name, p); // put pin into macro's pin_map
            }
            bigdie.set_nets_vector(n); // add net to die's nets vector
        }
        else if (label == "NumNets") {
            ifile >> temp >> num;
            bigdie.set_nets_size(num);
        }
        else if(label == "NumPins"){
            ifile >> temp >> num;
            // bigdie.set_pins_size(num);
        }
        
    }

    ifile.close();
}
void scl_file_in(string input_file){
    int num;
    int site_orient,site_symmetry,coordinate;

    string label = "";
    string temp;

    ifile.open(input_file);

    if (!ifile.is_open()){
        cout << "Error opening file: " << input_file << endl;
        exit(1);
    }

    ifile >> temp >> temp >> temp;  // skip UCLA scl 1.0
    ifile >> temp >> temp >> num;
    bigdie.set_rows_size(num); // set rows size
    ifile >> temp >> temp;
    while(ifile >> label){
        if(label == "Coordinate"){
            ifile >> temp >> coordinate;
        }
        else if(label == "Height"){
            ifile >> temp >> num;
            row::row_height = num; // set row height
        }
        else if(label == "Sitewidth"){
            ifile >> temp >> num;
            row::site_width = num; // set site width
        }
        else if(label == "Sitespacing"){
            ifile >> temp >> num;
            row::site_spacing = num; // set site spacing
        }
        else if(label == "Siteorient"){
            ifile >> temp >> site_orient;
        }
        else if(label == "Sitesymmetry"){
            ifile >> temp >> site_symmetry;
        }
        else if(label == "SubrowOrigin"){
            ifile >> temp >> num;
            row::sub_row_origin = num; // set sub row origin
        }
        else if(label == "NumSites"){
            ifile >> temp >> num;
            row::site_nums = num; // set site nums
        }
    }
    row r_init(site_orient, coordinate, site_symmetry);
    bigdie.set_rows_vector(r_init); // add row to die's rows vector
    for(int i=0;i < bigdie.get_num_rows() - 1 ; ++i){
        row r( (++site_orient) %= 2, coordinate += row::row_height, site_symmetry);
        bigdie.set_rows_vector(r); // add row to die's rows vector
    }

    ifile.close();
}
void v_file_in(string input_file){
    int num;
    int site_orient,site_symmetry,coordinate;

    char label = ';';
    string macro_name,type_name;

    ifile.open(input_file);

    if (!ifile.is_open()){
        cout << "Error opening file: " << input_file << endl;
        exit(1);
    }

    while(macro_name != "instantiations"){
        ifile >> macro_name; // skip until instantiations
    }

    while(1){
        if(label == ';'){
            ifile >> type_name >> macro_name;
            if(type_name == "endmodule") break; // end of module
            bigdie.Find_Macro(macro_name)->set_macro_type(type_name); // set macro type
        }
        ifile >> label; // read until ';'
    }
    
    ifile.close();
}




// void sdc_file_in(string input_file){

// }



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