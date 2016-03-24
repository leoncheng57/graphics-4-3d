#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main( int argc, char** argv ) {

  screen s;
  struct matrix *edges;
  struct matrix *transform;

  color c;
  c.red = 255;
  c.green = 255;
  c.blue = 255;
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );


  free_matrix( transform );
  free_matrix( edges );
}
