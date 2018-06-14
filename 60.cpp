/*


The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.

*/

#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
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


int combine( int a, int b)
{
	char aa[10], bb[10];
	itoa(a, aa, 10);
	itoa(b,bb,10);
	strcat(aa,bb);
	return atoi(aa);
}

int main()
{
	int b, a[4] ={2,3,5,7};
	bool found_next = false;
	int smallest_sum= 0;
	for(int i=9; !found_next; i++ )
	{
		if ( prime(i))
		{
			found_next = true;
			for (int j=0; j<3; j++)
			{
				if ( !prime(combine(a[j],i)) or !prime(combine(i,a[j])) )
				{
					found_next = false;
					continue;
				}
			}
			if (found_next )
				b = i;
				if (a[0]+a[1]+a[2]+a[3]+b < smallest_sum;
					smallest_sum =a[0]+a[1]+a[2]+a[3]+b ; 
		}
	}
	cout<<b<<endl<<a[0]+a[1]+a[2]+a[3]+b<<endl;
	return 0;
}
