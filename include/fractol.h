/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:22:01 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/09/27 16:38:51 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <float.h>

# include <stdio.h>
# include <unistd.h>
# include <errno.h>

# include "mlx.h"

# define HEIGHT 800
# define WIDTH 800
# define TITLE "Fractol"

# define MAX_CALCULATE 120
# define DIVERGE_STANDARD 2

# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2

# define KEY_ESCAPE 53
# define MOUSE_DOWN 4
# define MOUSE_UP 5

typedef struct s_minilibx{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx;
	void	*mlx_win;

	int		fractol_case;

	double	j_re;
	double	j_im;

	double	ratio;
}				t_data;

typedef struct s_complex_number{
	double	re;
	double	im;
}				t_cn;

double	ft_atof(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

void	mandelbrot(t_data data);
void	julia(t_data data);
void	burning_ship(t_data data);
void	do_fractol(t_data data);

void	hook_and_loop(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(int diverge_count);
int		get_when_diverge_mj(t_cn cn, t_cn z);
int		get_when_diverge_b(t_cn cn, t_cn z);

#endif
