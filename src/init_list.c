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

void			init_list(t_arg **argu, char **av, int fd, t_env *env)
{
	int			i;
	int			margex;
	int			posx;
	int			posy;

	(void)fd;
	margex = env->j[0];

	posx = 0;
	posy = -1;
	i = 1;
	while (av[i])
	{
		if (margex > i)
			posy++;
		else
		{
			margex += env->j[0] - 1;
			posx += 1;
			posy = 0;
		}
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