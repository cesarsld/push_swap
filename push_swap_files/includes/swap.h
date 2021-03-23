/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaimes <cjaimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:06:15 by cjaimes           #+#    #+#             */
/*   Updated: 2021/03/23 13:36:24 by cjaimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include "ft_printf.h"

typedef struct		s_link
{
	int				value;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;


typedef struct		s_bucket
{
	t_link			*stack;
	t_link			*last;
	int				length;
}					t_bucket;

t_link	*ft_lnknew(int v);

void	ft_lnkadd_front(t_link **alst, t_link *new);
void	ft_lnkadd_back(t_link **alst, t_link *new);
void	ft_lnkdelone(t_link *lst);
void	ft_lnkclear(t_link **lst);
t_link	*ft_lnklast(t_link *lst);
int		ft_lnk_count(t_link *lst);

void	swap_first(t_bucket *bk);
void	rotate(t_bucket *bucket);
void reverse_rotate(t_bucket *bucket);
void push(t_bucket *b1, t_bucket *b2);

#endif