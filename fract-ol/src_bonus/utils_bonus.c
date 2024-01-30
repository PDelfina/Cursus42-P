/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:25 by dparada           #+#    #+#             */
/*   Updated: 2024/01/29 16:30:13 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	msj_error(void)
{
	ft_printf("|-----------------------------------------|\n");
	ft_printf("|Si quiere ejecutar Mandelbrot, escriba:  |\n");
	ft_printf("|./fractol Mandelbrot o ./fractol 1       |\n");
	ft_printf("|-----------------------------------------|\n");
	ft_printf("|Si quiere ejecutar Julia, escriba:       |\n");
	ft_printf("|./fractol Julia x y  o ./fractol 2 x y   |\n");
	ft_printf("|-----------------------------------------|\n");
	ft_printf("|Si quiere ejecutar Burningship, escriba: |\n");
	ft_printf("|./fractol Burningship o ./fractol 3      |\n");
	ft_printf("|-----------------------------------------|\n");
}

double	ft_fatoi(int i, double n, double t, char *str)
{
	int	decimal;

	decimal = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			t = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == '.')
			decimal = 1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (decimal == 1)
				t /= 10.00;
			n = (n * 10.00) + (str[i] - '0');
		}
		i++;
	}
	return (t * n);
}

int	ft_mod(double z_real, double z_imag)
{
	return ((z_real * z_real) + (z_imag * z_imag));
}

int	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
