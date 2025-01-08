/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:59:41 by dimachad          #+#    #+#             */
/*   Updated: 2025/01/08 14:20:04 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	n_printed;

	n_printed = 0;
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	while (s[n_printed])
		n_printed += write(fd, &s[n_printed], 1);
	return (n_printed);
}

/*
#include <stdio.h>

int	main()
{
	ft_putstr_fd("Hello!", 1);
	puts("Hello!");
	return (0);
}
*/
