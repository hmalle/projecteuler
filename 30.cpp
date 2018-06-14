/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 14 + 64 + 34 + 44
    8208 = 84 + 24 + 04 + 84
    9474 = 94 + 44 + 74 + 44

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

// PAWNED LIKE EVERY OTHER,  (tho u have to limit the program maximum number to visit) 

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

char* itoa(int value, char* result, int base) {
                // check that the base if valid
                if (base < 2 || base > 36) { *result = '\0'; return result; }
                char* ptr = result, *ptr1 = result, tmp_char;
                int tmp_value;
                do {
                        tmp_value = value; value /= base;
                        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
                } while ( value );
                // Apply negative sign
                if (tmp_value < 0) *ptr++ = '-';
                *ptr-- = '\0';
                while(ptr1 < ptr) {
                        tmp_char = *ptr;
                        *ptr--= *ptr1;
                        *ptr1++ = tmp_char;
                }
                return result;
        }


bool crack ( int n  , int pw){
	char num[10];
	itoa (n , num , 10); 
	int sum=0 , i, 
	len=strlen(num);
	for (int j=0; j<len; j++ ){
		i = num[j] - '0' ;
//		sum += pow( atoi(num[j]), 4);
		sum += pow ( i , pw);
	}
	if ( sum == n ) return true;
	else return false;
}

int main (int argc, char ** argv){
	if ( argc != 3 ){
		cout << "Need  two arguments here\n";
		exit (0);
	}
	int max = atoi(argv[1]), sum = 0;
	for (int i=10; i<=max; i++){
		if ( crack(i , atoi(argv[2])) ){
			cout << i << endl;
			sum += i ; 
		}
	}
	cout << "SUM = " << sum << endl;
	return 0;
}
