/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:34:19 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/09/27 16:53:47 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static void	print_intro(void)
{
	ft_putstr_fd("chose fractal type as an argment.\
		\nselectable fractal type:\
		\n[mandelbrot] [julia] [burning-ship]\n", 1);
	exit(EXIT_FAILURE);
}

static void	print_julia_intro(void)
{
	ft_putstr_fd("argment invalid.\
	\nyou can pass two double int numbers as argments\
	\nexample:\
	\n./fractol julia -0.8 0.125\n", 1);
	exit(EXIT_FAILURE);
}

static bool	is_num(char *av)
{
	int	count;

	count = 0;
	if (av[count] != '\0' && (av[count] == '-' || av[count] == '+'))
		count++;
	if (av[count] != '\0' && av[count] == '.')
		count++;
	if (av[count] != '\0' && av[count] >= '0' && av[count] <= '9')
		return (1);
	return (0);
}

void	data_init(t_data *data, int argc, char *argv[])
{
	data->ratio = 1;
	if (argc >= 2 && !ft_strncmp("julia", argv[1], 6))
	{
		data->fractol_case = JULIA;
		if (argc == 2)
		{
			data->j_re = -0.8;
			data->j_im = 0.125;
		}
		else if (argc == 4 && is_num(argv[2]) && is_num(argv[3]))
		{
			data->j_re = ft_atof(argv[2]);
			data->j_im = ft_atof(argv[3]);
		}
		else
			print_julia_intro();
	}
	else if (argc == 2 && !ft_strncmp("mandelbrot", argv[1], 16))
		data->fractol_case = MANDELBROT;
	else if (argc == 2 && !ft_strncmp("burning-ship", argv[1], 13))
		data->fractol_case = BURNING_SHIP;
	else
		print_intro();
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data_init(&data, argc, argv);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, TITLE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	do_fractol(data);
	hook_and_loop(&data);
	free(data.mlx);
	data.mlx = NULL;
}
