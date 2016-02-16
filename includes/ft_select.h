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
# include <signal.h>

# define ANSI_COLOR_UNDERLINE	"\x1b[4m\x1b[35m"
# define ANSI_COLOR_RESET_UND	"\x1b[24m\x1b[0m"

# define ANSI_COLOR_REVERSE		"\x1b[7m\x1b[35m"
# define ANSI_COLOR_RESET_REV   "\x1b[27m\x1b[0m"
//typedef struct termios *t_term;
typedef struct 			s_arg{
		char			*name;
		int				x;
		int				y;
		int				index;
		int				focus;
		int				select;
		struct s_arg	*last;
		struct s_arg	*prev;
		struct s_arg	*next;
}						t_arg;

typedef struct 			s_env{
		int				j[2];
		int				tot;
		int				wordmax;
		int				cursorx;
		int				cursory;
		int				prevcursorx;
		int				prevcursory;
		int				fd;
		int				del;
		int				ymax;
}						t_env;

int						g_flagsignal;
int						g_flagsignalz;
int						g_fd;
int						g_canon;
int						g_echo;
int						g_vim;
int						g_tim;
/*
**	keyhook.c
*/
void				check_key(t_env *env, t_arg **arg);
void				redraw(t_arg **arg, t_arg *ptr, t_env *env);
void				next_element(t_arg *arg, t_arg *ptr, t_env *env);
t_arg				*get_index(int index, t_arg *arg);

/*
**	init.c
*/
int					useless(int c);
int					uselesse(int c);
void				start_new_w(t_env *env);
void				poscur(int x, int y, t_env *env);
void				init_fd(char *path);
void				draw_argv(t_arg **arg, t_env *env);
void				balise_ptr(t_arg *ptr, t_env *env);
void				init_index(t_arg **arg, t_env *env);
int					check_wsize(t_env *env);
void				exit_fct(t_env *env);
/*
** main.c
*/
void				check_terminal();
struct termios		set_term();
int 				unset_term(struct termios term);

/*
** init_list.c
*/

void				init_list(t_arg **argu, char **av, t_env *env);
void				addlist(t_arg **argu, char *av, int posx, int posy, int i);
t_arg				*setmarg(int x, int y, char *av);
void				del_list(t_arg **arg, t_env *env);

/*
** init_env.c
*/
void				winsize(int fd, int i[2]);
void				init_env(t_env *env, char **av);

/*
** signal.c
*/
void				signal_fct();
void				sig_handler(int signo);

#endif
