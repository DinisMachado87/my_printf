/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:27:15 by dimachad          #+#    #+#             */
/*   Updated: 2025/01/06 22:04:02 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	validate_type(const char *form_str)
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

static char	is_d_i_or_u(const char *form_str)
{
	if (*form_str == 'd' || *form_str == 'i')
		return ('d');
	else if (*form_str == '+' && (form_str[1] == 'd' || form_str[1] == 'i'))
		return ('+');
	else if (*form_str == '-' && (form_str[1] == 'd' || form_str[1] == 'i'))
		return ('-');
	else if (*form_str == 'u') 
		return ('u');
	else if ((*form_str == '-' || *form_str == '+') && form_str[1] == 'u')
		return ('U');
	else
		return ('\0');
}

int	printf_lock(va_list args, char form_str, char details)
{
	int		n_printed;

	n_printed = 0;
	if (form_str == 'c')
		n_printed += ft_putchar_fd(va_arg(args, int), 1);
	else if (form_str == 's')
		n_printed += ft_putstr_fd(va_arg(args, char *), 1);
	else if (form_str == 'p')
		n_printed += ft_putptr(va_arg(args, intptr_t), 1, 'x');
	else if (form_str == 'u')
		n_printed += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if ((form_str == 'i') || (form_str == 'd'))
		n_printed += ft_putnbr_fd(va_arg(args, int), 1, details);
	else if (form_str == 'x')
		n_printed += ft_putbase(va_arg(args, unsigned int), 1, form_str);
	else if (form_str == 'X')
		n_printed += ft_putbase(va_arg(args, unsigned int), 1, form_str);
	else if (form_str == '%')
		n_printed += ft_putchar_fd('%', 1);
	return (n_printed);
}

int	ft_printf(const char *form_str, ...)
{
	int		n_printed;
	va_list	args;
	char	details;

	n_printed = 0;
	details = '\0';
	va_start(args, form_str);
	while (*form_str)
	{
		if (*form_str == '%' && validate_type(form_str))
		{
			form_str++;
			details = is_d_i_or_u(form_str);
			if (details)
			{
				if (details == '-' || details == '+' || details == 'U')
					form_str++;
			}
			n_printed += printf_lock(args, *form_str, details);
		}
		else
			n_printed += ft_putchar_fd(*form_str, 1);
		form_str++;
	}
	return (n_printed);
}
