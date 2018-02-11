/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include "malloc.h"
#include "header_free.h"

void	 		free(void *ptr)
{
	header_t	*header_elem;

	if (!ptr)
		return ;
	pthread_mutex_lock(&mutex);
	header_elem = ptr - sizeof(header_t);
	if (header_is_in_lst(&taken_head, header_elem)) {
		header_delete(&taken_head, header_elem);
		header_free_add_sorted_asc(header_elem);
		header_elem->isFree = true;
	}
	pthread_mutex_unlock(&mutex);
}