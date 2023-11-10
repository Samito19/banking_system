#include <stdlib.h>
#include "table.h"

#define MAX_TABLE_PAGES 100

Table* new_table(){
	Table* table = (Table*)malloc(sizeof(Table));
	table->num_rows = 0;

	for (int i = 0; i < MAX_TABLE_PAGES; i++) {
		table->pages[i] = NULL;
	}
	
	return table;
}	

void free_table(Table* table){
	for (int i = 0; table->pages[i]; i++)
		free(table->pages[i]);

	free(table);
}


/* This function allows us to find the slot of a row in a table by calculating the offset */
void* find_row_slot(Table* table, int num_rows){
	/*Calculate the next non-full page available and store its memory address */
	uint32_t page_num = num_rows / ROWS_PER_PAGE;
	void* page = table->pages[page_num];
	
	/* If page is empty then allocate space for it */
	if (page == NULL)
		page = table->pages[page_num] = malloc(PAGE_SIZE);

	/*Calculate the next available slot within the page */
	uint32_t rows_offset = num_rows % ROWS_PER_PAGE;
	uint32_t bytes_offset = rows_offset * ROW_SIZE;
	
	/* Finally return a pointer to the next available row slot in the table */
	return page + bytes_offset; 
}
