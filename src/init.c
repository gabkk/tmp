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
	 	tputs(ti, env->fd, useless);
	// path = tgetstr("is", NULL);//init term
	// if (path)
	// 	tputs(path, 1, useless);
	poscur(0, 0, env); // positionne cursor
	if ((CD = tgetstr("cd", NULL)) == NULL) //clear from the cursor to the end of the screen
		CD = tgetstr("cl", NULL);
	tputs(CD, env->fd, useless);
}

void			draw_argv(t_arg **arg, t_env *env)
{
	t_arg		*ptr;
	int			x;
	int			reachtot;
	int			size;

	reachtot = 0;
	x = 0;
	size = 0;

	if (env->del == 1)
	{
		del_list(arg, env);
		init_index(arg, env);
		env->del = 0;
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
//	ft_putnbr_fd(env->tot, env->fd);
//	ft_putnbr_fd(env->j[0], env->fd);
}

			/*responsive
			x = 0;
			y = 5;
			while (x < 3)
			{
				write(fd, "\n", 1);
				x++;
			}
			while (y <= ptr->y)
			{
				write(fd, "\t", 1);
				y++;
			}
			end responsive*/

void		poscur(int x, int y, t_env *env)
{
	char	*CM;

	CM = tgetstr("cm", NULL);
	tputs(tgoto(CM, y , x), env->fd, useless);
}

int			useless(int c)
{
	write( 3, &c, 1);
	return (0);
}

int			check_wsize(t_env *env)
{
	// int		totalw;
	// int		totaldraw;
	int		draw;

	draw = 1;
	// totalw = env->j[0] * env->j[1];
	// totaldraw = (env->tot + 1) * (env->wordmax + 4);
	// // if (totaldraw > totalw)
	// // 	draw = 0;
	if (env->j[1] < (env->ymax + env->wordmax + 2))
		draw = 0;
	return (draw);
}

void		balise_ptr(t_arg *ptr, t_env *env)
{
	if (ptr->select == 1)
		ft_putstr_fd(ANSI_COLOR_REVERSE, env->fd);
	if (ptr->focus == 1)
		ft_putstr_fd(ANSI_COLOR_UNDERLINE, env->fd);
	ft_putstr_fd(ptr->name, env->fd);
	if (ptr->focus == 1)
		ft_putstr_fd(ANSI_COLOR_RESET_UND, env->fd);
	if (ptr->select == 1)
		ft_putstr_fd(ANSI_COLOR_RESET_REV, env->fd);

}