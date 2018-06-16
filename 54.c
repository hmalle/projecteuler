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

void get_values_suits(char* str,char* one_values, char* one_suits,char* two_values, char* two_suits){
  //separates out the player cards and assign card values and suits
  const char delim[2] = " ";
  char* token=strtok(str, delim);
  for(short a=0; token!=NULL; a++){
    if(a<5){
      strncat(one_values, &token[0], 1);
      strncat(one_suits, &token[1], 1);
    }else{
      strncat(two_values, &token[0], 1);
      strncat(two_suits, &token[1], 1);
    }
    token=strtok(NULL, delim);
  }
}

short max_suits(char* suits){
  //helper function get the max number of suits
  int c=0,d=0,h=0,s=0;
  for(short a=0; a<strlen(suits);a++){
    if(suits[a]=='C') c++;
    if(suits[a]=='D') d++;
    if(suits[a]=='H') h++;
    if(suits[a]=='S') s++;
  }
  //TODO: There has to be an easier way
  if(c>=d && c>=h && c>=s) return c;
  if(d>=c && d>=h && d>=s) return d;
  if(h>=c && h>=d && h>=s) return h;
  if(s>=c && s>=d && s>=h) return s;
  
  return 0;
}

char high_value(char * values){
  char deck[] = "23456789TJQKA";
  char result = deck[0];
  for(short a=0;a<strlen(deck);a++){
    for(short b=0;a<strlen(values); a++){
      if(deck[a] == values[b]){
        result = values[a];
      }
    }
  }
  return result;
}

char pair(char* values){
  char deck[] = "23456789TJQKA";
  char this_repeat,pair_value, max_repeat='0';
  for(short a=0;a<strlen(deck);a++){
    this_repeat = 0;
    for(short b=0;b<strlen(values); a++){
      if(deck[a] == values[b]){
        this_repeat++;
      }
    }
    if(max_repeat >= this_repeat ){
      max_repeat = this_repeat;
      pair_value = deck[a];
    }
  }
  if(max_repeat == 3){
    return pair_value;
  }else{
    return '0';
  }
}

char three_of_a_kind(char* values){
  char deck[] = "23456789TJQKA";
  char this_repeat, three_value, max_repeat='0';
  for(short a=0;a<strlen(deck);a++){
    this_repeat = 0;
    for(short b=0;b<strlen(values); a++){
      if(deck[a] == values[b]){
        this_repeat++;
      }
    }
    if(max_repeat >= this_repeat ){
      max_repeat = this_repeat;
      three_value = deck[a];
    }
  }
  if(max_repeat == 3){
    return three_value;
  }else{
    return '0';
  }
}

char four_of_a_kind(char* values){
  char deck[] = "23456789TJQKA";
  char this_repeat, four_value, max_repeat='0';
  for(short a=0;a<strlen(deck);a++){
    this_repeat = 0;
    for(short b=0;b<strlen(values); a++){
      if(deck[a] == values[b]){
        this_repeat++;
      }
    }
    if(max_repeat >= this_repeat ){
      max_repeat = this_repeat;
      four_value = deck[a];
    }
  }
  if(max_repeat == 4){
    return four_value;
  }else{
    return '0';
  }
}

int compare_hands(char* one_values, char* one_suits, char* two_values, char* two_suits){
  int one_max_suits = max_suits(one_suits);
  int two_max_suits = max_suits(two_suits);
  printf("%s, %d, %s, %d\n", one_suits, one_max_suits, two_suits, two_max_suits);

  return 1;
}

int find_winner( char * str){
  char one_values[10] ={0};
  char two_values[10] ={0};
  char one_suits[10] ={0};
  char two_suits[10] ={0};
  get_values_suits(str, one_values, one_suits, two_values, two_suits);
//  printf("one: values %s, suits %s \n",one_values, one_suits);
//  printf("two: values %s, suits %s \n",two_values, two_suits);
  if(compare_hands(one_values,one_suits, two_values, two_suits)==1){
    return 1;
  }else{
    return 2;
  }
}

int main(){
  char pokerfile[20] = "54.txt";
  short size = 50;
  char s[size]; memset(s, 0, size);
  short player1 = 0, player2 = 0;
  FILE * fs = fopen(pokerfile, "r");
  if(!fs){ 
    printf("The file %s cannot be opened\n", pokerfile);
    exit(0); 
  }
  while(fgets(s, size, fs)!=NULL){
    if(find_winner(s)==1){
      player1++;
    }else{
      player2++;
    }
  }
  printf("Player 1: %d\nPlayer 2: %d\n", player1, player2);
  return 0;
}

