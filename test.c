
#include<stdio.h>
#include<stdbool.h>

bool coprime(int x, int y){
  if( x%2==0 && y%2==0){
    return false;
  }else{
    for(int a=3; a<x&& a<y; a++){
      if(x%a==0 && y%a==0){
        return false;
      }
    }
  }
  return true;
}

int get_totient(int n){
  int totient=0;
  for(int a=0; a<n; a++){
    if(coprime(a,n)){
      totient++;
    }
  }
  return totient;
}

int main(){
  printf("totient maximum\n");
  //int max = 1000000;
  int max = 10;
  int max_totient = 1;
  int totient;
  int has_max = 1;
  for(int a=0; a<max;a++){
    totient = get_totient(a);
    if(max_totient< totient){
      max_totient = totient;
      has_max = a;
    }
  }
  printf("The number is %d\n", has_max);
  
  return 0;
}
