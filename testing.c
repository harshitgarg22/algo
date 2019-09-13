/* #include "./merge_sort.h" */
/* #include "./array_input.h" */
// #include "./strassan_matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include "./karatsuba_multiply.h"

/* #define MAX_DIGIT 64 */

int main(){
  long double x, y;

  printf("Enter the two numbers: ");
  scanf("%llf", &x);
  scanf("%llf", &y);

  printf("%llf\n", karatsuba_multiply(x,y));


}
/*   char *x = malloc(sizeof(char)*(MAX_DIGIT+1)); */
/*   char *y = malloc(sizeof(char)*(MAX_DIGIT+1)); */

/*   printf("Enter the two numbers: "); */
/*   scanf("%s", x); */
/*   scanf("%s", y); */

/*   printf("%s", karatsuba_multiply_big(x,y)); */

// Code for multiplication for small numbers


/* // Code for mergeSort */

/*     int size; */

/*     size = 8; */

/*     int *arr = malloc(sizeof(int)*size); */
/*     array_input(arr, size); */

/*     mergeSort(arr, size); */

/*     for(int i=0; i<size; i++){ */
/*         printf("%d ", arr[i]); */
/*     } */

/*     putchar('\n'); */

/* } */

//  Code for strassan_matrix.c

    // int n;
    
    // n = 2;

    // int A[10][10], B[10][10], C[10][10];

    // // int *A[n], *B[n], *C[n];
    // // int *A = (void *)malloc(sizeof(int)*n*n);
    // // int *B = (int *)malloc(sizeof(int)*n*n);
    // // int *C = (int *)malloc(sizeof(int)*n*n);


    // for(int i=0; i<n; i++){
    //     // A[i] = malloc(sizeof(int)*n);
    //     // B[i] = malloc(sizeof(int)*n);
    //     for(int j=0; j<n; j++){
            
    //         printf("A[%d][%d] = ", i, j);
    //         scanf("%d", &A[i][j]);

    //         printf("B[%d][%d] = ", i, j);
    //         scanf("%d", &B[i][j]);
    //     }
    // }

    // matrix_multiply(A,B,n,C);

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%d ", C[i][j]);
    //     }
    //     putchar('\n');
    // }

    // return 0;
