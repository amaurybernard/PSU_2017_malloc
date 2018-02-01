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

	static void		*genesis = NULL;
	static header 		*headers_head = NULL;

#endif /* !PSU_2017_MALLOC_MALLOC_H */
