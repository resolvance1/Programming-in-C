#include <stdlib.h>
#include <stdio.h>
#include "cardlib.h"

int main(void)
{
  
  Deck d = newDeck();
  shuffleDeck(&d);
  Deck p1Deck = splitDeck1();
  Deck p2Deck = splitDeck2();
  printDeck(d);
}
