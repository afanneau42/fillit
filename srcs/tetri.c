/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwortham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:57:26 by pwortham          #+#    #+#             */
/*   Updated: 2016/11/19 15:57:23 by pwortham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_tab(char *tetri, char **tetrimi,
		t_point *min, t_point *max)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = min->y * 5;
	while (i < max->y - min->y + 1)
	{
		j = 0;
		k = k + min->x;
		tetrimi[i] = ft_strnew(max->x - min->x + 1);
		while (k < (max->x + ((k / 5) * 5)) + 1)
		{
			tetrimi[i][j] = tetri[k];
			j++;
			k++;
		}
		tetrimi[i][j] = '\0';
		while (k % 5 != 0)
			k++;
		i++;
	}
	tetrimi[i] = NULL;
	return (tetrimi);
}

t_tetri	*ft_create_tetri(char **tetrimi, int large, int longu, char c)
{
	t_tetri	*tetris;

	if (!(tetris = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	tetris->str = tetrimi;
	tetris->large = large;
	tetris->longu = longu;
	tetris->value = c;
	return (tetris);
}

t_point	*ft_create_point(int x, int y)
{
	t_point	*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		return (0);
	point->x = x;
	point->y = y;
	return (point);
}

void	ft_minmax(char *tetri, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '#')
		{
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

t_tetri	*ft_save_tetri(char *tetri, char c)
{
	t_point	*min;
	t_point *max;
	char	**tetrimi;
	int		i;
	t_tetri	*piece;

	i = 0;
	min = ft_create_point(3, 3);
	max = ft_create_point(0, 0);
	ft_minmax(tetri, min, max);
	if (!(tetrimi = (char**)malloc(sizeof(*tetrimi) * (max->y - min->y + 2))))
		return (0);
	tetrimi = ft_create_tab(tetri, tetrimi, min, max);
	piece = ft_create_tetri(tetrimi, max->x - min->x + 1,
			max->y - min->y + 1, c);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (piece);
}
