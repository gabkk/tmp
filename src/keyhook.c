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

void		check_key(t_env *env, t_arg *arg)
{
	//char	*none;
//	int		i;
//	int		j;
	t_arg	*ptr;

	ptr = arg;
	env->cursorx = 0;
	env->cursory = 0;
	while (1)
	{
		char	buff[3];

//		j = 0;
//		i = 0;
		read(0 , buff, env->fd);
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
					ptr = get_index(env->tot, arg);
			}
			else if (buff[2] == 'B' ) //remettre a -1 quand on pourra aller a l element de la colonne suivante
			{
				if (ptr && ptr->next)
					ptr = ptr->next;
				else if (ptr)
					ptr = get_index(1, arg);
			}
			ptr->focus = 1;
		}
		
		if (buff[0] == 32) //SPACE
		{
			if (ptr->select == 1)
				ptr->select = 0;
			else
				ptr->select = 1;
		}
		if (buff[0] == 10) //
		{
			if (env->del == 0)
				env->del = 1;
		}
		if (buff[0] == 4)
		{
			ft_putstr("cmd + d");
			return ;
		}
		redraw(arg, ptr, env);
		ft_bzero(buff, 3);
	}
	return ;
}

void		redraw(t_arg *arg, t_arg *ptr, t_env *env)
{
	char	*CD;

	poscur(0, 0);
	if ((CD = tgetstr("cd", NULL)) == NULL)
	CD = tgetstr("cl", NULL);
	tputs(CD, 1, useless);
	add_argv(arg, env);
	//if (next_element(arg, ptr, env) == 1)
		next_element(arg, ptr, env);
		poscur(env->cursorx, env->cursory);
	// else
	// {
	// 	poscur(env->prevcursorx, env->prevcursory);
	// 	env->cursorx = env->prevcursorx;
	// 	env->cursory = env->prevcursory;
	// }
}

void			next_element(t_arg *arg, t_arg *next, t_env *env)
{
	// t_arg	*ptr;
	(void)arg;
	// ptr = arg;
	// while (ptr)
	// {
	// 	if ((next->y == ptr->y) && (next->x == ptr->x))
	// 	{
			env->cursory = next->y;
			env->cursorx = next->x;
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








/*

			else if (buff[2] == 'C')
			{
//				while (i < env->wordmax + 2)
//				{
					env->cursory += env->wordmax + 2;
//					i++;
//				}
			}
			else if (buff[2] == 'D' && (env->cursory > 0))
			{
//				while (i < env->wordmax + 2)
//				{
					env->cursory -= env->wordmax + 2;
//					i++;
//				}
			}

*/

