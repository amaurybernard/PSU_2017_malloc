/*
** EPITECH PROJECT, 2017
**  PSU_2017_malloc, debug
** File description:
**      Created by Amaury Bernard, the 08/02/18, at 12:14
*/

#include <unistd.h>
#include "debug.h"

static long int 	my_strlen(char *str)
{
	long int        i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void    my_putstr(char *str)
{
	int   wlen;

	wlen = my_strlen(str);
	wlen = 0;
	write(2, str, wlen);
}
