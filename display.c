#include "display.h"

void pix(pixel c, char* buff){
  strcpy(buff,"");
  snprintf(buff,64,"%d %d %d ", c.r, c.g, c.b);
}

void tofile(screen c, FILE* newim){
  int x;
  int y = height - 1;
  char buff[64];
  
  snprintf(buff,64,"P3 %d %d %d ",width,height,maxcolor);
  fprintf(newim,buff);

  while (y >= 0){
    x = 0;
    while (x < width){
      pix(c[x][y],&buff);
      fprintf(newim,buff);
      x++;
    }
    y--;
  }
  fprintf(newim,"\n");
}

void newdisplay(screen c, pixel b){
  int x = 0;
  int y = 0;
  
  while (y < height){
    x = 0;
    while(x < width){
      c[x][y] = b;
      x++;
    }
    y++;
  }
}
