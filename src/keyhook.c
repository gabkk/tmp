/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_select.h"

void		check_key(t_env *env, t_arg **arg)
{
	t_arg	*ptr;
	char	*CD;

	ptr = *arg;
	env->cursorx = 1;
	env->cursory = 1;
	env->draw = 0;
	env->action = 0;
	poscur(0, 0);
	while (1)
	{
		env->ymax = 0;
		env->draw = check_wsize(env);
		if (g_flagsignal == 1 || g_flagsignalz == 1)
		{
		//	tputs(tgetstr("bl", NULL), env->fd, useless);
		//	init_env(env, NULL);
			winsize(env->fd, env->j);
			init_index(arg, env, *arg);
			env->draw = check_wsize(env);
			if (env->draw == 1)
				redraw(arg, ptr, &env);
			else
			{
				poscur(0, 0);
				if ((CD = tgetstr("cd", NULL)) == NULL)
					CD = tgetstr("cl", NULL);
				tputs(CD, env->fd, useless);
				ft_putstr_fd("Your terminal is too small", env->fd);
			}
			g_flagsignal = 0;
			g_flagsignalz = 0;
			//ft_putnbr_fd(ptr->x, env->fd);
			//ft_putnbr_fd(ptr->y, env->fd);
		}
		else if (env->draw == 0 && env->action == 0)
		{
			poscur(0, 0);
			if ((CD = tgetstr("cd", NULL)) == NULL)
				CD = tgetstr("cl", NULL);
			tputs(CD, env->fd, useless);
			ft_putstr_fd("Your terminal is too small", env->fd);	
			env->action = 1;
			//env->draw = check_wsize(env);
		}
		//if ((env->draw = check_wsize(env)) == 1)
		read_input(arg, &ptr, &env);
	}
	return ;
}

void		redraw(t_arg **arg, t_arg *ptr, t_env **env)
{
	char	*CD;

	//tputs(tgetstr("bl", NULL), env->fd, useless);

	poscur(0, 0);
	if ((CD = tgetstr("cd", NULL)) == NULL)
	CD = tgetstr("cl", NULL);
	tputs(CD, (*env)->fd, useless);
	ptr->focus = 1;
	draw_argv(arg, *env);
	//if (next_element(arg, ptr, env) == 1)

	next_element(arg, ptr, env);
	poscur((*env)->cursorx, (*env)->cursory);
}

void			next_element(t_arg **arg, t_arg *ptr, t_env **env)
{
	(void)arg;
	(*env)->cursory = ptr->y;
	(*env)->cursorx = ptr->x;
	// if (reset_cursor(arg, env) == 1)
	// 	poscur(0, 0, NULL);
}

t_arg			*get_index(int index, t_arg *arg)
{
	t_arg		*ptr;

	ptr = arg;
	while (ptr)
	{
		if (ptr->index == index)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

