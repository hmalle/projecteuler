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
  for(int a=0; token!=NULL; a++){
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

void reverse_values(char * str){
  char c;
  int len = strlen(str);
  for(int a=0; a<len; a++){
    c = str[a];
    str[a] = str[len-1];
    str[len-1] = c; 
  }
}

void sort_hand(char* values){
  //sorting the hand makes it easy to find straights
  char tmp, deck[] = "23456789TJQKA";
  int index=0;
  for(int a=0;a<strlen(deck); a++){
    for(int b=0;b<strlen(values); b++){
      if(deck[a] == values[b]){
        tmp = values[index];
        values[index] = deck[a];
        values[b] = tmp;
        index++;
      }
    }
  }
}

int high_value(char * values){
  char deck[] = "23456789TJQKA";
  int result = 0;
  int deck_len = strlen(deck);
  int values_len = strlen(values);
  for(int a=deck_len-1; a>=0; a--){
    if(deck[a] == values[values_len-1]){
      result = a;
      break;
    }
  }
  return result;
}

int flush(char* suits){
  //helper function get the max number of suits
  int c=0,d=0,h=0,s=0;
  for(int a=0; a<strlen(suits);a++){
    if(suits[a]=='C') c++;
    else if(suits[a]=='D') d++;
    else if(suits[a]=='H') h++;
    else s++ ;//(suits[a]=='S') s++;
  }
  if(c==5||d==5 || h==5||s==5){
    return 470; 
  }else return 0;
}

int greater_card(char one, char two){
  char deck[] = "23456789TJQKA";
  if(one == '0' && two =='0') return 0;
  else if(one != '0' && two =='0') return 1;
  else if(one == '0' && two !='0') return -1;
  for(int a=strlen(deck)-1;a>=0;a--){
    if(deck[a]== one && deck[a]== two){
      return 0;
    }else if(deck[a] == one){
      return 1;
    }else{
      return -1;
    }
  }
  return 0;
}

int find_repeats(char* values){
  char deck[] = "23456789TJQKA";
  int deck_len = strlen(deck), values_len = strlen(values);
  int skip=0, repeat=0, sum = 0;
  for(int a=0; a<deck_len; a++){
    repeat = 0;
    for(int b=0; b<=values_len; b++){
      if( b-skip>0 && deck[a] != values[b]){
        if(repeat==2){
          sum += (100+(a*2));
          skip = b;
          repeat = 0;
        }else if(repeat==3){
          sum += (300+(a*3));
          skip = b;
          repeat = 0;
        }else if(repeat==4){
          sum += (600+(a*4));
          return sum;
        }
      }else if(deck[a] == values[b]){
        repeat++;
      }
    }
  }
  return sum;
}

int straight(char* values){
  char deck[] = "23456789TJQKA";
  int sum = 0, card_sum = 0;
  for(int a=0, b=0;a<strlen(deck);a++){
    if(b>0 && b<6 && deck[a] != values[b]){
      break;
    }else if(deck[a] == values[b]){
      b++;
      card_sum+=a;
      if(b == 5){
        sum += (400+card_sum);
      }
    }
  }
  return sum;
}

int find_winner(char * str){
  char one_values[10] = "";
  char two_values[10] = "";
  char one_suits[10] = "";
  char two_suits[10] = "";
  int sum_one, sum_two;
  get_values_suits(str, one_values, one_suits, two_values, two_suits);
  sort_hand(one_values); sort_hand(two_values);
  sort_hand(one_suits); sort_hand(two_suits);
  sum_one =flush(one_suits)+find_repeats(one_values)+straight(one_values);
  sum_two =flush(two_suits)+find_repeats(two_values)+straight(two_values);
  if(sum_one == sum_two){
    sum_one += high_value(one_values);
    sum_two += high_value(two_values);
  }
  if(sum_one> sum_two){
    printf("%s,%s - (%d, %d) %s,%s\n",one_values,two_values,sum_one,sum_two, one_suits, two_suits);
    return 1;
  }else if(sum_one < sum_two){
    return 2;
  }else{
    printf("sum1=sum2 %d %d\n", sum_one, sum_two);
    return 0;
  }
}

int main(){
  char pokerfile[20] = "54.txt";
  int size = 50;
  char s[size]; memset(s, 0, size);
  int player1 = 0, player2 = 0;
  FILE * fs = fopen(pokerfile, "r");
  if(!fs){ 
    printf("The file %s cannot be opened\n", pokerfile);
    exit(0); 
  }
  while(fgets(s, size, fs)!=NULL){
    int winner = find_winner(s);
    if(winner == 1){
      player1++;
    }else if(winner==2){
      player2++;
    }else{
      printf("------------Draw---------------\n");
    }
  }
  printf("Player 1: %d\nPlayer 2: %d\n", player1, player2);
  return 0;
}

