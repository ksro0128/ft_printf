/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:26:02 by surkim            #+#    #+#             */
/*   Updated: 2023/03/21 16:09:11 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(unsigned char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
	{
		*(len) += 6;
		return (write(1, "(null)", 6));
	}
	while (s[i])
	{
		if (write(1, s + i, 1) < 0)
		{
			return (-1);
		}
		i++;
		(*len)++;
	}
	return (*len);
}
