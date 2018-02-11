/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include <unistd.h>
#include <memory.h>
#include "header.h"
#include "malloc.h"

void 		*realloc(void *ptr, size_t size)
{
	void		*new_ptr;
	header_t	*header_elem;

	if (!ptr)
		return (NULL);
	header_elem = ptr - sizeof(header_t);
	if (!header_is_in_lst(&taken_head, header_elem))
		return (NULL);
	if (size <= header_elem->size) {
		cut_overhang_mem(header_elem, size);
		return (ptr);
	}
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	memcpy(new_ptr - sizeof(header_t), header_elem,
		header_elem->size + sizeof(header_t));
	return (new_ptr);
}