/*


If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

*/
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int triangles_with_perimeter( int perim)
{
	int solutions = 0;
	for ( int i=3; i<perim; i++ )
	{
		for( int j=i+1; j<perim; j++ )
		{
			if (pow(i,2)+ pow(j,2) == pow(perim-i-j ,2) )
			{
				solutions++;
			}
		}
	}
	
	return solutions;
}

int main(int argc, char **argv)
{
	int max_triangles=0, max_perimeter, solutions;
	for ( int i=0; i<=1000; i++ )
	{
		solutions = triangles_with_perimeter(i);
		if (solutions > max_triangles)
		{
			max_triangles = solutions ; 
			max_perimeter = i;
		}
	}
	cout<<max_perimeter<<endl;
	return 0;
}
