/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2007  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#include <igraph.h>
#include <stdio.h>

int main() {

  igraph_t g;
  FILE *ifile;
  
  ifile=fopen("karate.gml", "r");
  if (ifile==0) {
    return 10;
  }
  
  igraph_read_graph_gml(&g, ifile);
  fclose(ifile);

  if (igraph_is_directed(&g)) {
    printf("directed\n");
  } else {
    printf("undirected\n");
  }
    
  igraph_write_graph_edgelist(&g, stdout);
  printf("-----------------\n");
  igraph_write_graph_gml(&g, stdout, 0, "test suite");
  igraph_destroy(&g);
  
  return 0;
}
