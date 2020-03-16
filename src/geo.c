#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "lista.h"

char *obterNomeArquivo(char path[]){
    char *aux = strrchr(path,'/');
    if(aux == NULL){
        return strtok(path,".");
    }
	return strtok(&aux[1],".");
}

no* geo(char geoArq[]){
    no* svg = criarLista();
    char tipo,cor1[10] ,cor2[10] ,txt[50];
    int n = 0, max = 1000, i;
    float x,y,w,h; 
    FILE* geo = fopen(geoArq,"r");
    while((tipo = getc(geo)) != EOF){
        if (tipo == 'n'){
            fscanf(geo,"n %d\n", &max);
        }
        else if(tipo == 'c'){
            if (n < max){
                fscanf(geo,"%d %f %f %f %s %s\n", &i, &x, &y, &h, cor1, cor2);
                svg = adicionarNo(svg, i, 'c');
                adicionarCirculo(svg,i,x,y,h,cor1,cor2);
                n++;
            }
        }
        else if(tipo == 'r'){
            if (n < max){
                fscanf(geo,"%d %f %f %f %f %s %s\n", &i, &x, &y, &h, &w, cor1, cor2);
                svg = adicionarNo(svg, i, 'r');
                adicionarRetangulo(svg,i,x,y,w,h,cor1,cor2);
                n++;
            }
            
        }
        else if(tipo == 't'){
            fscanf(geo,"%d %f %f %s %s %s\n", &i, &x, &y, cor1, cor2, txt);
            svg = adicionarNo(svg, i, 't');
            adicionarTexto(svg,i,x,y,cor1,cor2,txt);
        }
    }
    fclose(geo);
    return svg;
}