/*
** EPITECH PROJECT, 2021
** Project
** File description:
** Created by ouranos27,
*/
#ifndef PROJECT_HEADER_H
	#define PROJECT_HEADER_H
	#include <unistd.h>
	#include <stdlib.h>
	#include <stdbool.h>

	typedef struct		header_s {
		size_t		size;
		struct header_s	*next;
		bool		isFree;
	}			header_t;

	void	header_add_to_end(header_t **first, header_t *new_elem);
	void	header_add_after_elem(header_t *elem, header_t *new_elem);
	void	header_delete(header_t **first, header_t *to_delete);
	bool	header_is_in_lst(header_t **head, header_t *ptr);
	void	cut_overhang_mem(header_t *curs, size_t size);

#endif /* !PROJECT_HEADER_H*/
