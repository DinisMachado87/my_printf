/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:28:12 by dimachad          #+#    #+#             */
/*   Updated: 2025/01/06 21:04:58 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	core_putbase(long num, char *base, int fd)
{
	int		n_printed;
	size_t	base_len;

	n_printed = 0;
	base_len = ft_strlen(base);
	if (num < (long)base_len)
	{
		write(fd, &base[num], 1);
		n_printed++;
	}
	else
	{
		n_printed += core_putbase((num / base_len), base, fd);
		n_printed += core_putbase((num % base_len), base, fd);
	}
	return (n_printed);
}

int	ft_putptr(uintptr_t n, int fd, char form_str)
{
	int	n_printed;

	n_printed = 0;
	n_printed += ft_putstr_fd("0x", 1);
	n_printed += ft_putbase(n, fd, form_str);
	return (n_printed);
}

int	ft_putbase(uintptr_t n, int fd, char form_str)
{
	int		n_printed;
	long	num;
	char	*base;

	n_printed = 0;
	if (form_str == 'X')
		base = "0123456789ABCDEF"; 
	else
		base = "0123456789abcdef";
	num = (long)n;
	n_printed += core_putbase(num, base, fd);
	return (n_printed);
}
/*
int main()
{
    char *base16 = "0123456789ABCDEF";
    char *base2 = "01";

    ft_putbase(255, base16, 1); // Hexadecimal
    write(1, "\n", 1);
    ft_putbase(255, base2, 1);  // Binary
    write(1, "\n", 1);
    ft_putbase(-42, base16, 1); // Negative hexadecimal
    write(1, "\n", 1);
    ft_putbase(-2147483648, base2, 1); // INT_MIN in binary
    write(1, "\n", 1);

    return (0);
}
*/
