/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:51:55 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/10 11:29:27 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	int			i;
	void		*str;

	i = 0;
	if ((str = malloc(size)) != NULL)
	{
		while (((char *)str)[i])
		{
			((char *)str)[i] = '\0';
			i++;
		}
		return (str);
	}
	return (0);
}
