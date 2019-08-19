#include<stdio.h>

void array_input(int *arr, int size){
    
    printf("Enter the %d elements of the array: \n", size);
    
    for(int i=0; i<size; i++){
        printf("arr[%d]: ", i);
        scanf("%d", arr+i);
    }

}