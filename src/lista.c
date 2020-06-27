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
    if(aux->tipo == 't'){
      free(aux->fig->t.txt);
    }
    free(aux->fig);
    free(aux);
  }
}

no* deletarElemento(no* lista, int n){
  no *aux2, *aux;
  aux = lista;
  aux2 = NULL;
  while(aux != NULL){
    if (n == aux->i){
      if (aux2 == NULL){
        lista = lista->prox;
      }else{
        aux2->prox = aux->prox;
      }
      if(aux->tipo == 't'){
        free(aux->fig->t.txt);
      }
      free(aux->fig);
      free(aux);
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

void adicionarCirculo(no* lista, float xc, float yc, float raio, char cb[], char cp[]){
    while (lista->prox != NULL){
      lista = lista->prox;
    }
    lista->fig = (figura *)malloc(sizeof(figura));
    lista->fig->c.r = raio;
    lista->fig->c.x = xc;
    lista->fig->c.y = yc;
    strcpy(lista->fig->c.corp, cp);
    strcpy(lista->fig->c.corb, cb);
}

void adicionarRetangulo(no* lista, float xp, float yp, float wd, float ht, char cb[], char cp[]){
    while (lista->prox != NULL){
      lista = lista->prox;
    }
    lista->fig = (figura *)malloc(sizeof(figura));
    lista->fig->r.w = wd;
    lista->fig->r.h = ht;
    lista->fig->r.x = xp;
    lista->fig->r.y = yp;
    strcpy(lista->fig->r.corp, cp);
    strcpy(lista->fig->r.corb, cb);
}

void adicionarlinha(no* lista, float xi, float yi, float xf, float yf, char c[]){
    while (lista->prox != NULL){
      lista = lista->prox;
    }
    lista->fig = (figura *)malloc(sizeof(figura));
    lista->fig->l.x1 = xi;
    lista->fig->l.y1 = yi;
    lista->fig->l.x2 = xf;
    lista->fig->l.y2 = yf;
    strcpy(lista->fig->l.cor, c);
}

no* adicionarTexto(no* lista, float x, float y,char texto[], char cb[], char cp[]){
    no* aux = lista;
    while (aux->prox != NULL){
      aux = aux->prox;
    }
    aux->fig = (figura *)malloc(sizeof(figura));
    aux->fig->t.x = x;
    aux->fig->t.y = y;
    aux->fig->t.txt = (char*)malloc(sizeof(char)*(strlen(texto) + 1));
    strcpy(aux->fig->t.txt, texto);
    strcpy(aux->fig->t.corp, cp);
    strcpy(aux->fig->t.corb, cb);
    return lista;
}
