/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 11:59:19 by gkuma             #+#    #+#             */
/*   Updated: 2015/05/19 12:17:31 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		*ft_memalloc(size_t size)
{
	void*ptr;
	size_t i;

	i = 0;
	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}


int		main(void)
{
	char		*memalloc;
	int			i;

	i = 0;
	ft_putchar('\n');
	memalloc = ft_memalloc(3);
	memalloc = "yo";
	ft_putchar(memalloc[5]);
	ft_putchar('\n');
	ft_putstr(memalloc);
	ft_putchar('\n');
}
