#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000
#define NAME_PERSONA "persona %d"

typedef struct Persona {
    int edad;
    char *nombre;
} Persona;

Persona initPersona(int edad)
{
    char *name;
    Persona persona;
    name = malloc(strlen(NAME_PERSONA) + 10);
    sprintf(name, NAME_PERSONA, edad);
    persona.edad = edad;
    persona.nombre = strdup(name);
    return persona;
}

void swapPersonas(Persona *personas, int i, int j) {
    Persona key = personas[i];
    personas[i] = personas[j];
    personas[j] = key;
}

void printPersonas(Persona *personas, int N) {
    int n;
    for(n=0; n<N; n++)
        printf("(%s, %d)", personas[n].nombre, personas[n].edad);
    printf("\n");
}

void insertionSort(Persona *personas, int N) {
    int i, j;
    Persona key;
    for(i=1; i<N; i++) {
        j = i-1;
        key = personas[i];
        while((j>=0) && (key.edad<personas[j].edad)) {
            personas[j+1] = personas[j];
            j--;
        }
        personas[j+1] = key;
    }
}

void Merge(Persona *A, int p, int q, int r) {
    int n1, n2;
    int i, j, k;
    Persona *L, *R;

    n1 = q-p+1;
    L = (Persona *) malloc((n1 + 1)*sizeof(Persona));
    for(i=0; i<n1; i++)
        L[i] = A[p+i];
    L[i] = initPersona(INF);

    n2 = r-q;
    R = (Persona *) malloc((n2 + 1)*sizeof(Persona));
    for(i=0; i<n2; i++)
        R[i] = A[q+i+1];
    R[i] = initPersona(INF);

    i = 0;
    j = 0;
    for(k=p; k<=r; k++) {
        if(L[i].edad <= R[j].edad)
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Persona *A, int p, int r) {
    int q;
    if(p<r) {
        q = floor((p+r)/2);
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

int main()
{
    int N, n, rand_1, rand_2;
    Persona *personas;

    srand(time(NULL));      // should only be called once

    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &N);

    personas = (Persona *) malloc(N*sizeof(Persona));
    for(n=0; n<N; n++)
        personas[n] = initPersona(n+1);

    for(n=0; n<N; n++) {
        rand_1 = (rand()%(N-1));
        rand_2 = (rand()%(N-1));
        while(rand_1 == rand_2) {
            rand_1 = (rand()%(N-1));
            rand_2 = (rand()%(N-1));
        }
        swapPersonas(personas, rand_1, rand_2);
    }
    printPersonas(personas, N);

    //insertionSort(personas, N);
    mergeSort(personas, 0, N-1);

    printPersonas(personas, N);


// Invariante es el arreglo y con qué pregunto si el valor está o no está
    free(personas);
    return 0;
}
