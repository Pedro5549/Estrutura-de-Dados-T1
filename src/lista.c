#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

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
      if(aux == lista){
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

no* adicionarCirculo(no* lista, int n, char t, float xc, float yc, float raio, char cb[], char cp[]){
  no *aux;
  if(lista == NULL){
    lista = (no *) malloc(sizeof(no));
    lista->i = n;
    lista->tipo = t;
    lista->fig = NULL;
    lista->prox = NULL;
    aux = lista;
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
    aux = aux->prox;
  }
    aux->fig = (figura *)malloc(sizeof(figura));
    aux->fig->c.r = raio;
    aux->fig->c.x = xc;
    aux->fig->c.y = yc;
    strcpy(aux->fig->c.corp, cp);
    strcpy(aux->fig->c.corb, cb);
    return lista;
}

no* adicionarRetangulo(no* lista, int n, char t, float xp, float yp, float wd, float ht, char cb[], char cp[]){
    no *aux;
    if(lista == NULL){
      lista = (no *) malloc(sizeof(no));
      lista->i = n;
      lista->tipo = t;
      lista->fig = NULL;
      lista->prox = NULL;
      aux = lista;
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
      aux = aux->prox;
    }
    aux->fig = (figura *)malloc(sizeof(figura));
    aux->fig->r.w = wd;
    aux->fig->r.h = ht;
    aux->fig->r.x = xp;
    aux->fig->r.y = yp;
    strcpy(aux->fig->r.corp, cp);
    strcpy(aux->fig->r.corb, cb);
    return lista;
}

no* adicionarlinha(no* lista, int n, char t, float xi, float yi, float xf, float yf, char c[]){
    no *aux;
    if(lista == NULL){
      lista = (no *) malloc(sizeof(no));
      lista->i = n;
      lista->tipo = t;
      lista->fig = NULL;
      lista->prox = NULL;
      aux = lista;
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
      aux = aux->prox;
    }
    aux->fig = (figura *)malloc(sizeof(figura));
    aux->fig->l.x1 = xi;
    aux->fig->l.y1 = yi;
    aux->fig->l.x2 = xf;
    aux->fig->l.y2 = yf;
    strcpy(aux->fig->l.cor, c);
    return lista;
}

no* adicionarTexto(no* lista, int n, char t, float x, float y,char texto[], char cb[], char cp[]){
    no *aux;
    if(lista == NULL){
      lista = (no *) malloc(sizeof(no));
      lista->i = n;
      lista->tipo = t;
      lista->fig = NULL;
      lista->prox = NULL;
      aux = lista;
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
