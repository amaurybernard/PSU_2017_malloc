/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include "malloc.h"
#include "header_free.h"
#include <errno.h>
#include <stdio.h>

/** Address of the heap begin */
void		*genesis = NULL;
/** First member of the list of taken blocks */
header 		*taken_head = NULL;
/** First member of the list of free blocks */
header		*free_head = NULL;

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
		sbrk(getpagesize());//todo: chek if the last block of the page is free add it to free lst
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
	size_t 		size_to_alloc = 0;
	const size_t 	page_size = (size_t)getpagesize();

	if (!genesis) {
		while (size_to_alloc < (size + sizeof(header))) {
			size_to_alloc += page_size;
		}
		genesis = sbrk(size_to_alloc);
		if ((long int)genesis == -1 || errno == ENOMEM)
			return  NULL;
		header_elem = genesis;
		taken_head = header_elem;
		//todo: handle if there is no more space OK => Handle if free_head == NULL
		if (size_to_alloc > size + sizeof(header)) {
			free_head = genesis + size + sizeof(header);
			free_head->size = -size + sizeof(header);
			free_head->next = NULL;
		}
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
