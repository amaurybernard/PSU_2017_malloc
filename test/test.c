/*
** EPITECH PROJECT, 2017
**  PSU_2017_malloc, test
** File description:
**      Created by Amaury Bernard, the 05/02/18, at 16:57
*/

#include "malloc.h"
#include "../show_alloc_mem.h"

int 	main()
{
	char 	*str = malloc(6);

	if (!str)
		return (84);
	show_alloc_mem();
	str[0] = 0;
	free(str);
}
