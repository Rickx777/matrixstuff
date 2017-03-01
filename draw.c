#include "draw.h"

void drawline(double x0, double y0, double x1, double y1, screen c, pixel b) {  
  int x = x0; int y = (int)y0;
  int Ah = (int)(y1 - y0);
  int Bh = (int)-(x1 - x0);
  int d;

  if (x1 < x0 || (y1 < y0 && x1 == x0)){ //x1 < x0
    x = (int)x1; y = (int)y1; //change x and y to y1 vals    
    x1 = x0; y1 = y0; //change x1 to x0 and y1 to y0 vals
    Ah = (int)(y1 - y); //adjust values
    Bh = (int)-(x1 - x);
    //printf("Ah: %d Bh: %d\n", Ah, Bh);
  }

  if(Ah == 0){
    while (x <= x1){
      c[x][y] = b;
      x++;
    }
  }
  
  else if(Bh == 0){    
    //printf("Ah: %d Bh: %d\n", Ah, Bh);
    while (y <= y1){
      c[x][y] = b;
      y++;
    }
  }
  
  else if( (Ah/(-Bh)) == 0 && Ah > 0){ //I
    d = 2*Ah + Bh;
    
    while (x <= x1){
      c[x][y] = b;
      if (d > 0){
	y++;
	d+= 2*Bh;
      }
      x++;
      d += 2*Ah;
    }
  }

  else if ( (Ah/(-Bh)) > 0 && Ah > 0){ //II
    d = 2*Bh + Ah;
    
    while (y <= y1){
      c[x][y] = b;
      if (d < 0){	
	x++;
	d += 2*Ah;
      }
    y++;
    d += 2*Bh;
    }
  }

  else if ( (Ah/(-Bh)) == 0 && Ah < 0){ //VIII
    d = -2*Ah + Bh;

    while (x <= x1){
      c[x][y] = b;
      if (d < 0){
	y--;
	d -= 2*Bh; 
      }
      x++;
      d += 2*Ah;
    }    
  }

  else{ //VII
    d = -2*Bh + Ah;

    while(y > y1){
      c[x][y] = b;
      if (d > 0){
	x++;
	d += 2*Ah;
      }
      y--;
      d -= 2*Bh;
    }
  }
}

void drawmultiple(matrix a,screen c, pixel b){
  int ctr;
  int x0; int y0; int x1; int y1;
  
  if (a.cols % 2) {
    printf("Odd number of coordinates! This can't do!\n");
    return;
  }

  ctr = 0;
  while (ctr < a.cols){
    x0 = a.m[0][ctr]; y0 = a.m[1][ctr];
    x1 = a.m[0][ctr + 1]; y1 = a.m[1][ctr + 1];
    //printf("%d %d %d %d\n",x0,y0,x1,y1);
    //printf("ctr: %d n: %d\n",ctr,a.cols);    
    drawline(x0,y0,x1,y1,c,b);    
    ctr += 2;
  }
}

void pop(double* c, matrix a, int size){
  //printf("size %d\n cols: %d rows: %d\n",size,a.cols,a.rows);
  if (a.cols * a.rows != size){
    printf("Not enough or too many input coordinates!\n");
    return;
  }

  int ctr = 0;
  while (ctr < size){
    a.m[0][ctr/2] = c[ctr];
    a.m[1][ctr/2] = c[ctr + 1];
    ctr += 2;
  }
}
