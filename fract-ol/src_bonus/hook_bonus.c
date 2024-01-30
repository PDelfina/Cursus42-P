/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:25 by dparada           #+#    #+#             */
/*   Updated: 2024/01/29 17:02:05 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

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
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		info->min_real += info->shift * info->zoom * WIDTH / 2;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		info->min_real -= info->shift * info->zoom * WIDTH / 2;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_UP))
		info->max_imag -= info->shift * info->zoom * WIDTH / 2;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_DOWN))
		info->max_imag += info->shift * info->zoom * WIDTH / 2;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_KP_ADD))
		info->max_iter += 20;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_KP_SUBTRACT))
		info->max_iter -= 20;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_X))
		info->active = 1;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_Z))
		info->active = -1;
	else
		ft_keyboard(keys, info);
	ft_mousepos(info);
	printf_fractal(info);
}

void	ft_keyboard(mlx_key_data_t keys, t_fractol *info)
{
	(void)keys;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	else if (mlx_is_key_down(info->mlx, MLX_KEY_1))
	{
		if (mlx_image_to_window(info->mlx, info->img1, 0, 0) < 0)
			exit(EXIT_FAILURE);
	}
	else if (mlx_is_key_down(info->mlx, MLX_KEY_2))
	{
		if (mlx_image_to_window(info->mlx, info->img2, 0, 0) < 0)
			exit(EXIT_FAILURE);
	}
	else if (mlx_is_key_down(info->mlx, MLX_KEY_3))
	{
		if (mlx_image_to_window(info->mlx, info->img3, 0, 0) < 0)
			exit(EXIT_FAILURE);
	}
}

void	ft_move_key(t_fractol *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		info->min_real += info->shift * info->zoom * WIDTH / 2;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		info->min_real -= info->shift * info->zoom * WIDTH / 2;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_UP))
		info->max_imag -= info->shift * info->zoom * WIDTH / 2;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_DOWN))
		info->max_imag += info->shift * info->zoom * WIDTH / 2;
}
