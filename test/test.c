/*
** EPITECH PROJECT, 2017
**  PSU_2017_malloc, test
** File description:
**      Created by Amaury Bernard, the 05/02/18, at 16:57
*/

#include <memory.h>
#include "malloc.h"
#include "../show_alloc_mem.h"

int 	main()
{
	char 	*str = malloc(6);

	if (!str)
		return (84);
	str = malloc(552);
	memset(str, 3, 552);
	str = malloc(120);
	memset(str, 5, 120);
	str = malloc(1024);
	memset(str, 'e', 1024);
	str = malloc(5);
	memset(str, 't', 5);
	str = malloc(120);
	memset(str, 't', 120);
	str = malloc(776);
	memset(str, 't', 776);
	str = realloc(str, 1025);
	show_alloc_mem();
	str[0] = 0;
	free(str);
}