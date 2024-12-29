/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:59:41 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:54:43 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	n_printed;

	n_printed = 0;
	while (s[n_printed])
	{
		write(fd, &s[n_printed], 1);
		n_printed++;
	}
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
