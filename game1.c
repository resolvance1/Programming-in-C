#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


int  main()
{
  char c;
  int count = 0;
  char where[100][100];
  int k = 0;
  char word1[100];
  char word[100];
  FILE *in = fopen("gameWords.dat", "r");//opens file with pregenerated words
  if(in == NULL)
  {
	printf("Unable to open gameWords.dat.\n");//prompts if file can't be opened
	exit(1);
  }
  k = fscanf(in, "%s", word1);//searches for characters in file
  while(k > 0)
  {
	strcpy(where[count],word1); //pulls words from dat file
	count++;
	k = fscanf(in, "%s", word1);//converts characters to string
  }
  	
  	fclose(in);

	srand(time(0));//generates random seed
        int where1 = rand() % count;//uses remainder from count to pick a certain word from list
	strcpy(word,where[where1]);
	


	int len;//length of word counter
	int i = 0;
	int j = 6; // number of guesses 
	char xWord[100];
	char guess[100];// character holder for guess
	int x;	
	len = strlen(word);//get length of word 
	printf("Your hangman buddy is going to be hung.\n");
	printf("He has 6 lives/chances for you to correctly guess the word!\n");
	printf("The word is %d characters long\n", len);
	for (i=0; i < len; i++)//change upper case letters to lower case
	{
		word[i] = tolower(word[i]);
	}
        word[i] = 0;
	
	for (i = 0; i < len; i++)//change all letters to dashes
	{
		xWord[i] = '-';
	  
	}
        word[i] = 0;
	
	
	while(j != 0)
	{
	     
	     printf("%s\n", xWord);
	     printf("What is your guess?\n\n");
	     scanf("%s", guess);//2nd player inputs character for guess
	     x = 0;
	     while (strlen(guess) > 1)
		{
		i = len;
		printf("\nYou can only input in one letter cheater!\n");
		scanf(" %s", guess);
		
		}
	     for( i=0 ; i < len; i++)
			{
			 int redo = 0;//prompts character if they input a the same letter twice
			 if (guess[0] == xWord[i])
			 {
				printf("\nSorry but you already submitted that letter.\nTry again!\n\n");
				redo++;
				x++;
				i = len;
			 }
			 if (guess[0] == word[i]&& redo != 1)//check to see if its a repeating character 
			 {				//also swaps matching letters for hidden word 
				
				xWord[i] = word[i];
				x++;
			 }
			 if (strcmp(xWord, word) == 0)
			 {
				printf("%s\n\n!!", xWord);      //prompt for if player gets word 100% correct
				printf("You Win!!! CONGRATS!!!\n\n");
				return 1;
			 }
			}
	   	if( x == 0)
			{
			  printf("\nThat was a wrong guess! You're slowly killing him!\n\n");
			  
			  j= j-1;   //prompt if letter doesn't match at all
			  printf("\nYou have %d guesses left!\n", j);
			}

	   }

	   if (j == 0) 
	   {
		printf("\nSorry but you failed the game and Mr. Hangman died :'(\n");
		printf("If only you were smarter he would've lived\n\n");
	        return 1;
	   }

}
