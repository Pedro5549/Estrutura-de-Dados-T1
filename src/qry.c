#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"
#include "lista.h"
#include "gerarSvg.h"

float max(float n1, float n2){
    if(n1 > n2){
        return n1;
    }
    return n2;
}

float min(float n1, float n2){
    if(n1 > n2){
        return n2;
    }
    return n1;
}

void retanguloxCirculo(circulo circ, int c, retangulo ret, int r, FILE* saida, no* svg){
    float deltaX, deltaY, x, y, w, h;
    if(circ.x > ret.x){
        deltaX = pow(ret.x + ret.w - circ.x,2);
    }
    else{
        deltaX = pow(ret.x - circ.x,2);
    }
    if(circ.y > ret.y){
        deltaY = pow(ret.y + ret.h - circ.y,2);
    }
    else{
        deltaY = pow(ret.y - circ.y,2);
    }
    x = min(ret.x,circ.x - circ.r);
    w = max(ret.x + ret.w,circ.x + circ.r) - x;
    y = min(ret.y,circ.y - circ.r);
    h = max(ret.y + ret.h,circ.y + circ.r) - y;
    if(sqrt(deltaX + deltaY) <= circ.r){
        fprintf(saida,"%d: circulo %d: retangulo SIM",c,r);
        adicionarRetangulo(svg,-1,'r',x,y,w,h,"black","transparent");
    }else{
        fprintf(saida,"%d: circulo %d: retangulo NAO",c,r);
        adicionarRetangulo(svg,-1,'o',x,y,w,h,"black","transparent");
    }
}

void circuloInt(circulo c1, int j, circulo c2, int k, FILE* saida, no* svg){
    float dist,x,y,w,h;
    dist = sqrt(pow(c1.x - c2.x,2) + pow(c1.y - c2.y,2));
    x = min(c1.x - c1.r, c2.x - c2.r);
    w = max(c1.x + c1.r, c2.x + c2.r) - x;
    y = min(c1.y - c1.r, c2.y - c2.r);
    h = max(c1.y + c1.r, c2.y + c2.r) - y;
    if(dist <= c2.r + c1.r){
        fprintf(saida,"%d: circulo %d: circulo SIM",j,k);
        adicionarRetangulo(svg,-1,'r',x,y,w,h,"black","transparent");
    }
    else{
        fprintf(saida,"%d: circulo %d: circulo NAO",j,k);
        adicionarRetangulo(svg,-1,'o',x,y,w,h,"black","transparent");
    }
}

void retanguloInt(retangulo r1, int j, retangulo r2, int k, FILE* saida, no* svg){
    float x,w,y,h;
    x = min(r1.x,r2.x);
    w = max(r1.x + r1.w,r2.x + r2.w) - x;
    y = min(r1.y,r2.y);
    h = max(r1.y + r1.h,r2.y + r2.h) - y;
    if (w <= r1.w + r2.w && h <= r1.h + r2.h){
        fprintf(saida,"%d: retangulo %d: retangulo SIM",j,k);
        adicionarRetangulo(svg,-1,'r',x,y,w,h,"black","transparent");
    }
    else{
        fprintf(saida,"%d: retangulo %d: retangulo NAO",j,k);
        adicionarRetangulo(svg,-1,'o',x,y,w,h,"black","transparent");
    }
}

void intesecao(int j, int k, FILE* saida, no* svg){
    no *fig1 = buscarElemento(svg,j);
    no *fig2 = buscarElemento(svg,k);
    if (fig1->tipo == 'c' && fig2->tipo == 'c'){ 
        circuloInt(fig1->fig->c,j,fig2->fig->c,j,saida,svg);
    }
    else if (fig1->tipo == 'r' && fig2->tipo == 'r'){
        retanguloInt(fig1->fig->r,j,fig2->fig->r,j,saida,svg);
    }
    else if (fig1->tipo == 'c' && fig2->tipo == 'r'){
        retanguloxCirculo(fig1->fig->c,j,fig2->fig->r,k,saida,svg);
    }
    else{
        retanguloxCirculo(fig2->fig->c,k,fig1->fig->r,j,saida,svg);
    }
}

void pontoInterno(float x, float y, int j, FILE* saida, no* svg){
    char cor[10];
    no * aux = buscarElemento(svg,j);
    if (aux->tipo == 'c'){
        float dist = sqrt(pow(x - aux->fig->c.x,2) + pow(y - aux->fig->c.y,2));
        if (aux->fig->c.r > dist){
            fprintf(saida,"%d: circulo INTERNO\n",j);
            strcpy(cor,"blue");
        }else{
            fprintf(saida,"%d: circulo NAO INTERNO\n",j);
            strcpy(cor,"magenta");
        }
        adicionarlinha(svg,-1,'l',x,y,aux->fig->c.x,aux->fig->c.y,cor);
    }else{
        float difx = x - aux->fig->r.x;
        float dify = y - aux->fig->r.y;
        if(difx > 0 && difx < aux->fig->r.w && dify > 0 && dify < aux->fig->r.h){
            fprintf(saida,"%d: retangulo INTERNO\n",j);
            strcpy(cor,"blue");
        }else{
            fprintf(saida,"%d: retangulo NAO INTERNO\n",j);
            strcpy(cor,"magenta");
        }
        adicionarlinha(svg,-1,'l',x,y,aux->fig->r.x + aux->fig->r.w/2,aux->fig->r.y + aux->fig->r.h/2,cor);    
    }
    adicionarCirculo(svg,-1,'c',x,y,1,cor,cor);
}

no* delf(int j,FILE* saida, no* svg){
    no *aux;
    aux = buscarElemento(svg,j);
    if (aux != NULL){
        if(aux->tipo == 'c'){
            fprintf(saida,"%d: circulo x = %f y = %f r = %f corb = %s corp = %s\n",j,aux->fig->c.x,aux->fig->c.y,aux->fig->c.r,aux->fig->c.corb,aux->fig->c.corp);
        }
        else if(aux->tipo == 'r'){
            fprintf(saida,"%d: retangulo x = %f y = %f w = %f h = %f corb = %s corp = %s\n",j,aux->fig->r.x,aux->fig->r.y,aux->fig->r.w,aux->fig->r.h,aux->fig->r.corb,aux->fig->r.corp);      
        }
        else{
            fprintf(saida,"%d: texto x = %f y = %f corb = %s corp = %s texto = %s\n",j,aux->fig->t.x,aux->fig->t.y,aux->fig->t.corb,aux->fig->t.corp,aux->fig->t.txt);
        }
        svg = deletarElemento(svg,j);
    }
    return svg;
}

void pnt(int j, FILE* saida, no* svg, char corb[], char corp[]){
    no *aux = buscarElemento(svg, j);
    if(aux->tipo == 'c'){
        strcpy(aux->fig->c.corb,corb);
        strcpy(aux->fig->c.corp,corp);
        fprintf(saida,"x: %f y: %f\n",aux->fig->c.x,aux->fig->c.y);
    }
    else if(aux->tipo == 'r'){
        strcpy(aux->fig->r.corb,corb);
        strcpy(aux->fig->r.corp,corp);
        fprintf(saida,"x: %f y: %f\n",aux->fig->r.x,aux->fig->r.y);       
    }
    else{
        strcpy(aux->fig->t.corb,corb);
        strcpy(aux->fig->t.corp,corp);
        fprintf(saida,"x: %f y: %f\n",aux->fig->t.x,aux->fig->t.y);
    }
}