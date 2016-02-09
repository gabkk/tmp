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

void		start_new_w()
{
	char 	*none;
	char	*path;
	char	*CD;
	char 	**av;

	av = (char **)malloc(sizeof(char *) * 2);
	av[0] = ft_strdup("Yo");
	av[1] = NULL;
	path = tgetstr("is", &none);//init term
	if (path)
	{
		tputs(path, 1, useless);

		init_fd(path, av);
		add_argv(path, av);
	}

	poscur(0, 0); // positionne cursor
	if ((CD = tgetstr("cd", &none)) == NULL) //clear from the cursor to the end of the screen
		CD = tgetstr("cl", &none);
	tputs(CD, 1, useless);
}

void		init_fd(char *path, char **av)
{
	char	buff[513];
	int		fd;
	int		n;

	fd = open(path, 0, 0);
	ft_putnbr(fd);
	if (fd >= 0)
	{
		tputs(av[0], 1, useless);
		while ((n = read( fd, buff, 512)))
		{
			write(fd, buff, n);
			close(fd);
		}
	}
}

void		add_argv(char *path, char **av)
{
	int		fd;

	fd = open(path, 0, 0);
	ft_putnbr(fd);
	
	if (fd >= 0)
	{
		if (*av)
		{
			write(fd, av[0], ft_strlen(av[0]) + 1);
			close(fd);
			//(*av)++;
		}
	}
}

void		poscur(int x, int y)
{
	char 	*none;
	char	*CM;

	CM = tgetstr("cm", &none);
	tputs(tgoto(CM, y , x), 1, useless);
}

int			useless(int c)
{
	write( 1, &c, 1);
	return (0);
}