
/*
  The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating 
  them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 
  1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four 
  primes with this property.

  Find the lowest sum for a set of five primes for which any two primes concatenate to produce 
  another prime.
*/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<gmp.h>
#include<string.h>
#include<assert.h>

void print_primes( int* primes, int size){
  int sum = 0;
  printf("%d:[ ", size);
  for(int a=0; a<size; a++){
    sum += *(primes+a);
    printf("%d, ", *(primes+a));
  }
  printf("] -> sum : %d\n",sum);
}

int isprime(char * s){
  mpz_t n;
  mpz_init_set_str(n, s, 10);
  int status = mpz_probab_prime_p(n, 10);
  mpz_clear(n);
  return status;
}

void join(char* s, int x, int y){
  char a[10]="", b[10] ="";
  sprintf(a,"%d", x);
  sprintf(b,"%d", y);
  strcat(s, a);
  strcat(s, b);
}

int get_next_prime(int p){
  char sp[10]="";
  int max = 10000;
  for(int a=2+p; a<max; a+=2){ 
    if(a>max-2){
      return 0;
    }
    sprintf(sp, "%d", a);
    if(isprime(sp)){
      return a;
    }
  }
  return 0;
}

bool check_primes(int* primes, int size){
  char m[20]="", n[20]="";
  for(int i=0; i<size; i++){
    for(int j=0;j<size; j++){
      if(i==j) continue;
      memset(m,0,20);
      memset(n,0,20);
      join(m, *(primes+i) , *(primes+j) );
      join(n, *(primes+j) , *(primes+i) );
      //printf("%d, %d\n", m, n);
      if(!isprime(m) || !isprime(n)){
        return false;
      }
    }
  }
  return true;
}

void check_starting_with(int p){
  int size=2, max=5, next_prime;
  int ns[max];
  ns[0] = p;
  ns[1] = get_next_prime(p);
  while(size<=max){
    if( check_primes( (int *)&ns, size)){
      if(size > 3){
        print_primes((int*)&ns, size);
      }
      next_prime = get_next_prime(ns[size-1]);
      ns[size] = next_prime;
      size++;
    }else if(next_prime=get_next_prime(ns[size-1]) == 0){
      if(size>1){
        next_prime = get_next_prime(ns[size-2]);
        ns[size-2] = next_prime;
        size-=1;
      }
    } else{
      next_prime = get_next_prime(ns[size-1]);
      ns[size-1] = next_prime;
    }
  }
}

int main(int argc, char** argv){
  char sp[10] = "";
  //TODO: Make this work through all of them
  for(int p=3; p<200; p+=2){
    if(p%2==0 || p%5==0) continue;
    sprintf(sp, "%d", p);
    if(isprime(sp)){
      check_starting_with(p);
    }
  }
  return 0;
}
