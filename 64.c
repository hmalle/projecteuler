/*
 All square roots are periodic when written as continued fractions and can be written in the form:
  sqrt(N) = a0 + 1/( a1+ 1/(a2+ 1/(a3+1/(a4+ ....))))
  For example, let us consider sqrt(23):
    sqrt(23) = 4 + sqrt(23) -4 = 4 + 1/1/(sqrt(23)-4) 
             = 4 + 1/(sqrt(23) -3)/7
  If we continue we would get the following expansion:
    sqrt(23) = 4 + 1/(1 + 1/(3+(1/(1+1/(8+... 
  The process can be summarised as follows:
  *How many continued fractions for N ≤ 10000 have an odd period?
 */

#include<stdlib.h>
#include<stdio.h>
