/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				start_new_w(t_env *env)
{
	char			*cd;
	char			*ti;

	if ((ti = tgetstr("ti", NULL)))
		ft_putstr_fd(ti, env->fd);
	ft_putstr_fd(tgetstr("vi", NULL), env->fd);
	poscur(0, 0, env);
	if ((cd = tgetstr("cd", NULL)) == NULL)
		cd = tgetstr("cl", NULL);
	ft_putstr_fd(cd, env->fd);
}

void				draw_argv(t_arg **arg, t_env *env)
{
	t_arg			*ptr;
	t_arg			*argfocus;
	int				x;
	int				reachtot;

	reachtot = 0;
	x = 0;
	if (env->del == 1)
	{
		argfocus = del_list(arg, env);
		init_index(arg, env, argfocus);
		env->del = 0;
	}
	while (reachtot < env->tot)
	{
		ptr = *arg;
		draw_argv_loop(ptr, env, x, &reachtot);
		x++;
		if (x < env->j[0] - 1)
			ft_putchar_fd('\n', env->fd);
	}
	// ft_putendl_fd("", env->fd);
	// ft_putnbr_fd(env->tot, env->fd);
	// ft_putendl_fd("", env->fd);
	// ft_putnbr_fd(env->j[0], env->fd);
	// ft_putendl_fd("", env->fd);
	// ft_putnbr_fd(env->j[1], env->fd);
	ft_putendl_fd("", env->fd);
	ft_putnbr_fd(env->ymax, env->fd);
	ft_putendl_fd("", env->fd);
	ft_putnbr_fd(env->wordmax, env->fd);
}

void				draw_argv_loop(t_arg *ptr, t_env *env, int x, int *rt)
{
	int				size;

	size = 0;
	while (ptr)
	{
		if (ptr->x == x)
		{
			size = ft_strlen(ptr->name);
			if (size < env->wordmax)
				size = env->wordmax - size + 2;
			else
				size = 2;
			balise_ptr(ptr, env);
			ft_putnbr_fd(ptr->y, env->fd);
			while (size > 0)
			{
				ft_putchar_fd(' ', env->fd);
				size--;
			}
			*rt += 1;
		}
		ptr = ptr->next;
	}
}

void				balise_ptr(t_arg *ptr, t_env *env)
{
	if (ptr->select == 1)
		ft_putstr_fd(ANSI_COLOR_REVERSE, env->fd);
	if (ptr->focus == 1)
		ft_putstr_fd(ANSI_COLOR_UNDERLINE, env->fd);
	if (ptr->focus == 0)
		ft_putstr_fd("  ", env->fd);
	else if (ptr->focus == 1)
		ft_putstr_fd("->", env->fd);
	ft_putstr_fd(ptr->name, env->fd);
	if (ptr->focus == 1)
		ft_putstr_fd(ANSI_COLOR_RESET_UND, env->fd);
	if (ptr->select == 1)
		ft_putstr_fd(ANSI_COLOR_RESET_REV, env->fd);
}

void				exit_fct(t_env *env)
{
	struct termios	term;

	tgetent(NULL, getenv("TERM"));
	poscur(0, 0, env);
	ft_putstr_fd(tgetstr("te", NULL), env->fd);
	ft_putstr_fd(tgetstr("ve", NULL), env->fd);
	close(env->fd);
	if (tcgetattr(0, &term) == -1)
		return ;
	term.c_lflag = env->canon;
	term.c_lflag = env->echo;
	term.c_cc[VMIN] = env->vim;
	term.c_cc[VTIME] = env->tim;
	if (tcsetattr(0, 0, &term) == -1)
		return ;
}
