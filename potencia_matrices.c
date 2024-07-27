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

    printf("POTENCIA DE MATRICES\n\n");
    int matriz_potencia[maximo][maximo];
    printf("el cuadrado de la matriz es:\n");
    for(int i = 0; i < tamanio; ++i){
        for(int j = 0; j < tamanio; ++j) {
            matriz_potencia[i][j] = 0;
            for(int k = 0; k < tamanio; ++k){
                matriz_potencia[i][j] += matriz[i][k] * matriz[k][j];
            }
        }
    }
    for(int i = 0; i < tamanio; ++i){
        for(int j = 0; j < tamanio; ++j){
            printf("%d\t", matriz_potencia[i][j]);
        }
        printf("\n\n\n");
    }
    
    return 0;   
}
