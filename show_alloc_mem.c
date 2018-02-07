/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

//#include <stdio.h>
#include "malloc.h"
#include "show_alloc_mem.h"

void 		show_alloc_mem(void)
{
	header	*head = (header *)genesis;

	write(1, "break : 0x", 10);
	my_putnbr_base((long int)sbrk(0), "0123456789abcdef");
	write(1, "\n", 1);
	my_putnbr_base((long int)sizeof(header), "0123456789");
	while (head) {
		if (head >= (header *)sbrk(0))
			break ;
		/*write(1, "\nhead : ", 8);
		my_putnbr_base((long int)head, "0123456789");*/
		write(1, "\n0x", 3);
		my_putnbr_base((long int)head + sizeof(header), "0123456789abcdef");
		write(1, " - 0x", 5);
		my_putnbr_base((long int)head + sizeof(header) + (long int)head->size - 1,
			"0123456789abcdef");
		write(1, " : ", 3);
		my_putnbr_base((long int)head->size, "0123456789");
		head = head + head->size + sizeof(header);
	}
	write(1, "\n", 1);
}