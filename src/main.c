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
//	char		*path;
//	int				p;

//	p = 0;
	(void)ac;
	(void)envp;
	arg = NULL;
	env = (t_env *)malloc(sizeof(t_env));
	check_terminal(env);
	if (!av[1])
	{
		ft_putendl_fd("You should add at least one parameter to ft_select", 2);
		return (-1);
	}
	if ((tname = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, tname) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);


	start_new_w();
	init_env(env, av);


	init_list(&arg, av, env);
	add_argv(arg, env);
	poscur(0, 0);
	check_key(env, arg);





	close(env->fd);
	free(env);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
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

	name = ttyname(1);
	if (!name)
	{
		ft_putendl_fd("fd incorrect", 2);
		exit(EXIT_FAILURE);
	}
	env->fd = open(name, O_RDWR);
	if(!(isatty(env->fd)))
		exit(EXIT_FAILURE);
//	slot = ttyslot();
}