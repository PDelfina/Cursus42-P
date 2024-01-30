/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colores_iters_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:25 by dparada           #+#    #+#             */
/*   Updated: 2024/01/29 16:29:54 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	printimg(t_fractol *info)
{
	t_color	color;
	t_color	vio;
	t_color	red;

	if (info->iters == info->max_iter)
	{
		mlx_put_pixel(info->img1, info->x, info->y, 0x2f2f2fFF);
		mlx_put_pixel(info->img2, info->x, info->y, 0x2f2f2fFF);
		mlx_put_pixel(info->img3, info->x, info->y, 0x2f2f2fFF);
	}
	else
	{
		colores_blu(&color);
		info->color = coloresuno(&color, info->iters);
		mlx_put_pixel(info->img1, info->x, info->y, info->color);
		colores_red(&red);
		info->color = coloresuno(&red, info->iters);
		mlx_put_pixel(info->img2, info->x, info->y, info->color);
		colores_vio(&vio);
		info->color = coloresuno(&vio, info->iters);
		mlx_put_pixel(info->img3, info->x, info->y, info->color);
	}
}
