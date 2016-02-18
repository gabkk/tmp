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
	init_list(&arg, av, env);
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
	check_key(env, &arg);
	exit_fct(env);
}

void				init_term(t_env *env)
{
	struct termios	term;
	const char		*tname;

	if ((tname = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("Environement doesn't exist", 2);
		exit(EXIT_FAILURE);
	}
	if (tgetent(NULL, tname) == -1)
		return ;
	if (tcgetattr(0, &term) == -1)
		return ;
	env->canon = term.c_lflag;
	env->echo = term.c_lflag;
	env->vim = term.c_cc[VMIN];
	env->tim = term.c_cc[VTIME];
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 1;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return ;
}

void				check_terminal(t_env *env)
{
	char			*name;

	name = ttyname(0);
	if (!name)
	{
		ft_putendl_fd("fd incorrect", 2);
		exit(EXIT_FAILURE);
	}
	env->fd = open(name, O_RDWR | O_NONBLOCK);
	if (!(isatty(env->fd)))
	{
		ft_putendl_fd("Not a tty", 1);
		exit(EXIT_FAILURE);
	}
}

void				read_input(t_arg **arg, t_arg **ptr, t_env **env)
{
	read_key(arg, ptr, env);
	(*env)->draw = check_wsize(*env);
	if ((*env)->draw == 1 && (*env)->action == 0)
	{
		if ((*env)->draw == 1 || g_flagsignalz == 1)
		{
			redraw(arg, *ptr, env);
			(*env)->prevcursorx = (*env)->cursorx;
			(*env)->prevcursory = (*env)->cursory;
			(*env)->action = 1;
		}
	}
}
