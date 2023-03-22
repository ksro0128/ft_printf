/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:34:57 by surkim            #+#    #+#             */
/*   Updated: 2023/03/21 17:09:35 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putunbr_rec(unsigned int n, int *len)
{
	char	c;

	if (n == 0)
		return ;
	else
	{
		ft_putunbr_rec(n / 10, len);
		if (*len < 0)
			return ;
		c = n % 10 + '0';
		if (0 > write(1, &c, 1))
		{
			*len = -1;
			return ;
		}
		*len += 1;
	}
}

int	ft_putunbr(unsigned int n, int *len)
{
	int	tmp;

	tmp = *len;
	if (n == 0)
	{
		*len += 1;
		return (write(1, "0", 1));
	}
	ft_putunbr_rec(n, len);
	if (tmp + get_len(n) == *len)
		return (*len);
	else
		return (-1);
}
