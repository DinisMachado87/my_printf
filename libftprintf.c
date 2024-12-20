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
#include <stdarg.h>

int	count_args(const char *form_str)
{
	int	n_args;

	n_args = 0;
	while (*form_str)
	{
		if (*form_str == '%')
			n_args++;
		form_str++;
	}
	return (n_args);
}

int	ft_printf(const char *form_str, ...)
{
	int		printed;
	va_list	args;

	printed = 0;
	va_start(args, form_str);
	while (*form_str)
	{
		if ((*form_str == '%') && (*++form_str == 'c'))
			ft_putchar_fd(va_arg(args, int), 1);
		else
			ft_putchar_fd(*form_str, 1);
		form_str++;
	}
	return (printed);
}

int	main()
{
	ft_printf("is an atom %c \n", 'a');
	return (0);
}
