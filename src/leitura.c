#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "lista.h"
#include "qry.h"
#include "gerarSvg.h"

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
    if(geo == NULL){
        printf("erro ao abrir o arquivo\n");
        exit(1);
    }
    while((tipo = getc(geo)) != EOF){
        if (tipo == 'n'){
            fscanf(geo,"n %d\n", &max);
        }
        else if(tipo == 'c'){
            if (n < max){
                fscanf(geo,"%d %f %f %f %s %s\n", &i, &h, &x, &y, cor1, cor2);
                svg = adicionarNo(svg, i, 'c');
                adicionarCirculo(svg,x,y,h,cor1,cor2);
                n++;
            }
        }
        else if(tipo == 'r'){
            if (n < max){
                fscanf(geo,"%d %f %f %f %f %s %s\n", &i, &x, &y, &h, &w, cor1, cor2);
                svg = adicionarNo(svg, i, 'r');
                adicionarRetangulo(svg,x,y,w,h,cor1,cor2);
                n++;
            }
            
        }
        else if(tipo == 't'){
            fscanf(geo,"%d %f %f %s %s %s\n", &i, &x, &y, cor1, cor2, txt);
            svg = adicionarNo(svg, i, 't');
            adicionarTexto(svg,x,y,cor1,cor2,txt);
        }
    }
    fclose(geo);
    return svg;
}

void qry(no* svg, char path[], char nomeSaida[]){
    char* pathTxt = malloc((4 + strlen(nomeSaida))*sizeof(char));
    char* pathSvg = malloc((4 + strlen(nomeSaida))*sizeof(char));
    sprintf(pathTxt,"%s.txt",nomeSaida);
    sprintf(pathSvg,"%s.svg",nomeSaida);
    FILE* consulta = fopen(path,"r");
    FILE* saida = fopen(pathTxt,"w");
    if(saida == NULL || consulta == NULL){
        printf("erro ao abrir o arquivo\n");
        exit(1);
    }
    int j,k,i;
    float x,y;
    char tipo[5], corb[10], corp[100];
    while(fscanf(consulta,"%s",tipo) != EOF){
        if(strcmp(tipo,"o?") == 0){
            fscanf(consulta,"%d %d",&j,&k);
            fprintf(saida,"%s %d %d\n",tipo,j,k);
            intesecao(j,k,saida,svg);
        }
        else if(strcmp(tipo,"i?") == 0){
            fscanf(consulta,"%d %f %f",&j,&x,&y);
            fprintf(saida,"%s %d %f %f\n",tipo,j,x,y);
            pontoInterno(x,y,j,saida,svg);
        }
        else if(strcmp(tipo,"pnt") == 0){
            fscanf(consulta,"%d %s %s",&j,corb,corp);
            fprintf(saida,"%s %d %s %s\n",tipo,j,corb,corp);
            pnt(j,saida,svg,corb,corp);
        }
        else if(strcmp(tipo,"pnt*") == 0){
            fscanf(consulta,"%d %d %s %s",&j,&k,corb,corp);
            fprintf(saida,"%s %d %d %s %s\n",tipo,j,k,corb,corp);
            for(i = j; i <= k; i++){
                pnt(i,saida,svg,corb,corp);
            }
        }
        else if(strcmp(tipo,"delf") == 0){
            fscanf(consulta,"%d",&j);
            fprintf(saida,"%s %d\n",tipo,j);
            svg = delf(j,saida,svg);
        }
        else if(strcmp(tipo,"delf*") == 0){
            fscanf(consulta,"%d %d",&j,&k);
            fprintf(saida,"%s %d %d\n",tipo,j,k);
            for(i = j; i <= k; i++){
                svg = delf(i,saida,svg);
            }
        }
    }
    gerarSvg(pathSvg,svg);
    fclose(saida);
    fclose(consulta);
}