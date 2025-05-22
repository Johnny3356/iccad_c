#ifndef _FILEIO_H_
#define _FILEIO_H_
#include "bits/stdc++.h"

#include "class_def.h"
#include "die_def.h"
#include "row_def.h"
#include "track_def.h"
#include "gcellgrid_def.h"
#include "layer_def.h"
#include "net_def.h"

void parser();
void def_file_in(die &bdie);
void nets_file_in();
void nodes_file_in();
void pl_file_in();
void scl_file_in();
void v_file_in();

#endif