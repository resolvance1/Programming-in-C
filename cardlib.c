#include <stdlib.h>
#include <stdio.h>
#include "cardlib.h"
#include <time.h>
Card newCard(int val, char suit)
{
  Card retval;
  if (val < 0 || val > 13)
  {
	printf("Illegal card value %d\n", val);
	exit(1);
  }
  else
  {
	retval.value = val;
  }
  if (suit <= 'A' && suit >= 'Z')
  {
	suit += 32;
  }
  if (suit != 'C' && suit != 'D' && suit != 'H' && suit != 'S')
  {
	printf("Illegal suit %c\n",suit);
	exit(1);
  }
  return retval;
}

void printCard(Card c)
{
	switch(c.value)
	{
	case1:  printf("The ace of");
		break;
	case11: printf("The jack of");
		break;
	case12: printf("The Queen of");
		break;
	case13: printf("The King of");
		break;
	default:printf("The %d of",c.value);
	}
	switch(c.suit)
	{
	case 'C': printf("clubs\n");
		break;
	case 'D': printf("Diamonds\n");
		break;
	case 'H': printf("Hearts\n");
		break;
	case 'S': printf("Spades\n");
		break;
	}


}

Deck newDeck()
{
	Deck retval;
	retval.num = 0;
	char suits[] = {'C', 'D', 'H', 'S'};
	int s, v;
	for (s = 0; s < 4; s++)
	{
	  for(v = 1; v <=13; v++)
	  {
		retval.theDeck[retval.num] = newCard(v,suits[s]);
		retval.num++;
	  }
	}
	return retval;
}

	    
void printDeck(Deck d)
{
	int i;
	for (i = 0; i < d.num; i++)
	{
	  printCard(d.theDeck[i]);
	}
}
  	
card giveCard(Deck d)
{
	if (d.num <1)
	{
	  printf("Attempt to get a card from an empty card container\n");
	}
	
	d.num--;
	
	Card retval = d.theDeck[d.num];
	return retval;
}

void putCard(Deck d, Card c)
{
	if( d.num => 52)
	{
	  printf("Attempt to put card into a full card container\n");
	}
	
	int i; 

	for (i = d.num; i > 0; i--)
	{
	  d.theDeck[i] = d.theDeck[i-1];
	}
	d.theDeck[0] = c;
}	 

void shuffleDeck(Deck *d)
{
	srand(time(0));
	int NUMSWAP = 1000;
	int i;
	for(i=0; i < NUMSWAP; i++)
	{
	  int c1 = rand() % d->num; 
	  int c2 = rand() % d->num;
	  Card temp = d->theDeck[c1];
	  d->theDeck[c1] = d->theDeck[c2];
	  d->theDeck[c2] = temp;
	}
}

int main(void)
{
	Deck x = newDeck();
	shuffleDeck(&x);
	printDeck(x);
}





