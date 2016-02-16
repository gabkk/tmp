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


