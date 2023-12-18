/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:38:22 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/09/27 16:38:38 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static int	key_hook(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	return (key);
}

static int	finish(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

static int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (x && y)
		;
	if (button == MOUSE_DOWN)
		data->ratio *= 0.9;
	if (button == MOUSE_UP)
		data->ratio *= 1.1;
	if (data->fractol_case == MANDELBROT)
		mandelbrot(*data);
	else if (data->fractol_case == JULIA)
		julia(*data);
	else if (data->fractol_case == BURNING_SHIP)
		burning_ship(*data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (button);
}

void	hook_and_loop(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, finish, data);
	mlx_hook(data->mlx_win, 4, 0, mouse_hook, data);
	mlx_loop(data->mlx);
}
