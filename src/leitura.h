#ifndef __leitura_h
#define __leitura_h
#include "struct.h"

char *obterNomeArquivo(char path[]);

no* geo(char geoArq[], char saida[]);

void qry(no* svg, char path[], char nomeSaida[]);

void read(char path[], char outPath[], char paramGeo[], char paramQry[]);

#endif