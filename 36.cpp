/*The decimal number, 585 = 1001001001(base 2) (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/
//THIS WAS PAWNED LONG AGO

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

//we dont have itoa on gcc lol!!
char* itoa(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	do {
		tmp_value = value;
		value /= base;
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

// to check for a palindrome baby!
bool is_palindrome ( char * num ){
	int len = strlen(num)-1; 
	for( int i=0; i <= len; i++ ){
		if ( num[i] != num[len-i] ) 
			return false;
	}
	return true;
}
// worked like cham!!
int main (int argc, char ** argv){
	if ( argc!=2){ 
		cout << "needs one and only one argument\nprograms exiting...\n";
		exit(0);
	}
	int sum = 0, max = atoi(argv[1]);
	char nummy[50], num[20];
	for (int i=1; i<max ; i++ ){
		memset (num, 20, 0); 
		itoa( i, num , 10) ;
		if ( is_palindrome(num) ){
			memset (nummy, 50, 0);
			itoa (i , nummy, 2) ; 
			if ( is_palindrome(nummy))
				sum += i ;
		}
	}
	cout <<"SUM("<<max<<") = " << sum << endl;
	return 0;
}
