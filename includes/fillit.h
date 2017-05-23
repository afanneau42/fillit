/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwortham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 09:26:59 by pwortham          #+#    #+#             */
/*   Updated: 2016/11/19 14:27:35 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_grid
{
	size_t		size;
	size_t		best;
	char		**tab;
}				t_grid;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	char		**str;
	int			large;
	int			longu;
	char		value;
}				t_tetri;

size_t			ft_lstcount(t_list *lst);
void			ft_lstrev(t_list **alst);
int				ft_sqrt_grid(int size);
char			**ft_init_tab(size_t size);
t_grid			*ft_init_grid(size_t size, char **tab);
void			ft_print_grid(t_grid *grid);
int				ft_check_tetri(char *str);
int				ft_check_grid(char *str, int count);
t_list			*ft_read(int fd);
void			ft_place_tetri(t_tetri *tetri, t_grid *grid, int x, int y);
void			ft_place_dot(t_tetri *tetri, t_grid *grid, int x, int y);
int				ft_check_place(t_tetri *tetri, t_grid *grid, int x, int y);
int				ft_solve_grid(t_list *lst, t_grid *grid);
t_grid			*ft_solve(t_list *lst, int size);
char			**ft_create_tab(char *tetri, char **tetrimi,
		t_point *min, t_point *max);
t_tetri			*ft_create_tetri(char **tetrimi, int large, int longu, char c);
t_point			*ft_create_point(int x, int y);
void			ft_minmax(char *tetri, t_point *min, t_point *max);
t_tetri			*ft_save_tetri(char *tetri, char c);
t_grid			*ft_free_grid(t_grid *grid);
t_list			*ft_free_list(t_list *list);

#endif
