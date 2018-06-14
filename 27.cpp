/*

Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n² + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

*/

#include <cmath>
#include <iostream>

using namespace std;

/*

bool prime (int n)
{
	if (n==2 or n==3 or n==5) return true;
	if  ( n %2==0 || n%3 == 0 ) return false; 
	if ( n%6!=1 or n%6!=5 ) return false;
	for ( int z = 1; (6*z-1)<=sqrt(double(n)); z++){
		if( n%(6*z-1) == 0 )  return false;
		if( n%(6*z+1) == 0 ) return false; 
	}
	return true;
}
*/

bool prime (int num )
{
	if (num< 2) return false;
	for ( int i =2 ; i <= sqrt(double(num)) ; i++ )
	{
		if (num %i == 0) 
			return false;
	}
	return true;
}

int main()
{
	int max_consecutive_primes=0 , num_to_test, last_n, product ;
	bool prime_status = true;
	for ( int a = -1000; a < 1001 ; a++ )
	{
		for ( int b = -1000 ; b < 1001 ; b++ )
		{
			for ( int n = 0;  ; n++ )
			{
				num_to_test = pow(n,2) + a*n + b ;
				if ( ! prime (num_to_test ) )
				{ 
					prime_status = false;
					last_n = n+1 ;
					break;
				}
			}
			if ( last_n >  max_consecutive_primes ) 
			{
				prime_status = true;
				max_consecutive_primes = last_n;
				product = a *b ;
				cout << "( a , b , max consecutuve primes , product ) = " 
					<<a<<","<<b<<","<<max_consecutive_primes<<","<<product<<endl;
			}
		}
	}
	cout <<max_consecutive_primes << endl <<  product <<endl;
	return 0;
}
