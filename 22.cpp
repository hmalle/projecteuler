/*
		PAWNED!!!!
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

void usage ( int status )
{
	if ( status ==1 )
		cout <<"./program_name <filename>\n";
	else if ( status ==2 )
		cout<<"Filename provided wasnt opened, check if file exists\n";
	exit(0);
}

vector < string >  get_each_name ( string many_names )
{
	vector < string > each_name;
	for ( unsigned i=0; i< many_names.size(); i++ )
	{
		if ( many_names[i] == '\"') 
			many_names.erase( many_names.begin()+i);
	}
	string name;
	stringstream stream_baby( many_names);
	while ( getline (stream_baby , name, ',' ) )
		each_name.push_back ( name );
	//lets sort thee.
	sort ( each_name.begin(), each_name.end() );
	
	return each_name;
}

string read_file_to_cstring ( char * filename )
{
	ifstream in( filename );
	if ( in.is_open() == 0 ) usage(2);
	stringstream buffer; 
	buffer << in.rdbuf ();
	return buffer.str();
}

template <typename ANY >
void print_vector ( vector < ANY > vekky )
{
	for ( unsigned int i=0; i < vekky.size(); i++ )
		cout << vekky[i]<< endl;
}

unsigned calculate_score ( vector < string > & many_names )
{
	//capital ascii 65-90 so minus 64 to get alphabetical number
	unsigned big_sum_sum=0, name_sum;
	int case_holder;
	for ( unsigned i=0; i< many_names.size(); i++ )
	{
		name_sum =0 ;
		for (unsigned j=0 ; j<many_names[i].size() ; j++ )
		{
			name_sum += static_cast <int> (many_names[i][j]) -64 ;
		}
		big_sum_sum += name_sum * (i+1) ;
	}
	return big_sum_sum;
}

int main( int argc, char ** argv)
{
	if ( argc < 2 ) usage (1);
	string many_names = read_file_to_cstring ( argv[1] ) ;
	vector < string > sorted_names;
	sorted_names = get_each_name ( many_names);
	cout << calculate_score ( sorted_names) << endl;
	return 0;
}
	
