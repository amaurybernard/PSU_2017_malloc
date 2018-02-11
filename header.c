/*
** EPITECH PROJECT, 2021
** Project
** File description:
** Created by ouranos27,
*/

#include "header.h"

/**
* Add new_elem at the end of the list
* @param first != NULL
* @param new_elem != NULL
*/
void	header_add_to_end(header_t **first, header_t *new_elem)
{
	header_t	*curs = *first;

	new_elem->next = NULL;
	if (!curs) {
		*first = new_elem;
		return ;
	}
	while(curs->next != NULL) {
		curs = curs->next;
	}
	curs->next = new_elem;
}

/**
* Add new_elem after elem in the list
* @param first != NULL
* @param new_elem != null && new_elem->next == NULL
*/
void	header_add_after_elem(header_t *elem, header_t *new_elem)
{
       new_elem->next = elem->next;
       elem->next = new_elem;
}

/**
* Delete to_delete in first lst
* @param first != NULL
* @param to_delete != NULL
*/
void	header_delete(header_t **first, header_t *to_delete)
{
	if (*first == to_delete) {
		*first = (*first)->next ? (*first)->next : NULL;
		return ;
	}
	while ((*first)->next != to_delete) {
		if (!(*first)->next)
			return;
		*first = (*first)->next;
	}
	(*first)->next = (*first)->next->next;
	to_delete->next = NULL;
}