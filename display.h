#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "matrix.h"

#define width 500
#define height 500
#define maxcolor 255

typedef struct pixel {
  int r;
  int g;
  int b;
} pixel;

typedef struct pixel screen[width][height];


void pix(pixel,char*);
void tofile(screen, FILE *);
void newdisplay(screen,pixel);
