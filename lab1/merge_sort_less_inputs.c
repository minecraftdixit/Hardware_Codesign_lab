 // Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
  
        merge(arr, l, m, r);
    }
}
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
  
/* Driver program to test above functions */
int main()
{
    int n;

    // Ask the user how many random inputs they want
    printf("Enter the number of random inputs: ");
    scanf("%d", &n);

    // Generate random array with 'n' elements
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // You can adjust the range of random numbers as needed
    }

    printf("Generated random array is \n");
    printArray(arr, n);

    // Measure the time taken by the sorting algorithm
    clock_t start_time = clock();

    mergeSort(arr, 0, n - 1);

    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nSorted array is \n");
    printArray(arr, n);

    printf("\nTime taken: %f seconds\n", cpu_time_used);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}