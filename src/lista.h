#ifndef __lista_h
#define __lista_h
#include "struct.h"

no *criarLista();

no *adicionarNo(no* lista, int n, char t);

no* deletarLista(no* lista);

no* deletarElemento(no* lista, int i);

no* buscarElemento(no* lista, int i);

void adicionarCirculo(no* lista,int i, float xc, float yc, float raio, char cb[], char cp[]);

void adicionarRetangulo(no* lista, int i, float xp, float yp, float wd, float ht, char cb[], char cp[]);

void adicionarlinha(no* lista, int i, float xi, float yi, float xf, float yf, char c[]);

void adicionarTexto(no* lista, int i, float x, float y,char texto[], char cb[], char cp[]);

#endif