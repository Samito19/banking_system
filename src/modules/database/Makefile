CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi -std=gnu99

main: repl.c
	$(CC) $(CFLAGS) -o repl repl.c input_buffer.c meta_commands.c statements.c serializer.c table.c && ./repl
