
/*
 * The square root of 2 can be written as an infinite continued fraction.
  sqrt(2) = 1/(2+1/(2+1/(2+1/2+ ...
  The infinite continued fraction can be written, √2 = [1;(2)], (2) indicates that 2 repeats 
  ad infinitum. In a similar way, √23 = [4;(1,3,1,8)].

  It turns out that the sequence of partial values of continued fractions for square roots 
  provide the best rational approximations. Let us consider the convergents for √2.
  1+1/2 = 3/2
  1+1/(2+1/2) = 7/5
  etc

  Hence the sequence of the first ten convergents for √2 are:
  1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...

  What is most surprising is that the important mathematical constant,
  e = [2; 1,2,1, 1,4,1, 1,6,1 , ... , 1,2k,1, ...].

  The first ten terms in the sequence of convergents for e are:
  2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...

  The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.

  Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.
*/


#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int ans[2];

int minimum(int p, int q){
  if(p < q){
    return p;
  }else{
    return q;
  }
}

int find_gcd( int p, int q){
  int gcd = 1;
  for(int i=2; i<sqrt(minimum(p,q));i++){
    if(p%i ==0 && q%i==0){
      gcd *= i;
    }
  }
  return gcd;
}

int *add_fractions(int a1, int a2, int b1,int b2){
  int numer= (a1*b2) + (a2*b1);
  int denom = (a2*b2);
  int gcd = find_gcd(numer, denom);
  if (gcd>1){
    numer = numer/gcd; 
    denom = denom/gcd;
  }
  ans[0] = numer;
  ans[1] = denom; 
  return ans;
}

int calculate_e_repeating(){
  for(int i=1; i<100; i++){
    printf("%d,", 1);
    printf("%d,", 2*i);
    printf("%d,", 1);
  }
  printf("\n");
}

void sum_of_numerator_convergent(){
  char numer_char[31];
  sprintf(numer_char, "%ld", ans[0]);
  int sum = 0;
  char n[2];
  for(int a=0; a<strlen(numer_char); a++){
    n[0] = numer_char[a];
    sum += atoi(n);
  }
  printf("sum = %d\n", sum);

}

int main(){
  int numerator_sum = 0; 
  int max_index = 10;
  int nth_convergent;
  int nth= 100;
  nth_convergent = calculate_e_repeating(nth);
  /* TODO: Convert nth_covergent to char and add its integers together */
  sum_of_numerator_convergent();
  return 0;
}
