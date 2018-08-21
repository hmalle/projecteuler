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
#include<stdbool.h>
#include<string.h>

int get_periodicity( int* coeffs, int size){
  int period = 0;
  bool found_period = false;
  for(int a=0; a<size; a++){
    for(int b=a+1; b<size; b++){
      if(coeffs[a] == coeffs[b]){
        found_period = true;
        for(int offset=1; b+offset< size; offset++){
          if(coeffs[a+offset] != coeffs[b+offset]){
            found_period = false;
            break;
          }
        }
        if(found_period){
          period = b-a;
          goto end; //Jump off out of this loop
        }
      }
    }
  }
  end:
  return period;
}

int periodicity( int n ){
  printf("%4d= ", n);
  if(sqrt(n)== floor(sqrt(n))){
    printf("0\n");
    return 0;
  }
  int size = 500;
  int coeffs[size];
  memset(coeffs, 0, size);
  int period = 0;
  int m=0;
  int d=1;
  int a=floor(sqrt(n));
  for(int index=0;index<size;index++){
    m = d*a - m;
    d = (n - pow(m,2))/d;
    a = floor((sqrt(n)+m)/d);
    //printf("%d,",a);
    coeffs[index] = a;
  }
  period = get_periodicity( &coeffs[0], size);
  printf(": Period :%d\n",period);
  return period;
}

int main(){
  int N=10000;
  int odd_period = 0;
  int period=0;
  for(int n=2; n<=N; n++){
    period = periodicity(n);
    if(period%2== 1){
      odd_period++;
    }
  }
  printf("Odd Period(N<%d) = %d\n", N, odd_period);
  return 0;
}

