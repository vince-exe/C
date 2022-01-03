/*
Algoritmo Ricerca Binaria

È possibile usare questo algoritmo solo quando si ha un array ORDINATO
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int prendiSize();
void caricaArrayCrescente(int* arr, int dim);
int prendiValore(int min, int max);
int ricercaBinaria(int* arr, int dim, int valore);
void stampaArray(int* arr, int dim);

int main() {
    int dim = prendiSize(1, INT_MAX);

    int* arr = (int*) malloc(sizeof(int) * dim);
    caricaArrayCrescente(arr, dim);

    int val = prendiValore(arr[0], arr[dim - 1]);
    int posVal = ricercaBinaria(arr, dim, val);

    printf("\nIl valore %d si trova nella posizione %d dell'array :-)\n", val, ricercaBinaria(arr, dim, val));
    stampaArray(arr, dim);

    free(arr);
    return 0;
}

int prendiSize(int min, int max) {
    int dim;
    do {
        printf("\nInserire il numero di elementi per l'array (> 0): ");
        scanf("%d", &dim);      
    } while (dim < min || dim > max);

    return dim;
}

void caricaArrayCrescente(int* arr, int dim) {
    int i, temp = INT_MIN;

    for(i = 0; i < dim; i++) {
        do {
            printf("\nInserire un numero (crescente): ");
            scanf("%d", &arr[i]);

            if(temp < arr[i])
                temp = arr[i];

        } while(temp > arr[i]);
    }
}

int prendiValore(int min, int max) {
    int val;
    do {
        printf("\nInserire il valore da trovare (min: %d / max: %d): ", min, max);
        scanf("%d", &val);
    } while (val < min || val > max);
    
    return val;
}

int ricercaBinaria(int* arr, int dim, int valore) {
    int sx = 0, dx = dim - 1, md = 0;

    while(sx <= dx) {
        md = (sx + dx) / 2;
        if(arr[md] == valore) return md + 1;
        else if(arr[md] < valore) sx = md + 1;
        else dx = md - 1;
    }
}

void stampaArray(int* arr, int dim) {
    int i;
    for(i = 0; i < dim; i++) 
        printf("\nPos %d  equivale a: %d\n", i + 1, arr[i]);
}