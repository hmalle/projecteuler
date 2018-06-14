/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/
//PWNED IT AGAIN

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

char * itoa (int value, char * result, int base=10)
{
	if ( base < 2 || base > 36 )
	{
		*result = '\0' ;
		return result;
	}
	char * ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;
	do{
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)] ;
	} while (value );
	
	//apply negtatve sign
	if( tmp_value<0 ) 
		*ptr++ = '-';
	*ptr-- ='\0';
	while (ptr1 < ptr )
	{
		tmp_char = *ptr;
		*ptr-- = *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}


bool isprime ( int number )
{
	if ( number < 2 ) return false;
	if  ( number ==2 || number ==3 ) return true;
	if (number %2==0 || number%3 == 0) return false;
	for ( int i=5; i <= sqrt(number) ; i++ )
	{	
		if ( number% i == 0 ) return false;
	}
	return true;
}

vector < int >  get_all_all_all ( int passed_num , int stat = 1 )
{
	vector <int> numbers;
	int num  = passed_num;
	while ( num > 0 )
	{
		numbers.push_back (num );
		num = num/10;
	}
	char str_num[11];
	itoa( passed_num , str_num , 10 );
	for ( int i=0; i<strlen(str_num); i++ )
	{
		numbers.push_back( atoi(str_num) );
		str_num[i] = '0';
	}
	return numbers;
}

bool truncatable ( vector <int> all_numbers )
{
	sort (all_numbers.begin(), all_numbers.end() );
	for (unsigned i=0; i<all_numbers.size(); i++ )
	{
		if ( ! isprime( all_numbers[i] ) )
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector < int > integers;
	int sum = 0;
	int all=0;
	for ( int i=10; all < 11; i++ )
	{
		integers = get_all_all_all ( i ) ;
		if (truncatable( integers ))
		{
			cout << i << endl;
			sum += i;
			all+=1;
		}
	}
	cout <<"AUM AUM = "<< sum <<endl;
	return 0;
}
