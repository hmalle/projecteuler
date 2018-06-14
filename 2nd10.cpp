#include <iostream>
#include <cmath>
using namespace std;
bool prime (int n){
	for ( int z = 2; (n/2) + 1 > z; z++ )
		if( n%z == 0 ) 
		return false;
	return true;
}
int main(){
	cout<<"Enter the max\n";
	int max, sum=2; cin >> max;
	for (int x=3; x < max; x+=2 )
		if (prime(x)){
			sum += x;
	}
	cout <<"Sum of prime numbers below "<<max<<" = " <<sum<<endl;
	return 0;
}
