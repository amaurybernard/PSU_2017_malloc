/*
** EPITECH PROJECT, 2021
** Project
** File description:
** Created by ouranos27,
*/

#include "header.h"

void	add_to_end(header *first, header *new_elem)
{
	while(first->next != NULL) {
		
		first = first->next;
	}
	first->next = new_elem;
}

void	add_after_elem(header *elem, header *new_elem)
{
       new_elem->next = elem->next;
       elem->next = new_elem;
}
