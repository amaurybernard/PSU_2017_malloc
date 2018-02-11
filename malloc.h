/*
** EPITECH PROJECT, 2017
**  PSU_2017_malloc, malloc
** File description:
**      Created by Amaury Bernard, the 30/01/18, at 14:52
*/

#ifndef PSU_2017_MALLOC_MALLOC_H
	#define PSU_2017_MALLOC_MALLOC_H

	#include <unistd.h>
	#include <stdlib.h>
	#include "header.h"

	void 	*malloc(size_t);
	void	free(void *ptr);
	//void	*realloc(void *ptr, size_t size);

	/** Address of the heap begin */
	extern void		*genesis;
	/** First member of the list of taken blocks */
	extern header_t 		*taken_head;
	/** First member of the list of free blocks */
	extern header_t		*free_head;

#endif /* !PSU_2017_MALLOC_MALLOC_H */
