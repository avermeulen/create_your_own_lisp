
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <editline/readline.h>
// #include <editline/history.h>

// static char input[2048];


int main() {
	puts("Lipsy version 0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		
		char* input = readline("lispy> ");

		add_history(input);

		// fgets(input, 2048, stdin);
		if (strcmp(input, "exit") == 0) {
			break;
		}

		printf("No you're a %s\n", input);
		free(input);

	}

}