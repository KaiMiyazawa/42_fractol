/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:37:41 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/09/27 16:24:23 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int diverge_count)
{
	if (diverge_count == MAX_CALCULATE)
		return (0x000000);
	return (diverge_count * diverge_count * diverge_count * 10);
}

int	get_when_diverge_mj(t_cn cn, t_cn z)
{
	int		count;
	double	z_re_tmp;

	count = 0;
	while (count < MAX_CALCULATE)
	{
		z_re_tmp = z.re;
		z.re = cn.re + (z.re * z.re - z.im * z.im);
		z.im = cn.im + (2 * z_re_tmp * z.im);
		if (sqrt(z.re * z.re + z.im * z.im) > DIVERGE_STANDARD)
			return (count);
		count++;
	}
	return (count);
}

static double	abs_d(double num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

int	get_when_diverge_b(t_cn cn, t_cn z)
{
	int		count;
	double	z_re_tmp;

	count = 0;
	while (count < MAX_CALCULATE)
	{
		z_re_tmp = abs_d(z.re);
		z.re = cn.re + (z.re * z.re - z.im * z.im);
		z.im = cn.im + (2 * z_re_tmp * abs_d(z.im));
		if (sqrt(z.re * z.re + z.im * z.im) > DIVERGE_STANDARD)
			return (count);
		count++;
	}
	return (count);
}
