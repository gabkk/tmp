/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:59:17 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/18 19:59:19 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			winsize(int fd, int i[2])
{
	struct winsize w;

	ioctl(fd, TIOCGWINSZ, &w);
	i[0] = w.ws_row;
	i[1] = w.ws_col;
}

void			init_env(t_env *env, char **av)
{
	int			i;

	i = 0;
	winsize(env->fd, env->j);
	i = 1;
	env->ymax = 0;
	env->wordmax = 0;
	env->del = 0;
	env->tot = 0;
	env->cursorx = 0;
	env->cursory = 0;
	if (!*av)
		return ;
	while (av[i])
	{
		if (ft_strlen(av[i]) > (size_t)env->wordmax)
			env->wordmax = ft_strlen(av[i]);
		i++;
		env->tot++;
	}
}

void			poscur(int x, int y, t_env *env)
{
	char		*cm;

	cm = tgetstr("cm", NULL);
	ft_putstr_fd(tgoto(cm, y, x), env->fd);
}

int				check_wsize(t_env *env)
{
	int			draw;
	int			tmp;

	draw = 0;
	tmp = env->tot / (env->j[0]);
	if (env->j[1] + tmp > (((env->tot + tmp) / (env->j[0] - 1))\
		* (env->wordmax + 8)) + env->wordmax)
		draw = 1;
	return (draw);
}
