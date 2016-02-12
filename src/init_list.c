/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_select.h"

void			init_list(t_arg **argu, char **av, int fd)
{
	int			i;
	int			j[2];
	int			tot;
	int			margex;
	int			posx;
	int			posy;

	tot = 0;
	winsize(fd, j);
	i = 1;
	while (av[i])
	{
		i++;
		tot++;
	}
	if (tot > 0)
		margex = (int)(j[0] / tot);
	posy = 5;
	posx = 0;
	// ft_putnbr_fd(j[0], 2);
	// ft_putnbr_fd(j[1], 2);
	i = 1;
	while (av[i])
	{
		posx = margex * i;
		addlist(argu , av[i], posx, posy);
		i++;
	}
}


void			addlist(t_arg **argu, char *av, int posx, int posy)
{
	t_arg		*ptr;
	t_arg		*newm;

	if (!av)
		return ;
	newm = setmarg();
	if (!(*argu))
	{
		*argu = newm;
		newm->name = av;
		newm->x = posx;
		newm->y = posy;
		newm->next = NULL;
		return ;
	}
	ptr = *argu;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newm;
	newm->name = av;
	newm->x = posx;
	newm->y = posy;
	newm->next = NULL;
}


t_arg			*setmarg(void)
{
	t_arg		*newm;

	newm = (t_arg *)malloc(sizeof(t_arg));
	if (!newm)
		return (NULL);
	newm->name = NULL;
	newm->x = 0;
	newm->y = 0;
	newm->next = NULL;
	return (newm);
}