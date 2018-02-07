/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/

#include "malloc.h"
#include "header_free.h"
#include <errno.h>
#include <stdio.h>



static long int                my_strlen(char *str)
{
	long int        i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

static long int        my_putnbr_base(long int nbr, char *base)
{
	long int  len_base = my_strlen(base);
	if (nbr >= len_base) {
		my_putnbr_base((nbr / len_base), base);
		write(1, &base[nbr % len_base], 1);
	}
	if (nbr < len_base && nbr >= 0)
		write(1, &base[nbr % len_base], 1);
	return (nbr);
}

static void    my_putstr(char *str)
{
	int   wlen;

	wlen = my_strlen(str);
	write(1, str, wlen);
}

/** Address of the heap begin */
void		*genesis = NULL;
/** First member of the list of taken blocks */
header 		*taken_head = NULL;
/** First member of the list of free blocks */
header		*free_head = NULL;

//todo: mutex

/**
* Return the first element who have enough space
* @param size without header
* @return ptr to header of free sapce
*/
static header	*get_free_space(size_t size)
{
	my_putstr("get_free!\n");
	header	*curs;
	header	*new_free;

	curs = free_head;
	while (curs && curs->size < size) {
		my_putstr("Z\n");
		curs = curs->next;
	}
	my_putstr("A\n");
	if (!curs) {
		my_putstr("NOMEM");
		//sbrk(getpagesize());//todo: chek if the last block of the page is free add it to free lst
		return NULL;//head == null OR NOMEM <-- new page;
	} else {
		my_putstr("B\n");
		header_delete(&free_head, curs);
		header_add_to_end(taken_head, curs);
		my_putstr("C\n");

		my_putstr("size: ");
		my_putnbr_base((long int)curs->size, "0123456789");
		my_putstr("\n");
		if (curs->size > (size + sizeof(header))) {
			if (!free_head)
				my_putstr("free_head == NULL\n");
			my_putstr("D\n");
			new_free = curs + (size + sizeof(header));//
			my_putstr("new_free: 0x");
			my_putnbr_base((long int)new_free, "0123456789abcdef");
			my_putstr("\n");
			my_putstr("E\n");
			new_free->size = curs->size - (size + sizeof(header));//seg at this line
			my_putstr("F\n");
			header_free_add_sorted_asc(new_free);
			my_putstr("G\n");
			curs->size = size;//fai2 fois
			my_putstr("E\n");
		}
	}
	my_putstr("get_free end!\n");
	return curs;
}

/**
* @warning /!\ Add block others threads
* @param size
* @return
*/
void	*malloc(size_t size)
{
	my_putstr("malloc is call!\n");
	header		*header_elem;
	size_t 		size_to_alloc = 0;
	const size_t 	page_size = (size_t)getpagesize();

	if (!genesis) {
		while (size_to_alloc < (size + sizeof(header))) {
			size_to_alloc += page_size;
		}
		genesis = sbrk(size_to_alloc);
		if ((long int)genesis == -1 || errno == ENOMEM)
			return  NULL;
		header_elem = genesis;
		taken_head = header_elem;
		//todo: handle if there is no more space OK => Handle if free_head == NULL
		if (size_to_alloc > size + sizeof(header)) {
			free_head = genesis + (size + sizeof(header));
			free_head->size = size_to_alloc - (size + (sizeof(header) * 2));
			free_head->next = NULL;
		}
	} else {
		header_elem = get_free_space(size);
		//header_add_to_end(taken_head, header_elem);
	}

	if (!header_elem) {
		my_putstr("Malloc return null <3");
		return NULL;
	}
	header_elem->size = size;
	header_elem->next = NULL;
	my_putstr("malloc return!\n");

	return (header_elem + sizeof(header_elem));
}

void 	free(__attribute__((unused)) void *ptr)
{
	my_putstr("free is call!\n");
}
