#ifndef __qry_h
#define __qry_h
#include <stdio.h>
#include "struct.h"

float max(float n1, float n2);
//retorna a maior valor entre dois floats

float min(float n1, float n2);
//retorna o menor valor entre dois floats

void retanguloxCirculo(circulo circ, int c, retangulo ret, int r, no* svg);
//realiza o comando o? quando as figuras sao diferentes

void circuloInt(circulo c1, int j, circulo c2, int k, FILE* saida, no* svg);
//realiza o comando o? quando ambas as figuras sao circulos

void retanguloInt(retangulo r1, int j, retangulo r2, int k, FILE* saida, no* svg);
//realiza o comando o? quando ambas as figuras sao retangulos

void intesecao(int j, int k, FILE* saida, no* svg);
//analisa o caso do comando o? e chama a funcao correspondente

void pontoInterno(float x, float y, int j, FILE* saida, no* svg);
//realiza o comando i?

no* delf(int j,FILE* saida, no* svg);
//realiza os comandos delf e delf*

void pnt(int j, FILE* saida, no* svg, char corb[], char corp[]);
//realiza os comandos pnt e pnt*

#endif