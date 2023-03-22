/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:27:17 by surkim            #+#    #+#             */
/*   Updated: 2023/03/21 17:11:11 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_rec(unsigned int n, int *len)
{
	char	sixteen[16];
	int		i;

	i = 0;
	while (i < 10)
	{
		sixteen[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		sixteen[i] = 'A' + i - 10;
		i++;
	}
	if (n > 0)
	{
		ft_puthex_rec(n / 16, len);
		if (*len < 0)
			return ;
		if (0 > write(1, &sixteen[n % 16], 1))
			*len = -1;
		else
			*len += 1;
	}
}

static int	get_len_hex(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putrhex(unsigned int n, int *len)
{
	int	tmp;

	tmp = *len;
	if (n == 0)
		*len += write(1, "0", 1);
	ft_puthex_rec(n, len);
	if (get_len_hex(n) + tmp == *len)
		return (*len);
	else
		return (-1);
}
