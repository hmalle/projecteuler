/*
It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?
*/

#include<stdio.h>
#include<stdlib.h>

int ways(int n){
  if(n==2){
    return 1;
  }
  if(n%2==0){
    return (2+ways(n-1));
  }
  return (1+ways(n-1));
}

int main(int argc, char** argv){
  if(argv[1]){
    int n = atoi(argv[1]);
    printf("Ways of %d is %d\n", n, ways(n));
  }else{
    printf("Nothing was done, please provide a number\n");
  }

  return 0;
}

