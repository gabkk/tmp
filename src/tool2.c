/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					read_a_other(t_arg **a, t_arg **p, t_env *e, char *bf)
{
	t_arg				*tmp;

	tmp = NULL;
	if (bf[2] == 'B')
	{
		if ((*p) && (*p)->next)
			(*p) = (*p)->next;
		else if ((*p))
			(*p) = get_index(1, *a);
	}
	else if (bf[2] == 'C')
	{
		if ((*p) && (tmp = get_right(a, *p, e)))
			(*p) = tmp;
	}
	else if (bf[2] == 'D')
	{
		if ((*p) && (tmp = get_left(a, *p, e)))
			(*p) = tmp;
	}
	else if (!bf[2])
	{
		exit_fct(e);
		exit(0);
	}
}

void					init_term(t_env *env)
{
	struct termios		term;
	const char			*tname;

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

void					check_terminal(t_env *env)
{
	char				*name;

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

void					read_input(t_arg **a, t_arg **p, t_env **e, char **av)
{
	read_key(a, p, e, av);
	(*e)->draw = check_wsize(*e);
	if ((*e)->draw == 1 && (*e)->action == 0)
	{
		if ((*e)->draw == 1 || g_flagsignalz == 1)
		{
			redraw(a, *p, e);
			(*e)->prevcursorx = (*e)->cursorx;
			(*e)->prevcursory = (*e)->cursory;
			(*e)->action = 1;
		}
	}
}
