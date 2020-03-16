#ifndef __struct_h
#define __struct_h

typedef struct circulo{
    float x,y,r;
    char corb[10], corp[10];
}circulo;

typedef struct retangulo{
    float x,y,w,h;
    char corb[10], corp[10];
}retangulo;

typedef struct texto{
    float x,y;
    char corb[10], corp[10],txt[10];
}texto;

typedef struct linha{
    float x1,y1,x2,y2;
    char cor[10];
}linha;

typedef union figura{
    circulo c;
    retangulo r;
    texto t;
    linha l;
}figura;

typedef struct no{
  int i;  
  char tipo;
  figura *fig;
  struct no *prox;
}no;

#endif