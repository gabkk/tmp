/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 04:17:29 by gkuma             #+#    #+#             */
/*   Updated: 2016/01/16 05:11:08 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <stdio.h>

//typedef struct termios *t_term;
typedef struct 			s_arg{
		char			*name;
		int				x;
		int				y;
		struct s_arg	*next;
}						t_arg;

typedef struct 			s_env{
		int				j[2];
		int				tot;
		int				wordmax;
}						t_env;

/*
**	first.c
*/
void				check_key(t_env *env, int fd);

/*
**	init.c
*/
int					useless(int c);
void				start_new_w();
void				poscur(int x, int y);
void				init_fd(char *path);
void				add_argv(t_arg *arg, int fd, t_env *env);

/*
** main.c
*/
int					check_terminal();
struct termios		set_term();
int 				unset_term(struct termios term);

/*
** init_list.c
*/

void			init_list(t_arg **argu, char **av, int fd, t_env *env);
void			addlist(t_arg **argu, char *av, int posx, int posy);
t_arg			*setmarg(void);

/*
** init_env.c
*/
void			winsize(int fd, int i[2]);
void			init_env(t_env *env, char **av, int fd);

#endif
