#include <stdio.h>
#include <stdlib.h>

int recurse(int in) {
	if (in == 0) {
		return 0;
	} 
	
	int total = recurse(in - 1) + in;
	printf("total: %i - in: %i \n", total, in);
	return total;
}

int main (int argc, char**  argv) {
	
	int input = 3;
	if (argc > 1) {
		char* inc = argv[1];
		// input = ;
		// puts(inc);
		input = atoi(inc);
	}

	printf("%i\n", recurse(input));
}