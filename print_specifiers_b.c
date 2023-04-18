/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:51:34 by sunko             #+#    #+#             */
/*   Updated: 2023/04/12 11:40:48 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_decimal(va_list *ap, int *rst)
{
	unsigned int	nb;
	char			*str;
	int				i;

	i = -1;
	nb = va_arg(*ap, unsigned int);
	str = ft_unsigned_itoa(nb);
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
