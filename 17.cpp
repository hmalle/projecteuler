#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

void usage()
{
	cout << "./progname upper-number\n\tupper-number<1001\n";
	exit(0);
}

int main (int argc, char ** argv)
{
	if ( argc !=2 or atoi(argv[1])> 1000) usage();
	
	int max  = atoi(argv[1]) , num , letters_used=0;
	if (max>1000)  max = 1000;
	char ones[9][20] = {"one","two","three","four","five","six","seven","eight","nine" };
	char tens[9][20] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	char others[9][20] = {"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	char hund[3][20] = {"hundred" , "thousand", "and"};
	for ( int i=1; i<=max ; i++ )
	{
		num = i;
		if ( num >999 )
		{
			cout <<ones[0]<<" "<<hund[1];
			letters_used+=strlen(ones[0]);
			letters_used+=strlen(hund[1]);
			num = 0;
		}
		if ( num  > 99 and num<1000)
		{
			if ( num%100== 0 )
			{
				cout <<ones[num/100 -1]<<" "<<hund[0];
				letters_used += strlen(ones[num/100 -1]);
				letters_used += strlen(hund[0]);
				num = 0;
			}
			else 
			{
				cout<<  ones[num/100 - 1] <<" "<<hund[0]<<" "<<hund[2]<<" ";
				letters_used += strlen(ones[num/100 -1 ]) ;
				letters_used += strlen(hund[0]);
				letters_used += strlen(hund[2]);
				num = num%100;
			}
		}
		if ( num>0 and num < 100)
		{
			if ( num %10 ==0 )
			{
				cout <<others[num/10 - 1]<<" ";
				letters_used += strlen(others[num/10 -1]);
				num = 0;
			}
			else if ( num > 20 )
			{
				cout <<others[num/10 -1]<<" ";
				letters_used += strlen(others[num/10 -1] );
				num = num%10;
			}
			else if ( num > 10 ) 
			{
				cout << tens[num%10 -1]<<" ";
				letters_used+=strlen(tens[num%10 -1 ]) ;
				num = 0;
			}
			else cout<< "";
		}
		if ( num < 10 and num>0 ) 
		{
			cout << ones[num-1]<<" ";
			letters_used+=strlen( ones[num-1] );
		}
		cout << endl;
	}
	cout <<endl<<letters_used<<" letters used"<<endl;
	return 0;
}
