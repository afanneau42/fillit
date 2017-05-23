/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwortham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:16:03 by pwortham          #+#    #+#             */
/*   Updated: 2016/11/19 10:31:41 by pwortham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_lstcount(t_list *lst)
{
	size_t		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstrev(t_list **alst)
{
	t_list *prev;
	t_list *curr;
	t_list *next;

	prev = NULL;
	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*alst = prev;
}

int		ft_sqrt_grid(int size)
{
	int	r;

	r = 2;
	while (r * r < size)
		r++;
	return (r);
}
