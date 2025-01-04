/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:27:15 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/19 17:27:16 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int validate_type (const char *form_str)
{
	const char	*type_str = "cspdiuxX%+-";
	int			i_type;

	i_type = 0;
	while (type_str[i_type])
	{
		if (form_str[1] == type_str[i_type])
			return (1);
		i_type++;
	}
	return (0);
}

static char is_d_i_or_u(const char *form_str)
{
	if (*form_str == 'd' || *form_str == 'i')
		return ('d');
	else if (*form_str == '+' && (form_str[1] == 'd' || form_str[1] == 'i'))
		return ('+');
	else if (*form_str == '-' && (form_str[1] == 'd' || form_str[1] == 'i'))
		return ('-');
	else if (*form_str == 'u') 
		return ('u');
	else if	((*form_str == '-' || *form_str == '+') && form_str[1] == 'u')
		return ('U');
	else
		return ('\0');
}

int	ft_printf(const char *form_str, ...)
{
	int		n_printed;
	va_list	args;
	char	details;

	n_printed = 0;
	va_start(args, form_str);
	while (*form_str)
	{
		if (*form_str == '%' && validate_type(form_str))
		{
			if (*++form_str == 'c')
				n_printed += ft_putchar_fd(va_arg(args, int), 1);
			else if (*form_str == 's')
				n_printed += ft_putstr_fd(va_arg(args, char *), 1);
			else if (*form_str == 'p')
				n_printed += ft_putptr(va_arg(args, uintptr_t), "0123456789ABCDEF", 1);
			else if ((details = is_d_i_or_u(form_str)))
			{
				if (details == '-' || details == '+' || details == 'U')
					form_str++;
				if (*form_str == 'u')
					n_printed += ft_putunbr_fd(va_arg(args, unsigned int), 1);
				else
					n_printed += ft_putnbr_fd(va_arg(args, int), 1, details);
			}
			else if (*form_str == 'x')
				n_printed += ft_putbase(va_arg(args, unsigned int), "0123456789abcdef", 1);
			else if (*form_str == 'X')
				n_printed += ft_putbase(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
			else if (*form_str == '%')
				n_printed += ft_putchar_fd('%', 1);
		}
		else
			n_printed += ft_putchar_fd(*form_str, 1);
		form_str++;
	}
	return (n_printed);
}

#include <stdio.h>

int	main()
{
	char *test_str = "char %c char %%";
	ft_printf(", printed char: %d\n", ft_printf(test_str, 'a'));
	printf(", printed char: %d\n", printf(test_str, 'a'));
	printf("\n");

	char *test_str1 = "str %s";
	ft_printf(", printed char: %d\n", ft_printf(test_str1, "Hello"));
	printf(", printed char: %d\n", printf(test_str1, "Hello"));
	printf("\n");

	char *test_str2 = "decimal - %+d %-d %d";
	ft_printf(", printed char: %d\n", ft_printf(test_str2, 1059, -1059, -1059));
	printf(", printed char: %d\n", printf(test_str2, 1059, -1059, -1059));
	printf("\n");

	char *test_str3 = "int - %+i %-i %i";
	ft_printf(", printed char: %d\n", ft_printf(test_str3, 1059, -1059, -1059));
	printf(", printed char: %d\n", printf(test_str3, 1059, -1059, -1059));
	printf("\n");

	char *test_str4 = "un int - %+u %-u %u %u %u %u";
	ft_printf(", printed char: %d\n", ft_printf(test_str4, 1059, -1059, -1059, 1059, -1059, -1059));
	printf(", printed char: %d\n", printf(test_str4, 1059, -1059, -1059, 1059, -1059, -1059));
	printf("\n");
	
	char *test_str5 = "HEX cap - %X %X %X";
	ft_printf(", printed char: %d\n", ft_printf(test_str5, 1059, -1059, +1059));
	printf(", printed char: %d\n", printf(test_str5, 1059, -1059, +1059));
	printf("\n");
	
	char *test_str6 = "HEX small - %x %x %x";
	ft_printf(", printed char: %d\n", ft_printf(test_str6, 1059, -1059, +1059));
	printf(", printed char: %d\n", printf(test_str6, 1059, -1059, +1059));
	printf("\n");

	char *test_str7 = "PTR  - %p %p %p";
	ft_printf(", printed char: %d\n", ft_printf(test_str7, test_str7, test_str7, test_str7));
	printf(", printed char: %d\n", printf(test_str7, test_str7, test_str7, test_str7));
	printf("\n");
	
	return (0);
}
/*
*/
