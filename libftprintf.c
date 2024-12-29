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

static char is_d_format(const char *form_str)
{
	if (*form_str == 'd')
		return ('d');
	else if (*form_str == '+' && form_str[1] == 'd')
		return ('+');
	else if (*form_str == '-' && form_str[1] == 'd')
		return ('-');
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
			else if ((details = is_d_format(form_str)))
			{
				if (details == '-' || details == '+')
					form_str++;
				n_printed += ft_putnbr_fd(va_arg(args, int), 1, details);
			}
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
	char *test_str = "char %c,\nstr %s,\ndecimal - %+d %-d %d\n";
	ft_printf("printed char: %d\n", ft_printf(test_str, 'a', "Hello", 1059, -1059, -1059));
	printf("printed char: %d\n", printf(test_str, 'a', "Hello", 1059, -1059, -1059));
	return (0);
}
/*
*/
