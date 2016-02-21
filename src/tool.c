/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg					*get_right(t_arg **arg, t_arg *source, t_env *env)
{
	t_arg				*ptr;

	ptr = *arg;
	if (source->y == env->ymax)
	{
		while (ptr)
		{
			if (ptr->x == source->x)
				return (ptr);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (ptr->x == source->x && ptr->y == (source->y + env->wordmax + 2))
				return (ptr);
			ptr = ptr->next;
		}		
	}
	return (NULL);
}

t_arg					*get_left(t_arg **arg, t_arg *source, t_env *env)
{
	t_arg				*ptr;

	ptr = *arg;
	if (source->y == 0)
	{
		while (ptr)
		{
			if (ptr->x == source->x && ptr->y == env->ymax)
				return (ptr);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (ptr->x == source->x && ptr->y == (source->y - (env->wordmax + 2)))
				return (ptr);
			ptr = ptr->next;
		}		
	}
	return (NULL);
}