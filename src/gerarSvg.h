#ifndef __teste_h
#define __teste_h
#include <stdio.h>
#include "struct.h"

void desenharRetangulo(FILE* svg, int w, int h, int x, int y, char corb[], char corp[]);
//adiciona um retangulo ao arquivo svg

void desenharCirculo(FILE* svg, int r, int x, int y, char corb[], char corp[]);
//adiciona um circulo ao arquivo svg

void desenharLinha(FILE* svg, int x1, int x2, int y1, int y2, char cor[]);
//adiciona uma linha ao arquivo svg

void escreverTexto(FILE* svg, int x, int y, char corb[], char corp[], char texto[]);
//adiciona um texto ao arquivo svg

void desenharRetanguloTracejado(FILE* svg, int w, int h, int x, int y, char cor[]);
//adiciona um retangulo tracejado ao arquivo svg

void gerarSvg(char outpath[], no* figuras, float xi, float yi, float xf, float yf);
//percorre a lista de figuras e chama as funcoes anteriores para adicionar figuras ao arquivo svg

#endif