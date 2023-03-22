/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:34:20 by surkim            #+#    #+#             */
/*   Updated: 2023/03/21 17:07:40 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nbr(int n, int *len)
{
	char	c;

	if (n == 0)
		return ;
	else
	{
		print_nbr(n / 10, len);
		if (*len < 0)
			return ;
		c = n % 10 + '0';
		if (0 > write(1, &c, 1))
		{
			*len = -1;
		}
		else
			*len += 1;
	}
}

void	ft_putnbr2(int n, int *len)
{
	if (n == 0)
		*len += write(1, "0", 1);
	else if (n == -2147483648)
		*len += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		*len += write(1, "-", 1);
		print_nbr(-n, len);
	}
	else
		print_nbr(n, len);
}

static int	get_len_nbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	else if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr(int n, int *len)
{
	int	tmp;

	tmp = *len;
	ft_putnbr2(n, len);
	if (tmp + get_len_nbr(n) == *len)
		return (*len);
	else
		return (-1);
}
