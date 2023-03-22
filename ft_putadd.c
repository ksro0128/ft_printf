/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:26:50 by surkim            #+#    #+#             */
/*   Updated: 2023/03/21 17:03:55 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rec_print_add(unsigned long add, int *len)
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
		sixteen[i] = 'a' + i - 10;
		i++;
	}
	if (add > 0)
	{
		rec_print_add(add / 16, len);
		if (*len < 0)
			return ;
		if (0 > write(1, &sixteen[add % 16], 1))
			*len = -1;
		else
			*len += 1;
	}
}

static int	get_len_add(unsigned long a)
{
	int	i;

	if (a == 0)
		return (1);
	i = 0;
	while (a != 0)
	{
		a /= 16;
		i++;
	}
	return (i);
}

int	ft_putadd(void *a, int *len)
{
	unsigned long	add;
	int				tmp;

	add = (unsigned long) a;
	tmp = *len + 2;
	if (0 > write(1, "0x", 2))
	{
		return (-1);
	}
	*len += 2;
	if (add == 0)
	{
		if (0 > write(1, "0", 1))
			return (-1);
		*len += 1;
	}
	rec_print_add(add, len);
	if (get_len_add(add) + tmp == *len)
		return (*len);
	else
		return (-1);
}
