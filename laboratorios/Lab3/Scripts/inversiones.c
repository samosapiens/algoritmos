
// C program to Count  
// Inversions in an array 
// using Merge Sort 
//#include <bits/stdc++.h> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
int bruteForce(int arr[], int array_size);
int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 

/* This functions sorts the input array and returns the
   number of inversoins in the array*/
int bruteForce(int arr[], int array_size)
{
    int i, j, count;
    count = 0;
    for(i=0; i<array_size; i++)
        for(j=i; j<array_size; j++)
            if(arr[i] > arr[j])
                count++;
    return count;
}

/* This function sorts the input array and returns the 
   number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
    int* temp = (int*)malloc(sizeof(int) * array_size); 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function that sorts the input array and 
  returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and call _mergeSortAndCountInv() 
       for each of the parts */
        mid = (right + left) / 2; 
  
        /* Inversion count will be sum of inversions in left-part, right-part 
      and number of inversions in merging */
        inv_count = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
  
/* This funt merges two sorted arrays and returns inversion count in 
   the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            /*this is tricky -- see above explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray 
   (if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray 
   (if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  
/* Driver program to test above functions */
int main(int argv, char** args) 
{ 
    int *A, *A_inv;
    int i, count, N=100000;
    char *line = NULL, *pch = NULL;
    size_t len = 0;
    time_t begin, end;

    // Allocate memory for arrays
    A = (int *) malloc(N*sizeof(int));
    A_inv = (int *) malloc(N*sizeof(int));

    // Read input file
    FILE *file = fopen("./input.txt", "r");
    getline(&line, &len, file); // Header
    getline(&line, &len, file); // Array
    pch = strtok (line," ,.-");
    while ((pch != NULL) && (i < N)){ 
        sscanf(pch, "%d", &(A[i]));
        pch = strtok (NULL, " ");
        i++;
    }
    fclose(file);

    // Sort input array
    printf("Sort input array:\n");
    begin = clock();
    count = bruteForce(A, N);
    end = clock();
    printf(" - Brute Force = %f [s]\n", (float) (end-begin)/CLOCKS_PER_SEC);
    begin = clock();
    count = mergeSort(A, N);
    end = clock();
    printf(" - Merge Sort = %f [s]\n", (float) (end-begin)/CLOCKS_PER_SEC);
    
    // Count sorted array
    printf("\nCount sorted array:\n");
    begin = clock();
    count = bruteForce(A, N);
    end = clock();
    printf(" - Brute Force = %f [s]\n", (float) (end-begin)/CLOCKS_PER_SEC);
    begin = clock();
    count = mergeSort(A, N);
    end = clock();
    printf(" - Merge Sort = %f [s]\n", (float) (end-begin)/CLOCKS_PER_SEC);

    // Count inverted array
    for(i=0; i<N; i++)
        A_inv[i] = A[N-i-1];
    printf("\nCount inverted array:\n");
    begin = clock();
    count = bruteForce(A, N);
    end = clock();
    printf(" - Brute Force = %f [s]\n", (float) (end-begin)/CLOCKS_PER_SEC);
    begin = clock();
    count = mergeSort(A, N);
    end = clock();
    printf(" - Merge Sort = %f [s]\n", (float) (end-begin)/CLOCKS_PER_SEC);
    return 0; 
} 
