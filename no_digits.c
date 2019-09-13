#include<math.h>

unsigned long int no_digits(long double num){
  if(num==0)
    return 1;
  else
    return floor(log10(num)+1);
}
