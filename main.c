/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 18:17:52 by gkuma             #+#    #+#             */
/*   Updated: 2015/05/14 20:48:42 by gkuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>

#define UC unsigned char

void	ft_bzero(void *s, size_t n);

char	*ft_strcat(char *s1, const char *s2);

int		ft_isascii(int c);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isprint(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

int		ft_puts(const char *s);

int		ft_strlen(char *str);

void	*ft_memset(void *b, int c, size_t len);

void	ft_putstr(char *str);

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

char	*ft_strdup(const char *s1);

void	ft_cat(int fd);

/*
 *  Bonus
*/

void	ft_putchar(char c)
{
	write(1,&c,1);
}
/*
void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
*/
void	*ft_memsete(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	if (!b)
		return (b);
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}


int	main(int ac, char **av)
{
	/*
	 * 							Test ft_puts
	 */
	(void)ac;
	ft_putchar(10);
	puts("hello");
	ft_putchar(10);
	puts(NULL);
	ft_putchar(10);
	ft_puts("hello");
	ft_putchar(10);
	ft_puts(NULL);
	ft_putchar(10);

	/*
	 * 							Test ft_puts
	 */	
	/*
	 * 							Test ft_bzero
	 */

	char	str[] = "hello";
	char	str2[] = "hello";
	printf("\n ft_bzero \n");
	printf("Test 1 \n ft_bzero et bzero n = 1	et str : %s\n",str);
	bzero(str, 1);
	printf("Avec bzero et str[0] : %c\n",str[0]);
	ft_bzero(str2, 1);
	printf("Avec ft_bzero et str2[0] : %c\n",str2[0]);
	printf("Avec bzero et str[3] : %c\n",str[3]);
	printf("Avec ft_bzero et str[3] : %c\n\n",str[3]);

	char	str3[] = "hello";
	char	str4[] = "hello";
	printf("Test 2 \n ft_bzero et bzero n = 4	et str : %s\n",str3);
	bzero(str3, 4);
	printf("Avec bzero et str[0] : %c\n",str3[0]);
	ft_bzero(str4, 4);
	printf("Avec ft_bzero et str2[0] : %c\n",str4[0]);
	printf("Avec bzero et str[3] : %c\n",str3[3]);
	printf("Avec ft_bzero et str[3] : %c\n",str4[3]);
	printf("Avec bzero et str[4] : %c\n",str3[4]);
	printf("Avec ft_bzero et str[4] : %c\n\n",str4[4]);

	char	str5[] = "hello";
	char	str6[] = "hello";
	printf("Test 3 \n ft_bzero et bzero n = 9	et str : %s\n",str5);
	bzero(str5, 9);
	printf("Avec bzero et str[4] : %c\n",str5[4]);
	ft_bzero(str6, 9);
	printf("Avec ft_bzero et str2[4] : %c\n",str6[4]);


	/*
	 *							Fin ft_bzero
	 */

	/*
	 *							ft_strcat
	 */
	char		*src;
	char		*src2;
	char		*src3;
	char		*src4;
	char		dest[40] = "Please Cat";
	char		dest2[40] = "Please Cat";

	src = "_meEeeeEeeE";
	src2 = "_meEeeeEeeE";	
	printf("\n Test 1 ft_strcat\n");
	printf("Dest : %s\nSize Dest: 40\nSrc : %s .\n", dest, src);
	src3 = strcat(dest, src);
	printf("strcat Dest : %s\n", src3);
	src4 = ft_strcat(dest2, src2);
	printf("ft_strcat Dest : %s\n", src4);

	printf("\n And Re - ft_strcat\n");
	strcat(dest, src);
	printf("strcat Dest : %s\n", dest);
	src3 = ft_strcat(dest2, src2);
	printf("ft_strcat Dest : %s\n", src3);




	/*
	 *							Fin ft_strcat
	 */

	/*
	 *							 ft_isascii
	 */
	int		a;
	int		z;
	int		nbr;
	int		weird;
	int		neg;

	neg = -500;
	a = 'a';
	z = 'Z';
	nbr = 57;
	weird = 173;
	printf("\n\nTest ascii\n");
	printf("un = %c\ndeux = %c\ntrois = %c\nweird = %c\nneg = %d\n",a ,z, nbr, weird, neg);
	printf("ft_isascii       isascii\n");
	printf("%d                %d\n",ft_isascii(a), isascii(a));
	printf("%d                %d\n",ft_isascii(z), isascii(z));
	printf("%d                %d\n",ft_isascii(nbr), isascii(nbr));
	printf("%d                %d\n",ft_isascii(weird), isascii(weird));
	printf("%d                %d\n",ft_isascii(neg), isascii(neg));
	/*while (neg < 500)
	  {
	  neg++;
	  ft_putchar(ft_isascii(neg) + 48);

	  }*/


	/*
	 *							Fin ft_isascii
	 */
	/*
	 *							 ft_isalpha
	 */
	int		b;
	int		y;
	int		nb;
	int		weir;

	b = 'a';
	y = 94;
	nb = 'Z';
	weir = 173;
	neg = -1;
	printf("\n\nTest isalpha\n");
	printf("un = %c\ndeux = %c\ntrois = %c\nweird = %c\nneg = %d\n",b ,y, nb, weir,neg);
	printf("ft_isalpha       isalpha\n");
	printf("%d                %d\n",ft_isalpha(b), isalpha(b));
	printf("%d                %d\n",ft_isalpha(y), isalpha(y));
	printf("%d                %d\n",ft_isalpha(nb), isalpha(nb));
	printf("%d                %d\n",ft_isalpha(weir), isalpha(weir));
	printf("%d                %d\n",ft_isalpha(neg), isalpha(neg));
	/*
	 *							Fin ft_isalpha
	 */
	/*
	 *							 ft_isdigit
	 */
	int		c;
	int		x;
	int		nbt;
	int		weira;

	c = 47;
	x = 48;
	nbt = 57;
	weira = 58;
	printf("\n\nTest isdigit\n");
	printf("un = %c\ndeux = %c\ntrois = %c\nweird = %c\nneg = %d\n",c ,x, nbt, weira, neg);
	printf("ft_isdigit       isdigit\n");
	printf("%d                %d\n",ft_isdigit(c), isdigit(c));
	printf("%d                %d\n",ft_isdigit(x), isdigit(x));
	printf("%d                %d\n",ft_isdigit(nbt), isdigit(nbt));
	printf("%d                %d\n",ft_isdigit(weira), isdigit(weira));
	printf("%d                %d\n",ft_isdigit(neg), isdigit(neg));
	/*
	 *							Fin ft_isdigit
	 */
	/*
	 *							 ft_isalnum
	 */
	int		d;
	int		w;
	int		nbq;
	int		weirb;

	d = 69;
	w = 48;
	nbq = 57;
	weirb = 92;
	printf("\n\nTest isalnum\n");
	printf("un = %c\ndeux = %c\ntrois = %c\nweird = %c\nneg = %d\n",d ,w, nbq, weirb, neg);
	printf("ft_isalnum       isalnum\n");
	printf("%d                %d\n",ft_isalnum(d), isalnum(d));
	printf("%d                %d\n",ft_isalnum(w), isalnum(w));
	printf("%d                %d\n",ft_isalnum(nbq), isalnum(nbq));
	printf("%d                %d\n",ft_isalnum(weirb), isalnum(weirb));
	printf("%d                %d\n",ft_isalnum(neg), isalnum(neg));
	/*
	 *							Fin ft_isalnum
	 */
	/*
	 *							 ft_isprint
	 */
	int		e;
	int		v;
	int		nbs;
	int		weirc;

	e = 32;
	v = 126;
	nbs = 12;
	weirc = 380;
	printf("\n\nTest isprint\n");
	printf("un = %c\ndeux = %c\ntrois = %c\nweird = %c\nneg = %d\n",e ,v, nbs, weirc, neg);
	printf("ft_isprint       isprint\n");
	printf("%d                %d\n",ft_isprint(e), isprint(e));
	printf("%d                %d\n",ft_isprint(v), isprint(v));
	printf("%d                %d\n",ft_isprint(nbs), isprint(nbs));
	printf("%d                %d\n",ft_isprint(weirc), isprint(weirc));
	printf("%d                %d\n",ft_isprint(neg), isdigit(neg));
	/*
	 *							Fin ft_isprint
	 */
	/*
	 *							 ft_touppper
	 */
	e = 97;
	v = 122;
	nbs = 69;
	weirc = 36;
	printf("\n\nTest ft_toupper\n");
	printf("un = %c\ndeux = %c\ntrois = %c\nweird = %c\nneg = %d\n",e ,v, nbs, weirc, neg);
	printf("ft_toupper       toupper\n");
	printf("%c                %c\n",ft_toupper((UC)e), toupper((UC)e));
	printf("%c                %c\n",ft_toupper(v), toupper(v));
	printf("%c                %c\n",ft_toupper(nbs), toupper(nbs));
	printf("%c                %c\n",ft_toupper(weirc), toupper(weirc));
	printf("%c                %c\n",ft_toupper(neg), toupper(neg));
	/*
	 *							Fin ft_toupper
	 */
	/*
	 *							 ft_tolower
	 */
	e = 65;
	v = 90;
	nbs = 122;
	weirc = 36;
	printf("\n\nTest ft_tolower\n");
	printf("un = %c\ndeux = %c\ntrois = %c\nweird = %c\nneg = %d\n",e ,v, nbs, weirc, neg);
	printf("ft_tolower       tolower\n");
	printf("%c                %c\n",ft_tolower((UC)e), tolower((UC)e));
	printf("%c                %c\n",ft_tolower(v), tolower(v));
	printf("%c                %c\n",ft_tolower(nbs), tolower(nbs));
	printf("%c                %c\n",ft_tolower(weirc), tolower(weirc));
	printf("%c                %c\n",ft_tolower(neg), tolower(neg));
	/*
	 *							Fin ft_tolower
	 */
	ft_putchar('\n');

	int		l1;
	int		l2;

	/*
	 *						ft_strlen
	 */
	l1 = ft_strlen("yo Mamaa");
	ft_putstr("yo Mamaa ft_strlen: ");
	ft_putchar(l1 + 48);
	ft_putchar('\n');
	l2 = strlen("yo Mamaa");
	ft_putstr("yo Mamaa strlen: ");
	ft_putchar(l2 + 48);
	ft_putchar('\n');
	//	l2 = strlen(NULL);
	//	ft_putchar(l2 + 48);
	//	ft_putchar('\n');
	l1 = ft_strlen("\n");
	ft_putstr(" ft_strlen: ");
	ft_putchar(l1 + 48);
	ft_putchar('\n');
	l2 = strlen("\n");
	ft_putstr(" strlen: ");
	ft_putchar(l2 + 48);
	ft_putchar('\n');
	/*
	 *						Fin ft_strlen
	 */						


	/*
	 *						debut ft_memset
	 */						
	char	*memtmp;
	char	*memtmporg;
	char	*vide;
	char	*videe;

	printf("\nTEST ft_memset\n");
	vide = malloc(sizeof(char *) * 5);
	memtmporg = malloc(sizeof(char *) * 5);
	videe = malloc(sizeof(char *) * 5);
	memtmp = malloc(sizeof(char *) * 5);
	ft_putstr(memtmporg);
	ft_putchar('\n');
	memset(memtmporg, 'A', 4);
	ft_putstr(memtmporg);
	ft_putchar('\n');
	ft_memset(memtmp, 'B', 4);
	ft_putstr(memtmp);
	ft_putchar('\n');
	/*
	 *						Fin ft_memset
	 */						


	
	/*
	 *						debut ft_memcpy
	 */						
	
	
	printf("\nTEST ft_memcpy\n");
	
	memcpy(vide, memtmporg, 2);
	ft_putstr(vide);
	ft_putchar('\n');
	ft_memcpy(videe, memtmp, 2);
	ft_putstr(videe);
	ft_putchar('\n');



	/*
	 *						fin ft_memcpy
	 */



	 /*						debut ft_strdup
	 *						
	*/
	char		*isdup;
	char		*todup;
	char		*mydup;

	printf("\nTEST ft_strdup\n");
	todup = "Dupme";
	isdup = strdup(todup);
	ft_putstr(isdup);
	ft_putchar('\n');
	mydup = ft_strdup(todup);
	ft_putstr(mydup);
	ft_putchar('\n');


	 /*	[M@ft_putchar:					debut ft_strdup
	 *						
	*/


	 /*						debut ft_cat
	 *						
	*/
	int			fd;

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
