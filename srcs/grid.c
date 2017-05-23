/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwortham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:57:31 by pwortham          #+#    #+#             */
/*   Updated: 2016/11/19 17:42:04 by pwortham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_init_tab(size_t size)
{
	char	**grid;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(grid = (char**)malloc(sizeof(grid) * size + 1)))
		return (0);
	while (i < size)
	{
		j = 0;
		if (!(grid[i] = ft_strnew(size + 1)))
			return (0);
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

t_grid	*ft_init_grid(size_t size, char **tab)
{
	t_grid	*grid;

	if (!(grid = (t_grid*)malloc(sizeof(grid))))
		return (0);
	grid->size = size;
	grid->tab = tab;
	return (grid);
}

void	ft_print_grid(t_grid *grid)
{
	size_t i;

	i = 0;
	while (grid->tab[i] != NULL)
	{
		ft_putendl(grid->tab[i]);
		i++;
	}
}
