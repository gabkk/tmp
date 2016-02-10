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

void		check_key(char **av)
{
	char	*none;

	add_argv(av);
//	tgetstr("cm", &none);

	while (1)
	{
		char	buff[3];

		read(0 , buff, 3);
		if (buff[0] == 27)
		{
			if (buff[2] == 'A')
				tputs(tgetstr("up", &none), 1, useless);
			else if (buff[2] == 'B')
			{
				tputs(tgetstr( "do", &none), 1, useless);
			}
			else if (buff[2] == 'C')
				tputs(tgetstr("nd", &none), 1, useless);
			else if (buff[2] == 'D')
				tputs(tgetstr("le", &none), 1, useless);	
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

