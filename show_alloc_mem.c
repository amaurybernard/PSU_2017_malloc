/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include "debug.h"
#include "malloc.h"
#include "show_alloc_mem.h"

static void	show_address(char *str, const void *ptr)
{
	my_putstr(str);
	write(1, "0x", 2);
	my_putnbr_base((long)ptr, "0123456789abcdef");
	write(1, "\n", 1);
}

/*
static void	show_block(header_t *header_block) {
	write(1, "\n0x", 3);
	my_putnbr_base((long)header_block + sizeof(header_t), "0123456789abcdef");
	write(1, " - 0x", 5);
	my_putnbr_base((long)header_block + sizeof(header_t)
			+ (long)header_block->size - 1,
		"0123456789abcdef");
	write(1, " : ", 3);
	my_putnbr_base((long)header_block->size, "0123456789");
}*/

static void	show_block_state(header_t *header_block) {
	write(1, "\n0x", 3);
	my_putnbr_base((long)header_block + sizeof(header_t), "0123456789abcdef");
	write(1, " - 0x", 5);
	my_putnbr_base((long)header_block + (long)sizeof(header_t)
			+ (long)header_block->size - (long)1,
		"0123456789abcdef");
	write(1, " : ", 3);
	my_putnbr_base((long)header_block->size, "0123456789");
	write(1, " : ", 3);
	my_putstr(header_block->isFree ? " free" : " TAKEN");
}

void 		show_alloc_mem(void)
{
	header_t		*header_curs = genesis;
	const void	*heap_end = sbrk(0);

	if (!genesis)
		return;
	show_address("break : ", heap_end);
	while ((void *)header_curs < heap_end) {
		show_block_state(header_curs);
		header_curs = (header_t *)((unsigned long)header_curs
			+ (unsigned long)header_curs->size
			+ (unsigned long)sizeof(header_t));
	}
	write(1, "\n", 1);
}