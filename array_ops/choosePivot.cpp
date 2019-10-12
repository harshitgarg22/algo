#include<cstdlib>
#include<ctime>

/* The following methods can be used (based on the value of the `method` variable):-

   1. Always first element
   2. Random based on time and srand
   3.
   4.

*/

unsigned long int choosePivot(unsigned long int size, int method=2){

  if(method==1){
    return 0;
  }

  else if(method==2){
    srand((unsigned)time(0));

    unsigned long int pivot=0;
    pivot = (rand()%size);

    return pivot;
  }

  return 0;
}
