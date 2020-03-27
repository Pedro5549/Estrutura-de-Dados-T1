#ifndef __qry_h
#define __qry_h
#include <stdio.h>
#include "struct.h"

float max(float n1, float n2);

float min(float n1, float n2);

void retanguloxCirculo(circulo circ, int c, retangulo ret, int r, no* svg);

void circuloInt(circulo c1, int j, circulo c2, int k, FILE* saida, no* svg);

void retanguloInt(retangulo r1, int j, retangulo r2, int k, FILE* saida, no* svg);

void intesecao(int j, int k, FILE* saida, no* svg);

void pontoInterno(float x, float y, int j, FILE* saida, no* svg);

no* delf(int j,FILE* saida, no* svg);

void pnt(int j, FILE* saida, no* svg, char corb[], char corp[]);

#endif