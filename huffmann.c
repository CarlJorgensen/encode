#include <stdio.h>

int symbol_counter(FILE *fptr)
{
	int occurrences[26];
	for(int i=0; i < 25; i++)
	{
		occurrences[i] = 0;
	}

	char c;
	while((c = fgetc(fptr)) != EOF)
	{
		c = tolower(c);
		if(c => "a" && c <= "z")
		{
			// ASCII: a->97, b->98 ...
			occurrences[c-"a"]++; // Increment at inat index  c=a the occurrences[0]++  
		}
	}
	return 0;
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
	
	int ret = symbol_counter(fptr);

	fclose(fptr);

	return ret;
}


