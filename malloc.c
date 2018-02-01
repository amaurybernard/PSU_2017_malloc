/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include "header.h"
#include "malloc.h"
#include <errno.h>

static void 	*find_free_space(size_t size)
{

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
		if ((int)genesis == -1 || errno == ENOMEM)
			return  NULL;
		header_elem = genesis;
		taken_head = header_elem;
		free_head = taken_head + size + sizeof(header);
	} else {

		header_elem = find_free_space(size);
		header_add_to_end(taken_head, header_elem);
	}
	header_elem->size = size;
	header_elem->next = NULL;
	return (header_elem + sizeof(header_elem));
}

void 	free(__attribute__((unused)) void *ptr)
{

}
