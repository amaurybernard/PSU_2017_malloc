/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include <unistd.h>
#include <memory.h>
#include "header.h"


void 		*realloc(void *ptr, size_t size)
{
	void	*new_ptr = malloc(size);

	if (!new_ptr)
		return (NULL);
	if (!ptr)
		return (new_ptr);
	if (size <= ((header_t *)(ptr - sizeof(header_t)))->size) {
		memcpy(new_ptr, ptr, size);
	} else
		memcpy(new_ptr, ptr, ((header_t *)(ptr - sizeof(header_t)))->size);
	free(ptr);
	return (new_ptr);
}