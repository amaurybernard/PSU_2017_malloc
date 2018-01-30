/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include "malloc.h"

void	*malloc(size_t size)
{
	return (sbrk(size));
}

void 	free(__attribute__((unused)) void *ptr)
{

}