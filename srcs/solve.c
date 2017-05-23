/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwortham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:40:36 by pwortham          #+#    #+#             */
/*   Updated: 2016/11/19 17:43:25 by pwortham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_tetri(t_tetri *tetri, t_grid *grid, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < tetri->longu)
	{
		j = 0;
		while (j < tetri->large)
		{
			if (tetri->str[i][j] == '#')
				grid->tab[i + y][j + x] = tetri->value;
			j++;
		}
		i++;
	}
}

void	ft_place_dot(t_tetri *tetri, t_grid *grid, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < tetri->longu)
	{
		j = 0;
		while (j < tetri->large)
		{
			if (tetri->str[i][j] == '#')
				grid->tab[i + y][j + x] = '.';
			j++;
		}
		i++;
	}
}

int		ft_check_place(t_tetri *tetri, t_grid *grid, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < tetri->longu)
	{
		j = 0;
		while (j < tetri->large)
		{
			if (tetri->str[i][j] == '#' && grid->tab[i + y][j + x] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_place_tetri(tetri, grid, x, y);
	return (1);
}

int		ft_solve_grid(t_list *lst, t_grid *grid)
{
	t_tetri	*tetri;
	size_t	x;
	size_t	y;

	if (lst == NULL)
		return (1);
	tetri = (t_tetri*)lst->content;
	y = 0;
	while (y <= grid->size - tetri->longu)
	{
		x = 0;
		while (x <= grid->size - tetri->large)
		{
			if (ft_check_place(tetri, grid, x, y) == 1)
			{
				if (ft_solve_grid(lst->next, grid) == 1)
					return (1);
				else
					ft_place_dot(tetri, grid, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_grid	*ft_solve(t_list *lst, int size)
{
	char	**tab;
	t_grid	*grid;

	tab = ft_init_tab(size);
	grid = ft_init_grid(size, tab);
	while ((ft_solve_grid(lst, grid)) == 0)
	{
		free(grid);
		size++;
		tab = ft_init_tab(size);
		grid = ft_init_grid(size, tab);
	}
	return (grid);
}
