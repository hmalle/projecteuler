
/* It is possible to show that the square root of two can be expressed as an infinte continued fraction
 * (2^0.5) = 1+ 1/(2+1/(2+1/2+1/(2+...))) = 1.414213...
 * By expanding this for the first 4 iterations, we get:
 * 1+1/2 = 3/2 = 1.5
 * 1+1/(2+1/2) = 7/4 = 1.4
 * 1+1/(2+1/(2+1/2)) = 17/12 = 1.41666...
 *
 * In the first one-thousand expanseions, how many fractions contain a numerator whth more digits thatn demoninator?
 */

/* After analysis I realized that the 1+x will be 1+(1/2), 1+(2/5) , 1+5/12 ...
 * ie 1/2, 2/5, 5/12, 12/29, 92/70,...
 * numerator+1 = denominator
 * denomiator+1 = 2*denominator+numerator */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gmp.h>
#include<stdbool.h>

bool calculate( mpz_t  numer, mpz_t denom){
  bool state = false;
  char numerator[50];
  char denominator[50];
  memset(numerator, 0, 50);
  memset(denominator, 0, 50);
  mpz_t ans_numer;
  mpz_init(ans_numer);
  mpz_set(ans_numer,denom);
  mpz_add(ans_numer,ans_numer,numer); 
  gmp_sprintf(numerator, "%Zd",ans_numer);
  gmp_sprintf(denominator, "%Zd",denom);
  if(strlen(numerator) > strlen(denominator)){
    printf("%s / %s\n", numerator,denominator);
    state = true;
  }
  mpz_clear(ans_numer);
  return state;
}

int main(){
  int expansion_index = 1000;
  mpz_t numer, denom, tmp;
  mpz_init(numer); mpz_init(denom); mpz_init(tmp);
  mpz_set_ui(numer,1); mpz_set_ui(denom,2);
  unsigned short count = 0;

  for(int a=0; a< expansion_index; a++){
    if(calculate(numer, denom) > 0){
      count++;
    } 
    mpz_set(tmp, denom);
    mpz_mul_si(denom, denom, 2);
    mpz_add(denom, denom, numer);
    mpz_set(numer, tmp);
  }
  printf("count : %d\n", count);
}
