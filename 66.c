
/*
   Consider quadratic Diophantine equations of the form:
 x^2 – Dy^2 = 1
 
 For example, when D=13, the minimal solution in x is 6492 – 13×1802 = 1.
 
 It can be assumed that there are no solutions in positive integers when D is square.
 
 By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:
 
 3^2 – 2×2^2 = 1
 2^2 – 3×1^2 = 1
 9^2 – 5×4^2 = 1
 5^2 – 6×2^2 = 1
 8^2 – 7×3^2 = 1
 
 Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.
 Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.
*/

/* TODO: Use Continued Fractions to Solve this one */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

int get_minimal_solution(int D){
  double x2=0, sq_x2;
  int x2_int;
  for(int y=1; y<10000000; y++){
    x2 = 1+(D*pow(y,2));
    //printf("%f\n", x2);
    assert(x2>0);
    sq_x2 = sqrt(x2);
    x2_int = sq_x2;
    if(x2_int == sq_x2){
      //printf("%d^2-%d*%d^2=1\n", x2_int,D,y);
      return x2_int;
    }
  }
  return 0;
}

int main(){
  int max=1000, largest_x=0, D_max, sln;
  for(int D=2; D<max; D++){
    int sln = get_minimal_solution(D);
    if(sln > largest_x){
      largest_x = sln;
      D_max = D;
      printf("%d^2-%d*y^2=1\n", sln,D);
    }
  }
}
