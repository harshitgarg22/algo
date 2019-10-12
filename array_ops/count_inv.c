#include<stdio.h>
#include "./array_input.h"

int count_inv(int arr[], int size){

}

int main(){
    int size;

    size=7;

    int arr[] = malloc(sizeof(int)*size);

    array_input(arr, size);

    int count_inv = count_inv(arr, size);
}