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

no* geo(char geoArq[], char saida[]){
    no* svg = criarLista();
    char tipo,cor1[22] ,cor2[22], buffer;
    char *txt;
    int n = 0, max = 1000, nbuffer, i;
    float x,y,w,h,xi = 0,yi = 0,xf = 0,yf = 0; 
    FILE* geo = fopen(geoArq,"r");
    if(geo == NULL){
        printf("erro ao abrir o arquivo\n");
        exit(1);
    }
    while((tipo = getc(geo)) != EOF && n < max){
        if (tipo == 'n'){
            fscanf(geo,"x %d\n", &max);
        }
        else if(tipo == 'c'){
            fscanf(geo,"%d %f %f %f %s %s\n", &i, &h, &x, &y, cor1, cor2);
            svg = adicionarNo(svg, i, 'c');
            adicionarCirculo(svg,x,y,h,cor1,cor2);
            if(x - h < xi){
                xi = x - h;
            }
            if(y - h < yi){
                yi = y - h;
            }
            if(x + h > xf){
                xf = x + h;
            }
            if(y + h > yf){
                yf = y + h;
            }
            n++;
        }
        else if(tipo == 'r'){
            fscanf(geo,"%d %f %f %f %f %s %s\n", &i, &x, &y, &h, &w, cor1, cor2);
            svg = adicionarNo(svg, i, 'r');
            adicionarRetangulo(svg,x,y,w,h,cor1,cor2);
            if(x < xi){
                xi = x;
            }
            if(y < yi){
                yi = y;
            }
            if(x + w > xf){
                xf = x + w;
            }
            if(y + h > yf){
                yf = y + h;
            }
            n++;
        }
        else if(tipo == 't'){
            fscanf(geo,"%d %f %f %s %s", &i, &x, &y, cor1, cor2);
            buffer = getc(geo);
            nbuffer = 0;
            while(buffer != '\n' && buffer != EOF){
                buffer = getc(geo);
                nbuffer++;
            }
            fseek(geo,-nbuffer,SEEK_CUR);
            txt = (char*)malloc(sizeof(char)*nbuffer);
            fscanf(geo,"%[^\n]",txt);
            svg = adicionarNo(svg, i, 't');
            svg = adicionarTexto(svg,x,y,txt,cor1,cor2);
            if(x < xi){
                xi = x;
            }
            if(y - 10 < yi){
                yi = y - 10;
            }
            if(x + 12*strlen(txt) > xf){
                xf = x + 10*strlen(txt);
            }
            if(y > yf){
                yf = y;
            }
            free(txt);
        }
    }
    fclose(geo);
    gerarSvg(saida,svg,xi,yi,xf,yf);
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
    gerarSvg(pathSvg,svg,0,0,0,0);
    fclose(saida);
    fclose(consulta);
}

void read(char path[], char outPath[], char paramGeo[], char paramQry[]){
    char *geoArq = NULL;
    char *qryArq = NULL;
    char *nomeArq = NULL;
    char *nomeQry = NULL;
    char *saida = NULL;
    char *saidaGeo = NULL;
    char *saidaQry = NULL;
    if (path != NULL) {
        if(path[strlen(path) - 1] != '/'){
            geoArq = (char *)malloc((strlen(paramGeo)+strlen(path)+2)*sizeof(char));
    	    sprintf(geoArq,"%s/%s",path,paramGeo);
        }
		else{
            geoArq = (char *)malloc((strlen(paramGeo)+strlen(path)+1)*sizeof(char));
    	    sprintf(geoArq,"%s%s",path,paramGeo);
        }
        if (paramQry != NULL){
            qryArq = (char *)malloc((strlen(paramQry)+strlen(path)+2)*sizeof(char));
            sprintf(qryArq,"%s/%s",path,paramQry);
        }
	} else {
		geoArq = (char *)malloc((strlen(paramGeo)+1)*sizeof(char));
    	strcpy(geoArq, paramGeo);
        if(paramQry != NULL){
            qryArq = (char *)malloc((strlen(paramQry)+1)*sizeof(char));
            strcpy(qryArq, paramQry);
        }
	}
    nomeArq = obterNomeArquivo(paramGeo);
    if (outPath[strlen(outPath) - 1] == '/'){
        saida = (char*)malloc((strlen(nomeArq) + strlen(outPath) + 1)*sizeof(char));
        sprintf(saida,"%s%s",outPath,nomeArq);
    }
    else{
        saida = (char*)malloc((strlen(nomeArq) + strlen(outPath) + 2)*sizeof(char));
        sprintf(saida,"%s/%s",outPath,nomeArq);
    }
    saidaGeo = (char*)malloc((strlen(saida) + 5)*sizeof(char));
    sprintf(saidaGeo,"%s.svg",saida);
    no* figuras = geo(geoArq,saidaGeo);
    if (paramQry != NULL){
        nomeQry = obterNomeArquivo(paramQry);
        saidaQry = (char*)malloc((strlen(outPath) + strlen(saida) + 2)*sizeof(char));
        sprintf(saidaQry,"%s-%s",saida,nomeQry);
        qry(figuras,qryArq,saidaQry);
        free(saidaQry);
        free(qryArq); 
    }
    free(geoArq);
    free(saida);
    deletarLista(figuras);
}