/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbritoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:21:05 by dparada           #+#    #+#             */
/*   Updated: 2023/11/30 11:06:04 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char	*ft_convert(long n, char *ptr, size_t i)
{
	ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		ptr[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	long	nl;

	nl = (long)n;
	i = ft_digit(nl);
	j = i;
	ptr = malloc ((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	ptr = ft_convert(nl, ptr, i);
	return (ptr);
}
