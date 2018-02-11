/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/


#include <errno.h>
#include <stdio.h>
#include <pthread.h>
#include "malloc.h"
#include "header_free.h"

/** Address of the heap begin */
void		*genesis = NULL;
/** First member of the list of taken blocks */
header_t 		*taken_head = NULL;
/** First member of the list of free blocks */
header_t		*free_head = NULL;
/** multi thread locker */
pthread_mutex_t 	mutex = PTHREAD_MUTEX_INITIALIZER;

/**
* allocate the right numbers of pages
* todo: check is the block before breck is free
* @param size
* @return new free block
*/
static header_t	*sbrk_caller(size_t size)
{
	header_t			*header_elem;
	size_t 			size_to_alloc = 0;
	const size_t 		page_size = (size_t)getpagesize();

	while (size_to_alloc < (size + sizeof(header_t))) {
		size_to_alloc += page_size;
	}
	header_elem = sbrk(size_to_alloc);
	if (header_elem == (void *)-1 || errno == ENOMEM)
		return (NULL);
	if (!genesis)
		genesis = header_elem;
	header_elem->size = size_to_alloc - sizeof(header_t);
	return (header_elem);
}

void		cut_overhang_mem(header_t *curs, size_t size)
{
	header_t	*new_free;

	if (curs->size > (size + sizeof(header_t))) {
		new_free = (header_t *)((unsigned long)curs +
			(unsigned long)size + (unsigned long)sizeof(header_t));
		new_free->next = NULL;
		new_free->size = curs->size - size - sizeof(header_t);
		curs->size = size;
		new_free->isFree = true;
		header_free_add_sorted_asc(new_free);
	}
}

/**
* Return the first element who have enough space
* @param size without header
* @return ptr to header of free sapce
*/
static header_t	*get_free_space(size_t size)
{
	header_t	*curs = free_head;

	while (curs && curs->size < size)
		curs = curs->next;
	if (!curs) {
		curs = sbrk_caller(size);
		if (!curs)
			return (NULL);
	} else {
		header_delete(&free_head, curs);
	}
	curs->isFree = false;
	header_add_to_end(&taken_head, curs);
	cut_overhang_mem(curs, size);
	return (curs);
}

/**
* @warning /!\ Add block others threads
* @param size
* @return
*/
void	*malloc(size_t size)
{
	header_t		*header_elem;

	pthread_mutex_lock(&mutex);
	if (size == 0) {
		pthread_mutex_unlock(&mutex);
		return (NULL);
	}
	header_elem = get_free_space(size);
	if (!header_elem) {
		pthread_mutex_unlock(&mutex);
		return (NULL);
	}
	pthread_mutex_unlock(&mutex);
	return ((void *)((unsigned long)header_elem
		+ (unsigned long)sizeof(header_t)));
}

void	*calloc(size_t nmemb, size_t size)
{
	return (malloc(nmemb * size));
}