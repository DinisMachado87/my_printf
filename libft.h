/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:51:39 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 18:53:35 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd, char details);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_putbase(uintptr_t n, char *base, int fd);
int ft_putptr(uintptr_t n, char *base, int fd);
int	ft_printf(const char *form_str, ...);

#endif
