/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			addlist(t_arg **argu, char *av, int px, int py)
{
	t_arg		*ptr;
	t_arg		*newm;

	if (!av)
		return ;
	newm = setmarg(px, py, av);
	if (!(*argu))
	{
		*argu = newm;
		init_first(&newm, av);
		return ;
	}
	ptr = *argu;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newm;
	ptr->next->prev = ptr;
	newm->name = av;
	newm->x = px;
	newm->y = py;
	newm->index = 0;
	newm->next = NULL;
}

void			init_first(t_arg **newm, char *av)
{
	(*newm)->name = av;
	(*newm)->next = NULL;
	(*newm)->prev = NULL;
	(*newm)->index = 1;
	(*newm)->focus = 1;
}

t_arg			*setmarg(int posx, int posy, char *av)
{
	t_arg		*newm;

	newm = (t_arg *)malloc(sizeof(t_arg));
	if (!newm)
		return (NULL);
	newm->name = av;
	newm->x = posx;
	newm->y = posy;
	newm->focus = 0;
	newm->select = 0;
	newm->index = 0;
	newm->next = NULL;
	newm->prev = NULL;
	return (newm);
}

void			init_list(t_arg **argu, char **av, t_env **env)
{
	int			i;
	int			margex;
	int			posx;
	int			posy;

	margex = (*env)->j[0];
	posy = 0;
	posx = -1;
	i = 1;
	while (av[i])
	{
		if (margex > i)
			posx++;
		else
		{
			margex += (*env)->j[0] - 1;
			posy += (*env)->wordmax + 2;
			if ((*env)->ymax < posy)
				(*env)->ymax = posy;
			posx = 0;
		}
		addlist(argu, av[i], posx, posy);
		set_i(argu, i);
		i++;
	}
}

void			set_i(t_arg **argu, int i)
{
	t_arg		*ptr;

	ptr = *argu;
	while (ptr->next)
		ptr = ptr->next;
	if (ptr)
		ptr->index = i;
}
