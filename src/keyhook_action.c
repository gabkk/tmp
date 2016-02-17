/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_select.h"

void		read_input(t_arg **arg, t_arg **ptr, t_env **env)
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

void		read_key(t_arg **arg, t_arg **ptr, t_env **env)
{
	char	buff[4];

	read((*env)->fd , buff, 5);
	if (buff[0] != 0)
	{
		if (buff[0] == 27)
		{
			read_arrow_esc(arg, ptr, *env, buff);
			(*env)->action = 0;
		}
		if (buff[0] == 32)
		{
			read_space(ptr, env, arg);
			(*env)->action = 0;
		}
		if (buff[0] == 127 || (buff[0] == 27 && buff[2] == '3')) //
		{
			read_del(ptr, env, arg);
			(*env)->action = 0;
		}
		if (buff[0] == '\n')
		{
			read_enter(env, ptr, arg);
			(*env)->action = 0;
		}
		if (buff[0] == 4)
		{
			exit(0);
			return ;
		}		
		ft_bzero(buff, 3);
		return ;
	}
	(*env)->action = 1;
	ft_bzero(buff, 3);
}


void		read_arrow_esc(t_arg **arg, t_arg **ptr, t_env *env, char *buff)
{
	(*ptr)->focus = 0;
	if (buff[2] == 'A')
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
	else if (buff[2] == 'B' ) //remettre a -1 quand on pourra aller a l element de la colonne suivante
	{
		if ((*ptr) && (*ptr)->next)
			(*ptr) = (*ptr)->next;
		else if ((*ptr))
			(*ptr) = get_index(1, *arg);
	}
	else if (!buff[2]) //Esc
	{
		exit_fct(env);
		exit(0);
		return ;
	}
	(*ptr)->focus = 1;
}

void		read_space(t_arg **ptr, t_env **env, t_arg **arg)
{
	if ((*ptr)->select == 1)
	{
		(*ptr)->select = 0;
		(*ptr)->focus = 0;
	}
	else
	{
		(*ptr)->select = 1;
		(*ptr)->focus = 0;
	}
	if (!(*ptr)->next)
	{
		(*ptr) = get_index(1, *arg);
		(*ptr)->focus = 1;
		(*env)->cursorx = (*ptr)->x;
		(*env)->cursory = (*ptr)->y;
		poscur((*ptr)->x, (*ptr)->y);
	}
	else if ((*ptr)->next)
	{
		(*ptr)->next->focus = 1;
		(*env)->cursorx = (*ptr)->next->x;
		(*env)->cursory = (*ptr)->next->y;
		(*ptr) = (*ptr)->next;
		poscur((*ptr)->x, (*ptr)->y);
	}
}

void		read_del(t_arg **ptr, t_env **env, t_arg **arg)
{
	if ((*env)->del == 0)
		(*env)->del = 1;
	if (!(*ptr)->next)
	{
		(*ptr) = get_index(1, *arg);
		(*ptr)->focus = 1;
		(*env)->cursorx = (*ptr)->x;
		(*env)->cursory = (*ptr)->y;
		poscur((*ptr)->x, (*ptr)->y);
	}
	else if ((*ptr)->next)
	{
		(*ptr)->next->focus = 1;
		(*env)->cursorx = (*ptr)->next->x;
		(*env)->cursory = (*ptr)->next->y;
		(*ptr) = (*ptr)->next;
		poscur((*ptr)->x, (*ptr)->y);
	}
}

void		read_enter(t_env **env, t_arg **ptr, t_arg **arg)
{
	struct termios 	term;

	tputs(tgetstr("te", NULL), (*env)->fd, useless);
	tputs(tgetstr("ve", NULL), (*env)->fd, useless); // remet cursor
	tputs(tgetstr("it", NULL), (*env)->fd, useless);	
	tgetent(NULL, getenv("TERM"));
	if (tcgetattr(0, &term) == -1)
		return ;
	term.c_lflag = g_canon;
	term.c_lflag = g_echo;
	term.c_cc[VMIN] = g_vim;
	term.c_cc[VTIME] = g_tim;
	(*ptr) = *arg;
	while ((*ptr))
	{
		if ((*ptr)->select == 1)
		{
			//ft_putchar(' ');
			ft_putstr_fd((*ptr)->name, 1);
			ft_putchar_fd(' ', 1);
			//exit(0);
		}
		(*ptr) = (*ptr)->next;
	}
	if (tcsetattr(0, 0, &term) == -1)
	return ;
	exit(0);
}