/*
The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:
  1! + 4! + 5! = 1 + 24 + 120 = 145
Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are only three such loops that exist:
  169 → 363601 → 1454 → 169
  871 → 45361 → 871
  872 → 45362 → 872
It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,
  69 → 363600 → 1454 → 169 → 363601 (→ 1454)
  78 → 45360 → 871 → 45361 (→ 871)
  540 → 145 (→ 145)
Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number below one million is sixty terms.

How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int factorial(int n){
  int f=1;
  for(int a=n; a>0; a--){
    f*=a;
  }
  return f;
}

int repeating_index(int terms[], int size){
  int repeat = 0;
  bool falsecatch = false;
  for(int i=0; i+1< size; i++){
    for(int j=i+1; j<size; j++){
      if(terms[i] == terms[j]){
        //Check the next terms for periodicity
        for(int k=1; k<size; k++){
          if(terms[i+k] !=  terms[j+k]){
            falsecatch = true;
            break;
          }
        }
        if(falsecatch == false){
          return j+1; //The size of the longest chain containing non repeats
        }
      }
    }
  }
}

int next_factorial_sum(int n){
  int sum=0;
  char num_str[15], x[2];
  int y;
  sprintf(num_str, "%d", n);
  //printf("That string is %s\n", num_str);
  for(int a=0; a<strlen(num_str); a++){
    x[0] = num_str[a];
    sum += factorial(atoi(x));
  }
  //printf("The sum is %d\n", sum);
  return sum;
  //Change the int to string
}
  
int main(int argc, char** argv){
  int size = 100;
  int terms[size];
  for(int i=0; i<1000000; i++){
    memset(terms, 0, size);
    terms[0] = i;
    for(int a=1; a<size; a++){
      terms[a] = next_factorial_sum(terms[a-1]);
    }
  }
  return 0;
}

