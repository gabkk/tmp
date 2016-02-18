/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			init_index(t_arg **arg, t_env *env, t_arg *argfocus)
{
	t_arg		*ptr;

	ptr = *arg;
	env->tot = 0;
	env->wordmax = 0;
	(void)argfocus;
	if (!*arg)
		exit(0);
	while (ptr)
	{
		if (ft_strlen(ptr->name) > (size_t)env->wordmax)
			env->wordmax = ft_strlen(ptr->name);
		env->tot++;
		ptr = ptr->next;
	}
	set_index(arg, env, argfocus);
}

void			set_index(t_arg **arg, t_env *env, t_arg *argfocus)
{
	int			x;
	int			y;
	t_arg		*ptr;
	int			i;
	int			margex;

	margex = env->j[0];
	i = 1;
	y = 0;
	x = -1;
	ptr = *arg;
	while (ptr)
	{
		if (i < margex)
			new_line(&ptr, &x, &y);
		else
		{
			margex += env->j[0] - 1;
			y += env->wordmax + 2;
			new_colomn(&ptr, &env, &x, y);
		}
		ptr->index = i++;
		set_focus(&ptr, argfocus);
		ptr = ptr->next;
	}
}

void			set_focus(t_arg **ptr, t_arg *argfocus)
{
	if (*ptr != argfocus)
		(*ptr)->focus = 0;
}

void			new_line(t_arg **ptr, int *x, int *y)
{
	*x += 1;
	(*ptr)->x = *x;
	(*ptr)->y = *y;
}

void			new_colomn(t_arg **ptr, t_env **env, int *x, int y)
{
	if ((*env)->ymax < y)
		(*env)->ymax = y;
	(*ptr)->y = y;
	(*ptr)->x = 0;
	*x = 0;
}
