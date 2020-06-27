#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

int main(int argc, char *argv[]){
    int i = 1;
    char *paramGeo = NULL;
    char *paramQry = NULL;
    char *path = NULL;
    char *outPath = NULL;
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
    read(path,outPath,paramGeo,paramQry);
	free(paramQry);
    free(paramGeo);
    free(path);
	free(outPath);
    printf("Mémoria desalocada\n");   
    return 0;
}