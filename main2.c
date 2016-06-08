/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillau <aguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 01:23:30 by aguillau          #+#    #+#             */
/*   Updated: 2015/03/20 06:24:18 by aguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(char *str);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);
/*
void	*ft_memalloc(size_t n);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_isspace(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
*/
int		main(int ac, char **av)
{
//--------ft_bzero------------

	printf("\033[33m---ft_bzero---\n\n\033[0m");
	char str[4] = "slt";
	ft_bzero(str, 3);
	printf("%d\n", str[0]);
	printf("%d\n", str[1]);
	printf("%d\n", str[2]);
	ft_bzero(NULL, 0);
	printf("\n");

//-------ft_strcat------------

	printf("\033[33m---ft_strcat---\n\n\033[0m");
	char str1[6] = "sal";
	char str2[3] = "ut";

	ft_strcat(str1, str2);
	printf("%s\n", str1);
	printf("s1 = sal, s2 = ut\n");
	printf("\n");

//-------ft_isalpha-----------

	printf("\033[33m---ft_isalpha---\n\n\033[0m");
	int i;

	i = ft_isalpha(62);
	printf("> :%d\n", i);
	i = ft_isalpha(65);
	printf("A :%d\n", i);
	i = ft_isalpha(122);
	printf("z :%d\n", i);
	i = ft_isalpha(123);
	printf("{ :%d\n", i);
	i = ft_isalpha(91);
	printf("[ :%d\n", i);
	printf("\n");

//-------ft_isdigit------------

	printf("\033[33m---ft_isdigit---\n\n\033[0m");

	i = ft_isdigit(62);
	printf("> :%d\n", i);
	i = ft_isdigit('0');
	printf("0 :%d\n", i);
	i = ft_isdigit('9');
	printf("9 :%d\n", i);
	i = ft_isdigit(58);
	printf(": :%d\n", i);
	i = ft_isdigit(91);
	printf("[ :%d\n", i);
	printf("\n");

//-------ft_isalnum------------

	printf("\033[33m---ft_isalnum---\n\n\033[0m");

	i = ft_isalnum(48);
	printf("0 :%d\n", i);
	i = ft_isalnum(67);
	printf("C :%d\n", i);
	i = ft_isalnum(122);
	printf("z :%d\n", i);
	i = ft_isalnum(123);
	printf("{ :%d\n", i);
	i = ft_isalnum(91);
	printf("[ :%d\n", i);
	printf("\n");

//-------ft_isascii------------

	printf("\033[33m---ft_isascii---\n\n\033[0m");

	i = ft_isascii(0);
	printf("NULL :%d\n", i);
	i = ft_isascii(127);
	printf("DEL :%d\n", i);
	i = ft_isascii(152);
	printf("152 :%d\n", i);
	i = ft_isascii(66);
	printf("B :%d\n", i);
	printf("\n");

//-------ft_isprint------------

	printf("\033[33m---ft_isprint---\n\n\033[0m");

	i = ft_isprint(0);
	printf("NULL :%d\n", i);
	i = ft_isprint(127);
	printf("DEL :%d\n", i);
	i = ft_isprint('6');
	printf("6 :%d\n", i);
	i = ft_isprint(66);
	printf("B :%d\n", i);
	printf("\n");

//-------ft_toupper------------

	char c;

	printf("\033[33m---ft_toupper---\n\n\033[0m");

	c = ft_toupper('.');
	printf(". :%c\n", c);
	c = ft_toupper('a');
	printf("a :%c\n", c);
	c = ft_toupper('z');
	printf("z :%c\n", c);
	c = ft_toupper('D');
	printf("d :%c\n", c);
	printf("\n");

//-------ft_tolower------------

	printf("\033[33m---ft_tolower---\n\n\033[0m");

	c = ft_tolower('.');
	printf(". :%c\n", c);
	c = ft_tolower('A');
	printf("A :%c\n", c);
	c = ft_tolower('Z');
	printf("Z :%c\n", c);
	c = ft_tolower('d');
	printf("d :%c\n", c);
	printf("\n");

//-------ft_puts------------

	printf("\033[33m---ft_puts---\n\n\033[0m");

//	ft_putstr("\033[0mTest puts NULL + Return Value:");
//	ft_putchar('\n');
	printf("%d\n", ft_puts(NULL));
//
	ft_puts("Hello WORLD!");

	printf("\n");

//-------ft_strlen------------

	printf("\033[33m---ft_strlen---\n\n\033[0m");

	i = ft_strlen("salut");
	printf("Salut : %d\n", i);
	i = ft_strlen("Hello World!");
	printf("Hello World! : %d\n", i);
	i = ft_strlen("");
	printf("BSlash0 : %d\n", i);

	printf("\n");

//-------ft_memset------------

	printf("\033[33m---ft_memset---\n\n\033[0m");

	char *mem;
	char mem2[6] = "salut\0";
	char mem3[11] = "a b c d F \0";
	mem = ft_memset(mem2, 'e', 2);
	printf("salut - e - 2: %s\n", mem);
	mem = ft_memset(mem2, 'a', 5);
	printf("salut - a - 5: %s\n", mem);
	mem = ft_memset(mem3, 'Z', 5);
	printf("a b c d F - Z - 5 : %s\n", mem);
	mem = ft_memset(mem3, 'o', 9);
	printf("a b c d F - o - 10: %s\n", mem);
	printf("\n");

//-------ft_memcpy------------
/*
	printf("\033[33m---ft_memcpy---\n\n\033[0m");

	char *mem8;
	char mem4[6] = "salut\0";
	char mem5[6] = "abc\0";
	char mem6[6] = "abc\0";
	char mem7[6] = "salut\0";

	mem8 = ft_memcpy(mem4, mem5, 2);
	printf("salut - abc - 2: %s\n", mem8);
	mem8 = ft_memcpy(mem4, mem5, 3);
	printf("salut - abc - 3: %s\n", mem8);
	mem8 = ft_memcpy(mem6, mem7, 6);
	printf("abc - salut - 6: %s\n", mem8);
	printf("\n");

*/
//-------ft_strdup------------
/*
	printf("\033[33m---ft_strdup---\n\n\033[0m");

	char *mem10;

	mem10 = ft_strdup("Hello you!");
	printf("Hello you!: %s\n", mem10);
	printf("\n");
*/
//-------ft_putstr-------------
/*
	printf("\033[33m---ft_putstr---\n\n\033[0m");

	ft_putstr("\033[0mhello");
	printf("\n\nTest : hello\n\n");
	ft_putstr("World    8");
	printf("\n\nTest : World    8\n\n");
	ft_putstr(NULL);
	printf("Test : NULL\n");
	printf("\n");
*/
//-------ft_putchar-------------
/*
	printf("\033[33m---ft_putchar---\n\n\033[0m");

	printf("Test : &\n");
	ft_putchar('&');
	printf("\nTest : c\n");
	ft_putchar('c');
	printf("\n");
*/
//-------ft_isspace------------
/*
	printf("\033[33m---ft_isspace---\n\n\033[0m");

	i = ft_isspace(0);
	printf("NULL :%d\n", i);
	i = ft_isspace(127);
	printf("DEL :%d\n", i);
	i = ft_isspace('\t');
	printf("BsT :%d\n", i);
	i = ft_isspace('\f');
	printf("BsF :%d\n", i);
	printf("\n");
*/
//------ft_strchr-------------
/*
	printf("\033[33m---ft_strchr---\n\n\033[0m");

	char		str5[] = "Hello je test";

	if (strchr(str5, 'H') != ft_strchr(str5, 'H'))
		write(1, "FAIL\n", 5);
	if (strchr(str5, 'j') != ft_strchr(str5, 'j'))
		write(1, "FAIL\n", 5);
	if (strchr(str5, 't') != ft_strchr(str5, 't'))
		write(1, "FAIL\n", 5);
	if (strchr(str5, 'y') != ft_strchr(str5, 'y'))
		write(1, "FAIL\n", 5);
	if (strchr(str5, 0) != ft_strchr(str5, 0))
		write(1, "FAIL\n", 5);
	write(1, "\033[0mOK\n", 8);

	printf("\nTest : Cmp with real strchr\n");
	printf("\n");
*/
//------ft_strnew-------------
/*
	printf("\033[33m---ft_strnew---\n\n\033[0m");

	char		*str6;
	int			f;

	f = 0;
	str6 = ft_strnew(40);
	if (str6 != NULL)
	{
		while (f < 41)
		{
			if (str6[i] != '\0')
				printf("fail\n");				
			f++;
		}
	}
	printf("OK\n");
	printf("\nTest : Check if new str with Bs0\n\n\033[0m");
*/
//------ft_memalloc------------
/*
	printf("\033[33m---ft_memalloc---\n\n\033[0m");

	void	*mem1;

	if ((mem1 = ft_memalloc(4)))
		printf("OK\n");
	else
		printf("Fail\n");
	printf("\nTest : Check if malloc work.\n\n\033[0m");
*/
//--------ft_cat---------------
	 /*						debut ft_cat
	 *						
	*/
	int			fd;

(void)ac;
	printf("\nTEST ft_cat\n");
	printf("\n sur 0\n");
	ft_cat(0);
	printf("\n sur ./src/ft_cat.s\n");
	fd = open("./src/ft_cat.s", O_RDONLY);
	ft_cat(fd);
	close(fd);
	printf("\n sur -42\n");
	ft_cat(-42);
	printf("\n sur __FILE__\n");
	ft_cat(open(__FILE__, O_RDONLY));
	printf("\n sur av[0]\n");
	ft_cat(open(av[0], O_RDONLY));
	 /*						fin ft_cat
	 *						
	*/

	return (0);
}