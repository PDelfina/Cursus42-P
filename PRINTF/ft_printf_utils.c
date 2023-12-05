/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:14:37 by dparada           #+#    #+#             */
/*   Updated: 2023/12/04 15:12:55 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strdiv(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb < 16 && nb >= 0)
		i = 1;
	else
	{
		while (nb != 0)
		{
			nb /= 16;
			i++;
		}
	}
	return (i);
}
