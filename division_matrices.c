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
    double inversa[maximo][maximo];
    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            if(i == j){
                inversa[i][j] = 1.0;
            }else{
                inversa[i][j] = 0.0;
            }
        }
    }
    double aux2[maximo][maximo];
    for (int i = 0; i < tamanio2; i++){
        for(int j = 0; j < tamanio2; j++){
            aux2[i][j] = matriz2[i][j];
        }
    }
    for(int i = 0; i < tamanio2; i++){
        if(aux2[i][i] == 0.0){
            int aux = 0;
            for(int j = i + 1; j < tamanio2; j++){
                if(aux2[j][i] != 0.0){
                    aux = 1;
                    for( int k = 0; k < tamanio2; k++){
                        double temp = aux2[i][k];
                        aux2[i][k] = aux2[j][k];
                        aux2[j][k] = temp;
                    }
                }
            }
            if(!aux){
                printf("la matriz no se puede dividir.\n");
                return 1;
            }
        }
        double factor = aux2[i][i];
        for(int j = 0; j < tamanio2; j++){
            aux2[i][j] /= factor;
            inversa[i][j] /= factor;
        }
        for(int k = 0; k < tamanio2; k++){
            if(k != i){
                factor = aux2[k][i];
                for(int l = 0; l < tamanio2; l++){
                    aux2[k][l] -= factor * aux2[i][l];
                    inversa[k][l] -= factor * inversa[i][l];
                }
            }
        }
    }
    printf("DIVISION DE MATRICES\n\n");
    int matriz_div[maximo][maximo];
    if(tamanio2 != tamanio){
        printf("no se pueden dividir las matrices.\n");
    }else{
        printf("la division de la primera matriz con la segunda es:\n");
        for(int i = 0; i < tamanio2; ++i){
            for(int j = 0; j < tamanio2; ++j) {
                matriz_div[i][j] = 0;
                for(int k = 0; k < tamanio2; ++k){
                    matriz_div[i][j] += matriz[i][k] * inversa[k][j];
                }
            }
        }
        for(int i = 0; i < tamanio2; ++i){
            for(int j = 0; j < tamanio2; ++j){
                printf("%d\t", matriz_div[i][j]);
            }
            printf("\n\n\n");
        }
    }
    return 0;   
}
