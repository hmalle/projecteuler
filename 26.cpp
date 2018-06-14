/* 
A unit fraction contains 1 in the numerator. The decimal representation of the 
unit fractions with denominators 2 to 10 are given:
    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. 
It can be seen that 1/7 has a 6-digit recurring cycle.
Find the value of d < 1000 for which 1/d contains the longest 
recurring cycle in its decimal fraction part.
*/

#include<iostream>
#include<vector>
using namespace std;

vector <int> reciprocal( int d )
{
	vector <int> answer;
	int remainder=10;
	for ( int i=0; remainder!=0 and i<2*d; i++ )
	{
		if ( remainder < d )
			remainder*=10;
		else 
		{
			answer.push_back(remainder/d);
			remainder = remainder%d;
		}
	}
	return answer;
}

int sequence_length( vector <int> num )
{
	int seq = 0;
	bool not_found = true;
	for ( int i=0; i < num.size() && not_found; i++ )
	{
		for ( int j=i+1; j<num.size() && not_found; j++)
		{
			if ( num[i] == num[j] and num[i++] == num[j++] )
			{
				int k=0;
				not_found = false;
				for(; k+j < num.size() && k < j-i; k++ )
				{	
					if ( num[k+i] != num[k+j] )
					{
						not_found= true;
						break;
					}
				}
				if ( not_found == false)
					seq = j-i;
			}
		}
	}
	return seq; 
}

void print_vector( vector <int> sequence )
{
	for ( int i=0; i<sequence.size(); i++ )
	{
		cout <<sequence[i];
	}
	cout <<endl;
}

int main()
{
	int seq_len=0, sl, d_value = 0;
	for( int a=1;a<1000;a+=2 )
	{
		sl = sequence_length( reciprocal(a));
		if ( seq_len <  sl )
		{
			seq_len = sl;
			d_value = a;
		}
	}
	cout << d_value<<" : "<<seq_len<<endl;
	return 0;
}
