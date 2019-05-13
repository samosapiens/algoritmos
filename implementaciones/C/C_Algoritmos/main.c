#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000
#define NAME_PERSONA "persona %d"

/*
GLOBAL VARS
*/
FILE *file;

/*--------------------------------------------
Persona:
--------------------------------------------*/
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

/*--------------------------------------------
Insertion Sort:
--------------------------------------------*/

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

void testInsertionSort(int N)
{
    int n, i;
    double elapsed;
    time_t begin, end;
    int rand_1, rand_2;
    Persona *personas;
    printf("Test Insertion Sort:\n");
    // Realizar tests desde orden 1 hasta orden N
    for(n=1; n<=N; n++)
    {
        printf("\t n=%d\n", n);
        // Generar arreglo de personas
        personas = (Persona *) malloc(n*sizeof(Persona));
        for(i=0; i<n; i++)
            personas[i] = initPersona(i+1);
        // Mezclar a las personas aleatoriamente
        for(i=0; i<n-1; i++) {
            rand_1 = (rand()%(n-1));
            rand_2 = (rand()%(n-1));
            swapPersonas(personas, rand_1, rand_2);
        }
        // Make test
        begin = clock();
        insertionSort(personas, n);
        end = clock();
        elapsed = (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC;
        fprintf(file, "%f\t", elapsed);
    }
    fprintf(file, "\n");
    // Liberar memoria del arreglo
    free(personas);
}

// Invariante es el arreglo y con qué pregunto si el valor está o no está

/*--------------------------------------------
Merge Sort:
--------------------------------------------*/

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

void testMergeSort(int N)
{
    int n, i;
    double elapsed;
    time_t begin, end;
    int rand_1, rand_2;
    Persona *personas;
    printf("Test Merge Sort:\n");
    // Realizar tests desde orden 1 hasta orden N
    for(n=1; n<=N; n++)
    {
        printf("\t n=%d\n", n);
        // Generar arreglo de personas
        personas = (Persona *) malloc(n*sizeof(Persona));
        for(i=0; i<n; i++)
            personas[i] = initPersona(i+1);
        // Mezclar a las personas aleatoriamente
        for(i=0; i<n-1; i++) {
            rand_1 = (rand()%(n-1));
            rand_2 = (rand()%(n-1));
            swapPersonas(personas, rand_1, rand_2);
        }
        // Make test
        begin = clock();
        mergeSort(personas, 0, n-1);
        end = clock();
        elapsed = (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC;
        fprintf(file, "%f\t", elapsed);
    }
    fprintf(file, "\n");
    // Liberar memoria del arreglo
    free(personas);
}

/*--------------------------------------------
Main:
--------------------------------------------*/

int main()
{
    printf("Test Algorithms!\n");
    // should only be called once
    srand(time(NULL));
    // Open data file
    file = fopen("./data.txt", "w");
    // Insertion Sort
    testInsertionSort(1000);
    // Merge Sort
    testMergeSort(1000);
    // End of execution
    fclose(file);
    return 0;
}
