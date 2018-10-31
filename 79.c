
/* A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length. */

//Hand computed answer: 73162890

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int linecount(FILE* fptr){
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

void sort_unique(char **keys, int size){
  //TODO
}

void print_keys(char keys[][], int size){
  printf("Hello\n");
  printf("%s\n", keys[0]);
  printf("Hello\n");
  for(int a=0;a<size; a++){
    printf("Here morocho\n");
    printf("%s\n", keys[size]);
    printf("Here morocho\n");
  }
}

void handle_error(int status){
  if(status==1){
    printf("Please supply the text file as a command line argument\n");
  }else if(status==2){
    printf("Cannot open the file %s\nExiting \n");
  }
  exit(0);
}

int main(int argc, char **argv){
  //Open the file
  if(argc < 2) handle_error(1);
  FILE *fptr;
  fptr=fopen(argv[1],"r");
  if(fptr==NULL) handle_error(2);

  //Data
  int keys_size=linecount(fptr);
  int buff_index=0;
  int buff_size=4;
  int keys_index=0;
  char buff[buff_size];
  char c;
  char keys[keys_size][buff_size];

  //printf("Size of keys %d\n", sizeof(keys));
  memset(buff,0,buff_size);
  while((c=fgetc(fptr))!=EOF){
    if(c!=EOF && c!='\n'){
      buff[buff_index]=c;
      buff_index++;
    }else{
      buff[buff_index] = '\0';
      strcpy(keys[keys_index], buff);
      printf("copying one key: %s\n",buff);
      printf("copied value :%s\n", keys[keys_index]);
      memset(buff,0,buff_size);
      buff_index=0;
      keys_index++;
    }
  }
  fclose(fptr);
  print_keys(keys, keys_size);
  return 0;
}

