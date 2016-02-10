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

char		*start_new_w()
{
	char 	*none;
	char	*path;
	char	*CD;

	path = tgetstr("is", &none);//init term
	if (path)
	{
		tputs(path, 1, useless);
	}
	poscur(0, 0); // positionne cursor
	if ((CD = tgetstr("cd", &none)) == NULL) //clear from the cursor to the end of the screen
		CD = tgetstr("cl", &none);
	tputs(CD, 1, useless);
	return (path); 
}

void		init_fd(char *path)
{
	char	buff[513];
	int		fd;
	int		n;

	fd = open(path, 0, O_RDWR);
	//ft_putnbr(fd);
	if (fd >= 0)
	{
		//tputs(av[0], 1, useless);
		while ((n = read( fd, buff, 512)))
		{
			write(fd, buff, n);
		}
	}
	close(fd);
}

void			add_argv(char **av)
{
	int		i;
	//char	*none;

	i = 1;
	while (av[i])
	{
		ft_putendl(av[i]);
		//tputs(tgetstr( "do", &none), 1, useless);
		i++;
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