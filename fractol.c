/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:36 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/09/27 16:36:05 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

///mlx_get_data_addrの返り血はint の配列の箱　で　座標と対応してる
///data.addr = (color)の形で直書きもできる

//data.addr[y * WIDTH * 4 + x * 4] = get_color(get_when_diverge_mj(cn, z0));
void	mandelbrot(t_data data)
{
	int		x;
	int		y;
	t_cn	cn;
	t_cn	z0;

	y = -1;
	z0.re = 0;
	z0.im = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cn.re = x - WIDTH / 2;
			cn.re = cn.re / (WIDTH / 4) * data.ratio;
			cn.im = y - HEIGHT / 2;
			cn.im = cn.im / (HEIGHT / 4) * data.ratio;
			my_mlx_pixel_put(&data, x, y, get_color
				(get_when_diverge_mj(cn, z0)));
		}
	}
}

void	julia(t_data data)
{
	int		x;
	int		y;
	t_cn	cn;
	t_cn	z0;

	y = -1;
	cn.re = data.j_re;
	cn.im = data.j_im;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z0.re = x - WIDTH / 2;
			z0.re = z0.re / (WIDTH / 4) * data.ratio;
			z0.im = y - HEIGHT / 2;
			z0.im = z0.im / (HEIGHT / 4) * data.ratio;
			my_mlx_pixel_put(&data, x, y, get_color
				(get_when_diverge_mj(cn, z0)));
		}
	}
}

void	burning_ship(t_data data)
{
	int		x;
	int		y;
	t_cn	cn;
	t_cn	z0;

	y = -1;
	z0.re = 0;
	z0.im = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cn.re = x - WIDTH / 2;
			cn.re = cn.re / (WIDTH / 4) * data.ratio;
			cn.im = y - HEIGHT / 2;
			cn.im = cn.im / (HEIGHT / 4) * data.ratio;
			my_mlx_pixel_put(&data, x, y, get_color
				(get_when_diverge_b(cn, z0)));
		}
	}
}

void	do_fractol(t_data data)
{
	if (data.fractol_case == MANDELBROT)
		mandelbrot(data);
	else if (data.fractol_case == JULIA)
		julia(data);
	else if (data.fractol_case == BURNING_SHIP)
		burning_ship(data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
}
