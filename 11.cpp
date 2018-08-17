// this is xompete but there seems to be some trouble with thwe strcat in line 51
// THIS IS ABOUT OFFICIALLY PAWNED :)))  

#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int box[20][20];
//diagonally moving down right 
int r_diag( int i, int j){
  int prod=1;
  for (int step=0 ;i>=0 && i<20 && j>=0 && j<20 && step<4 ; i++, j++, step++)
    prod *= box[i][j];
  return prod;
}
//diagonally moving left down 
int l_diag(int i, int j){
  int prod=1;
  for (int step=0 ;i>=0 && i<20 && j>=0 && j<20 && step<4 ; i++, j--, step++)
                prod *= box[i][j];
  return prod;
}
//moving down
int down(int i, int j){
  int prod=1;
  for (int step=0 ;i>=0 && i<20 && j>=0 && j<20 && step<4 ; i++, step++) // keep y the same
                prod *= box[i][j];
  return prod;
}
//moving right 
int right(int i, int j){
  int prod=1;
  for (int step=0 ;i>=0 && i<20 && j>=0 && j<20 && step<4 ; j++, step++) // leep x the same
                prod *= box[i][j];
  return prod;
}

int solve (int i, int j){
  int ans1 , ans2;
  right(i,j) < down(i,j) ? ans1=down(i,j) : ans1=right(i,j);
  r_diag(i,j) < l_diag(i,j) ? ans2=l_diag(i,j) : ans2=r_diag(i,j);
  return (ans1<=ans2 ? ans2 : ans1 ) ;
}

int main (int argc, char ** argv){
  if ( !argv[1] ){
    cout << "You will need to enter a filename as an argument\n";
    exit(0);
  }
  fstream fin(argv[1], ios::in);
  char ch, buff[3], ch_hld;
  // this loop for readin  the box yaddi yadda .... 
  for (int i=0; i<20; i++){
    for (int j=0; j<20; j++){
      memset(buff, 0, 3);
      if ( ! fin.eof() ){
        fin.get(ch); buff[0] = ch;
        fin.get(ch); buff[1] = ch;
        fin.get(ch);
      }
      box[i][j] = atoi(buff);  
      if (ch == '\n' || fin.eof() ) break;
    }
    if ( fin.eof() ) break;
  }
  /*
  cout << "Finished loading the file in the memory\n";
  cout << "Lets now print the box\n";
  for (int i =0; i < 20 ; i++ ){
    for (int j =0 ; j < 20 ; j++){
      cout << box[i][j]<<"  ";
    }
    cout << endl;
  }
  */
  int maxx = 0, tmp;
  for (int i=0; i<20; i++){
    for (int j=0; j<20; j++){
      tmp = solve (i,j); 
      if ( tmp > maxx )
        maxx = tmp;
    }
  }
  cout <<"the maximum product is " << maxx << endl;
  return 0;
}
