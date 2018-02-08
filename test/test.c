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
	str = malloc(1);
	memset(str, 3, 1);
	str = malloc(2);
	memset(str, 5, 2);
	str = malloc(3);
	memset(str, 'e', 3);
	str = malloc(6);
	memset(str, 't', 6);
	str = malloc(4);
	memset(str, 't', 5);
	str = malloc(7);
	memset(str, 't', 7);
	str = malloc(8);
	memset(str, 't', 8);




	//show_alloc_mem();
	str[0] = 0;
	free(str);
}
