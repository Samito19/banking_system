#ifndef META_COMMANDS_H

#define META_COMMANDS_H
#include "input_buffer.h"
#include "table.h"

typedef enum {
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED
} MetaCommandResult;

MetaCommandResult exec_meta_command(InputBuffer*, Table*);
#endif
