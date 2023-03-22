/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:12:43 by surkim            #+#    #+#             */
/*   Updated: 2023/03/21 21:34:01 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	int		flag;
	va_list	ap;

	va_start(ap, str);
	i = -1;
	len = 0;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == '%' && flag == 0)
			flag = 1;
		else
		{
			if (take_format(str[i], &len, &ap, &flag) == -1)
			{
				va_end(ap);
				return (-1);
			}
			flag = 0;
		}
	}
	va_end(ap);
	return (len);
}
