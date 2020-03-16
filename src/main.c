#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "lista.h"
#include "gerarSvg.h"
#include "geo.h"

int main(int argc, char *argv[])
{
    int i = 1;
    char *paramGeo = NULL;
    char *paramQry = NULL;
    char *path = NULL;
    char *outPath = NULL;
    char *geoArq = NULL;
    char *qryArq = NULL;
    char *nomeArq = NULL;
    char *out = NULL;
    while(i<argc){
        if (strcmp("-f",argv[i])==0){
            i++;
            if (argv[i] == NULL){
                printf("Erro - Sem parametros em -f");
                exit(1);
            }
            paramGeo = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(paramGeo,argv[i]);
        }
        else if (strcmp("-e",argv[i])==0){
            i++;
            if (argv[i] == NULL){
                printf("Erro - Sem parametros em -e");
                exit(1);
            }
            path = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(path,argv[i]);
        }
        else if (strcmp("-q",argv[i])==0){
            i++;
            if (argv[i] == NULL){
                printf("Erro - Sem parametros em -q");
                exit(1);
            }
            paramQry = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(paramQry,argv[i]);
        }
        else if (strcmp("-o",argv[i])==0){
            i++;
            if (argv[i] == NULL){
                printf("Erro! - Sem parametros em -o");
                exit(1);
            }
            outPath = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(outPath,argv[i]);
        }
        i++;
    }
	if (path != NULL) {
		geoArq = (char *)malloc((strlen(paramGeo)+strlen(path)+2)*sizeof(char));
    	sprintf(geoArq,"%s/%s",path,paramGeo);
    	qryArq = (char *)malloc((strlen(paramQry)+strlen(path)+2)*sizeof(char));
    	sprintf(qryArq,"%s/%s",path,paramQry);
	} else {
		geoArq = (char *)malloc((strlen(paramGeo)+1)*sizeof(char));
    	strcpy(geoArq, paramGeo);
    	qryArq = (char *)malloc((strlen(paramQry)+1)*sizeof(char));
    	strcpy(qryArq, paramQry);
	}
    no* figuras = geo(geoArq);
    nomeArq = obterNomeArquivo(paramGeo);
    out = (char*)malloc((strlen(nomeArq) + strlen(outPath) + 6)*sizeof(char));
    printf("%d\n%d", strlen(nomeArq),strlen(outPath));
    sprintf(out,"%s/%s.svg",outPath,nomeArq);
    printf("\n%d", strlen(out));
    printf("%s",out);
    gerarSvg(out,figuras);
	free(paramGeo);
    free(paramQry);
    free(path);
	free(outPath);
    free(geoArq);
    free(qryArq);
    free(out);
    deletarLista(figuras);
    printf("Mémoria desalocada\n");   
    return 0;
}