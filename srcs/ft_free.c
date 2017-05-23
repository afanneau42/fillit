/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwortham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:01:21 by pwortham          #+#    #+#             */
/*   Updated: 2016/11/19 14:28:01 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid	*ft_free_grid(t_grid *grid)
{
	int	i;

	i = 0;
	while (grid->tab[i] != NULL)
	{
		ft_memdel((void**)&(grid->tab[i]));
		i++;
	}
	ft_memdel((void**)&grid);
	return (NULL);
}

t_list	*ft_free_list(t_list *lst)
{
	t_list *tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		ft_memdel((void**)&lst);
		lst = tmp;
	}
	return (NULL);
}
