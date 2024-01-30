/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:25 by dparada           #+#    #+#             */
/*   Updated: 2024/01/29 16:53:19 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	ft_mousepos(void *param)
{
	int32_t		x;
	int32_t		y;
	t_fractol	*info;

	info = param;
	if (info->active == 1 && info->set == 2)
	{
		mlx_get_mouse_pos(info->mlx, &x, &y);
		info->c_r = ft_esc((double)x, info->min_real, info->max_real, \
		WIDTH);
		info->c_i = ft_esc((double)y, info->min_imag, info->max_imag, \
		HEIGHT);
	}
	printf_fractal(info);
}

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*info;
	int32_t		x;
	int32_t		y;

	info = param;
	xdelta = 0;
	mlx_get_mouse_pos(info->mlx, &x, &y);
	if (ydelta > 0)
	{
		info->min_real += (info->shift * WIDTH * info->zoom \
		* ((double)x / WIDTH));
		info->max_imag -= (info->shift * HEIGHT * info->zoom \
		* ((double)y / WIDTH));
		info->shift -= info->shift * info->zoom;
	}
	else if (ydelta < 0)
	{
		info->min_real -= (info->shift * WIDTH * info->zoom \
		* ((double)x / WIDTH));
		info->max_imag += (info->shift * HEIGHT * info->zoom \
		* ((double)y / WIDTH));
		info->shift += info->shift * info->zoom;
	}
	printf_fractal(info);
}

void	msj_usage(void)
{
	ft_printf("|----------------------------------------------------------|\n");
	ft_printf("|Utilice el raton para hacer zoom.                         |\n");
	ft_printf("|Utilice ESC para salir del programa.                      |\n");
	ft_printf("|Utilice el + de la derecha para aumentar las iteraciones  |\n");
	ft_printf("|Utilice el - de la derecha para disminuir las iteraciones.|\n");
	ft_printf("|Utilice X y Z para interactuar con Julia.                 |\n");
	ft_printf("|Utilice las flechas para moverse por el fractal.          |\n");
	ft_printf("|Utilice 1, 2, 3 para cambiar el color del fractal.        |\n");
	ft_printf("|----------------------------------------------------------|\n");
}
