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

int					main(int ac, char **av, char **env)
{
	const char		*tname;
	struct termios 	term;
	int				fd;
	t_arg			*arg;
//	char		*path;
	(void)ac;
	(void)env;
	(void)av;
	arg = NULL;
	fd = check_terminal();
	if (!*av)
		return (-1);
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

	//ft_putendl("YO");
	start_new_w();

    //ft_putnbr_fd(fd, 2);
	//ft_putendl("YO");
	init_list(&arg, av, fd);
	add_argv(arg, fd);
	//poscur(0, 0);
	check_key();
	close(fd);

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}

int		check_terminal()
{
	int		fildes;
	char	*name;
	int 	slot;
	int		fd;

	slot = 0;
	fildes = 0;

	/*              WTF IS THAT */

	name = ttyname(1);
	if (!name)
	{
		ft_putendl_fd("fd incorrect", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(name, O_RDWR);
	if(!(isatty(fd)))
		exit(EXIT_FAILURE);
	slot = ttyslot();
	//ft_putnbr(ioctl(fd, 0));
	return (fd);
}