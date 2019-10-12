#include<stdio.h>
#include "../../../array_ops/merge_sort.h"
#include<stdlib.h>

int main(){
  FILE *IntArr = fopen("./IntegerArray.txt", "r");

  int *arr = malloc(sizeof(int)*100000);

  for(int i=0; i<100000; ++i){
    fscanf(IntArr, "%d\n", &arr[i]);
  }

  mergeSort(arr, 100000);
  return 0;
}
