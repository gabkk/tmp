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

int					main(int ac, char **av, char **envp)
{
	t_arg			*arg;
	t_env			*env;

	(void)ac;
	(void)envp;
	arg = NULL;
	g_flagsignal = 0;
	g_flagsignalz = 0;
	signal_fct();
	env = (t_env *)malloc(sizeof(t_env));
	check_terminal(env);
	if (!av[1])
	{
		ft_putendl_fd("You should add at least one parameter to ft_select", 2);
		exit(0);
	}
	main_body(env, av, arg);
	return (0);
}

void				main_body(t_env *env, char **av, t_arg *arg)
{
	int				draw;
	char			*cd;

	draw = 0;
	init_term(env);
	start_new_w(env);
	init_env(env, av);
	init_list(&arg, av, &env);
	draw = check_wsize(env);
	if (draw == 1)
		draw_argv(&arg, env);
	else
	{
		if ((cd = tgetstr("cd", NULL)) == NULL)
			cd = tgetstr("cl", NULL);
		ft_putstr_fd(cd, env->fd);
		ft_putstr_fd("Your terminal is too small", env->fd);
	}
	check_key(env, &arg, av);
	exit_fct(env);
}
