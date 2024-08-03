#include <stdio.h>

int symbol_counter(FILE *fptr)
{
	fseek(fptr, 0, SEEK_END);
	size_t length = ftell(fptr);
	char content[length];
	
	while(fgets(content, length, fptr))
	{
		// TODO: Count number of letters a-z 
	}
}


int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		fprint(stderr, "Missing txt-file input\n");
		return 1;
	}
	if(argc > 2)
	{
		fprint(stderr, "Too many inputs\n");
		return 1;
	}

	char *filename = argv[1];
	FILE *fptr = fopen(filename, "r");
	
	if(fptr = NULL)
	{
		fprint(stderr, "Error opening file");
		return 1;
	}
	
	
	
	return 0;
}


