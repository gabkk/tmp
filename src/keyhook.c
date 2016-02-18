/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				check_key(t_env *env, t_arg **arg)
{
	t_arg			*ptr;

	ptr = *arg;
	env->cursorx = 1;
	env->cursory = 1;
	env->draw = 0;
	env->action = 0;
	poscur(0, 0, env);
	while (1)
	{
		env->ymax = 0;
		env->draw = check_wsize(env);
		if (g_flagsignal == 1 || g_flagsignalz == 1)
			check_signal(arg, ptr, env);
		else if (env->draw == 0 && env->action == 0)
		{
			draw_small(env);
			env->action = 1;
		}
		read_input(arg, &ptr, &env);
	}
	return ;
}

void				check_signal(t_arg **arg, t_arg *ptr, t_env *env)
{
	winsize(env->fd, env->j);
	init_index(arg, env, ptr);
	env->draw = check_wsize(env);
	if (env->draw == 1)
		redraw(arg, ptr, &env);
	else
		draw_small(env);
	g_flagsignal = 0;
	g_flagsignalz = 0;
}

void				draw_small(t_env *env)
{
	char			*cd;

	poscur(0, 0, env);
	if ((cd = tgetstr("cd", NULL)) == NULL)
		cd = tgetstr("cl", NULL);
	ft_putstr_fd(cd, env->fd);
	ft_putstr_fd("Your terminal is to small", env->fd);
}

void				redraw(t_arg **arg, t_arg *ptr, t_env **env)
{
	char			*cd;

	poscur(0, 0, *env);
	if ((cd = tgetstr("cd", NULL)) == NULL)
		cd = tgetstr("cl", NULL);
	ft_putstr_fd(cd, (*env)->fd);
	draw_argv(arg, *env);
	(*env)->cursory = ptr->y;
	(*env)->cursorx = ptr->x;
	poscur((*env)->cursorx, (*env)->cursory, *env);
}

t_arg				*get_index(int index, t_arg *arg)
{
	t_arg			*ptr;

	ptr = arg;
	while (ptr)
	{
		if (ptr->index == index)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
