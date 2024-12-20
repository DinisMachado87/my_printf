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

static int	print_formated(const char form_c, va_list args)
{
	int n_printed;

	n_printed = 0;
	if (form_c == 'c')
		n_printed = ft_putchar_fd(va_arg(args, int), 1);
	return (n_printed);
}

int	ft_printf(const char *form_str, ...)
{
	int		n_printed;
	va_list	args;

	n_printed = 0;
	va_start(args, form_str);
	while (*form_str)
	{
		if (*form_str == '%')
			n_printed = print_formated(*++form_str, args);
		else
			ft_putchar_fd(*form_str, 1);
		form_str++;
	}
	return (n_printed);
}

int	main()
{
	ft_printf("is an atom %c \n", 'a');
	return (0);
}
