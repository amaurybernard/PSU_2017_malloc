/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include "malloc.h"
#include "header_free.h"
#include <errno.h>

/**
* Return the first element who have enough space
* @param size without header
* @return ptr to header of free sapce
*/
static void 	*get_free_space(size_t size)
{
	header	*curs;
	header	*new_free;

	curs = free_head;
	while (!curs && curs->size >= size + sizeof(header)) {
		curs = curs->next;
	}
	if (!curs) {
		sbrk(getpagesize());//chek if the last block of the page is free add it to free lst
		return NULL;//head == null OR NOMEM <-- new page;
	} else { //cut
		header_delete(free_head, curs);
		header_add_to_end(taken_head, curs);
		if (curs->size > size + (sizeof(header) * 2)) {
			new_free = curs + size + sizeof(header);
			new_free->size = curs->size - (size + sizeof(header));
			header_free_add_sorted_asc(new_free);
			curs->size -= new_free->size;
		}
	}
	return curs;
}

/**
* @warning /!\ Add block others threads
* @param size
* @return
*/
void	*malloc(size_t size)
{
	header		*header_elem;

	if (!genesis) {
		genesis = sbrk(getpagesize());
		if ((long int)genesis == -1 || errno == ENOMEM)
			return  NULL;
		header_elem = (header *)genesis;
		taken_head = header_elem;
		free_head = taken_head + size + sizeof(header);
		free_head->size = getpagesize() - size + sizeof(header);
		free_head->next = NULL;
	} else {
		header_elem = get_free_space(size);
		header_add_to_end(taken_head, header_elem);
	}
	header_elem->size = size;
	header_elem->next = NULL;
	return (header_elem + sizeof(header_elem));
}

void 	free(__attribute__((unused)) void *ptr)
{

}
