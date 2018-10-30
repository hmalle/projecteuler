
/* A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length. */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lines(FILE* fptr){
  //Returns the lines count in the file
  int lines=0;
  char ch;
  while((ch=fgetc(fptr))!=EOF){
    if(ch=='\n'){
      lines++;
    }
  }
  rewind(fptr);
  return lines;
}

void sort(char **keys, int size){

}

void print_keys(char ** keys, int size){
  for(int a=0;a<size; a++){
    printf("%s\n", *(keys)[size]);
  }
}

int main(int argc, char **argv){
  if(argc < 2){ //Check the number of arguments
    printf("Please supply the text file as a command line argument\n");
    exit(0);
  }
  FILE *fptr;
  fptr=fopen(argv[1],"r");
  if(fptr==NULL){ //Check if the file was opened
    printf("Cannot open the file %s\nExiting \n", argv[1]);
    exit(0);
  }

  int size=lines(fptr);
  int buff_index=0;
  int buff_size=4;
  int keys_index=0;
  char buff[buff_size];
  char c;
  char keys[size][buff_size];
  memset(buff,0,buff_size);
  while((c=fgetc(fptr))!=EOF){
    if(c!=EOF && c!='\n'){
      buff[buff_index]=c;
      buff_index++;
    }else{
      buff[buff_index] = '\0';
      strncpy(keys[keys_index], buff,3);
      printf("copying one key: %s\n",buff);
      memset(buff,0,buff_size);
      buff_index=0;
      keys_index++;
    }
  }

  for(int a=0;a<size;a++){
    printf("-> %s\n", keys[a]);
  }
  fclose(fptr);
  return 0;
}
