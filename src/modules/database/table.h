#ifndef TABLE_H
#define TABLE_H

#include <stdlib.h>
#include "serializer.h"

typedef struct {
	int num_rows;
	void* pages[MAX_TABLE_PAGES];
} Table;

Table* new_table();
void free_table(Table*);
void* find_row_slot(Table*, int);

#endif
