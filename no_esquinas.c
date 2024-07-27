#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maximo 100

int main(){
    int tamanio;
    int matriz[maximo][maximo];
    printf("Ingrese el tamaño de la matriz nxn entre 1 y %d)\n", maximo);
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
    if(tamanio > 1){
        printf("los numeros aparte de los de las esquinas de la matriz son: ");
        for (int i = 0; i < tamanio; i++){
            for (int j = 0; j < tamanio; j++){
                if (matriz[i][j] != matriz[0][0] && matriz[i][j] != matriz[0][tamanio - 1] && matriz[i][j] != matriz[tamanio - 1][0] && matriz[i][j] != matriz[tamanio - 1][tamanio - 1]){
                    printf("%d, ", matriz[i][j]);
                }
            }
        }
    }

    return 0;
}
