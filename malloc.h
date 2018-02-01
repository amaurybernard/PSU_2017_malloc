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

	void 	*malloc(size_t);
	void	free(void *ptr);

	/** Address of the heap begin */
	static const void	*genesis = NULL;
	/** First member of the list of taken blocks */
	static header 		*taken_head = NULL;
	/** First member of the list of free blocks */
	static header		*free_head = NULL;

#endif /* !PSU_2017_MALLOC_MALLOC_H */
