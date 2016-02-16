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

# include "ft_select.h"

void		signal_fct()
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

void			sig_handler(int signo)
{
	// int 	canon;
	// int 	echo;
	// int 	vim;
	// int 	tim;
	struct termios 	term;
//	const char		*tname;

	if (signo == SIGWINCH)
	{
		g_flagsignal = 1;
		return ;
	}
	if (signo == SIGTSTP)
	{
	struct termios 	term;

	// poscur(0, 0, NULL);
	// tputs(tgetstr("te", NULL), 1, useless);


	// close(g_fd);
	// //free(env); // free tt dans env

	// 	//tputs(tgetstr("it", NULL), 1, useless);
	// if (tcgetattr(0, &term) == -1)
	// 	return ;
	// term.c_lflag = g_canon;
	// term.c_lflag = g_echo;
	// term.c_cc[VMIN] = g_vim;
	// term.c_cc[VTIME] = g_tim;
	// if (tcsetattr(0, 0, &term) == -1)
	// 	return ;


				tgetent(NULL, getenv("TERM"));
				tcgetattr(0, &term);
				char cmd[3];
				cmd[0] = term.c_cc[VSUSP];
				cmd[2] = '\0';


				poscur(0, 0, NULL);
				//close(g_fd);
				//tputs(tgetstr("it", NULL), 1, useless);
				 //Reconfigure SIGTSTP par son état par défaut
				//ioctl(0, TIOCSTI, cmd);
				ioctl(0, TIOCSTI, cmd);

				signal(SIGTSTP, SIG_DFL);
				tputs(tgetstr("te", NULL), 1, useless);

				// if (tcgetattr(0, &term) == -1)
				// 	return ;

				term.c_lflag = g_canon;
				term.c_lflag = g_echo;
				term.c_cc[VMIN] = g_vim;
				term.c_cc[VTIME] = g_tim;

				// term.c_lflag = canon;
				// term.c_lflag = echo;
				// term.c_cc[VMIN] = vim;
				// term.c_cc[VTIME] = tim;

				//tputs(tgetstr("it", NULL), 1, useless);
				if (tcsetattr(0, TCSANOW, &term) == -1)
					return ;


				// tputs(tgetstr("nw", NULL), 1, useless);




		//g_flagsignalz = 0;

		return ;
	}
	if (signo == SIGCONT)
	{
		if (signal(SIGTSTP, sig_handler) == SIG_ERR)
			ft_putendl_fd("SIGTSTP error", 2);
		g_flagsignalz = 1;
	 	tputs(tgetstr("ti", NULL), 1, useless);
		if (tcgetattr(0, &term) == -1)
			return ;
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (tcsetattr(0, 0, &term) == -1)
			return ;
		return ;
	}
}










