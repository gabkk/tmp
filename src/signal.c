/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:53:58 by gkuma             #+#    #+#             */
/*   Updated: 2016/02/09 12:54:00 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				signal_fct(void)
{
	if (signal(SIGWINCH, sig_handler) == SIG_ERR)
		ft_putendl_fd("sig error1", 2);
	if (signal(SIGTSTP, sig_handler) == SIG_ERR)
		ft_putendl_fd("Succed", 2);
	if (signal(SIGCONT, sig_handler) == SIG_ERR)
		ft_putendl_fd("sig error3", 2);
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		ft_putendl_fd("sig error3", 2);
}

void				sig_handler(int signo)
{
	struct termios	term;

	if (signo == SIGWINCH)
		g_flagsignal = 1;
	else if (signo == SIGTSTP)
		sig_stp();
	else if (signo == SIGCONT)
	{
		if (signal(SIGTSTP, sig_handler) == SIG_ERR)
			ft_putendl_fd("SIGTSTP error", 2);
		g_flagsignalz = 1;
		ft_putstr_fd(tgetstr("vi", NULL), 3);
		ft_putstr_fd(tgetstr("ti", NULL), 3);
		if (tcgetattr(0, &term) == -1)
			return ;
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (tcsetattr(0, 0, &term) == -1)
			return ;
	}
	return ;
}

void				sig_stp(void)
{
	struct termios	term;
	char			cmd[3];

	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &term);
	cmd[0] = term.c_cc[VSUSP];
	cmd[2] = '\0';
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), 3);
	ioctl(0, TIOCSTI, cmd);
	signal(SIGTSTP, SIG_DFL);
	ft_putstr_fd(tgetstr("te", NULL), 3);
	ft_putstr_fd(tgetstr("ve", NULL), 3);
	term.c_lflag = 536872399;
	term.c_lflag = 536872399;
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 1;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return ;
}
