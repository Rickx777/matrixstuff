typedef struct matrix {
  int rows, cols;
  double **m;
  int lastcol;
} matrix;


matrix *new_matrix(int,int);
void free_matrix(matrix *);
void resize(matrix *,int);
void copy_matrix(matrix *, matrix *);
void print(matrix *);
void populate(matrix *); //testing
void ident(matrix *);
void scalar_mult(double, matrix *);
void matrix_mult(matrix *, matrix *);

