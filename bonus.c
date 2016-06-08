/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 18:17:45 by gkuma             #+#    #+#             */
/*   Updated: 2015/05/19 10:53:17 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putstr(char *str);

//int		ft_strlen(char *str);

void	ft_bzero(void *s, size_t n);

void	*ft_memalloc(size_t size);

void 	*ft_memchr(const void *s, int c, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
//int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}


int		main(void)
{
	ft_putstr("\n------------Bonus----------\n");
	ft_putchar('\n');
	ft_putstr("-----------ft_putstr----------");
	ft_putchar('\n');
	ft_putstr("yo     42");
	ft_putchar('\n');
//	ft_putstr(NULL);
	ft_putchar('\n');
	ft_putstr("segfault putin");

	ft_putchar('\n');

	ft_putstr("-----------ft_memchr----------");
	int		memsize;
	int		charc;
	char	*testmem;

	testmem = "salut";
	charc = 108;
	memsize = 5;
	ft_putchar('\n');
	ft_putstr(ft_memchr(testmem, charc, memsize));
	ft_putchar('\n');
	ft_putstr(memchr(testmem, charc, memsize));
	ft_putchar('\n');

	ft_putstr("-----------ft_strcmp----------");
	char	*test1 = "gabba";
	char	*test2 = "gabbuss";

	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr("ft_strcmp : ");
	ft_putnbr(ft_strcmp(test1, test2));
	ft_putchar('\n');
	ft_putstr("ft_strncmp : ");
	ft_putnbr(strcmp(test1, test2));
	ft_putchar('\n');
	ft_putstr("ft_strcmp : ");
	ft_putnbr(ft_strcmp(test2, test1));
	ft_putchar('\n');
	ft_putstr("ft_strncmp : ");
	ft_putnbr(strcmp(test2, test1));
	ft_putchar('\n');
	ft_putstr("ft_strcmp : ");
	ft_putnbr(ft_strcmp(test1, test2));
	ft_putchar('\n');
	ft_putstr("ft_strncmp : ");
	ft_putnbr(strcmp(test1, test2));
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr("-----------ft_strncmp----------");
	char	*testa1 = "gabba";
	char	*testa2 = "gabbu";

	ft_putchar('\n');
	ft_putstr("ft_strcmp : ");
	ft_putnbr(ft_strncmp(testa1, testa2, 3));
	ft_putchar('\n');
	ft_putstr("ft_strncmp : ");
	ft_putnbr(strncmp(testa1, testa2, 3));
	ft_putchar('\n');
	ft_putstr("ft_strcmp : ");
	ft_putnbr(ft_strncmp(testa2, testa1, 4));
	ft_putchar('\n');
	ft_putstr("ft_strncmp : ");
	ft_putnbr(strncmp(testa2, testa1, 4));
	ft_putchar('\n');
	ft_putstr("ft_strcmp : ");
	ft_putnbr(ft_strncmp(testa1, testa2, 5));
	ft_putchar('\n');
	ft_putstr("ft_strncmp : ");
	ft_putnbr(strncmp(testa1, testa2, 5));
	ft_putchar('\n');

	ft_putstr("-----------ft_memalloc----------");
	ft_putchar('\n');


	char		*memalloc;
	int			i;

	i = 0;
	ft_putchar('\n');
	memalloc = ft_memalloc(3);
	memalloc = "yo";
	ft_putchar(memalloc[5]);
	ft_putchar('\n');
	ft_putstr(memalloc);
	ft_putchar('\n');
	return (0);
}
