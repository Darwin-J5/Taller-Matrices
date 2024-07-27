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
    if(tamanio == 1){
        printf("\nLa matriz solo tiene el numero %d.", matriz[tamanio-1][tamanio-1]);
    }else{
        printf("\nLOS 4 ELEMENTOS DE LA ESQUINA DE LA MATRIZ\n\n");
        printf("los numeros son: %d, %d, %d y %d", matriz[0][0], matriz[0][tamanio-1], matriz[tamanio-1][0], matriz[tamanio-1][tamanio-1]);
    }

    return 0;
}
