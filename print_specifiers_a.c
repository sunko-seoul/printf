/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:35:03 by sunko             #+#    #+#             */
/*   Updated: 2023/04/12 11:59:29 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(va_list *ap, int *rst)
{
	char	value;

	value = va_arg(*ap, int);
	if (write(1, &value, 1) == -1)
		return (ft_error(rst, NULL));
	*rst += 1;
	return (*rst);
}

int	print_string(va_list *ap, int *rst)
{
	char	*value;
	int		i;

	i = -1;
	value = va_arg(*ap, char *);
	if (!value)
	{
		if (write(1, "(null)", 6) == -1)
			return (ft_error(rst, NULL));
		*rst += 6;
		return (*rst);
	}
	while (value[++i] != '\0')
	{
		if (write(1, &value[i], 1) == -1)
			return (ft_error(rst, NULL));
		*rst += 1;
	}
	return (*rst);
}

int	print_decimal(va_list *ap, int *rst)
{
	int		value;
	char	*str;
	int		i;

	i = -1;
	value = va_arg(*ap, int);
	str = ft_itoa(value);
	if (!str)
		return (ft_error(rst, NULL));
	while (str[++i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			return (ft_error(rst, str));
		*rst += 1;
	}
	free(str);
	str = NULL;
	return (*rst);
}

int	print_pointer(va_list *ap, int *rst)
{
	unsigned long long	addr;

	if (write(1, "0x", 2) == -1)
		return (ft_error(rst, NULL));
	else
		*rst += 2;
	addr = (unsigned long long)va_arg(*ap, void *);
	goto_memory(addr, rst);
	return (*rst);
}

void	goto_memory(unsigned long long nb, int *rst)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		goto_memory(nb / 16, rst);
		goto_memory(nb % 16, rst);
	}
	else
	{
		if (write(1, &base[nb], 1) == -1)
		{
			*rst = -1;
			return ;
		}
		*rst += 1;
	}
}
