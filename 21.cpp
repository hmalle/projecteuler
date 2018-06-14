/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than 
n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair 
and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 
55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 
71 and 142; so d(284) = 220.

calculate all amicable numbers under 10000
*/

#include <cstdlib>
#include <iostream>
using namespace std;

int test ( int a ){
	int b = 0, cc = 0;
	for( int i=1; i <= a/2 ; i++ ){
		if ( a %i == 0)
			b += i ;
	}
	if (b > a ){
		for (int i=1; i <= b/2 ; i++ ){
			if ( b %i ==0 ) 
				cc += i;
		}
		if ( cc == a ){
			cout << a << " and " << b << endl;
			return a+b;
		}
	}
	return 0;
}
//works like cham 
int main (int argc, char ** argv){
	if ( argc < 2 ){
		cout << "U gonna need an argument for this program\n";
		exit(0);
	}
	int upper = atoi( argv[1] ), sum = 0; 
	for (int i=0; i<upper ; i++)
		sum += test(i);
	cout <<"sum_amicable[" << argv[1]<<"] ="<< sum << endl;
	return 0;
}
//works like cham. 
