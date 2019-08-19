#include<stdio.h>
#include<stdlib.h>

int matrix_multiply(int A[][10], int B[][10], int n, int C[][10]){
    
    if(n!=1){
        matrix_multiply(A, B, n/2, C);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                C[i][j] += A[k][j]*B[i][k];
            }
        }
    }

}
