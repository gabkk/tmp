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


void			addlist(t_arg **argu, char *av, int posx, int posy, int i)
{
	t_arg		*ptr;
	t_arg		*newm;


	if (!av)
		return ;
	newm = setmarg(posx, posy, av);
	if (!(*argu))
	{
		*argu = newm;
		newm->name = av;
		newm->next = NULL;
		newm->prev = NULL;
		newm->index = i;
		newm->focus = 1;
//		first = newm;
//		first->next = *argu;
	}
	ptr = *argu;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newm;
	ptr->next->prev = ptr;
	newm->name = av;
	newm->x = posx;
	newm->y = posy;
	newm->index = i;
	newm->next = NULL;
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
	newm->next = NULL;
	newm->prev = NULL;
	return (newm);
}

void			init_list(t_arg **argu, char **av, t_env *env)
{
	int			i;
	int			margex;
	int			posx;
	int			posy;

	margex = env->j[0];
	posy = 0;
	posx = -1;
	i = 1;

	while (av[i])
	{
		if (margex > i)
			posx++;
		else
		{
			margex += env->j[0] - 1;
			posy += env->wordmax + 2;
			posx = 0;
		}
		addlist(argu , av[i], posx, posy, i);
		i++;
	}
}

void			del_list(t_arg *arg, t_env *env)
{
	t_arg		*ptr;

	ptr = arg;
	while (ptr)
	{
		if (ptr->select == 1)
		{
			if (!(ptr->prev))
			{
				arg = ptr->next;
			}
			else if (!(ptr->next))
			{
				ptr->prev->next = NULL;
			}
			else
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			env->tot -= 1;
			del_list(arg, env);
			free(ptr);
		}
		ptr = ptr->next;
	}
}

void			init_index(t_arg *arg, t_env *env)
{
	t_arg		*ptr;
	int			i;
	int			margex;

	i = 1;
	margex = env->j[0];
	ptr = arg;
	ptr->y = 0;
	ptr->x = -1;
	while (ptr)
	{
		if (margex > i)
			ptr->x++;
		else
		{
			margex += env->j[0] - 1;
			ptr->y += env->wordmax + 2;
			ptr->x = 0;
		}
		ptr->index = i;
		i++;
		ptr = ptr->next;
	}
}
/*------------------------------*/

/* add liste test*/

	// {
	// 	*argu = newm;
	// 	first->next = last->next = NULL;
	// 	first->prev = last->prev = NULL;
	// 	return;
	// }
	// ptr = newm;
	// last->next = newm;
	// newm->prev = last;
	// last = newm;
	// last->next = first;
	// first->prev = last;
	

	// if (!first)
	// {
	// 	first = newm;
	// 	first->next = first;
	// 	return ;
	// }
	// else
	// {
	// 	last = first;
	// 	while (last->next != first)
	// 		last = last->next;
	// 	ptr = newm;
	// 	ptr->next = first;
	// 	ptr = first;
	// 	last->next = newm;
	// }
	// *argu = first;

/* GOOD ONE
	if (!(*argu))
	{
		*argu = newm;
		newm->name = av;
		newm->next = NULL;
		newm->prev = NULL;
//		first = newm;
//		first->next = *argu;
	}
	ptr = *argu;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newm;
	ptr->next->prev = ptr;
	newm->name = av;
	newm->x = posx;
	newm->y = posy;
	newm->next = NULL;
	*/