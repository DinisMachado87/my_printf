/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:30:40 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:54:43 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_dig(long n, int fd)
{
	char	chr;

	chr = n + '0';
	write(fd, &chr, 1);
}

static int check_positive(int n, int fd, int details)
{
	int	n_printed;

	n_printed = 0;
	if ((n > 0 && details == '+') || (n < 0 && details == '-'))
	{
		ft_putchar_fd('+', fd);
		n_printed++;
	}
	else if ((n < 0 && details != '-') || (n > 0 && details == '-'))
	{
		ft_putchar_fd('-', fd);
		n_printed++;
	}
	return (n_printed);
}

static int my_putnum(long n, int fd)
{
	int	n_printed;

	n_printed = 0;
	if (n <= 9)
	{
		print_dig(n, fd);
		n_printed++;
	}
	else if (n >= 10)
	{
		n_printed += my_putnum(n / 10, fd);
		n_printed += my_putnum(n % 10, fd);
	}
	return (n_printed);
}

int	ft_putnbr_fd(int n, int fd, char details)
{
	int 	n_printed;

	n_printed = 0;
	n_printed += check_positive(n, fd, details);
	if (n < 0)
		n = -n;
	n_printed += my_putnum((long)n, fd);
	return (n_printed);
}

#include <stdio.h>

int	main()
{
	printf(", %d\n", ft_putnbr_fd(1059, 1, 'd'));
	printf(", %d\n", ft_putnbr_fd(-1059, 1, 'd'));
	printf(", %d\n", ft_putnbr_fd(+1059, 1, 'd'));
	printf(", %d\n", ft_putnbr_fd(1059, 1, '-'));
	printf(", %d\n", ft_putnbr_fd(-1059, 1, '-'));
	printf(", %d\n", ft_putnbr_fd(+1059, 1, '-'));
	printf(", %d\n", ft_putnbr_fd(1059, 1, '+'));
	printf(", %d\n", ft_putnbr_fd(-1059, 1, '+'));
	printf(", %d\n", ft_putnbr_fd(+1059, 1, '+'));
	printf(", %d\n", ft_putnbr_fd(11, 1, '+'));
	printf(", %d\n", ft_putnbr_fd(-11, 1, '+'));
	printf(", %d\n", ft_putnbr_fd(+11, 1, '+'));
	return(0);
}
