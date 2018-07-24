/*
 All square roots are periodic when written as continued fractions and can be written in the form:
  sqrt(N) = a0 + 1/( a1+ 1/(a2+ 1/(a3+1/(a4+ ....))))
  For example, let us consider sqrt(23):
    sqrt(23) = 4 + sqrt(23) -4 = 4 + 1/1/(sqrt(23)-4) 
             = 4 + 1/(sqrt(23) -3)/7
  If we continue we would get the following expansion:
    sqrt(23) = 4 + 1/(1 + 1/(3+(1/(1+1/(8+... 
  The process can be summarised as follows:
  *How many continued fractions for N ≤ 10000 have an odd period?
 */

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int * coefficients( int n ){
  int a=n, b=sqrt(n), c=1; //numerator
  int x=1, y=0;   //denominator
  int coeff;
  //c(a+b)/(x+y);
  for(int index=0; index<2; index++){
    printf("a%d: %d(%d+%d)/(%d-%d)\n", index, c,a,b,x,y);
    //Reciprocate
    x = a; y = b;
    //Rationalize the denominator
    x = a; b = y;
    x = x-pow(y,2); y = 0;
    printf("a%d: %d(%d-%d)/(%d-%d)\n", index, c,a,b,x,y);
    if(a-y >1){
      
    }else{

    }
    printf("\n\n");
  }
  return 0;
}

int main(){
  for(int a=23; a<24; a++){
    coefficients(a);
  }
  return 0;
}
