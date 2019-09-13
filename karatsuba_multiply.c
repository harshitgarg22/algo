#include<stdio.h>
#include "./no_digits.h"
#include<math.h>
#include<string.h>
#include<stdlib.h>

char *karatsuba_multiply_big(char *x, char *y){

  unsigned long int n = strlen(x);


  if(n==1){
    char *mul = malloc(sizeof(char)*3);
    char *ptr;
    sprintf(mul, "%ld", strtol(x, &ptr, 10)*strtol(y, &ptr, 10));
    return mul;
  }

  return "Hullo";
}


long double karatsuba_multiply(long double x, long double y){

  // basic motive is
  // x = b*10^n/2 + a; y = d*10^n/2 + c

  long double sum1, sum2, sum3;

  unsigned long int n = no_digits(x);

  /* printf("\n%d\n", n); */

  if(n==1){
    return x*y;
  }

  if(n%2==1){
    n++;
  }

  long double a = fmod(x,pow(10, n/2)), b = floor(x/pow(10, n/2)); // x = [b][a]
  long double c = fmod(y,pow(10, n/2)), d = floor(y/pow(10, n/2)); // y = [d][c]

  /* printf("\n%d %d %d %d\n", a, b, c, d); */

  sum1 = karatsuba_multiply(a, c); // ac
  sum2 = karatsuba_multiply(b, d); // bd
  sum3 = karatsuba_multiply(a+b, c+d); // (a+b)*(c+d)

  /* printf("\n%d %d %d\n", sum1, sum2, sum3); */

  return sum1 + (sum3-sum1-sum2)*pow(10, n/2) + sum2*pow(10,n); // ac + ((a+b)(c+d)-ac-bd)*10^n/2 + bd*10^n

}
