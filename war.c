#include <stdio.h>
#include <stdlib.h>
#include "cardlib.h"
#include <time.h>
#define totalCardDeck 52
Card newCard(int value, char suit);
void printCard(Card);
Deck newDeck(int populate);// populate non-zero means create 52 cards
void printDeck(Deck);
Card giveCard(Deck *); // declare fucntions
void putCard(Deck *, Card);
void shuffleDeck(Deck *);
int deckIsEmpty(Deck);
int deckIsFull(Deck);
int doWar();
int main (void)
{
  srand(time(0)); //intialize random integer
  int j;
  int sum  = 0;
  printf("How many games:");
  int howMany;// counter for how many games
  scanf("%d", &howMany);
  printf("\n\n\n");

  for (j = 0; j < howMany; j++) //function for number of games
  { 
    int numTurns = doWar();
    sum += numTurns;
    printf("%d games played and finished\n",sum );
  }
}
int doWar()
{
  int i;
  int t4 = 0;//integers to prevent a never ending game
  int t5 = 0;
  Deck theDeck = newDeck(1);
  shuffleDeck(&theDeck);// create decks and table and suffle them
  Deck hand1 = newDeck(0);
  Deck hand2 = newDeck(0);
  Deck table = newDeck(0);
    for( i = 1; i <= 52; i++)
    {
      if( (i % 2)== 1) // deal cards out to hands
      {
        putCard(&hand1, giveCard(&theDeck));
      }
      if( (i % 2)== 0)
      {
        putCard(&hand2, giveCard(&theDeck));
      }
    }
   int t = 1 ; 
  while((hand1.num > 0 && hand2.num > 0) && t < 100000 )
  {
    Card c1 = giveCard(&hand1); // take cards from hands and put them on table
    Card c2 = giveCard(&hand2);
    putCard(&table, c1);
    putCard(&table, c2);
    t++;
    if(c1.value > c2.value) //compare card values to find winner
    {
      putCard(&hand1, giveCard(&table));
      putCard(&hand1, giveCard(&table));
    }
    if(c1.value < c2.value)
    {
      putCard(&hand2, giveCard(&table));
      putCard(&hand2, giveCard(&table));

    }

    int t1 = 1;
    while(c1.value == c2.value && t1 < 1000 ) // initiates a war!
    { t1++;
      if(hand1.num  == 0) // protects from taking a card from a empty deck
      {
           printf("Player 1 ran out of cards!\nPlayer 2 Wins!\n");
           return 1;
      }
      if(hand2.num == 0)
      {
 	   printf("Player 1 ran out of cards!\nPlayer 1 Wins!\n");
 	   return 1;
      }
      c1 = giveCard(&hand1);
      c2 = giveCard(&hand2);
      putCard(&table, c1);
      putCard(&table, c2);

      if(hand1.num  == 0)
      {
           printf("Player 1 ran out of cards!\nPlayer 2 Wins!\n");
           return 1;
      }
      if(hand2.num == 0)
      {
         printf("Player 2 ran out of cards!\nPlayer 1 Wins!\n");
         return 1;
      }
     
      c1 = giveCard(&hand1);
      c2 = giveCard(&hand2);
      putCard(&table, c1);
      putCard(&table, c2);
  

      if(hand1.num  == 0)
      {
           printf("Player 1 ran out of cards!\nPlayer 2 Wins!\n");
	   return 1;

      }
      if(hand2.num == 0)
      {
           printf("Player 2 ran out of cards!\nPlayer 1 Wins!\n");
	   return 1;

      }
      c1 = giveCard(&hand1);
      c2 = giveCard(&hand2);
      putCard(&table, c1);
      putCard(&table, c2);

      
      if(c1.value > c2.value && t4 <200  ) //function if player 1 wins
      { 
        t4++; 
	int t2 = table.num;
        while(table.num > 0 && t2 != 0) //puts all cards from war in hand
        {
          putCard(&hand1, giveCard(&table));
        }
      }
      if(c1.value < c2.value && t5 < 200 )
      { 
	t5++;
	int t3 = table.num;
        while(table.num > 0 && t3 != 0)
        {
          putCard(&hand2, giveCard(&table));
          t3--;
        }
     
      }
     
     }
   
  }
  if(hand1.num  == 0 )
    {

       printf("Player 1 ran out of cards!\nPlayer 2 Wins!\n");
    } 
  if(hand2.num == 0)
    {
       printf("Player 2 ran out of cards!\nPlayer 1 Wins!\n");
    }
  printf("Endless game! thats a tie!\n");
  return 0;
}

