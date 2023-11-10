#include <stdlib.h>
#include <string.h>
#include "meta_commands.h"
#include "table.h"

MetaCommandResult exec_meta_command(InputBuffer* input_buffer, Table* table) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
	  free_table(table);
    exit(EXIT_SUCCESS);
  } else {
    return META_COMMAND_UNRECOGNIZED;
  }
}

