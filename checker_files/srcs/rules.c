/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaimes <cjaimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:15:08 by cjaimes           #+#    #+#             */
/*   Updated: 2021/03/04 22:16:59 by cjaimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_first(t_bucket *bk)
{
	if (bk->length <= 1)
		return;
	bk->stack->value = bk->stack->value ^ bk->stack->next->value;
	bk->stack->next->value = bk->stack->value ^ bk->stack->next->value;
	bk->stack->value = bk->stack->value ^ bk->stack->next->value;
}

void	rotate(t_bucket *bucket)
{
	t_link *ffirst;

	if (bucket->length <= 1)
		return;
	ffirst = bucket->stack->next;
	bucket->stack->next->prev = 0;
	bucket->stack->next = 0;
	bucket->last->next = bucket->stack;
	bucket->stack->prev = bucket->last;
	bucket->last = bucket->stack;
	bucket->stack = ffirst;
}

void reverse_rotate(t_bucket *bucket)
{
	t_link *flast;

	if (bucket->length <= 1)
		return;
	flast = bucket->last->prev;
	bucket->last->prev->next = 0;
	bucket->last->prev = 0;
	bucket->stack->prev = bucket->last;
	bucket->last->next = bucket->stack;
	bucket->stack = bucket->last;
	bucket->last = flast;
}

void push_multi_case(t_bucket *b1, t_bucket *b2)
{
	t_link *temp;

	temp = b1->stack;
	b1->stack = b1->stack->next;
	b1->stack->prev = 0;
	b2->stack->prev = temp;
	temp->next = b2->stack;
	b2->stack = temp;
}

void push(t_bucket *b1, t_bucket *b2)
{	
	if (!b1->length)
		return;
	if (b1->length == 1)
	{
		b2->stack->prev = b1->stack;
		b1->stack->next = b2->stack;
		b2->stack = b1->stack;
		b1->stack = 0;
		b1->last = 0;
	}
	else if (!b2->length)
	{
		b2->stack = b1->stack;
		b2->last = b2->stack;
		b1->stack = b1->stack->next;
		b1->stack->prev = 0;
		b2->stack->next = 0;
		b2->stack->prev = 0;
	}
	else
		push_multi_case(b1, b2);
	b1->length--;
	b2->length++;
}