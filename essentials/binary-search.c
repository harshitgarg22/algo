

int binary_search(int *A, int size,  int num){

    if(A[size/2]>num){
        binary_search(A, size/2, num);
    }
    
    else if(A[size/2]<num){
        binary_search(A, size-size/2, num);
    }
    else if(A[size/2]==num){
        return 1;
    }
    
    return 0;

}