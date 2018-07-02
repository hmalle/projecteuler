
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

int permutable_cubes(char * cube, int size){
  char tmp, s_cube[20] = "";
  int num, count=1;
  double ans;
  strcpy(s_cube, cube);
  for(int a=0; a<size; a++){
    for(int b=0; b<size; b++){
      strcpy( s_cube, cube);
      if(a==b) continue;
      tmp = s_cube[a];
      s_cube[a] = s_cube[b];
      s_cube[b] = tmp;
      num = atoi(s_cube);
      ans = pow(num, 0.3333333333333);
        printf("%s, %f\n", s_cube, ans);
      if( ceil(ans) == ans ){
        count++;
      }
    }
  }
  return count;
}

int main(void){
  int count = 0, cube = 0;
  char s_cube[20] = "";
  for(int a=5; a<6; a++){
    cube = (int)pow(a,3);
    sprintf(s_cube, "%d", cube);
    count = permutable_cubes(s_cube, strlen(s_cube));
    if(count > 1){
      printf("%d^3 -> %f\n", a, pow(a,3));
    }
  }
  return 0;
}
