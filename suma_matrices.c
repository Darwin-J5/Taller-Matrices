#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maximo 100

int main(){
    int tamanio;
    int matriz[maximo][maximo];
    printf("Ingrese el tamaño de la matriz nxn entre 1 y %d\n", maximo);
    scanf("%d", &tamanio);

    do{
        if(tamanio < 0 || tamanio > maximo){
            printf("por favor, ingrese un valor entre 1 y %d\n", maximo);
            scanf("%d", &tamanio);
        }
    }while(tamanio < 0 || tamanio > 100);

    srand(time(NULL));
    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            matriz[i][j] = (rand() % 20);
        }
    }

    printf("\nMATRIZ GENERADA\n\n");
    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n\n\n");
    }
    
    int tamanio2;
    int matriz2[maximo][maximo];
    printf("Ingrese el tamaño de la segunda matriz nxn entre 1 y %d\n", maximo);
    scanf("%d", &tamanio2);

    do{
        if(tamanio2 < 0 || tamanio2 > maximo){
            printf("por favor, ingrese un valor entre 1 y %d\n", maximo);
            scanf("%d", &tamanio2);
        }
    }while(tamanio2 < 0 || tamanio2 > 100);

    srand(time(NULL));
    for(int i = 0; i < tamanio2; i++){
        for(int j = 0; j < tamanio2; j++){
            matriz2[i][j] = (rand() % 20);
        }
    }

    printf("\nSEGUNDA MATRIZ GENERADA\n\n");
    for(int i = 0; i < tamanio2; i++){
        for(int j = 0; j < tamanio2; j++){
            printf("%d\t", matriz2[i][j]);
        }
        printf("\n\n\n");
    }
    printf("SUMA DE MATRICES\n\n");
    int mat_sum[maximo][maximo];
    if (tamanio == tamanio2 && tamanio == tamanio2){
        printf("matriz suma de la primera mas la segunda matriz:\n");
        for (int i = 0; i < tamanio2; i++){
            for (int j = 0; j < tamanio2; j++){
                printf("%d\t", matriz[i][j] + matriz2[i][j]);
            }
        printf("\n\n\n");
        }
    } else {
        printf("no se puede sumar las matrices.\n");
    }

    return 0;   
}
