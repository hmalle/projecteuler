/*

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

*/

#include <cstdlib>
#include <iostream>
using namespace std;

char* itoa(int value, char* result, int base) 
{
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

bool curious_fraction ( int a, int  b )
{
	char aa[3];
	itoa ( a , aa, 10 );
	char bb[3] ;
	itoa ( b, bb, 10 );
	//if ( aa[0] == bb[0] or aa[0]==bb[1] or aa[1]==bb[0] or aa[1]==bb[1] )
	if  (aa[0] == bb[0]  && aa[0]!='0')
	{
		if (((double(aa[1]-'0')/ double(bb[1]-'0')) == double(a)/double(b)) && double(a)/double(b) <1.0)
		{
			cout <<"case 1 " <<aa << "/"<<bb<<endl;
			return true;
		}
	}
	if (aa[0] == bb[1] && aa[0] != '0' )
	{
		if (((double(aa[1]-'0')/ double(bb[0]-'0')) == double(a)/double(b)) && double(a)/double(b) <1.0)
		{
			cout <<"case 2 " <<aa << "/"<<bb<<endl;
			return true;
		}
	}
	if (aa[1] == bb[0] && aa[1] != '0'  )
	{
		if (((double(aa[0]-'0')/ double(bb[1]-'0')) == double(a)/double(b)) && double(a)/double(b) <1.0)
		{
			cout <<"case 3 " <<aa << "/"<<bb<<endl;
			return true;
		}
	}
	if (aa[1] == bb[1] && aa[1] != '0' )
	{
		if (((double(aa[0]='0')/ double(bb[0]-'0')) == double(a)/double(b)) && double(a)/double(b) <1.0)
		{
			cout <<"case 4 " <<aa << "/"<<bb<<endl;
			return true;
		}
	}
	return false;
}

int main()
{
	int numerator = 1 , denominator = 1;
	for ( int i = 10 ; i < 100  ; i++ )
	{
		for ( int j = i+1; j < 100 ; j++ )
		{
			if (curious_fraction ( i , j ) )
			{
				numerator *= i ;
				denominator *= j ; 
			}
		}
	}
	cout <<"numerator / denominator = " << numerator<<"/"<<denominator<<endl;
	cout <<"Demoninator in lowest common term " <<denominator/numerator <<endl;
	return 0;
}
