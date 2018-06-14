/*


Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	vector<int> diagonal_numbers;
	int step=0,diagonal_sum = 0, last_num=1;
	for( int i=1; last_num < 1001*1001; i++)
	{
		diagonal_numbers.push_back(last_num+step);
		last_num+=step;
		if ( sqrt(last_num) == int(sqrt(last_num))  )
			step +=2;
	}

	for ( int i=0; i<diagonal_numbers.size(); i++ )
	{
		diagonal_sum += diagonal_numbers[i];
	}
	
	cout << diagonal_sum<<endl;
	return 0;
}
