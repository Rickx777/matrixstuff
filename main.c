#include "draw.h"
void main(){
  /*SPACE INVADER CREATION*/
  screen a;
  pixel def;  
  matrix *test; //declare + initiate
  int x;
  double arg[]= {0,13,1,13,1,13,1,15,1,15,2,15,2,15,2,13,2,13,3,13,3,13,3,14,3,14,8,14,8,14,8,13,8,13,9,13,9,13,9,15,9,15,10,15,10,15,10,13,10,13,11,13,11,13,11,16,11,16,10,16,10,16,10,17,10,17,9,17,9,17,9,18,9,18,8,18,8,18,8,19,8,19,7,19,7,19,7,18,7,18,4,18,4,18,4,19,4,19,3,19,3,19,3,18,3,18,2,18,2,18,2,17,2,17,1,17,1,17,1,16,1,16,0,16,0,16,0,13,/*<body of invader*/ 7,17,7,16,7,16,8,16,8,16,8,17,8,17,7,17,3,17,3,16,3,16,4,16,4,16,4,17,4,17,3,17, /*<eyes of invader*/ 3,12,5,12,5,12,5,13,5,13,3,13,3,13,3,12,6,13,6,12,6,12,8,12,8,12,8,13,8,13,6,13,/*<mouth of invader*/ 8,20,8,19,8,19,9,19,9,19,9,20,9,20,8,20,2,20,3,20,3,20,3,19,3,19,2,19,2,19,2,20 /*<ears of invader*/};
  for(x = 0; x < sizeof(arg)/(sizeof(arg[0])); x++){
    if (!(x % 2)) arg[x] += 6.5;
  }
  
  test = new_matrix(2,(sizeof(arg)/sizeof(arg[0]))/2);

  pop(arg,*test,sizeof(arg)/sizeof(arg[0])); //populating matrix with array
  scalar_mult(20,test);
  
  def.r = 0; def.g = 0; def.b = 0;  
  newdisplay(a,def);

  def.r = 255; def.g = 255; def.b = 255;
  drawmultiple(*test,a,def);

  FILE *newim = fopen("image.ppm","w");
  tofile(a,newim);
 
  printf("Image created!\n\n");
  free_matrix(test);
  
  /*MATRIX TESTING*/
  printf("----MATRIX TESTING----\n");
  matrix *test1; matrix *test2; //declare + initiate
  test1 = new_matrix(4,5);
  test2 = new_matrix(4,4);
  
  populate(test1);  //putting stuff in matrixes
  populate(test2);
  printf("=Matrix [test1]:\n");
  print(test1);
  printf("=Matrix [test2]:\n");
  print(test2);

  printf("\n=Matrix [test2]: after Identity function\n"); //testing ident
  ident(test2);
  print(test2);
  
  printf("\n=Multiply: test2 * test1 -> test1\n"); //testing multiply
  matrix_mult(test2,test1);
  print(test1);
  printf("\n=Multiply: test1 * 2:\n"); //testing multiply_matrix
  scalar_mult(2.0,test1);
  print(test1);
}
