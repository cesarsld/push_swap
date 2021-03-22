/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaimes <cjaimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:10:19 by cjaimes           #+#    #+#             */
/*   Updated: 2021/03/04 20:25:40 by cjaimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_link	*ft_lnklast(t_link *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


t_link	*ft_lnknew(int v)
{
	t_link	*new_ele;

	if (!(new_ele = malloc(sizeof(t_link))))
		return (NULL);
	new_ele->value = v;
	new_ele->next = NULL;
	new_ele->prev = NULL;
	return (new_ele);
}

void	ft_lnkadd_front(t_link **alst, t_link *new)
{
	if (!alst || !new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	new->next = *alst;
	(*alst)->prev = new;
	*alst = new;
}

void	ft_lnkadd_back(t_link **alst, t_link *new)
{
	t_link *last;

	if (!alst || !new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	last = ft_lnklast(*alst);
	last->next = new;
	new->prev = last;
}

void	ft_lnkdelone(t_link *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lnkclear(t_link **lst)
{
	t_link *next;
	t_link *first;

	if (!lst || !(*lst))
		return ;
	first = *lst;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lnkdelone(*lst);
		*lst = next;
	}
	first = NULL;
}