/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:51:39 by dimachad          #+#    #+#             */
/*   Updated: 2025/01/06 20:56:32 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

size_t	ft_strlen(const char *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd, char details);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putbase(uintptr_t n, int fd, char form_str);
int		ft_putptr(uintptr_t n, int fd, char form_str);
int		ft_printf(const char *form_str, ...);

#endif
