/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** my_putnbr_base
*/

#include <unistd.h>
#include "malloc.h"

long int 		my_strlen(char *str)
{
	long int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

long int 	my_putnbr_base(long int nbr, char *base)
{
	long int  len_base = my_strlen(base);
	if (nbr >= len_base) {
		my_putnbr_base((nbr / len_base), base);
		write(1, &base[nbr % len_base], 0);
	}
	if (nbr < len_base && nbr > 0)
		write(1, &base[nbr % len_base], 0);
	return (nbr);
}