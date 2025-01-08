/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:49:58 by dimachad          #+#    #+#             */
/*   Updated: 2025/01/08 20:51:14 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	char	*test_str = "char %c char %%";
	ft_printf(", printed char: %d\n", ft_printf(test_str, 'a'));
	printf(", printed char: %d\n", printf(test_str, 'a'));
	printf("\n");

	char	*test_str1 = "str %s";
	ft_printf(", printed char: %d\n", ft_printf(test_str1, "Hello"));
	printf(", printed char: %d\n", printf(test_str1, "Hello"));
	ft_printf(", printed char: %d\n", ft_printf("NULL %s NULL", NULL));
	printf(", printed char: %d\n", printf("NULL %s NULL", (char*)NULL));
	printf("\n");

	char	*test_str2 = "decimal - %+d %-d %d";
	ft_printf(", printed char: %d\n", ft_printf(test_str2, 1059, -1059, -1059, INT_MIN));
	printf(", printed char: %d\n", printf(test_str2, 1059, -1059, -1059, INT_MIN));
	printf("\n");

	char	*test_str3 = "int - %+i %-i %i %i";
	ft_printf(", printed char: %d\n", ft_printf(test_str3, 1059, 1059, -1059, 0));
	printf(", printed char: %d\n", printf(test_str3, 1059, 1059, -1059, 0));
	printf("\n");

	char	*test_str4 = "un int - %+u %-u %u %u %u %u";
	ft_printf(", printed char: %d\n", ft_printf(test_str4, 1059, -1059, -1059, 1059, -1059, -1059));
	printf(", printed char: %d\n", printf(test_str4, 1059, -1059, -1059, 1059, -1059, -1059));
	printf("\n");
	
	char	*test_str5 = "HEX cap - %X %X %X";
	ft_printf(", printed char: %d\n", ft_printf(test_str5, 1059, -1059, +1059));
	printf(", printed char: %d\n", printf(test_str5, 1059, -1059, +1059));
	printf("\n");
	
	char	*test_str6 = "HEX small - %x %x %x";
	ft_printf(", printed char: %d\n", ft_printf(test_str6, 1059, -1059, +1059));
	printf(", printed char: %d\n", printf(test_str6, 1059, -1059, +1059));
	printf("\n");

	char	*test_str7 = "PTR  - %p %p %p %p";
	ft_printf(", printed char: %d\n", ft_printf(test_str7, test_str7, test_str7, test_str7, 0));
	printf(", printed char: %d\n", printf(test_str7, test_str7, test_str7, test_str7, 0));
	printf("\n");

	return (0);
}
