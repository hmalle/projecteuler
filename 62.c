
/*
 * The cube, 41063625 (345^3), can be permuted to produce two other cubes: 
 * 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest 
 * cube which has exactly three permutations of its digits which are also cube.
 *
 * Find the smallest cube for which exactly five permutations of its digits are cube.
 */

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

void swap( char* x, char* y){
  char tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void permute(char * cube, int l, int r){
  if(l==r){
    int num = atoi(cube);
    double ans = pow(num, 0.333333333);
    if(fabs(round(ans)-ans) <= 0.000005f){
      printf("%d, %f=%f\n", num, ans, round(ans));
    }
  }else{
    for(int a=l; a<=r; a++){
      swap((cube+l), (cube+a));
      permute(cube, l+1, r);
      swap((cube+l), (cube+a));
    }
  }
}

int main(void){
  int cube = 0;
  char s_cube[20] = "";
  for(int a=345; a<346; a++){
    cube = (int)pow(a,3);
    sprintf(s_cube, "%d", cube);
    permute(s_cube, 0, strlen(s_cube)-1);
  }
  return 0;
}
