#ifndef __lista_h
#define __lista_h
#include "struct.h"

no* deletarLista(no* lista);
//percorre a lista e desaloca todos os nos

no* deletarElemento(no* lista, int i);
//deleta um elemento da lista indicado pelo inteiro identificador

no* buscarElemento(no* lista, int i);
//percorre a lista para encontrar e retornar um no com um inteiro identificador igual ao passado como parâmetro

no* adicionarCirculo(no* lista, int n, char t, float xc, float yc, float raio, char cb[], char cp[]);
//adiciona um circulo para a lista de figuras

no* adicionarRetangulo(no* lista, int n, char t, float xp, float yp, float wd, float ht, char cb[], char cp[]);
//adiciona um retangulo para a lista de figuras

no* adicionarlinha(no* lista, int n, char t, float xi, float yi, float xf, float yf, char c[]);
//adiciona uma linha para a lista de figuras

no* adicionarTexto(no* lista, int n, char t, float x, float y,char texto[], char cb[], char cp[]);
//adiciona um texto para a lista de figuras

#endif