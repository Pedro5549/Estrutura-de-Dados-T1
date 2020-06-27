#ifndef __struct_h
#define __struct_h

typedef struct circulo{
    float x,y,r;
    char corb[22], corp[22];
}circulo;

typedef struct retangulo{
    float x,y,w,h;
    char corb[22], corp[22];
}retangulo;

typedef struct texto{
    float x,y;
    char corb[22], corp[22];
    char *txt;
}texto;

typedef struct linha{
    float x1,y1,x2,y2;
    char cor[22];
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