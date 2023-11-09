#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "input_buffer.h"
#include "meta_commands.h"
#include "statements.h"

int main(int argc, char* argv[]){
	InputBuffer* input_buffer = new_input_buffer();
	
	while (true){
		printf("db > ");
		read_input(input_buffer);

		if (input_buffer->buffer[0] == '.'){
			switch(exec_meta_command(input_buffer)){
				case (META_COMMAND_SUCCESS):
					continue;
				case (META_COMMAND_UNRECOGNIZED):
					printf("Unrecognized command %s\n", input_buffer->buffer);
					continue;
			}
		}

		Statement statement;
		switch (prepare_statement(input_buffer, &statement)){
			case (PREPARE_SUCCESS):
				break;
			case (PREPARE_UNRECOGNIZED_STATEMENT):
				printf("Unrecoginized keyword at the start of %s.\n", input_buffer->buffer);
				continue;
		}

		exec_statement(&statement);
		printf("Statement executed.\n");

	}
	return 0;
}



