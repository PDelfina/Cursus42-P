/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:32:05 by dparada           #+#    #+#             */
/*   Updated: 2023/12/04 14:28:07 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_punt(void *nb)
{
	int		i;
	char	word;

	i = 0;
	word = 'x';
	if (!nb)
	{
		ft_putstr("0x0");
		return (3);
	}
	else
	{
		write(1, "0x", 2);
		i = ft_hexa(((unsigned long)nb), word) + 2;
	}
	return (i);
}
