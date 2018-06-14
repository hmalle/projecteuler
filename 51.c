/*
 * By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible
 * values: 13, 23, 43, 53, 73, and 83, are all prime.
 *
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the
 * first example having seven primes among the ten generated numbers, yielding the family: 56003,
 * 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this
 * family, is the smallest prime with this property.
 *
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits)
 * with the same digit, is part of an eight prime value family.
 *
 */

//Bruteforce approach; //There must be a more general method instead of multiple for loops

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

bool isprime( int num) {
  if ( num< 2 ) return false;
  if (num ==2 || num==3 )
    return true;
  if (num%2==0 || num%3==0)
    return false;
  if (num %6 ==1 || num%6==5 ){
    int sx= 6;
    for (int i=1; (6*i-1)<=sqrt(num); i++){
      sx = 6*i;
      if ( num%(sx-1)==0 || num%(sx+1)==0 )
        return false;
    }
    return true;
  }
}

bool candidate(int n){
  //To filter out the primes starting with 0,1 or 2
  char s[10];
  sprintf(s, "%d", n);
  int len = strlen(s) -1;
  for(short a=0; a<len; a++){
    if(s[a]=='0' || s[a]=='1'|| s[a]=='2'){
      return true;
    }
  }
  return false;
}

int prime_family(int n){
  char s[10];
  sprintf(s,"%d",n);
  int count = 1;
  int len = strlen(s)-1;
  for(short a=0;a<len; a++){
    for(short b=a+1;b<len; b++){
      for(short c=b+1;c<len; c++){
        if(s[a] == s[b] && s[a]==s[c] && s[a]<='2'){
          for( ;s[a]<'9'; ){
            s[a]= s[b] = s[c] = (s[a]+1);
            if(isprime(atoi(s))){
              count++;
            }
          }
        }
      }
    }
  }
  return count;
}

int main(){
  int max = 100000000;
  short count=0;
  for(int index=10;index<max; index++){
    if(isprime(index)&& candidate(index)){
      count = prime_family(index);
      if(count==8){
        printf("That first prime is: %d\n", index);
        break;
      }
    }
  }
  printf("\n");
  return 0;
}

