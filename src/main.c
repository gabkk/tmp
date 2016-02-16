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

int					main(int ac, char **av, char **envp)
{
	const char		*tname;
	struct termios 	term;
	t_arg			*arg;
	t_env			*env;
	int				draw;
//	char		*path;
//	int				p;
	char	*CD;


//	p = 0;
	(void)ac;
	(void)envp;
	arg = NULL;
	g_flagsignal = 0;
	g_flagsignalz = 0;
	signal_fct();
	env = (t_env *)malloc(sizeof(t_env));
	env->del = 0;
	env->tot = 0;

	check_terminal(env);
	if (!av[1])
	{
		ft_putendl_fd("You should add at least one parameter to ft_select", 2);
		exit(0);
	}
	if ((tname = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("Environement doesn't exist", 2);
		exit(EXIT_FAILURE);
	}
	if (tgetent(NULL, tname) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);



	g_canon = term.c_lflag;
	g_echo = term.c_lflag;
	g_vim = term.c_cc[VMIN];
	g_tim = term.c_cc[VTIME];
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);



	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);


	start_new_w(env);
	init_env(env, av);


	init_list(&arg, av, env);



	draw = check_wsize(env);
	if (draw == 1)
		draw_argv(&arg, env);
	else
	{
		poscur(0, 0, env);
		if ((CD = tgetstr("cd", NULL)) == NULL)
			CD = tgetstr("cl", NULL);
		tputs(CD, env->fd, useless);
	}

	//poscur(0, 0, env);
	check_key(env, &arg);

	//draw_argv(&arg, env);
	exit_fct(env);
	return (0);
}

void		check_terminal(t_env *env)
{
//	int		fildes;
	char	*name;
//	int 	slot;

//	slot = 0;
//	fildes = 0;

	/*              WTF IS THAT */

	name = ttyname(0);
	if (!name)
	{
		ft_putendl_fd("fd incorrect", 2);
		exit(EXIT_FAILURE);
	}
	env->fd = open(name, O_RDWR | O_NONBLOCK);
	g_fd = env->fd;
	if(!(isatty(env->fd)))
	{
		ft_putendl_fd("Not a tty", 1);
		exit(EXIT_FAILURE);
	}
//	slot = ttyslot();
}