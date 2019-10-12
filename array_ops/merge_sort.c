#include<stdio.h>
#include<stdlib.h>
#include "./array_input.h"

int mergeSort(int *, int);
int sort(int *, int);
int merge(int *, int, int *, int);


int mergeSort(int *arr, int size){


    if(size==0){
        printf("Invalid array of length 0\n");
        return -1;
    }

    else if(size==1){
        return 0;
    }

    int count = 0;

    count += sort(arr, size/2);
    count += sort(arr + size/2, size-size/2);
    count += merge(arr, size/2, arr+size/2, size-size/2);  // Count of inversions is outputted by merge() itself

    printf("\nCOUNT = %d\n", count);

    return 0;
}

int sort(int *arr, int size){

    int count = 0;  //  Count of inversions by this iteration of merge()

    if(size!=1){
        count += sort(arr, size/2);
        count += sort(arr + size/2, size-size/2);
    }

    count += merge(arr, size/2, arr+size/2, size-size/2);  

    return count;
}

int merge(int left[], int l, int right[], int r){
    int *temp = malloc(sizeof(int)*(l+r));

    int count=0; // Maintains the count of inversions

    int i=0, j=0, k=0;

    while(j<l&&k<r){

        if(left[j]<right[k]){
            temp[i++] = left[j++];
        }
        
        else {
            temp[i++] = right[k++];
            count+=l-j;  // If an element from right array is being taken, that means it has the smaller number, which is a "problem" in the sense that it must be counted as inversion.
        }
        
    }

    if(j<l){
        while(j<l){
            temp[i++] = left[j++];
        }
    }

    else if(k<r){
        while(k<r){
            temp[i++] = right[k++];
        }
    }


    // Merging is done by above code but now we copy it to 'arr'.
    for(int i=0; i<(l+r); i++){
        *(left+i) = temp[i];
    }

    return count;
}