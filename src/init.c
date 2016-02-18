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

# include "ft_select.h"

void		start_new_w(t_env *env)
{
//	char	*path;
	char	*CD;
	char	*ti;

	if((ti = tgetstr("ti", NULL)))
	 	tputs(ti, 1, useless);
	// path = tgetstr("is", NULL);//init term
	// if (path)
	// 	tputs(path, 1, useless);
	tputs(tgetstr("vi", NULL), env->fd, useless);
	poscur(0, 0); // positionne cursor
	if ((CD = tgetstr("cd", NULL)) == NULL) //clear from the cursor to the end of the screen
		CD = tgetstr("cl", NULL);
	tputs(CD, 1, useless);
}

void			draw_argv(t_arg **arg, t_env *env)
{
	t_arg		*ptr;
	t_arg		*argfocus;
	int			x;
	int			reachtot;
	int			size;

	reachtot = 0;
	x = 0;


	size = 0;

	if (env->del == 1)
	{
		argfocus =  del_list(arg, env);
		init_index(arg, env, argfocus);

		env->del = 0;
		//reset_focus(arg, env);
		//poscur(0, 0, env);
	}
	if (env->tot < 1)
	{
		ft_putendl_fd("Your list is empty", env->fd);
		exit(0);
	}
			// ft_putstr_fd("x : ", env->fd);
			// ft_putnbr_fd(env->j[0], env->fd);
			// ft_putstr_fd(" y : ", env->fd);
			// ft_putnbr_fd(env->j[1], env->fd);
	while (reachtot < env->tot)
	{
		ptr = *arg;
		while (ptr)
		{
			if (ptr->x == x)
			{
			// ft_putstr_fd("x : ", env->fd);
			//ft_putnbr_fd(ptr->index, env->fd);
			//ft_putnbr_fd(ptr->x, env->fd);
			//ft_putnbr_fd(ptr->y, env->fd);
			// ft_putstr_fd(" y : ", env->fd);

			//ft_putnbr_fd(ptr->y, env->fd);


				size = ft_strlen(ptr->name);
				if (size < env->wordmax)
					size = env->wordmax - size + 2;
				else
					size = 2;

				balise_ptr(ptr, env);

				while (size > 0)
				{
					ft_putchar_fd(' ', env->fd);
					size--;
				}


				reachtot++;
			}
			ptr = ptr->next;
		}
		x++;
		if (x < env->j[0] - 1)
			ft_putchar_fd('\n', env->fd);
	}
	// ft_putnbr_fd(env->tot, env->fd);
	// ft_putendl_fd("", env->fd);
	// ft_putnbr_fd(env->j[0], env->fd);
	// ft_putendl_fd("", env->fd);
	// ft_putnbr_fd(env->j[1], env->fd);
	// ft_putendl_fd("", env->fd);
	// ft_putnbr_fd(env->wordmax, env->fd);
	// ft_putendl_fd("", env->fd);
	// ft_putnbr_fd((((env->tot + (env->tot / (env->j[0]))) / (env->j[0] - 1)) * (env->wordmax + 5)), env->fd);

}

void		poscur(int x, int y)
{
	char	*CM;

	CM = tgetstr("cm", NULL);
	tputs(tgoto(CM, y , x), 1, useless);
}

int			useless(int c)
{
	write( g_fd, &c, 1);
	return (0);
}

int			uselesse(int c)
{
	write( 1, &c, 1);
	return (0);
}

int			check_wsize(t_env *env)
{
	int		draw;
	int		tmp;

	draw = 0;
	tmp = env->tot / (env->j[0]);
	// tmp += env->tot;
	//if (env->j[1] > (env->ymax + env->wordmax + 2))
	if (env->j[1] + tmp > (((env->tot + tmp) / (env->j[0] - 1)) * (env->wordmax + 8)) + env->wordmax)
		draw = 1;
	return (draw);
}

void		balise_ptr(t_arg *ptr, t_env *env)
{
	if (ptr->select == 1)
		ft_putstr_fd(ANSI_COLOR_REVERSE, env->fd);
	if (ptr->focus == 1)
		ft_putstr_fd(ANSI_COLOR_UNDERLINE, env->fd);
	if (ptr->focus == 0)// GERER LE REsize pour faire un truc style
		ft_putstr_fd("  ", env->fd);
	else if (ptr->focus == 1)
		ft_putstr_fd("->", env->fd);
	ft_putstr_fd(ptr->name, env->fd);
	if (ptr->focus == 1)
		ft_putstr_fd(ANSI_COLOR_RESET_UND, env->fd);
	if (ptr->select == 1)
		ft_putstr_fd(ANSI_COLOR_RESET_REV, env->fd);

}

int		reset_cursor(t_arg **arg, t_env *env)
{
	t_arg	*ptr;

	ptr = *arg;
	while (ptr)
	{
		if (ptr->x == env->cursorx && ptr->y == env->cursory)
			return (1);
		ptr = ptr->next;
	}
	return (0);
	// arg->focus = 1;
	// env->cursorx = 0;
	// env->cursory = 0;
	// poscur(0, 0, NULL);
}

void		exit_fct(t_env *env)
{
	struct termios 	term;

	tgetent(NULL, getenv("TERM"));
	poscur(0, 0);
	tputs(tgetstr("te", NULL), 1, useless);
	tputs(tgetstr("ve", NULL), env->fd, useless);

	close(g_fd);
	//free(env); // free tt dans env

	//tputs(tgetstr("it", NULL), 1, useless);
	if (tcgetattr(0, &term) == -1)
		return ;
	term.c_lflag = g_canon;
	term.c_lflag = g_echo;
	term.c_cc[VMIN] = g_vim;
	term.c_cc[VTIME] = g_tim;
	if (tcsetattr(0, 0, &term) == -1)
		return ;
}