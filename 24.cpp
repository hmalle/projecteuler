/*

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

*/

#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int numbers[] =  {0,1,2,3,4,5,6,7,8,9};
	int counter = 0;
	sort (numbers, numbers+10);
	do
	{
		counter++ ;
		if (counter == 1000000 )
		{
			for (int i=0; i< 10; i++ )
	                        cout <<numbers[i];
			break;
		}
	} while (next_permutation (numbers,numbers+10) ) ;
	
	return 0;
}
