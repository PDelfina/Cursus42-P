/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:01:36 by dparada           #+#    #+#             */
/*   Updated: 2023/12/04 14:51:49 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
int		ft_check(char const *str, va_list parametros, int total);
int		ft_check_hexa(char const *str, va_list parametros);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_strlen(char const *s);
int		ft_hexa(unsigned long nb, char word);
int		ft_digit(long n);
int		ft_digit_u(long n);
int		ft_punt(void *nb);
int		ft_strdiv(unsigned long nb);
char	*ft_convert_u(long n, char *ptr, size_t i);
char	*ft_convert(long n, char *ptr, size_t i);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
char	*ft_new(char *ptr);
char	*ft_convert_he(unsigned long nb, char *base);
#endif
