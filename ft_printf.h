/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:19:19 by surkim            #+#    #+#             */
/*   Updated: 2023/03/22 12:32:21 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int n, int *len);
int	ft_putchar(unsigned char c, int *len);
int	ft_putstr(unsigned char *s, int *len);
int	ft_putadd(void *a, int *len);
int	ft_strlen(const char *str);
int	is_in_list(char c);
int	take_format(char c, int *len, va_list *ap, int *flag);
int	ft_putunbr(unsigned int n, int *len);
int	ft_puthex(unsigned int n, int *len);
int	ft_putrhex(unsigned int n, int *len);
int	ft_printf(const char *str, ...);

#endif