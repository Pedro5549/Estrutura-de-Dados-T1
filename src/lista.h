#ifndef __lista_h
#define __lista_h
#include "struct.h"

no *criarLista();

no *adicionarNo(no* lista, int n, char t);

no* deletarLista(no* lista);

no* deletarElemento(no* lista, int i);

no* buscarElemento(no* lista, int i);

void adicionarCirculo(no* lista, float xc, float yc, float raio, char cb[], char cp[]);

void adicionarRetangulo(no* lista, float xp, float yp, float wd, float ht, char cb[], char cp[]);

void adicionarlinha(no* lista, float xi, float yi, float xf, float yf, char c[]);

no* adicionarTexto(no* lista, float x, float y,char texto[], char cb[], char cp[]);

#endif