/*
** EPITECH PROJECT, 2017
**  PSU_2017_malloc, header_free
** File description:
**      Created by Amaury Bernard, the 05/02/18, at 13:04
*/

#include "malloc.h"

void 	header_free_add_at_head(header *new_head)
{
	new_head->next = free_head;
	free_head = new_head;
}


/**
* Add sorted by size in the list (for the free lst)
* @param first != NULL
* @param to_add to_add->next != NULL
*/
void 	header_free_add_sorted_asc(header *to_add) {
	header	*prev = NULL;
	header	*first = free_head;

	while (first->size >= to_add->size && first->next) {
		prev = first;
		first = first->next;
	}
	if (!prev) {
		header_free_add_at_head(to_add);
	} else {
		header_add_after_elem(prev, to_add);
	}
}

