
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <editline/readline.h>
#include "mpc.h"

// static char input[2048];


int main() {

	/* Create Some Parsers */
	mpc_parser_t* Number   = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr     = mpc_new("expr");
	mpc_parser_t* Lispy    = mpc_new("lispy");

	mpca_lang(MPCA_LANG_DEFAULT,
		"                                                     \
			number   : /-?[0-9]+/ ;                             \
			operator : '+' | '-' | '*' | '/' | '%' | /add/ | /sub/ | /mul/ | /div/ ;   \
			expr     : <number> | '(' <operator> <expr>+ ')'  ;  \
			lispy    : /^/ <operator> <expr>+ /$/ | /^/ <expr> <operator> <expr> /$/ ;             \
		",
		Number, Operator, Expr, Lispy);


	puts("Lipsy version 0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		
		char* input = readline("lispy> ");

		add_history(input);

		// fgets(input, 2048, stdin);
		if (strcmp(input, "\\q") == 0) {
			break;
		}

		mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lispy, &r)) {
			/* On Success Print the AST */
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		} else {
			/* Otherwise Print the Error */
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}


		// printf("No you're a %s\n", input);
		// free(input);

	}

	mpc_cleanup(4, Number, Operator, Expr, Lispy);

}