/*
** EPITECH PROJECT, 2021
** Project
** File description:
** Created by ouranos27,
*/

#include "header.h"

header	*head = NULL;

header		*append(header *elem, size_t size)
{
	header	*ret = elem + elem->size;
	ret->size = size;
	ret->next = NULL;
	return	(ret);
}