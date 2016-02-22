/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg					*get_right(t_arg **arg, t_arg *source, t_env *env)
{
	t_arg				*ptr;

	ptr = *arg;
	if (source->y == env->ymax)
	{
		while (ptr)
		{
			if (ptr->x == source->x)
				return (ptr);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (ptr->x == source->x && ptr->y == (source->y + env->wordmax + 2))
				return (ptr);
			ptr = ptr->next;
		}
	}
	return (NULL);
}

t_arg					*get_left(t_arg **arg, t_arg *source, t_env *env)
{
	t_arg				*ptr;

	ptr = *arg;
	if (source->y == 0)
	{
		while (ptr)
		{
			if (ptr->x == source->x && ptr->y == env->ymax)
				return (ptr);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (ptr->x == source->x && ptr->y ==\
				(source->y - (env->wordmax + 2)))
				return (ptr);
			ptr = ptr->next;
		}
	}
	return (NULL);
}

void					select_all(t_arg **arg, t_env **env)
{
	t_arg				*ptr;

	ptr = *arg;
	while (ptr)
	{
		if ((*env)->all == 0)
			ptr->select = 1;
		else
			ptr->select = 0;
		ptr = ptr->next;
	}
	if ((*env)->all == 0)
		(*env)->all = 1;
	else
		(*env)->all = 0;
}

t_arg					*reset_arg(t_arg **arg, t_env **env, char **av)
{
	t_arg				*ptr;
	t_arg				*tmp;

	ptr = *arg;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(ptr);
	*arg = NULL;
	init_list(arg, av, env);
	winsize((*env)->fd, (*env)->j);
	init_index(arg, *env, ptr);
	(*env)->draw = check_wsize(*env);
	(*arg)->focus = 1;
	(*env)->all = 0;
	if ((*env)->draw == 1)
		redraw(arg, *arg, env);
	else
		draw_small(*env);
	return (*arg);
}

void					change_color(t_env **env, char c)
{
	if (c == '+' && (*env)->color < 231)
		(*env)->color++;
	else if (c == '-' && (*env)->color > 35)
		(*env)->color--;
}
