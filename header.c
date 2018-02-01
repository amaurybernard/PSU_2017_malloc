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
* @param new_elem != NULL && new_elem->next == NULL
*/
void	header_add_to_end(header *first, header *new_elem)
{
	while(first->next != NULL) {
		first = first->next;
	}
	first->next = new_elem;
}

/**
* Add new_elem after elem in the list
* @param first !@null
* @param new_elem !@null && new_elem->next == @null
*/
void	header_add_after_elem(header *elem, header *new_elem)
{
       new_elem->next = elem->next;
       elem->next = new_elem;
}
