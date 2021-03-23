/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaimes <cjaimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:05:49 by cjaimes           #+#    #+#             */
/*   Updated: 2021/03/23 15:40:18 by cjaimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		is_number_n_e(char *input, int size)
{
	char	*start;
	int		neg;

	neg = 0;
	if (*input == '+' || *input == '-')
	{
		neg = *input == '-' ? 1 : 0;
		input++;
		size--;
	}
	start = input;
	while (size-- > 0)
		if (!ft_isdigit(*input++))
			return (0);
	return (1);
}

int		split_arg(t_link **first, char *arg) {
	char	**split;
	char	**copy;
	t_link	*ele;

	split = ft_split(arg, ' ');
	copy = split;
	while (*split)
	{
		if (is_number_n_e(*split, ft_strlen(*split)))
		{
			ele = ft_lnknew(ft_atoi(*split));
			ft_lnkadd_back(first, ele);
		}
		else {
			ft_printf("ERROR\n");
			ft_lnkclear(first);
			free(copy);
			exit(1);
		}
		split++;
	}
	free(copy);
	return (0);
}

t_link	*check_valid_args(int ac, char **args)
{
	t_link *first;
	t_link *list;
	int		i;

	i = 0;
	first = 0;
	while (ac--)
	{
		if (is_number_n_e(args[i + 1], ft_strlen(args[i + 1])))
		{
			list = ft_lnknew(ft_atoi(args[i + 1]));
			ft_lnkadd_back(&first, list);
		}
		else
			split_arg(&first, args[i + 1]);
		i++;
	}
	return (first);
}

void print_states(t_bucket *b11, t_bucket *b22)
{
	t_link *b1 = b11->stack;
	t_link *b2 = b22->stack;
	ft_printf("Stack A | Stack B\n");
	while(b1 || b2)
	{
		if (b1 && b2)
		{
			ft_printf("    %-4d|    %-4d\n", b1->value, b2->value);
			b1 = b1->next;
			b2 = b2->next;
		}
		else if (b1)
		{
			ft_printf("    %-4d|\n", b1->value);
			b1 = b1->next;
		}
		else if (b2)
		{
			ft_printf("        |    %-4d\n", b2->value);
			b2 = b2->next;
		}
	}
}

void print_reverse_states(t_bucket *b11, t_bucket *b22)
{
	t_link *b1 = b11->last;
	t_link *b2 = b22->last;
	ft_printf("Stack A | Stack B\n");
	while(b1 || b2)
	{
		if (b1 && b2)
		{
			ft_printf("    %-4d|    %-4d\n", b1->value, b2->value);
			b1 = b1->prev;
			b2 = b2->prev;
		}
		else if (b1)
		{
			ft_printf("    %-4d|\n", b1->value);
			b1 = b1->prev;
		}
		else if (b2)
		{
			ft_printf("        |    %-4d\n", b2->value);
			b2 = b2->prev;
		}
	}
}

int	check_in_order(t_bucket *b, int total)
{
	t_link *first;

	first = b->stack;
	if (b->length != total)
		return (0);
	while (first)
	{
		if (first->next)
			if (first->value > first->next->value)
				return (0);
		first = first->next;
	}
	return (1);
}

void	bubblesort(int* array, int len) {
	int j;

	len--;
	while (len > 0)
	{
		j = 0;
		while (j < len) {
			if (array[j] > array[j + 1])
			{
				array[j] = array[ j] ^ array[j + 1];
				array[j + 1] = array[j] ^ array[j + 1];
				array[j] = array[j] ^ array[j + 1];
			}
			j++;
		}
		len--;
	}
}

void	sort_from_pivot(t_bucket *a, t_bucket *b, int pivot, int len)
{
	t_link *val;

	val = a->stack;
	while (len--)
	{
		if (val->value < pivot)
		{
			ft_printf("pa\n");
			push(a, b);
		}
		else
		{
			ft_printf("ra\n");
			rotate(a);
		}
		val = a->stack;
	}
}

void	fill_array(int *arr, t_link *list)
{
	while (list)
	{
		*arr = list->value;
		arr++;
		list = list->next;
	}
}

int main(int ac, char **av)
{
	t_bucket main;
	t_bucket reserve;
	int		*array;

	int		min;
	int		med;
	int		max;

	if (ac == 1)
		return (0);
	main.stack = check_valid_args(ac - 1, av);
	main.last = ft_lnklast(main.stack);
	main.length = ft_lnk_count(main.stack);
	array = malloc(sizeof(int) * (main.length + 1));
	if (!array)
	{
		return (0);
	}
	fill_array(array, main.stack);
	reserve.stack = 0;
	reserve.last = 0;
	if (!main.stack)
		return (0);
	reserve.length = 0;
	if (main.length == 1)
	{
		ft_printf("OK\n");
		return(0);
	}
	bubblesort(array, main.length);
	min = array[0];
	med = array[(main.length - 1) / 2 + ((main.length - 1) % 2)];
	max = array[main.length - 2];
	sort_from_pivot(&main, &reserve, med, main.length);
	// from this moment, hi array is on main stack, low array in reserve

	// algo:
	// step 1: find median of whole array
	// step 2: sort array in 2 sub arrays (2 stacks) with hi on one side, lo on other
	// step 3: recurively find median on one side and keep sorting until sub array length is small enough so solve linearly

}