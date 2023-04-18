/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:13:47 by sunko             #+#    #+#             */
/*   Updated: 2023/04/12 11:52:10 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		format_specifiers(const char *str, va_list *ap, int *rst);
int		print_character(va_list *ap, int *rst);
int		print_string(va_list *ap, int *rst);
int		print_decimal(va_list *ap, int *rst);
int		print_pointer(va_list *ap, int *rst);
int		print_hexa_low(va_list *ap, int *rst);
int		print_hexa_upper(va_list *ap, int *rst);
int		print_unsigned_decimal(va_list *ap, int *rst);
void	goto_memory(unsigned long long nb, int *rst);
int		goto_hexa_low(unsigned int nb, int *rst);
int		goto_hexa_upper(unsigned int nb, int *rst);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_error(int *rst, char *str);

#endif
