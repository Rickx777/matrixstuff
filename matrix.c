#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

/*void main(){
  matrix *test1; matrix *test2; //declare + initiate
  test1 = new_matrix(4,5);
  test2 = new_matrix(4,4);
  
  populate(test1);  //putting stuff in matrixes
  populate(test2);
  printf("test1:\n");
  print(test1);
  printf("test2:\n");
  print(test2);

  printf("\ntest1: after identing\n"); //testing ident
  ident(test1);
  print(test1);
  
  printf("\nmultiply: test2 * test1 -> test1\n"); //testing multiply
  matrix_mult(test2,test1);
  print(test1);
  printf("\nMultiply test1 with 2:\n"); //testing multiply_matrix
  scalar_mult(2.0,test1);
  print(test1);
  }*/

matrix *new_matrix(int rows,int cols){
  double ** tmp;
  matrix *m;
  int i = 0;
  
  tmp = (double **)malloc(rows * sizeof(double*));
  while (i < rows){
    tmp[i] = (double *)malloc(cols * sizeof(double));
    i++;
  }

  m = (matrix *)malloc(sizeof(matrix));
  (*m).m = tmp;
  (*m).rows = rows;
  (*m).cols = cols;
  (*m).lastcol = 1;

  return m;
}

void free_matrix(matrix * m){
  int ctr;
  while (ctr < (*m).rows){
    free((*m).m[ctr]);
    ctr++;
  }
  free((*m).m);
  free(m);
}

void resize(matrix * m, int newcols){
  int ctr;
  while (ctr < (*m).rows){
    (*m).m[ctr] = realloc((*m).m[ctr], newcols * sizeof(double));
  }
  (*m).cols = newcols;
}

void copy(matrix * a, matrix * b){
  if ((*a).rows != (*b).rows || (*a).cols != (*b).cols) {printf("Size of two matrixes are unequal!\n"); return;}
  
  int r = 0;
  int c;

  while (r < (*a).rows){
    c = 0;
    while (c < (*a).cols){
      (*b).m[r][c] = (*a).m[r][c];
      c++;
    }
    r++;
  }
}

void print(matrix * m){
  int r = 0;
  int c;

  while (r < (*m).rows){
    c = 0;
    printf("[");
    while (c < (*m).cols){
      printf(" %f ", (*m).m[r][c]);
      c++;
    }
    printf("]\n");
    r++;
  }
  c = 0;
  printf("[");
  while (c < (*m).cols){
    printf(" %f ", 1.0);
    c++;
  }
  printf("]\n");
}

void populate(matrix * m){ //testing
  int r = 0;
  int c;

  while (r < (*m).rows){
    c = 0;
    while (c < (*m).cols){
      (*m).m[r][c] = 3.0; 
      c++;
    }
    r++;
  }
}

void ident(matrix * m){
  if ((*m).rows != (*m).cols){printf("Not a square matrix!\n"); return;}
  
  int r = 0;
  int c;
  while (r < (*m).rows){
    c = 0;
    while(c < (*m).cols){
      if (r == c){
	(*m).m[r][c] = 1.0;
      }
      else (*m).m[r][c] = 0;
      c++;
    }
    r++;
  }  
}

void scalar_mult(double x, matrix *m){
  int r = 0;
  int c;
  while (r < (*m).rows){
    c = 0;
    while(c < (*m).cols){
      (*m).m[r][c] *= x;
      c++;
    }
    r++;
  } 
}

void matrix_mult(matrix *a, matrix *b){
  matrix * c = new_matrix((*a).rows,(*b).cols);
  int m1r = 0; //Which row to place
  int m2c = 0; //Which column to place
  int parse = 0; //parse through Matrix 1 columns or Matrix 2 rows
  double tmp;
  
  while (m1r < (*a).rows){    
    m2c = 0;
    while (m2c < (*b).cols){
      tmp = 0; parse = 0;
      while(parse < (*a).cols){
	tmp += (*a).m[m1r][parse] * (*b).m[parse][m2c];
	parse++;
      }
      (*c).m[m1r][m2c] = tmp;
      m2c++;
    }
    m1r++;
  }
  free_matrix(b);
  (*b) = *c;
}
