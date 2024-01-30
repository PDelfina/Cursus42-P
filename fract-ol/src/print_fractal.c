/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:05:41 by dparada           #+#    #+#             */
/*   Updated: 2024/01/30 10:43:15 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_fractal(int argc, char **argv, t_fractol *info)
{
	if (argc > 1)
	{
		if ((ft_strcmp(argv[1], "Mandelbrot") || ft_strcmp(argv[1], "1")) \
		&& argc == 2)
			info->set = 1;
		else if ((ft_strcmp(argv[1], "Julia") || ft_strcmp(argv[1], "2")))
		{
			julia_args(info);
			info->set = 2;
		}
		else
		{
			msj_error();
			return (0);
		}
	}
	else
	{
		msj_error();
		return (0);
	}
	return (1);
}

void	julia_args(t_fractol *info)
{
	info->min_real = -1.5;
	info->max_real = 1.5;
	info->min_imag = -1.5;
	info->max_imag = 1.5;
	if (info->argv[2] && info->argv[3])
	{
		info->c_r = ft_fatoi(0, 0.0, 1.0, info->argv[2]);
		info->c_i = ft_fatoi(0, 0.0, 1.0, info->argv[3]);
	}
	else
	{
		info->c_r = 0.35;
		info->c_i = 0.35;
	}
}
