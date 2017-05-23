/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwortham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:40:58 by pwortham          #+#    #+#             */
/*   Updated: 2016/11/19 16:37:13 by pwortham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tetri(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 1] == '#')
			count++;
		if (str[i] == '#' && str[i - 1] == '#')
			count++;
		if (str[i] == '#' && str[i + 5] == '#')
			count++;
		if (str[i] == '#' && str[i - 5] == '#')
			count++;
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		ft_check_grid(char *str, int count)
{
	int	i;
	int nb;

	i = 0;
	nb = 0;
	while (i < count)
	{
		if (((i + 1) % 5 == 0 || i == 20) && str[i] == '\n')
			i++;
		else if (i + 1 % 5 != 0 && str[i] == '.')
			i++;
		else if (i + 1 % 5 != 0 && str[i] == '#')
		{
			i++;
			nb++;
		}
		else
			return (0);
	}
	if (ft_check_tetri(str) != 0 && nb == 4)
		return (1);
	return (0);
}

t_list	*ft_read(int fd)
{
	t_list	*list;
	t_tetri *piece;
	char	*buf;
	char	charact;
	int		count;

	list = NULL;
	charact = 'A';
	count = 0;
	if ((buf = ft_strnew(21)) == 0)
		return (0);
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (ft_check_grid(buf, count) == 0 ||
				(piece = ft_save_tetri(buf, charact++)) == NULL)
		{
			return (ft_free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(piece, sizeof(t_tetri)));
	}
	if (count != 0)
		return (ft_free_list(list));
	ft_lstrev(&list);
	close(fd);
	return (list);
}
