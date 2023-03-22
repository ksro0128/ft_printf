/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:30:34 by surkim            #+#    #+#             */
/*   Updated: 2023/03/21 21:27:16 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_in_list(char c)
{
	if (c == 'c')
		return ('c');
	else if (c == 's')
		return ('s');
	else if (c == 'p')
		return ('p');
	else if (c == 'd' || c == 'i')
		return ('d');
	else if (c == 'u')
		return ('u');
	else if (c == 'x')
		return ('x');
	else if (c == 'X')
		return ('X');
	else if (c == '%')
		return ('%');
	else
		return (0);
}

int	ft_putpercent(int *len)
{
	*len += 1;
	return (write(1, "%", 1));
}

int	take_format(char c, int *len, va_list *ap, int *flag)
{
	if (c == 'c' && *flag == 1)
		return (ft_putchar(va_arg(*ap, int), len));
	else if (c == 's' && *flag == 1)
		return (ft_putstr(va_arg(*ap, unsigned char *), len));
	else if (c == 'p' && *flag == 1)
		return (ft_putadd(va_arg(*ap, void *), len));
	else if ((c == 'd' || c == 'i') && *flag == 1)
		return (ft_putnbr(va_arg(*ap, int), len));
	else if (c == 'u' && *flag == 1)
		return (ft_putunbr(va_arg(*ap, unsigned int), len));
	else if (c == 'x' && *flag == 1)
		return (ft_puthex(va_arg(*ap, unsigned int), len));
	else if (c == 'X' && *flag == 1)
		return (ft_putrhex(va_arg(*ap, unsigned int), len));
	else if (c == '%' && *flag == 1)
		return (ft_putpercent(len));
	else
	{
		*flag = 0;
		*len += 1;
		return (write(1, &c, 1));
	}
}
