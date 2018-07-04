
/*
 * The cube, 41063625 (345^3), can be permuted to produce two other cubes: 
 * 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest 
 * cube which has exactly three permutations of its digits which are also cube.
 *
 * Find the smallest cube for which exactly five permutations of its digits are cube.
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

void swap( char* x, char* y){
  char tmp = *x;
  *x = *y;
  *y = tmp;
}

void sort(char * str, int size){
  for(int a=0; a<size; a++){
    for(int b=a+1; b<size; b++){
      if(str[a] > str[b]){
        swap( (str+a), (str+b));
      }
    }
  }
}

bool compare(int a, int b){
  long long a3 = pow(a,3);
  long long b3 = pow(b,3);
  char s_a[30] = "";
  char s_b[30] = "";
  sprintf(s_a, "%lld", a3);
  sprintf(s_b, "%lld", b3);
  sort(s_a, strlen(s_a));
  sort(s_b, strlen(s_b));
  if(strcmp(s_a, s_b) == 0){
    return true;
  }
  return false;
}

int main(){
  for(int a=5; a<10000; a++){
    for(int b=a+1; b<10000; b++){
      if(compare(a,b)){
        for(int c=b+1; c<10000; c++){
          if(compare(b,c)){
            for(int d=c+1; d<10000; d++){
              if(compare(c,d)){
                printf("%d, %d, %d, %d\n", a,b,c, d);
                for(int e=d+1; e<10000; e++){
                  if(compare(d,e))
                    printf("%d, %d , %d, %d, %d\n", a,b,c,d,e);
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
