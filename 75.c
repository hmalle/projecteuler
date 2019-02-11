
/*
It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.

12 cm: (3,4,5)
24 cm: (6,8,10)
30 cm: (5,12,13)
36 cm: (9,12,15)
40 cm: (8,15,17)
48 cm: (12,16,20)

In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.

120 cm: (30,40,50), (20,48,52), (24,45,51)

Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int triplets_count(int n){
  float aa, bb, cc;
  int count = 0;
  for(int a=0; a<n/2; a++){
    for(int b = a+1; b<n/2; b++){
      for(int c=b+1; c<n/2; c++){
        aa = pow(a,2);
        bb = pow(b,2);
        cc = pow(c,2);
        if(a+b+c == n){
          if( aa+bb == cc ){
            //printf("%2d: (%d, %d, %d)\n", n, a,b,c);
            count++;
          }
        }
      }
    }
  }
  return count;
}

int main(int argc, char** argv){
  //int max = 1500000;
  int max = 1500;
  int one_sided = 0;
  for(int l=12; l<max; l+=2){
    if(triplets_count(l) == 1){
      one_sided++;
    }
  }
  printf("One sided triangles %d\n", one_sided);
  return 0;
}
