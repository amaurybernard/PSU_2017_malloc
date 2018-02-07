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

	typedef struct		header {
		size_t		size;
		struct header	*next;
	}			header;

	void	header_add_to_end(header **first, header *new_elem);
	void	header_add_after_elem(header *elem, header *new_elem);
	void	header_delete(header **first, header *to_delete);

#endif /* !PROJECT_HEADER_H*/
