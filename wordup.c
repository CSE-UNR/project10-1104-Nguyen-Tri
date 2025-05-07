//CS 135 - Project 10
//Author: Duy Tri Nguyen
//Instructor: Erin Keith

#include<stdio.h>
#include<stdbool.h>

void mysteryword( char mystery_word[])
{
	FILE *input;
	input = fopen("word.txt", "r");
	if ( input == NULL )
	{
		printf("Can't open file!\n");
	}
	fscanf(input,"%s", mystery_word);
	fclose(input);
}
int checksize(char guess[])
{
	int j = 0;
	while ( guess[j] != '\0')
	{
		j++;
	}
	if ( j > 5 )
	{
	return false;
	}
	return true;
}
int checkword( char guess[] )
{
	for ( int i = 0 ; i < 5; i++ )
	{
		if ( (guess[i] >= 'a' && guess[i] <= 'z' ) || ( guess[i] >= 'A' && guess[i] <= 'Z' ))
		{
			continue;
		}
		else return false;
	}
	return true;
}
void getuserinput( int i, char guess[])
{
	printf("GUESS %d! Enter your guess: ",i + 1);
	scanf("%s", guess);
	int j = 0;
	if ( checksize(guess) == false )
	{
		int length = 0;
		while ( length != 5 )
		{
			printf("Your guess must be 5 letters long.\n");
			printf("Please try again: ");
			scanf("%s", guess);
			int j = 0;
			while ( guess[j] != '\0')
			{	
				j++;
			}
			length = j;
		}
	}
	while ( checkword(guess) == false )
	{
		printf("Your guess must contain only letters.\n");
		printf("Please try again: ");
		scanf("%s", guess);
	}
}
int anticapitalize( char guess[] )
{
	for ( int i = 0 ; i < 5 ; i++ )
	{
		if ( guess[i] >= 'A' && guess[i] <= 'Z' )
		{
			return true;
		}
	}
	return false;
}
int check( char guess[], char mystery_word[])
{
	if ( anticapitalize(guess) == true )
	{
		for ( int i = 0 ; i < 5 ; i++ )
		{
			if ( guess[i] >= 'A' && guess[i] <= 'Z' )
			{
				guess[i] += 32;
			}
		}
	}
	for ( int i = 0 ; i < 5; i++ )
	{
		if ( guess[i] != mystery_word[i] )
		{
			return false;
		}
	}
	return true;
}
void displaywrong( char a[][6], char b[], int current )
{
	for ( int i = 0 ; i < 5; i++)
	{
		if ( a[current][i] == b[i] )
		{
			printf("%c", b[i] - 32);
		}
		else
		{
			printf("%c", a[current][i]);
		}
	}
	printf("\n");
	for ( int i = 0 ; i < 5 ; i++ )
	{
		int tmp = true;
		for ( int j = 0 ; j < 5 ; j++ )
		{
			if ( a[current][i] == b[j] && i != j )
			{
				printf("^");
				tmp = false;
				break;
			}
		}
		if ( tmp == true )
		{
			printf(" ");
		}
	}
	
}
void displaycongratulation( char mystery_word[], int k)
{
	for ( int i = 0 ; i < 12; i++ )
	{
		printf(" ");
	}
	for ( int i = 0 ; i < 5; i++ )
	{
		printf("%c", mystery_word[i] - 32);
	}
	for ( int i = 0 ; i < 12; i++ )
	{
		printf(" ");
	}
	printf("\n");
	for ( int i = 0 ; i < 5; i++ )
	{
		printf(" ");
	}
	printf("You won in %d guess!\n", k + 1);
	for ( int i = 0 ; i < 12 ; i++ )
	{
		printf(" ");
	}
	printf("GOATED!\n");		
}
int main()
{
	char mystery_word[6];
	mysteryword(mystery_word);
	int i = 0;
	char oldword[6][6];
	char guess[6];
	while ( i < 6 )
	{
		if ( i == 5 )
		{
			printf("FINAL GUESS : ");
			scanf("%s", guess);
			if ( check(guess, mystery_word) == false )
			{
				printf("You lost, better luck next time!\n");
				return 0;				
			}
			else 
			{
				displaycongratulation(mystery_word, i);
				return 0;
			}
		}
		else
		{
		getuserinput(i,guess);
		if ( check(guess, mystery_word) == false )
		{
			for( int j = 0 ; j < 5 ; j++)
			{
				oldword[i][j] = guess[j];
			}
			for( int i = 0 ; i < 24 ; i++ )
			{
				printf("=");
			}
			printf("\n");
			int j = 0;
			while ( j <= i )
			{
				displaywrong(oldword, mystery_word, j);	
				printf("\n");	
				j++;
			}
		}
		else 
		{
			displaycongratulation(mystery_word, i);
			return 0;
		}
		
	}
	i++;
	}
	return 0;
}
