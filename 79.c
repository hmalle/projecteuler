
/* A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length. */

//Hand computed answer: 73162890

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
  char text[4];
  struct Node* next;
  struct Node* prev;
};

int main(int argc, char **argv){
  //Open the file
  if(argc<2){
    fprintf(stderr,"Please supply the text file as a command line argument\n");
    exit(0);
  }
  FILE *fptr;
  fptr=fopen(argv[1],"r");
  if(fptr==NULL){
    fprintf(stderr,"The file %s cannot be opened\n",argv[1]);
    exit(0);
  }

  struct Node* head=NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  int buff_size = 4;
  char buff[buff_size];

  memset(buff,0,buff_size);
  while((c=fgetc(fptr))!=EOF){
    if(c!=EOF && c!='\n'){
      struct Node* node= (struct Node*)malloc(sizeof(struct Node));
      head->next = node;
    }else{
      buff[buff_index] = '\0';
      strcpy(keys[keys_index], buff);
      memset(buff, 0, buff_size);
      buff_index=0;
      keys_index++;
    }
  }
  fclose(fptr);
  return 0;
}

