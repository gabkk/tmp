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


void			addlist(t_arg **argu, char *av, int posx, int posy, int i)
{
	t_arg		*ptr;
	t_arg		*newm;


	if (!av)
		return ;
	newm = setmarg(posx, posy, av);
	if (!(*argu))
	{
		*argu = newm;
		newm->name = av;
		newm->next = NULL;
		newm->prev = NULL;
		newm->index = i;
		newm->focus = 1;
//		first = newm;
//		first->next = *argu;
		return;
	}
	ptr = *argu;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newm;
	ptr->next->prev = ptr;
	newm->name = av;
	newm->x = posx;
	newm->y = posy;
	newm->index = i;
	newm->next = NULL;
}


t_arg			*setmarg(int posx, int posy, char *av)
{
	t_arg		*newm;

	newm = (t_arg *)malloc(sizeof(t_arg));
	if (!newm)
		return (NULL);
	newm->name = av;
	newm->x = posx;
	newm->y = posy;
	newm->focus = 0;
	newm->select = 0;
	newm->next = NULL;
	newm->prev = NULL;
	return (newm);
}

void			init_list(t_arg **argu, char **av, t_env *env)
{
	int			i;
	int			margex;
	int			posx;
	int			posy;

	margex = env->j[0];
	posy = 0;
	posx = -1;
	i = 1;

	while (av[i])
	{
		if (margex > i)
			posx++;
		else
		{
			margex += env->j[0] - 1;
			posy += env->wordmax + 2;
			if (env->ymax < posy)
				env->ymax = posy;
			posx = 0;
		}
		addlist(argu , av[i], posx, posy, i);
		i++;
	}
}

t_arg			*del_list(t_arg **arg, t_env *env)
{
	t_arg		*ptr;
	t_arg		*tmp;
	t_arg		*tmpfocus;

	if (!(*arg))
	{
		exit_fct(env);
		exit(0);
	}
	tmpfocus = NULL;
	ptr = *arg;
	while (ptr)
	{
		if (ptr->select == 1 || ptr->focus == 1)
		{
			if (!ptr->next && !ptr->prev)
			{
				free(ptr);
				exit_fct(env);
				exit(0);
			}
			if (ptr->next && ptr->prev)
			{
				if (ptr->focus == 1)
				 	tmpfocus = ptr->next; // a faire sur le premier et dernier
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				//env->cursorx = tmpfocus->x;
				//env->cursory = focus->y;
				free(ptr);
				//ptr = tmpfocus;
			}
			else if (!ptr->prev)
			{				
				if (ptr->focus == 1)
					tmpfocus = get_index(2, *arg);
				tmp = ptr->next;
				free(ptr);
				tmp->prev = NULL;
				*arg = tmp;
			 }
			else if (!ptr->next)
			{
				if (ptr->focus == 1)
					tmpfocus = get_index(1, *arg);
				ptr->prev->next = NULL;
				free(ptr);
				//ptr = tmpfocus;
			}
		}
		ptr = ptr->next;
	}
	if (tmpfocus)
		tmpfocus->focus = 1;
	// env->cursorx = (*arg)->x;
	// env->cursory = (*arg)->y;
	return (tmpfocus);
}

void			init_index(t_arg **arg, t_env *env, t_arg *argfocus)
{
	t_arg		*ptr;
	int			i;
	int			margex;
	int			x;
	int			y;

	i = 1;
	margex = env->j[0];
	ptr = *arg;
	y = 0;
	x = -1;
	env->tot = 0;
	env->wordmax = 0;
	(void)argfocus;
	if (!*arg)
		exit(0);
	while (ptr)
	{
		if (ft_strlen(ptr->name) > (size_t)env->wordmax)
			env->wordmax = ft_strlen(ptr->name);
		env->tot++;
		ptr = ptr->next;
	}

	ptr = *arg;
	while (ptr)
	{
		if (i < margex)
		{
			x++;
			ptr->x = x;
			ptr->y = y;
		}
		else
		{
			margex += env->j[0] - 1;
			y += env->wordmax + 2;
			if (env->ymax < y)
				env->ymax = y;
			ptr->y = y;
			ptr->x = 0;
			x = 0;
		}
		ptr->index = i;
		if (ptr != argfocus)
			ptr->focus = 0;
		i++;
		ptr = ptr->next;
	}
}