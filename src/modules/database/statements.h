#include <stdint.h>
#include "input_buffer.h"
#include "table.h"

typedef enum {
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT,
	PREPARE_SYNTAX_ERROR
} PrepareStatementResult;

typedef enum {
	STATEMENT_INSERT,
	STATEMENT_SELECT
} StatementType;

typedef struct {
	StatementType type;
	Row row_to_insert;
} Statement;

typedef enum {
	EXECUTE_SUCCESS,
	EXECUTE_TABLE_FULL
} ExecuteResult;

PrepareStatementResult prepare_statement(InputBuffer*, Statement*);
ExecuteResult exec_statement(Statement*, Table*);
ExecuteResult exec_insert(Statement*, Table*);
ExecuteResult exec_select(Table*);
