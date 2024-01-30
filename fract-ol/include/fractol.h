/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:25:48 by dparada           #+#    #+#             */
/*   Updated: 2023/12/28 10:57:26 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 750
# define HEIGHT 750

# include "../lib/LIBFT/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			iters_r;
	int			iters_g;
	int			iters_b;
}				t_color;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			iters;
	int			set;
	double		x;
	double		y;
	int			p;
	int			max_iter;
	double		zoom;
	double		shift;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		j_real;
	double		j_imag;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	int			colores;
	int			active;
	char		**argv;
	int32_t		color;
}				t_fractol;

int		check_fractal(int argc, char **argv, t_fractol *info);
void	printf_fractal(t_fractol *info);

void	calcular_complex(t_fractol *info);
double	ft_esc(double coor, double new_min, double new_max, double old_max);

int		mandel_julia(t_fractol *info);
void	julia_args(t_fractol *info);

int32_t	coloresuno(t_color *rango, int iters);
void	printimg(t_fractol *info);
void	colores_red(t_color *rango);
void	colores_vio(t_color *rango);
void	colores_blu(t_color *rango);
int		get_color(int r, int g, int b, int a);
int		ft_strcmp(char *s1, char *s2);
double	ft_fatoi(int i, double n, double t, char *str);
int		ft_mod(double z_real, double z_imag);
void	msj_error(void);
void	ft_hook(void *param);
void	my_keyhook(mlx_key_data_t esc, void *param);
void	ft_scrollhook(double xdelta, double ydelta, void *param);
void	msj_usage(void);
void	ft_mousepos(void *param);

#endif