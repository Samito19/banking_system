#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <stdint.h>
#include "table.h"

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 55
#define MAX_TABLE_PAGES 100
#define PAGE_SIZE 4096

typedef struct {
	uint32_t id;
	char username[COLUMN_USERNAME_SIZE];
	char email[COLUMN_EMAIL_SIZE];
} Row;

extern const uint32_t ROW_SIZE;
extern const uint32_t ROWS_PER_PAGE;
extern const uint32_t MAX_TABLE_ROWS;

void serialize_row(Row*, void*);
void deserialize_row(void*, Row*);

#endif
