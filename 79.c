
/* A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length. */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char ** argv){
  if(argc < 2){
    printf("Please supply the text file as a command line argument\n");
    exit(0);
  }
  FILE *fptr;
  fptr=fopen(argv[1],"r");
  if(fptr==NULL){
    printf("Cannot open the file %s\nExiting \n", argv[1]);
    exit(0);
  }

  //Plan:
  //Read 2 characters from the keylog.txt to see if they repeat
  //If they do, append the whole letter to the other repeat
  //If there is a necessary insertion needed, insert
  //TODO: But how does I guarantee insertion is in the right spot??
  //
  return 0;
}
