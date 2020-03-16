#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

no *criarLista(){
  return NULL;
}

no *adicionarNo(no* lista, int n, char t){
  no *aux;
  if(lista == NULL){
    lista = (no *) malloc(sizeof(no));
    lista->i = n;
    lista->tipo = t;
    lista->fig = NULL;
    lista->prox = NULL;
  }else{
    aux = lista;
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = (no *)malloc(sizeof(no));
    aux->prox->i = n;
    aux->prox->tipo = t;
    aux->prox->fig = NULL;
    aux->prox->prox = NULL;
  }
  return lista;
}

void deletarLista(no* lista){
  no* aux;
  while(lista != NULL){
    aux = lista;
    lista = lista->prox;
    free(aux->fig);
    free(aux);
  }
}

no* deletarElemento(no* lista, int n){
  no *aux2, *aux = lista;
  while(aux != NULL){
    if (n == aux->i){
      if (aux == lista){
        lista = lista->prox;
        free(aux->fig);
        free(aux);
      }else{
        aux2->prox = aux->prox;
        free(aux->fig);
        free(aux);
      }
      return lista;
    }
    aux2 = aux;
    aux = aux->prox;
  }
  return lista;
}

no* buscarElemento(no* lista, int i){
  while(lista != NULL){
    if (i == lista->i){
      return lista;
    }
    lista = lista->prox;
  }
  return NULL;
}

void adicionarCirculo(no* lista, int i, float xc, float yc, float raio, char cb[], char cp[]){
    lista = buscarElemento(lista, i);
    lista->fig = (figura *)malloc(sizeof(figura));
    lista->fig->c.r = raio;
    lista->fig->c.x = xc;
    lista->fig->c.y = yc;
    strcpy(lista->fig->c.corp, cp);
    strcpy(lista->fig->c.corb, cb);
}

void adicionarRetangulo(no* lista,int i, float xp, float yp, float wd, float ht, char cb[], char cp[]){
    lista = buscarElemento(lista, i);
    lista->fig = (figura *)malloc(sizeof(figura));
    lista->fig->r.w = wd;
    lista->fig->r.h = ht;
    lista->fig->r.x = xp;
    lista->fig->r.y = yp;
    strcpy(lista->fig->r.corp, cp);
    strcpy(lista->fig->r.corb, cb);
}

void adicionarlinha(no* lista, int i, float xi, float yi, float xf, float yf, char c[]){
    lista = buscarElemento(lista, i);
    lista->fig = (figura *)malloc(sizeof(figura));
    lista->fig->l.x1 = xi;
    lista->fig->l.y1 = yi;
    lista->fig->l.x2 = xf;
    lista->fig->l.y2 = yf;
    strcpy(lista->fig->l.cor, c);
}

void adicionarTexto(no* lista, int i, float x, float y,char texto[], char cb[], char cp[]){
    lista = buscarElemento(lista, i);
    lista->fig = (figura *)malloc(sizeof(figura));
    lista->fig->t.x = x;
    lista->fig->t.y = y;
    strcpy(lista->fig->t.txt, texto);
    strcpy(lista->fig->t.corp, cp);
    strcpy(lista->fig->t.corb, cb);
}
