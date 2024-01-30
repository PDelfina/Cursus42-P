/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:25 by dparada           #+#    #+#             */
/*   Updated: 2024/01/30 10:22:30 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_hook(void *param)
{
	t_fractol	*info;

	info = param;
}

void	my_keyhook(mlx_key_data_t keys, void *param)
{
	t_fractol	*info;

	info = param;
	(void)keys;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	else if (mlx_is_key_down(info->mlx, MLX_KEY_KP_ADD))
		info->max_iter += 20;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_KP_SUBTRACT))
		info->max_iter -= 20;
	printf_fractal(info);
}
