/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:44:14 by dparada           #+#    #+#             */
/*   Updated: 2024/01/29 17:01:42 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractal_init(t_fractol *info)
{
	info->mlx = mlx_init(WIDTH, HEIGHT, "42 fract-ol", false);
	if (!info->mlx)
		exit(EXIT_FAILURE);
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img)
		exit(EXIT_FAILURE);
	info->max_iter = 50;
	info->min_real = -2.0;
	info->max_real = 1.0;
	info->min_imag = -1.5;
	info->max_imag = 1.5;
	info->zoom = 1;
	info->active = -1;
}

int	main(int argc, char **argv)
{
	t_fractol	info;

	info.argv = argv;
	fractal_init(&info);
	if (check_fractal(argc, argv, &info) == 0)
		return (EXIT_FAILURE);
	printf_fractal(&info);
	if (mlx_image_to_window(info.mlx, info.img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	msj_usage();
	mlx_key_hook(info.mlx, &my_keyhook, &info);
	mlx_scroll_hook(info.mlx, &ft_scrollhook, &info);
	mlx_loop_hook(info.mlx, &ft_hook, &info);
	mlx_loop(info.mlx);
	mlx_terminate(info.mlx);
	return (EXIT_SUCCESS);
}
