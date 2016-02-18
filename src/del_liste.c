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

#include "ft_select.h"

t_arg			*del_list(t_arg **arg, t_env *env)
{
	t_arg		*tmpfocus;

	if (!(*arg))
	{
		exit_fct(env);
		exit(0);
	}
	tmpfocus = NULL;
	do_the_del(arg, &tmpfocus, env);
	if (tmpfocus)
		tmpfocus->focus = 1;
	return (tmpfocus);
}

void			do_the_del(t_arg **arg, t_arg **tmpfocus, t_env *env)
{
	t_arg		*ptr;

	ptr = *arg;
	while (ptr)
	{
		if (ptr->focus == 1)
		{
			if (!ptr->next && !ptr->prev)
			{
				free(ptr);
				exit_fct(env);
				exit(0);
			}
			if (ptr->next && ptr->prev)
				del_normal(&ptr, tmpfocus);
			else if (!ptr->prev)
				*arg = first_del(&ptr, tmpfocus, *arg);
			else if (!ptr->next)
				last_del(&ptr, tmpfocus, *arg);
		}
		ptr = ptr->next;
	}
}

void			del_normal(t_arg **ptr, t_arg **tmpfocus)
{
	if ((*ptr)->focus == 1)
		*tmpfocus = (*ptr)->next;
	(*ptr)->prev->next = (*ptr)->next;
	(*ptr)->next->prev = (*ptr)->prev;
	free(*ptr);
}

t_arg			*first_del(t_arg **ptr, t_arg **tmpfocus, t_arg *arg)
{
	t_arg		*tmp;

	if ((*ptr)->focus == 1)
		*tmpfocus = get_index(2, arg);
	tmp = (*ptr)->next;
	free(*ptr);
	tmp->prev = NULL;
	return (tmp);
}

void			last_del(t_arg **ptr, t_arg **tmpfocus, t_arg *arg)
{
	if ((*ptr)->focus == 1)
		*tmpfocus = get_index(1, arg);
	(*ptr)->prev->next = NULL;
	free(*ptr);
}
