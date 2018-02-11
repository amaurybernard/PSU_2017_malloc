/*
** EPITECH PROJECT, 2017
*
**  PSU_2017_malloc, header_free
** File description:
**      Created by Amaury Bernard, the 05/02/18, at 13:04
*/

#include "debug.h"
#include "malloc.h"

void 	header_free_add_at_head(header_t *new_head)
{
	new_head->next = free_head;
	free_head = new_head;
}


/**
* Add sorted by size in the list (for the free lst)
* @param to_add to_add->next != NULL
*/
void 	header_free_add_sorted_asc(header_t *to_add) {
	header_t *curs = free_head ;
	header_t *prev = NULL;

	to_add->next = NULL;
	while (curs && curs->size < to_add->size) {
		prev = curs;
		curs = curs->next;
	}
	if (!prev) {
		to_add->next = free_head;
		free_head = to_add;
	} else if (!curs) { //fin de la list
		prev->next = to_add;
	} else {
		to_add->next = prev->next;
		prev->next = to_add;
	}
}
