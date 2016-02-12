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

void		check_key(t_env *env, int fd)
{
	//char	*none;
	int		margin;
	int		i;
	int		j;
	int		posx;
	int		posy;

	margin = 0;
	posx = 0;
	posy = 1;
	while (1)
	{
		char	buff[3];

		j = 0;
		i = 0;
		read(0 , buff, fd);
		if (buff[0] == 27)
		{
			if (buff[2] == 'A' && (posy > 1))
			{
				tputs(tgetstr("up", NULL), 1, useless);
				posy--;
			}
			else if (buff[2] == 'B' && (posy < env->j[0]))
			{
				tputs(tgetstr( "do", NULL), 1, useless);
				while (j < margin)
				{
					while (i < env->wordmax + 2)
					{
						tputs(tgetstr("nd", NULL), 1, useless);
						i++;
					}
					j++;
				}
				posy++;
			}
			else if (buff[2] == 'C')
			{
				while (i < env->wordmax + 2)
				{
					tputs(tgetstr("nd", NULL), 1, useless);
					i++;
				}
				margin++;
				posx++;
			}
			else if (buff[2] == 'D')
			{
				while (i < env->wordmax + 2)
				{
					tputs(tgetstr("le", NULL), 1, useless);
					i++;
				}
				margin--;
				posx--;
			}
		}
		else if (buff[0] == 4)
		{
			ft_putstr("cmd + d");
			return ;
		}

		ft_bzero(buff, 3);
	}
	return ;
}

