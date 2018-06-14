/*
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

*/
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool prime( int num)
{
	if ( num< 2 ) return false;
	if (num ==2 or num==3 )
		return true;
	if (num%2==0 or num%3==0)
		return false;
	if (num %6 ==1 or num%6==5 )
	{
		int sx= 6;
		for (int i=1; (6*i-1)<=int(sqrt(num)); i++)
		{
			sx = 6*i;
			if ( num%(sx-1)==0 or num%(sx+1)==0 )
				return false;
		}
		return true;
	}
}

int main()
{
	int largest_sequence=0, the_prime=0, sum, steps, below=1000000;
	vector <int> primelist;
	for ( int i=0; i< below; i++ )
	{
		if (prime(i))
			primelist.push_back(i);
	}
	for ( int i=0; i< primelist.size(); i++ )
	{
		sum  = 0;
		for ( int j=i; j<primelist.size(); j++)
		{
			steps = j-i;
			sum+=primelist[j] ;
			if (sum > below)
				break;
			else if ( prime(sum))
			{
				if ( largest_sequence < steps)
				{
					largest_sequence = steps; 
					the_prime = sum;
				}
			}
		}
	}
	cout <<largest_sequence<<"   "<<the_prime<<endl;
	return 0;
}
