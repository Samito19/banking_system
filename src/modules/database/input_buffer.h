#include <stdlib.h>

#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

typedef struct {
  char* buffer;
  size_t b_length; // Buffer length
  ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void read_input(InputBuffer*);
void close_input_buffer(InputBuffer*);
#endif
