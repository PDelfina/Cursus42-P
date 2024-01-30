/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:25 by dparada           #+#    #+#             */
/*   Updated: 2024/01/30 10:40:09 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*info;

	info = param;
	xdelta = 0;
	if (ydelta > 0)
		info->zoom *= 1.05;
	else if (ydelta < 0)
		info->zoom *= 0.95;
	printf_fractal(info);
}

void	msj_usage(void)
{
	ft_printf("|----------------------------------------------------------|\n");
	ft_printf("|Utilice el raton para hacer zoom.                         |\n");
	ft_printf("|Utilice ESC para salir del programa.                      |\n");
	ft_printf("|Utilice el + de la derecha para aumentar las iteraciones  |\n");
	ft_printf("|Utilice el - de la derecha para disminuir las iteraciones.|\n");
	ft_printf("|----------------------------------------------------------|\n");
}
