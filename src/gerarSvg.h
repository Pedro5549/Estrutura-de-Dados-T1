#ifndef __teste_h
#define __teste_h
#include <stdio.h>
#include "struct.h"

void desenharRetangulo(FILE* svg, int w, int h, int x, int y, char corb[], char corp[]);

void desenharCirculo(FILE* svg, int r, int x, int y, char corb[], char corp[]);

void desenharLinha(FILE* svg, int x1, int x2, int y1, int y2, char cor[]);

void escreverTexto(FILE* svg, int x, int y, char corb[], char corp[], char texto[]);

void gerarSvg(char outpath[], no* figuras);

#endif