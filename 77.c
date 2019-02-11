
/*
It is possible to write ten as the sum of primes in exactly five different ways:

7 + 3
5 + 5
5 + 3 + 2
3 + 3 + 2 + 2
2 + 2 + 2 + 2 + 2

What is the first value which can be written as the sum of primes in over five thousand different ways?
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char** argv){
  if(argc < 2){
    printf("Please enter the number to check for?\n");
    exit(0);
  }
  printf("argv[1] = %s\n", argv[1]);
  for(int i=0; i<strlen(argv[1]); i++){
    if(!isdigit(argv[1][i])){
      printf("Please enter digits only");
      exit(0);
    }
  }
  
}

