#include<stdio.h>

int main(int argc, char *argv[]){
    
    char square[5][5];

    for(int i=0; i<5; i++){
        for(int j=1; j<=5; j++){
            square[i][j-1] = (char)(64+i*5+j);
        }
    }

    square[0][0];
    printf("Hi\n");

    int input[100];

    int i=0;

    do {
        printf("\n%d\n", i);
        scanf("%d", &input[i]);
        
    }while(input[i++]);
   

    return 0;
}
