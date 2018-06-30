typedef struct card
{
  char suit; // 'C' 'D' 'H' or 'S'
  int value; //  0 - joker 1 = ace ... 13 = King
} Card;

typedef struct deck
{
  Card theDeck[52];
  int num;
}  Deck;

Card newCard(int value, char suit);
void printCard(Card);
Deck newDeck(int populate);// populate non-zero means create 52 cards
void printDeck(Deck);
Card giveCard(Deck *);
void putCard(Deck *, Card);
void shuffleDeck(Deck *);
int deckIsEmpty(Deck);
int deckIsFull(Deck);

