/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include "malloc.h"
#include "header_free.h"

void	 		free(void *ptr)
{
	header_t	*current = taken_head;
	bool	check = false;

	if (!ptr)
		return ;
	while (current) {
		if (current->size ==
			((header_t *)(ptr - sizeof(header_t)))->size) {
			check = true;
			break ;
		}
		current = current->next;
	}
	if (check == true) {
		header_delete(&taken_head, current);
		header_free_add_sorted_asc(current);
	}
}