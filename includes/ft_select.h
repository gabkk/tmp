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
# define ANSI_COLOR_RESET_REV	"\x1b[27m\x1b[0m"

typedef struct			s_arg{
	char				*name;
	int					x;
	int					y;
	int					index;
	int					focus;
	int					select;
	struct s_arg		*last;
	struct s_arg		*prev;
	struct s_arg		*next;
}						t_arg;

typedef struct			s_env{
	int					j[2];
	int					tot;
	int					wordmax;
	int					cursorx;
	int					cursory;
	int					prevcursorx;
	int					prevcursory;
	int					fd;
	int					del;
	int					ymax;
	int					draw;
	int					action;
	int					canon;
	int					echo;
	int					vim;
	int					tim;
}						t_env;

int						g_flagsignal;
int						g_flagsignalz;

/*
**	keyhook.c
*/
void					check_key(t_env *env, t_arg **arg);
void					check_signal(t_arg **arg, t_arg *ptr, t_env *env);
void					draw_small(t_env *env);
void					redraw(t_arg **arg, t_arg *ptr, t_env **env);
t_arg					*get_index(int index, t_arg *arg);

/*
**	init.c
*/

void					start_new_w(t_env *env);
void					draw_argv(t_arg **arg, t_env *env);
void					draw_argv_loop(t_arg *ptr, t_env *env, int x, int *rt);
void					balise_ptr(t_arg *ptr, t_env *env);
void					exit_fct(t_env *env);

/*
** main.c
*/
void					main_body(t_env *env, char **av, t_arg *arg);
void					init_term(t_env *env);
void					check_terminal(t_env *env);
void					read_input(t_arg **arg, t_arg **ptr, t_env **env);

/*
** init_list.c
*/

void					init_list(t_arg **argu, char **av, t_env *env);
void					addlist(t_arg **argu, char *av, int px, int py);
t_arg					*setmarg(int x, int y, char *av);
void					init_first(t_arg **newm, char *av);
void					set_i(t_arg **argu, int i);

/*
** del_liste.c
*/
t_arg					*del_list(t_arg **arg, t_env *env);
void					do_the_del(t_arg **arg, t_arg **tmpfocus, t_env *env);
void					del_normal(t_arg **ptr, t_arg **tmpfocus);
t_arg					*first_del(t_arg **ptr, t_arg **tmpfocus, t_arg *arg);
void					last_del(t_arg **ptr, t_arg **tmpfocus, t_arg *arg);

/*
** init_index.c
*/
void					init_index(t_arg **arg, t_env *env, t_arg *argfocus);
void					set_index(t_arg **arg, t_env *env, t_arg *argfocus);
void					set_focus(t_arg **ptr, t_arg *argfocus);
void					new_line(t_arg **ptr, int *x, int *y);
void					new_colomn(t_arg **ptr, t_env **env, int *x, int y);

/*
** init_env.c
*/
void					winsize(int fd, int i[2]);
void					init_env(t_env *env, char **av);
void					poscur(int x, int y, t_env *env);
int						check_wsize(t_env *env);
void					init_fd(char *path);

/*
** signal.c
*/
void					signal_fct(void);
void					sig_handler(int signo);
void					sig_stp(void);

/*
** keyhook_action.c
*/
void					read_key(t_arg **arg, t_arg **ptr, t_env **env);
void					read_a(t_arg **arg, t_arg **ptr, t_env *env, char *bf);
void					read_space(t_arg **ptr, t_env **env, t_arg **arg);
void					read_del(t_arg **ptr, t_env **env, t_arg **arg);
void					read_enter(t_env **env, t_arg **ptr, t_arg **arg);

/*
** tool.c
*/
t_arg					*get_right(t_arg **arg, t_arg *ptr, t_env *env);
t_arg					*get_left(t_arg **arg, t_arg *source, t_env *env);

#endif
