/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:51:13 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/09/27 16:24:25 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static int	del_sign(int count, const char *str)
{
	if (str[count] == '-' || str[count] == '+')
		return (0);
	return (-1);
}

static bool	minus_judge(char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

double	ft_atof(const char *str)
{
	long double	num;
	int			count;
	int			u_p_count;

	num = 0;
	u_p_count = 0;
	count = del_sign(0, str);
	while ((str[++count] >= '0' && str[count] <= '9') || str[count] == '.')
	{
		if (str[count] == '.')
		{
			if (!u_p_count++)
				continue ;
			else
				break ;
		}
		if (u_p_count)
			num += (str[count] - '0') * pow(10, -(u_p_count++));
		else
			num = num * 10 + str[count] - '0';
	}
	if (minus_judge((char *)str))
		num *= -1;
	return (num);
}
