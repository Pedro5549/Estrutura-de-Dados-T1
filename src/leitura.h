#ifndef __leitura_h
#define __leitura_h
#include "struct.h"

char *obterNomeArquivo(char path[]);
//a partir do parametro -f extrai o nome do arquivo de saida do .geo

no* geo(char geoArq[], char saida[]);
//processa o comandos do arquivo .geo

no* qry(no* svg, char path[], char nomeSaida[]);
//processa o comandos do arquivo .qry

void tratamento(char path[], char outPath[], char paramGeo[], char paramQry[]);
//processa o parametros do programa e chama as funcoes geo e qry

#endif