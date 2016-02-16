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

void		check_key(t_env *env, t_arg **arg)
{
	//char	*none;
//	int		i;
//	int		j;
	t_arg	*ptr;
	int		draw;

	char	*CD;

	ptr = *arg;
	env->cursorx = 0;
	env->cursory = 0;
	while (1)
	{
		char	buff[4];

//		j = 0;
//		i = 0;
		env->ymax = 0;
		if (g_flagsignal == 1 || g_flagsignalz == 1)
		{
		//	tputs(tgetstr("bl", NULL), env->fd, useless);

		//	init_env(env, NULL);
			winsize(env->fd, env->j);
			init_index(arg, env);
			draw = check_wsize(env);


			if (draw == 1)
				redraw(arg, ptr, env);
			else
			{
				poscur(0, 0, env);
				if ((CD = tgetstr("cd", NULL)) == NULL)
					CD = tgetstr("cl", NULL);
				tputs(CD, env->fd, useless);
				ft_putstr_fd("Your terminal is too smallqqq", env->fd);
			}
			g_flagsignal = 0;
			g_flagsignalz = 0;
			//ft_putnbr_fd(ptr->x, env->fd);
			//ft_putnbr_fd(ptr->y, env->fd);
		}

		read(env->fd , buff, 5);
		env->prevcursorx = env->cursorx;
		env->prevcursory = env->cursory;
		if (buff[0] == 27)
		{
			ptr->focus = 0;
			if (buff[2] == 'A')
			{
				if (ptr && ptr->prev && ptr->index != 1)
				 	ptr = ptr->prev;
				else if (ptr)
					ptr = get_index(env->tot, *arg);
			}
			else if (buff[2] == 'B' ) //remettre a -1 quand on pourra aller a l element de la colonne suivante
			{
				if (ptr && ptr->next)
					ptr = ptr->next;
				else if (ptr)
					ptr = get_index(1, *arg);
			}
			else if (!buff[2])
			{
				exit_fct(env);
				return ;
			}
			ptr->focus = 1;
		}
		
		if (buff[0] == 32) //SPACE
		{
			if (ptr->select == 1)
			{
				ptr->select = 0;
				ptr->focus = 0;
			}
			else
			{
				ptr->select = 1;
				ptr->focus = 0;
			}
			if (!ptr->next)
			{
				ptr = get_index(1, *arg);
				ptr->focus = 1;
				env->cursorx = ptr->x;
				env->cursory = ptr->y;
				poscur(ptr->x, ptr->y, env);
			}
			else if (ptr->next)
			{
				ptr->next->focus = 1;
				env->cursorx = ptr->next->x;
				env->cursory = ptr->next->y;
				ptr = ptr->next;
				poscur(ptr->x, ptr->y, env);
			}
		}
		if (buff[0] == 127 || (buff[0] == 27 && buff[2] == '3')) //
		{
			if (env->del == 0)
				env->del = 1;
		}

		if (buff[0] == '\n')
		{


			tputs(tgetstr("te", NULL), env->fd, useless);
			// tputs(tgoto(tgetstr("cm", NULL), 0 , 0), 1, useless);
	//		tputs(tgetstr("nw", NULL), env->fd, useless);



			//tputs(tgetstr("nw", NULL), 1, useless);

	//		ft_putstr_fd("awe", 1);
			tputs(tgetstr("it", NULL), env->fd, useless);

			ptr = *arg;
			while (ptr)
			{
				if (ptr->select == 1)
				{
					//ft_putchar(' ');
					ft_putstr_fd(ptr->name, 1);
					ft_putchar_fd(' ', 1);
					//exit(0);
				}
				ptr = ptr->next;
			}

//exit_fct(env);
			
			exit(0);
			return;
//			return ;
			//exit(0);
		}
		if (buff[0] == 4)
		{
			ft_putstr("cmd + d");
			return ;
		}
		if (buff[0])
		{
			draw = check_wsize(env);
			if (draw == 1 || g_flagsignalz == 1)
				redraw(arg, ptr, env);
			else
			{
				poscur(0, 0, env);
				if ((CD = tgetstr("cd", NULL)) == NULL)
					CD = tgetstr("cl", NULL);
				tputs(CD, env->fd, useless);
				ft_putstr_fd("Your terminal is too small", env->fd);
			}
		}
		ft_bzero(buff, 3);
	}
	return ;
}

void		redraw(t_arg **arg, t_arg *ptr, t_env *env)
{
	char	*CD;

	//tputs(tgetstr("bl", NULL), env->fd, useless);

	poscur(0, 0, env);
	if ((CD = tgetstr("cd", NULL)) == NULL)
	CD = tgetstr("cl", NULL);
	tputs(CD, env->fd, useless);
	draw_argv(arg, env);
	//if (next_element(arg, ptr, env) == 1)
	next_element(*arg, ptr, env);
	poscur(env->cursorx, env->cursory, env);
	// else
	// {
	// 	poscur(env->prevcursorx, env->prevcursory);
	// 	env->cursorx = env->prevcursorx;
	// 	env->cursory = env->prevcursory;
	// }
}

void			next_element(t_arg *arg, t_arg *ptr, t_env *env)
{
	// t_arg	*ptr;
	(void)arg;
	// ptr = arg;
	// while (ptr)
	// {
	// 	if ((next->y == ptr->y) && (next->x == ptr->x))
	// 	{
			env->cursory = ptr->y;
			env->cursorx = ptr->x;
	// 		return (1);
	// 	}
	// 	ptr = ptr->next;
	// }
	// return (0);
}

t_arg			*get_index(int index, t_arg *arg)
{
	t_arg		*ptr;

	ptr = arg;
	while (ptr)
	{
		if (ptr->index == index)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

