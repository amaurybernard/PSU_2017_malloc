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
		my_putstr("header_free curs->size :");
		my_putnbr_base(curs->size, "0123456789");
		my_putstr("\n");
		my_putstr("header_free to_add->size :");
		my_putnbr_base(to_add->size, "0123456789");
		my_putstr("\n");

		prev = curs;
		curs = curs->next;
	}
	if (!prev) {//Pas d'élément dans la liste ou size < à tout les autres
		if (free_head){
		my_putstr("\t\t !prev\n");
		my_putstr("\t\theader_free before free_head->size :");
		my_putnbr_base(free_head->size, "0123456789");
		my_putstr("\n");
		}
		to_add->next = free_head;
		free_head = to_add;

		if (free_head) {
			my_putstr("\t\theader_free after free_head->size :");
			my_putnbr_base(free_head->size, "0123456789");
			my_putstr("\n");
		}
	} else if (!curs) { //fin de la list
		my_putstr("a");
		prev->next = to_add;
	} else {//au mileu
		my_putstr("b");
		to_add->next = prev->next;
		prev->next = to_add;
	}
	my_putstr("\n");
}
