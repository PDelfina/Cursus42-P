/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colores_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:25 by dparada           #+#    #+#             */
/*   Updated: 2024/01/29 16:29:51 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	colores_red(t_color *rango)
{
	rango->r = 255;
	rango->g = 0;
	rango->b = 0;
	rango->iters_r = 0;
	rango->iters_g = 10;
	rango->iters_b = 10;
}

void	colores_vio(t_color *rango)
{
	rango->r = 124;
	rango->g = 0;
	rango->b = 255;
	rango->iters_r = 5;
	rango->iters_g = 5;
	rango->iters_b = 0;
}

void	colores_blu(t_color *rango)
{
	rango->r = 0;
	rango->g = 0;
	rango->b = 255;
	rango->iters_r = 10;
	rango->iters_g = 10;
	rango->iters_b = 0;
}

int32_t	coloresuno(t_color *rango, int iters)
{
	int	i;

	i = 0;
	while (i <= iters && \
	(rango->r <= 255 && rango->g <= 255 && rango->b <= 255))
	{
		rango->r += rango->iters_r;
		rango->g += rango->iters_g;
		rango->b += rango->iters_b;
		i += 2;
	}
	return (get_color(rango->r, rango->g, rango->b, 255));
}
