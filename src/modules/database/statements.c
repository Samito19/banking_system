#include <stdio.h>
#include <string.h>
#include "statements.h"

PrepareStatementResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
	if (strncmp(input_buffer->buffer, "insert", 6) == 0){
		statement->type = STATEMENT_INSERT;
		return PREPARE_SUCCESS;
	} else if (strcmp(input_buffer->buffer, "select") == 0){
		statement->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	} else {
		return PREPARE_UNRECOGNIZED_STATEMENT;
	}
}

void exec_statement(Statement* statement){
	switch (statement->type){
		case (STATEMENT_INSERT):
			printf("This is where we would do an insert...\n");
			break;
		case (STATEMENT_SELECT):
			printf("This is where we would do a select...\n");
			break;
		}
}
