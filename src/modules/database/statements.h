#include "input_buffer.h"

typedef enum {
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
} PrepareStatementResult;

typedef enum {
	STATEMENT_INSERT,
	STATEMENT_SELECT
} StatementType;

typedef struct {
	StatementType type;
} Statement;

PrepareStatementResult prepare_statement(InputBuffer*, Statement*);
void exec_statement(Statement*);
