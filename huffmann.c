#include <stdio.h>
#include <ctype.h>
/*
TODO: 
1. Sort list of symbols based off frequency. -> Priority queue.
2. Error handling for non-ASCII symbols and symbols not a-z. 
*/

typedef struct
{
	char character;
	int frequency;
} symbol;


symbol *character_frequency(FILE *fptr)
{

	// Init array, set every symbol counter to 0.
	symbol *list = (symbol*)malloc(26 * sizeof(symbol));
	if(list == NULL)
	{
		printf("Allocation error");
		return NULL;
	}


	for(int i=0; i < 25; i++)
	{
		list[i].character= 'a' + i;
		list[i].frequency = 0;
	}

	char c;
	while((c = fgetc(fptr)) != EOF)
	{
		c = tolower(c);
		if(c >= 'a' && c <= 'z')
		{
			// ASCII: a->97, b->98 ...
			list[c - 'a'].frequency++; // Increment frequency counter in array
		}
	}

	return list;

}


int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("error: missing txt-file input\n");
		return 1;
	}
	if(argc > 2)
	{
		printf("error: too many inputs\n");
		return 1;
	}

	char *filename = argv[1];

	FILE *fptr = fopen(filename, "r");
	
	if(fptr == NULL)
	{
		printf("error opening file");
		return 1;
	}
	
	symbol *list= character_frequency(fptr);
	

	fclose(fptr);

	return ret;
}


