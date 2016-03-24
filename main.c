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

  add_box(edges,0, 0, 0, 200, 100, 100);
  ident(transform);
  transform = make_rotX(20);
  matrix_mult(transform, edges);
  ident(transform);
  transform = make_rotY(20);
  matrix_mult(transform, edges);
  transform = make_translate(150, 200, 0);
  matrix_mult(transform, edges);
  draw_lines(edges, s, c);
  display(s);

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );


  free_matrix( transform );
  free_matrix( edges );
}
