#include <stdio.h>
#include <string.h>
#include "statements.h"
#include "table.h"
#include "serializer.h"

PrepareStatementResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
	if (strncmp(input_buffer->buffer, "insert", 6) == 0){
		statement->type = STATEMENT_INSERT;
		int args_assigned = sscanf(input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id), statement->row_to_insert.username, statement->row_to_insert.email);
		if (args_assigned < 3)
			return PREPARE_SYNTAX_ERROR;
		return PREPARE_SUCCESS;
	} else if (strcmp(input_buffer->buffer, "select") == 0){
		statement->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	} else {
		return PREPARE_UNRECOGNIZED_STATEMENT;
	}
}

ExecuteResult exec_statement(Statement* statement, Table* table){
	switch (statement->type){
		case (STATEMENT_INSERT):
			return exec_insert(statement, table);
			break;
		case (STATEMENT_SELECT):
			return exec_select(table);
			break;
		}
}

ExecuteResult exec_insert(Statement* statement, Table* table){
	if (table->num_rows >= MAX_TABLE_ROWS)
		return EXECUTE_TABLE_FULL;
	Row* row_to_insert = &(statement->row_to_insert);
	serialize_row(row_to_insert, find_row_slot(table, table->num_rows));
	table->num_rows += 1;

	return EXECUTE_SUCCESS;
}

void print_row(Row* row){
	printf("(%d %s %s)\n", row->id, row->username, row->email);
}

ExecuteResult exec_select(Table* table){
	Row row;
	for (int row_num = 0; row_num < table->num_rows; row_num++){
		deserialize_row(find_row_slot(table, row_num), &row);
		print_row(&row);
	}

	if (table->num_rows == 0)
		printf("The table is empty.\n");

	return EXECUTE_SUCCESS;
}
