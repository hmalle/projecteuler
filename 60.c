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

void print_primes(int* primes, int size){
  printf("[");
  for(int a=0;a<size;a++){
    printf("%d, ", *(primes+a));
  }
  printf("]\n");
}

int isprime(int i){
  mpz_t n;
  mpz_init_set_ui(n, i);
  int status = mpz_probab_prime_p(n, 10);
  mpz_clear(n);
  return status;
}

int join( int x, int y){
  char a[10]="", b[10] ="";
  sprintf(a,"%d", x);
  sprintf(b,"%d", y);
  strcat(a, b);
  //printf("%s\n", a);
  return atoi(a);
}

void print_sum( int* primes, int size){
  int sum = 0;
  for(int a=0; a<size; a++){
    sum += *(primes+a);
  }
  printf("sum : %d\n",sum);
}

bool assign_next_prime(int* primes, int index){
  //printf("that primes is: %d\n", *(primes+index));
  for(int a=2+*(primes+index);a<1000000; a+=2){ //TODO: limit that a
    if(isprime(a)){
      *(primes+index) = a;
      return true;
    }
  }
  return false;
}

int check_primes(int* primes, int size){
  int n;
  for(int i=0; i<size; i++){
    for(int j=0;j<size; j++){
      if(i==j) continue;
      n = join( *(primes+i) , *(primes+j) );
      if( !isprime(n) &&j>i ){
        return j;
      }
      if(!isprime(n)){
        return j-1;
      }
    }
  }
  return -1;
}

int main(int argc, char** argv)
{
  if(argc!=2){
    printf("Enter the correct number of arguments\n");
    exit(0);
  }
  int index, size=atoi(argv[1]);
  bool found = false;
  int primes[size];
  //Get the first few primes as needed by the program
  for(int n=3,p=0; p<size; n+=2){
    if(isprime(n)){
      primes[p]= n;
      p++;
    }
  }

  for(int a=0;!found; a++){
    index = check_primes( primes, size);
    printf("checking:");
    print_primes( (int*)&primes, size);
    if(index == -1){
      print_primes((int*)&primes,size);
      found = true;
    }else{
      assign_next_prime((int*)&primes, index);
    }
  }
  print_sum( (int*)&primes, size);
  return 0;
}
