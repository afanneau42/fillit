/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwortham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:10:12 by pwortham          #+#    #+#             */
/*   Updated: 2016/11/19 17:43:27 by pwortham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_error(char *file)
{
	char	*str;
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	str = ft_strnew(512);
	ret = read(fd, str, 511);
	str[ret] = '\0';
	close(fd);
	if (str[ret - 2] == '\n')
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		size;
	t_list	*list;
	t_grid	*grid;

	if (argc < 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if ((list = ft_read(fd)) == NULL || ft_check_error(argv[1]) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	size = (ft_lstcount(list) * 4);
	grid = ft_solve(list, ft_sqrt_grid(size));
	ft_print_grid(grid);
	ft_free_grid(grid);
	ft_free_list(list);
	return (0);
}
