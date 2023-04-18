/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:02:39 by sunko             #+#    #+#             */
/*   Updated: 2023/04/12 12:02:20 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_low(va_list *ap, int *rst)
{
	unsigned int	dec;

	dec = va_arg(*ap, unsigned int);
	return (goto_hexa_low(dec, rst));
}

int	goto_hexa_low(unsigned int nb, int *rst)
{
	char	*base;

	if (*rst == -1)
		return (-1);
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		goto_hexa_low(nb / 16, rst);
		goto_hexa_low(nb % 16, rst);
	}
	else
	{
		if (write(1, &base[nb], 1) == -1)
			return (ft_error(rst, NULL));
		*rst += 1;
	}
	return (*rst);
}

int	print_hexa_upper(va_list *ap, int *rst)
{
	unsigned int	dec;

	dec = va_arg(*ap, unsigned int);
	return (goto_hexa_upper(dec, rst));
}

int	goto_hexa_upper(unsigned int nb, int *rst)
{
	char	*base;

	if (*rst == -1)
		return (-1);
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		goto_hexa_upper(nb / 16, rst);
		goto_hexa_upper(nb % 16, rst);
	}
	else
	{
		if (write(1, &base[nb], 1) == -1)
			return (ft_error(rst, NULL));
		*rst += 1;
	}
	return (*rst);
}
