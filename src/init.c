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

void			add_argv(t_arg *arg, int fd, t_env *env)
{
	t_arg		*ptr;
	int			x;
	// int			y;
	// //char	*none;
	int			reachtot;
	int			size;

	reachtot = 0;
	x = 1;
	size = 0;
	// y = 0;
	(void)env;
		// ft_putstr_fd("env tot : ", fd);
		// ft_putnbr_fd(env->tot, fd);
		// ft_putstr_fd(" windows x : ", fd);
		// ft_putnbr_fd(env->j[0], fd);
		// ft_putstr_fd(" windows y : ", fd);
		// ft_putnbr_fd(env->j[1], fd);
		// ft_putchar_fd('\n', 2);

	while (reachtot < env->tot)
	{
		ptr = arg;
		while (ptr)
		{
			// ft_putstr_fd("x : ", fd);
			// ft_putnbr_fd(ptr->x, fd);
			// ft_putstr_fd(" y : ", fd);
			// ft_putnbr_fd(ptr->y, fd);

			/*responsive
			x = 0;
			y = 5;
			while (x < 3)
			{
				write(fd, "\n", 1);
				x++;
			}
			while (y <= ptr->y)
			{
				write(fd, "\t", 1);
				y++;
			}
			end responsive*/
			if (ptr->x == x)
			{
				size = ft_strlen(ptr->name);
				if (size < env->wordmax)
					size = env->wordmax - size + 2;
				else
					size = 2;
				ft_putstr_fd(ptr->name, fd);
				while (size > 0)
				{
					ft_putchar_fd(' ', fd);
					size--;
				}
				reachtot++;
			}
			ptr = ptr->next;
		}
		ft_putchar_fd('\n', fd);
		x++;
	}
}

void		poscur(int x, int y)
{
	char	*CM;

	CM = tgetstr("cm", NULL);
	tputs(tgoto(CM, y , x), 1, useless);
}

int			useless(int c)
{
	write( 1, &c, 1);
	return (0);
}
