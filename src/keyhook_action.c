/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				read_key(t_arg **arg, t_arg **ptr, t_env **env)
{
	char	buff[4];

	read((*env)->fd, buff, 4);
	if ((buff[0] > 12 && buff[0] <= 127) || buff[0] == '\n')
	{
		if (buff[0] == 27)
			read_a(arg, ptr, *env, buff);
		if (buff[0] == 32)
			read_space(ptr, env, arg);
		if (buff[0] == 127 || (buff[0] == 27 && buff[2] == '3'))
			read_del(ptr, env, arg);
		if (buff[0] == '\n')
			read_enter(env, ptr, arg);
		(*env)->action = 0;
		ft_bzero(buff, 3);
		return ;
	}
	(*env)->action = 1;
	ft_bzero(buff, 4);
}

void				read_a(t_arg **arg, t_arg **ptr, t_env *env, char *bf)
{
	(*ptr)->focus = 0;
	if (bf[2] == 'A')
	{
		if ((*ptr) && (*ptr)->prev && (*ptr)->index != 1)
		{
			(*ptr) = (*ptr)->prev;
			if ((*ptr)->next && (*ptr)->next->focus == 1)
				(*ptr)->next->focus = 0;
		}
		else if ((*ptr))
			(*ptr) = get_index(env->tot, *arg);
	}
	else if (bf[2] == 'B')
	{
		if ((*ptr) && (*ptr)->next)
			(*ptr) = (*ptr)->next;
		else if ((*ptr))
			(*ptr) = get_index(1, *arg);
	}
	else if (!bf[2])
	{
		exit_fct(env);
		exit(0);
	}
	(*ptr)->focus = 1;
}

void				read_del(t_arg **ptr, t_env **env, t_arg **arg)
{
	if ((*env)->del == 0)
		(*env)->del = 1;
	if ((*ptr)->next)
		*ptr = (*ptr)->next;
	else if (!(*ptr)->next)
		*ptr = get_index(1, *arg);
}

void				read_space(t_arg **ptr, t_env **env, t_arg **arg)
{
	if ((*ptr)->select == 1)
		(*ptr)->select = 0;
	else
		(*ptr)->select = 1;
	(*ptr)->focus = 0;
	if (!(*ptr)->next)
	{
		(*ptr) = get_index(1, *arg);
		(*ptr)->focus = 1;
		(*env)->cursorx = (*ptr)->x;
		(*env)->cursory = (*ptr)->y;
		poscur((*ptr)->x, (*ptr)->y, *env);
	}
	else if ((*ptr)->next)
	{
		(*ptr)->next->focus = 1;
		(*env)->cursorx = (*ptr)->next->x;
		(*env)->cursory = (*ptr)->next->y;
		(*ptr) = (*ptr)->next;
		poscur((*ptr)->x, (*ptr)->y, *env);
	}
}

void				read_enter(t_env **env, t_arg **ptr, t_arg **arg)
{
	struct termios	term;

	ft_putstr_fd(tgetstr("te", NULL), (*env)->fd);
	ft_putstr_fd(tgetstr("ve", NULL), (*env)->fd);
	ft_putstr_fd(tgetstr("it", NULL), (*env)->fd);
	tgetent(NULL, getenv("TERM"));
	if (tcgetattr(0, &term) == -1)
		return ;
	term.c_lflag = (*env)->canon;
	term.c_lflag = (*env)->echo;
	term.c_cc[VMIN] = (*env)->vim;
	term.c_cc[VTIME] = (*env)->tim;
	(*ptr) = *arg;
	while ((*ptr))
	{
		if ((*ptr)->select == 1)
		{
			ft_putstr_fd((*ptr)->name, 1);
			ft_putchar_fd(' ', 1);
		}
		(*ptr) = (*ptr)->next;
	}
	if (tcsetattr(0, 0, &term) == -1)
		return ;
	exit(0);
}
