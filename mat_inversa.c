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
    printf("MATRIZ INVERSA\n\n");
    double matriz_inversa[maximo][maximo];
    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            if(i == j){
                matriz_inversa[i][j] = 1.0;
            }else{
                matriz_inversa[i][j] = 0.0;
            }
        }
    }
    double mat_aux[maximo][maximo];
    for (int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            mat_aux[i][j] = matriz[i][j];
        }
    }
    for(int i = 0; i < tamanio; i++){
        if(mat_aux[i][i] == 0.0){
            int aux = 0;
            for(int j = i + 1; j < tamanio; j++){
                if(mat_aux[j][i] != 0.0){
                    aux = 1;
                    for( int k = 0; k < tamanio; k++){
                        double temp = mat_aux[i][k];
                        mat_aux[i][k] = mat_aux[j][k];
                        mat_aux[j][k] = temp;
                    }
                }
            }
            if(!aux){
                printf("la matriz no tiene inversa.\n");
                return 1;
            }
        }
        double factor = mat_aux[i][i];
        for(int j = 0; j < tamanio; j++){
            mat_aux[i][j] /= factor;
            matriz_inversa[i][j] /= factor;
        }
        for(int k = 0; k < tamanio; k++){
            if(k != i){
                factor = mat_aux[k][i];
                for(int l = 0; l < tamanio; l++){
                    mat_aux[k][l] -= factor * mat_aux[i][l];
                    matriz_inversa[k][l] -= factor * matriz_inversa[i][l];
                }
            }
        }
    }
    printf("la matriz inversa es:\n");
    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            printf("%0.2f\t", matriz_inversa[i][j]);
        }
        printf("\n\n\n");
    }

    return 0;
}
