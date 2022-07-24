#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

int main(int argc, char** argv)
{
	if(argc < 4)
	{
		fprintf(stderr, "Usage: b2b <source base> <destination base> <first number> ... <last number>\n");
		exit(EXIT_FAILURE);
	}

	for(int i=3; i < argc; i++)
	{
		switch(atoi(argv[2]))
		{
			case 8:
				fprintf(stdout, "%.llo\n", strtouq(argv[i], NULL, atoi(argv[1])));
				break;
			case 10:
				fprintf(stdout, "%.llu\n", strtouq(argv[i], NULL, atoi(argv[1])));
				break;
			case 16:
				fprintf(stdout, "%.llX\n", strtouq(argv[i], NULL, atoi(argv[1])));
				break;
			default:
				fprintf(stderr, "Error: destination base %s is unsupported!\n", argv[2]); 
				exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}
