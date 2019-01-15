/*
 * Euler's Totient function, φ(n) [sometimes called the phi function], is used to 
 * determine the number of numbers less than n which are relatively prime to n. 
 * For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively 
 * prime to nine, φ(9)=6.
 *  It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

 * Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
*/


#include<stdio.h>
#include<stdbool.h>

bool coprime(int x, int n){
  if( x%2==0 && n%2==0){
    return false;
  }else{
    for(int a=3; a<=x&& a<n; a+=2){
      if(x%a==0 && n%a==0){
        return false;
      }
    }
  }
  return true;
}

float get_totient_ratio(int n){
  float totient=1.0;  //To account for 1
  for(int a=2; a<n; a++){
    if(coprime(a,n)){
      totient+=1;
    }
  }
  //printf("n, tot = ( %d, %f)\n", n, totient);
  return n/totient;
}

int main(){
  printf("totient maximum\n");
  int max = 10000;
  float max_totient_ratio=0;
  float totient_ratio=0;
  int has_max = 1;
  for(int a=2; a<max; a++){
    totient_ratio = get_totient_ratio(a);
    if(max_totient_ratio<totient_ratio){
      max_totient_ratio = totient_ratio;
      has_max = a;
    }
  }
  printf("The number is %d\n", has_max);
  
  return 0;
}
