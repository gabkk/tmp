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

	path = tgetstr("is", &none);//init term
	if (path)
		tputs(path, 1, useless);
	poscur(0, 0); // positionne cursor
	if ((CD = tgetstr("cd", &none)) == NULL) //clear from the cursor to the end of the screen
		CD = tgetstr("cl", &none);
	tputs(CD, 1, useless);
}

void		init_fd(char *path)
{
	char	buff[513];
	int		fd;
	int		n;

	fd = open(path, 0, O_RDWR);
	if (fd >= 0)
	{
		while ((n = read( fd, buff, 512)))
			write(fd, buff, n);
	}
	close(fd);
}

void			add_argv(t_arg *arg, int fd)
{
	t_arg		*ptr;
	//char	*none;

	ptr = arg;
	while (ptr)
	{
		ft_putendl_fd(ptr->name, fd);
		ft_putnbr_fd(ptr->x, fd);
		ft_putnbr_fd(ptr->y, fd);
		ptr = ptr->next;
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

void			winsize(int fd, int *i)
{
	struct winsize w;
    ioctl(fd, TIOCGWINSZ, &w);

    i[0] = w.ws_row;
    i[1] = w.ws_col;
    // ft_putstr_fd("line : ", 2);
    // ft_putnbr_fd(i[0], 2);
    // ft_putstr_fd("col : ", 2);
    // ft_putnbr_fd(i[1] , 2);
    //return i;
}