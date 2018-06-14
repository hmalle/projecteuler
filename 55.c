
/* Project Euler 55 
 * If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
 * Not all numbers produce palindromes so quickly. For example,
 * 349 + 943 = 1292,
 * 1292 + 2921 = 4213
 * 4213 + 3124 = 7337
 * That is, 349 took three iterations to arrive at a palindrome.
 * Although no one has proved it yet, it is thought that some numbers, like 196, never produce 
 * a palindrome. A number that never forms a palindrome through the reverse and add process is 
 * called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose 
 * of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition 
 * you are given that for every number below ten-thousand, it will either (i) become a palindrome 
 * in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has 
 * managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to 
 * require over fifty iterations before producing a palindrome: 
 * 4668731596684224866951378664 (53 iterations, 28-digits).
 * Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first 
 * example is 4994.
 * How many Lychrel numbers are there below ten-thousand?
 * NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature 
 * of Lychrel numbers.
 */

//gcc -o 55 55.c -lgmp to compile the code using gmp library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <gmp.h>

bool palindrome(char * num){
  int len = strlen(num);
  for (int j=0; j<len; j++){
    if(num[j] != num[strlen(num)-1-j]){
      return false;
    }
  }
  return true;
}

void reverse(char * str){
  int len = strlen(str);
  char tmp;
  for(int a=0;a<len/2;a++){
    tmp=str[a];
    str[a] = str[len-1-a];
    str[len-1-a] = tmp;
  }
}

bool lychrel(int num){
  char s[50];
  mpz_t rans, ans;
  mpz_init(rans); mpz_init(ans);
  mpz_set_ui(rans,0);
  mpz_set_ui(ans,num);
  int a;
  for(a=1; a<50; a++){
    gmp_sprintf(s, "%Zd",ans);
    //printf("num: %s: ",s);
    reverse(s);
    int flag = mpz_set_str(rans,s,10);
    //printf("rev_num:%s\n",s);
    mpz_add(ans,ans,rans);
    char ans_str[50];
    gmp_sprintf(ans_str,"%Zd", ans);
    if(palindrome(ans_str)){
      mpz_clear(ans);
      mpz_clear(rans);
      return false;
    }
  }
  mpz_clear(ans);
  mpz_clear(rans);
  return true;
}

int main(){
  int count = 0;
  int max = 10000;
  printf("Lychrel Numbers below %d = \n[", max);
  for(int num=1; num<max; num++){
    if(lychrel(num)){
      printf("%d, ", num);
      count++;
    }
  }
  printf("]\n");
  printf("Total Count : %d\n", count);
  return 0;
}
