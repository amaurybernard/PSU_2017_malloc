/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by ouranos27,
*/


#include <errno.h>
#include <stdio.h>
#include "malloc.h"
#include "header_free.h"
#include "debug.h"

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
	header			*header_elem;
	size_t 			size_to_alloc = 0;
	const size_t 		page_size = (size_t)getpagesize();

	while (size_to_alloc < (size + sizeof(header))) {
		size_to_alloc += page_size;
	}
	header_elem = sbrk(size_to_alloc);
	if (header_elem == (void *)-1 || errno == ENOMEM)
		return (NULL);
	if (!genesis)
		genesis = header_elem;
	my_putstr("test size: ");
	my_putnbr_base(size_to_alloc, "0123456789");
	my_putstr("\n");
	header_elem->size = size_to_alloc - sizeof(header);
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
		if (!curs)
			return (NULL);
	} else {
		header_delete(&free_head, curs);
	}
	my_putstr("1\n");
	//header_add_to_end(&taken_head, curs);
	my_putstr("IF SIZE: ");
	my_putnbr_base((long int)curs->size, "0123456789");
	my_putstr("\n");
	if (curs->size > (size + sizeof(header))) {
		if (!free_head)
			my_putstr("free_head == NULL\n");
		new_free = (header *)((unsigned long)curs + (unsigned long)size + (unsigned long)sizeof(header));
		if ((void *)new_free >= sbrk(0)) {
			my_putstr("Alexandre est un pd!\n");
			return curs;
		}
		my_putstr("here!\n");
		new_free->next = NULL;
		new_free->size = curs->size;
		new_free->size -= size;
		new_free->size -= sizeof(header) * 2;//seg at this
		my_putstr("not here!\nsize new_free: ");
		my_putnbr_base(new_free->size, "0123456789");
		my_putstr("\n");
		if ((void *)(new_free + new_free->size + sizeof(header)) >= sbrk(0)) {
			my_putstr("Alexandre est un pd!\n");
			return curs;
		}
		header_free_add_sorted_asc(new_free);//todo make it work
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
	if (free_head) {
		header *first = free_head;
		while (first) {
			my_putstr("\t\theader_free curs->size :");
			my_putnbr_base(first->size, "0123456789");
			my_putstr("\n");
			first = first->next;
		}
	}
	my_putstr("malloc is call!\n size :");
	my_putnbr_base((long int)size, "0123456789");
	my_putstr("\n");
	header		*header_elem;

	header_elem = get_free_space(size);
	if (!header_elem) {
		my_putstr("Malloc return null <3");
		return NULL;
	}

	my_putstr("end size: ");
	my_putnbr_base((long int)header_elem->size, "0123456789");
	my_putstr("\n");
	my_putstr("malloc return!\n");
	return (header_elem + sizeof(header_elem));
}

//todo
void 	free(__attribute__((unused)) void *ptr)
{
	my_putstr("free is call!\n");
}

//todo: calloc
/*
void 	*realloc(void *ptr, size_t size)
{

	if (size <= ((header *)(ptr - sizeof(header)))->size)//todo make it free !
		return (ptr);
	return (NULL);
}*/
