/*
In England the currency is made up of pound, £, and pence, p, and 
there are eight coins in general circulation:
    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:
    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

#include<iostream>
using namespace std;

int coin_ways ( int value )
{
	int ways = 0;
	int sum = 0;
	for ( int a=0; a<= value ; a+=200 )
	{
		for ( int b=0; a+b<=value ; b+=100)
		{
			for ( int c=0; a+b+c<=value; c +=50 )
			{
				for ( int d=0; a+b+c+d<=value; d+=20)
				{
					for ( int e=0; a+b+c+d+e<=value; e+=10)
					{
						for ( int f=0; a+b+c+d+e+f<=value; f+=5 )
						{
							for ( int g=0; a+b+c+d+e+f+g<=value; g+=2)
							{
								for ( int h=0;a+b+c+d+e+f+g+h<= value ; h+=1 )
								{
									sum = a + b+c +d+e+f+g+h;
									if ( sum == value )
									{
										ways ++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return ways;
}

int main()
{
	cout << "Enter the value : ";
	int value;
	cin>> value;
	cout <<endl<< coin_ways ( value)<<endl;
	return 0;
}
	
