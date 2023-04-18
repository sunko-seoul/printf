/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:35:13 by sunko             #+#    #+#             */
/*   Updated: 2023/04/18 11:02:25 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			rst;

	va_start(ap, str);
	i = -1;
	rst = 0;
	while (str[++i] != '\0')
	{
		if (str[i] != '%')
		{
			if (write(1, &str[i], 1) == -1)
				return (-1);
			rst++;
		}
		else if (str[i] == '%')
		{
			if (format_specifiers(&str[i], &ap, &rst) == -1)
				return (-1);
			if (str[i + 1] != '\0')
				i++;
		}
	}
	va_end(ap);
	return (rst);
}

int	format_specifiers(const char *str, va_list *ap, int *rst)
{
	int		error_num;

	error_num = 0;
	if (str[1] == 'c')
		error_num = print_character(ap, rst);
	else if (str[1] == 's')
		error_num = print_string(ap, rst);
	else if (str[1] == 'd' || str[1] == 'i')
		error_num = print_decimal(ap, rst);
	else if (str[1] == 'p')
		error_num = print_pointer(ap, rst);
	else if (str[1] == 'u')
		error_num = print_unsigned_decimal(ap, rst);
	else if (str[1] == 'x')
		error_num = print_hexa_low(ap, rst);
	else if (str[1] == 'X')
		error_num = print_hexa_upper(ap, rst);
	else if (str[1] == '%')
	{
		if (write(1, "%", 1) == -1)
			return (ft_error(rst, NULL));
		*rst += 1;
	}
	return (error_num);
}

int	ft_error(int *rst, char *str)
{
	*rst = -1;
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (-1);
}
