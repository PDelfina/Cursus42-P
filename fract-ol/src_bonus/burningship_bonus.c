/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:05:41 by dparada           #+#    #+#             */
/*   Updated: 2024/01/29 16:31:06 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	burningship_iters(t_fractol *info)
{
	int		iters;
	double	temp;

	iters = 0;
	info->z_i = 0.0;
	info->z_r = 0.0;
	while (iters < info->max_iter && ft_mod(info->z_r, info->z_i) <= 4.0)
	{
		temp = (info->z_r * info->z_r - info->z_i * info->z_i) - info->c_r;
		info->z_i = fabs(2.0 * info->z_r * info->z_i) - info->c_i;
		info->z_r = temp;
		iters++;
	}
	return (iters);
}

void	burningship(t_fractol *info)
{
	info->x = 0;
	info->y = 0;
	while (info->y < HEIGHT)
	{
		while (info->x < WIDTH)
		{
			calcular_complex(info);
			if (info->set == 1)
				info->iters = burningship_iters(info);
			else
				info->iters = mandel_julia(info);
			printimg(info);
			info->x++;
		}
		info->x = 0;
		info->y++;
	}
}
