#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "lista.h"

void desenharRetangulo(FILE* svg, int w, int h, int x, int y, char corb[], char corp[]){
    fprintf(svg,"\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"%s\"/>\n",x,y,w,h,corp,corb);
}

void desenharCirculo(FILE* svg, int r, int x, int y, char corb[], char corp[]){
    fprintf(svg,"\t<circle x=\"%d\" y=\"%d\" r=\"%d\" fill=\"%s\" stroke=\"%s\"/>\n",x,y,r,corp,corb);
}

void desenharLinha(FILE* svg, int x1, int x2, int y1, int y2, char cor[]){
    fprintf(svg,"\t<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\"/>\n",x1,y1,x2,y2,cor);
}

void escreverTexto(FILE* svg, int x, int y, char corb[], char corp[], char texto[]){
    fprintf(svg,"\t<text x=\"%d\" y=\"%d\" stroke=\"%s\" fill=\"%s\">%s</text>\n",x,y,corb,corp,texto);
}

void gerarSvg(char outpath[], no* figuras){
    printf("\n%s\n", outpath);
    FILE *svgArq = fopen(outpath,"w");
    fprintf(svgArq,"<svg>\n");
    while(figuras != NULL){
        switch (figuras->tipo){
        case 'c':
            desenharCirculo(svgArq,figuras->fig->c.r,figuras->fig->c.x,figuras->fig->c.y,figuras->fig->c.corb, figuras->fig->c.corp);
            break;
        case 'r':
            desenharRetangulo(svgArq,figuras->fig->r.w,figuras->fig->r.h,figuras->fig->r.x,figuras->fig->r.y,figuras->fig->r.corb, figuras->fig->r.corp);
            break;
        case 'l':
            desenharLinha(svgArq,figuras->fig->l.x1,figuras->fig->l.x2,figuras->fig->l.y1,figuras->fig->l.y2,figuras->fig->l.cor);
            break;
        case 't':
            escreverTexto(svgArq,figuras->fig->t.x,figuras->fig->t.y,figuras->fig->t.corb,figuras->fig->t.corp,figuras->fig->t.txt);
            break;
        }
        figuras = figuras->prox;
    }
    fprintf(svgArq,"</svg>");
    fclose(svgArq);
}