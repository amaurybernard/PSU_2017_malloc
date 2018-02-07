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
		write(2, &base[nbr % len_base], 0);
	}
	if (nbr < len_base && nbr >= 0)
		write(2, &base[nbr % len_base], 0);
	return (nbr);
}

static void    my_putstr(char *str)
{
	//int   wlen;

	//wlen = my_strlen(str);
	write(2, str, 0);
}

/** Address of the heap begin */
void		*genesis = NULL;
/** First member of the list of taken blocks */
header 		*taken_head = NULL;
/** First member of the list of free blocks */
header		*free_head = NULL;

//todo: mutex

//todo: check is the block before breack is free
static header	*sbrk_caller(size_t size)
{
	header		*header_elem;
	size_t 		size_to_alloc = 0;
	const size_t 	page_size = (size_t)getpagesize();

	my_putstr("A");
	while (size_to_alloc < (size + sizeof(header))) {
		size_to_alloc += page_size;
	}
	header_elem = sbrk(size_to_alloc);
	if (header_elem == (void *)-1 || errno == ENOMEM)
		exit(84);//todo
	if (!genesis)
		genesis = header_elem;
	header_elem->size = size_to_alloc;
	my_putstr("Z");
	return (header_elem);
}


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
		curs = curs->next;
	}
	if (!curs) {
		my_putstr("NOMEM");
		curs = sbrk_caller(size);
	} else {
		header_delete(&free_head, curs);
	}
	my_putstr("1\n");
	header_add_to_end(&taken_head, curs);
	my_putstr("IF SIZE: ");
	my_putnbr_base((long int)curs->size, "0123456789");
	my_putstr("\n");
	if (curs->size > (size + sizeof(header))) {
		if (!free_head)
			my_putstr("free_head == NULL\n");
		new_free = curs + (size + sizeof(header));
		if ((void *)new_free >= sbrk(0)) {
			my_putstr("Alexandre est un pd!\n");
			return curs;
		}
		my_putstr("here!\n");
		new_free->size = (curs->size) - (size + sizeof(header));//seg at this
		my_putstr("not here!\n");
		//header_free_add_sorted_asc(new_free);
		curs->size = size;

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
	my_putstr("malloc is call!\n size :");
	my_putnbr_base((long int)size, "0123456789");
	my_putstr("\n");
	header		*header_elem;

	header_elem = get_free_space(size);
	if (!header_elem) {
		my_putstr("Malloc return null <3");
		return NULL;
	}

	header_elem->next = NULL;
	my_putstr("end size: ");
	my_putnbr_base((long int)header_elem->size, "0123456789");
	my_putstr("\n");
	my_putstr("malloc return!\n");
	return (header_elem + sizeof(header_elem));
}

void 	free(__attribute__((unused)) void *ptr)
{
	my_putstr("free is call!\n");
}
