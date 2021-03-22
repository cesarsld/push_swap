/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaimes <cjaimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:05:49 by cjaimes           #+#    #+#             */
/*   Updated: 2021/03/22 10:59:41 by cjaimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		else {
			ft_printf("ERROR\n");
			ft_lnkclear(&first);
			exit(1);
		}
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

int	find_median(t_bucket *b)
{
	t_link	*first;
	int		med;
	int		over;
	int		under;
	int		min;
	int		max;

	med = b->stack->value;
	min = med;
	max = med;
	over =  0;
	under = 0;
	first = b->stack->next;
	while (first)
	{
		if (first->value > max)
			max = 
	}
}

int main(int ac, char **av)
{
	t_bucket main;
	t_bucket reserve;
	char	*user_input;

	if (ac == 1)
		return (0);
	main.stack = check_valid_args(ac - 1, av);
	main.last = ft_lnklast(main.stack);
	main.length = ac - 1;
	reserve.stack = 0;
	reserve.last = 0;
	if (!main.stack)
		return (0);
	reserve.length = 0;
	if (ac == 2)
	{
		ft_printf("OK\n");
		return(0);
	}
	while (1)
	{
		if (check_in_order(&main, ac - 1))
		{
			ft_lnkclear(&(main.stack));
			ft_printf("OK\n");
			return(0);
		}
		if (!get_next_line(STDIN_FILENO, &user_input))
			return (0);
		if (ft_strcmp(user_input, "sa") == 0)
			swap_first(&main);
		else if (ft_strcmp(user_input, "sb") == 0)
			swap_first(&reserve);
		else if (ft_strcmp(user_input, "ss") == 0)
		{
			swap_first(&main);
			swap_first(&reserve);
		}
		else if (ft_strcmp(user_input, "ra") == 0)
			rotate(&main);
		else if (ft_strcmp(user_input, "rb") == 0)
			rotate(&reserve);
		else if (ft_strcmp(user_input, "rr") == 0)
		{
			rotate(&main);
			rotate(&reserve);
		}
		else if (ft_strcmp(user_input, "rra") == 0)
			reverse_rotate(&main);
		else if (ft_strcmp(user_input, "rrb") == 0)
			reverse_rotate(&reserve);
		else if (ft_strcmp(user_input, "rrr") == 0)
		{
			reverse_rotate(&main);
			reverse_rotate(&reserve);
		}
		else if (ft_strcmp(user_input, "pa") == 0)
			push(&main, &reserve);
		else if (ft_strcmp(user_input, "pb") == 0)
			push(&reserve, &main);
		print_states(&main, &reserve);
		//print_reverse_states(&main, &reserve);
	}
}