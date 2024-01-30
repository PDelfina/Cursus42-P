/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:44:14 by dparada           #+#    #+#             */
/*   Updated: 2024/01/29 17:02:15 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	fractal_init(t_fractol *info)
{
	info->mlx = mlx_init(WIDTH, HEIGHT, "42 fract-ol", false);
	if (!info->mlx)
		exit(EXIT_FAILURE);
	info->img1 = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img1)
		exit(EXIT_FAILURE);
	info->img2 = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img2)
		exit(EXIT_FAILURE);
	info->img3 = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img3)
		exit(EXIT_FAILURE);
	info->max_iter = 50;
	info->min_real = -2.0;
	info->max_real = 1.0;
	info->min_imag = -1.5;
	info->max_imag = 1.5;
	info->zoom = 0.0078125 * 4;
	info->shift = (info->max_imag * 2) / WIDTH;
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
	if (mlx_image_to_window(info.mlx, info.img1, 0, 0) < 0)
		exit(EXIT_FAILURE);
	msj_usage();
	mlx_key_hook(info.mlx, &my_keyhook, &info);
	mlx_scroll_hook(info.mlx, &ft_scrollhook, &info);
	mlx_loop_hook(info.mlx, &ft_mousepos, &info);
	mlx_loop_hook(info.mlx, &ft_hook, &info);
	mlx_loop(info.mlx);
	mlx_terminate(info.mlx);
	return (EXIT_SUCCESS);
}
