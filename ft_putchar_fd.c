/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:42:18 by dimachad          #+#    #+#             */
/*   Updated: 2025/01/06 20:22:04 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Prints a char and returns the print count.
int	ft_putchar_fd(char c, int fd)
{
	int	n_printed;

	n_printed = 1;
	write(fd, &c, 1);
	return (n_printed);
}
