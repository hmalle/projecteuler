/* In the card game poker, a hand consists of five cards and are ranked, from lowest to 
 highest, in the following way:
  * High Card: Highest value card.
  * One Pair: Two cards of the same value.
  * Two Pairs: Two different pairs.
  * Three of a Kind: Three cards of the same value.
  * Straight: All cards are consecutive values.
  * Flush: All cards of the same suit.
  * Full House: Three of a kind and a pair.
  * Four of a Kind: Four cards of the same value.
  * Straight Flush: All cards are consecutive values of same suit.
  * Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
 The cards are valued in the order: 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 
 If two players have the same ranked hands then the rank made up of the highest value wins; 
 for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks 
 tie, for example, both players have a pair of queens, then highest cards in each hand are 
 compared (see example 4 below); if the highest cards tie then the next highest cards are 
 compared, and so on.

Consider the following five hands dealt to two players:
 Hand   Player 1          Player 2            Winner
 1      5H 5C 6S 7S KD    2C 3S 8S 8D TD      Player 2
        Pair of Fives     Pair of Eights
 2      5D 8C 9S JS AC    2C 5C 7D 8S QH      Player 1
        Highest card Ace  Highest card Queen
 3      2D 9C AS AH AC    3D 6D 7D TD QD      Player 2
        Three Aces        Flush with Diamonds
 4      4D 6S 9H QH QC    3D 6D 7H QD QS      Player 1 
        Pair of Queens    Pair of Queens    
        Highest card Nine Highest card Seven
 5      2H 2D 4C 4D 4S    3C 3D 3S 9S 9D      Player 1 
        Full House        Full House
        With Three Fours  with Three Threes

 *The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the 
 file contains ten cards (separated by a single space): the first five are Player 1's cards and 
 the last five are Player 2's cards. You can assume that all hands are valid (no invalid 
 characters or repeated cards), each player's hand is in no specific order, and in each hand 
 there is a clear winner.
 How many hands does Player 1 win?  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b, int c, int d){
  if(a>=b && a>=c && a>=d) return a;
  else if(b>=a && b>=c && b>=d) return b;
  else if(c>=a && c>=b && c>=d) return c;
  else if(d>=a && d>=b && d>=c) return d;
  return 0;
}

int same_suit(char *copy_hand){
  //Returns the maximum number of suits regardless of kind
  char hand[128];
  strcpy(hand, copy_hand);
  int c=0, d=0, h=0, s=0;
  char * token = strtok(hand," ");
  while( token != NULL){
    if(token[1]=='C') c++;
    else if(token[1]=='D') d++;
    else if(token[1]=='H') h++;
    //else if(token[1]=='S') s++;
    else s++;
    token = strtok(NULL, " ");
  }
  return max(c,d,h,s);
}

void straight(char * result, char *hand){
  char values[] = "23456789TJQKA";
  char hand_values[10];
  char copy_hand[128]; strcpy(copy_hand, hand);
  char * token = strtok(copy_hand," ");
  char max_straight = '0';
  char max_value = '0';
  char tmp_max_value;
  short tmp_straight;
  for(short a=0; token != NULL;a++){
    hand_values[a]=token[0];
    hand_values[a+1] = '\0';
    token = strtok(NULL, " ");
  }
  for(short a=0; a< strlen(values); a++){
    tmp_straight = '0';
    for(short b=0; b<strlen(hand_values); b++){
      if(values[a] == hand_values[b]){
        tmp_straight++;
        tmp_max_value = hand_values[b];
      }
    }
    if(max_straight <= tmp_straight ){
      max_straight = tmp_straight;
      max_value = tmp_max_value;
    }
  }
  result[0] = max_straight;
  result[1] = max_value;
}

int greater_card( char one, char two){
  char values[] = "23456789TJQKA";
  int indexofa, indexofb;
  for(short a=0; a<strlen(values); a++){
    if(values[a] == one) indexofa = a;
    if(values[a] == two) indexofb = a;
  }
  if(indexofa> indexofb) return 1;
  else return 0;
}

void same_value(char * result, char *copy_hand){
  char values[] = "23456789TJQKA";
  char hand_values[10];
  char repeats='0';
  char repeating_value='0';

  char hand[128];
  memset(hand,0,128);
  strcpy(hand, copy_hand);
  char *token = strtok(hand," ");
  for(short a=0; token != NULL;a++){
    hand_values[a]=token[0];
    hand_values[a+1] = '\0';
    token = strtok(NULL, " ");
  }
  for(short a=0; a<strlen(values); a++){
    char tmp='0';
    for(short b=0; b<strlen(hand_values); b++){
      if(values[a] == hand_values[b]){
        tmp++;
      }
    }
    if(repeats <= tmp){
      repeats = tmp;
      repeating_value = values[a];
    }
  }
  result[0] = repeats;
  result[1] = repeating_value;
}

int compare_hands(char *one_hand, char *two_hand){
  char omcv [3]= {0};   //one max count value,
  char tmcv [3]= {0};   //two max count value,
  char oscv [3]= {0};   //one straight count value,
  char tscv [3]= {0};   //two straight count value,
  int osuit =same_suit(one_hand); //one suits
  int tsuit =same_suit(two_hand); //two suits
  same_value(omcv, one_hand); 
  same_value(tmcv, two_hand); 
  straight(oscv, one_hand);
  straight(tscv, two_hand);

  if(osuit== 5 && omcv[0]=='5'&& omcv[1]=='A'){ return 1;} //one flash
  else if(tsuit== 5 && tmcv[0]=='5'&& tmcv[1]=='A'){ return 2;} //two flash 
  else if(osuit== 5 && omcv[0]=='5' && tsuit=='5' && tmcv[0]=='5'){
    if(oscv[1]>tscv[1]){ return 1; } else{ return 2;}  //straight flush
  }else if(omcv[0] == '4' && tmcv[0]=='4'){
    if(omcv[1]>tmcv[1]) return 1; else return 2;  //might be a typo here
  }else if(omcv[0] == '3' && tmcv[0] =='3'){
    if(omcv[1]>omcv[2]) return 1; else return 2;  //three of a kind(almost a full house);
  }else if(osuit==5 && tsuit==5){
    if(oscv[1]>tscv[1]) return 1; else return 0;
  }

  return 2;
}

void separate_hands(char* str, char* one_hand, char* two_hand){
  char *token = strtok(str," ");
  for(short a=0; token!=NULL; a++){
    if(a<5){
      strcat(one_hand, token);
      strcat(one_hand, " ");
    }else{
      strcat(two_hand, token);
      strcat(two_hand, " ");
    }
    token = strtok(NULL," ");
  }
}

int find_winner( char * str){
  char one_hand[128], two_hand[128];
  memset(one_hand, 0, 128);
  memset(two_hand, 0, 128);
  separate_hands(str, one_hand, two_hand);
  if(compare_hands(one_hand, two_hand)==1){
    return 1;
  }else{
    return 2;
  }
}

void remove_newline(char * str){
  for(int a=0;a<strlen(str); a++){
    if(str[a] == '\n'){
      str[a] = '\0';
      str[a+1] = 0;
    }
  }
}

int main(){
  char pokerfile[20] = "54.txt";
  char s[256];
  int size= 256;
  memset(s, 0, size);
  short player1 = 0, player2 = 0;
  FILE * fs = fopen(pokerfile, "r");
  if(!fs){ 
    printf("The file %s cannot be opened\n", pokerfile);
    exit(0); 
  }
  while(fgets(s, size, fs)!=NULL){
    remove_newline(s);
    if(find_winner(s)==1){
      player1++;
    }else{
      player2++;
    }
  }
  printf("Player 1: %d\nPlayer 2: %d\n", player1, player2);
  return 0;
}

