/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:23:12 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:24:12 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_and_struct.h"

int	get_color_blue(int i, t_fractol *fractol)
{
	if (i < fractol->iter_max * 0.02)
		return (0x07365A);
	else if (i < fractol->iter_max * 0.03)
		return (0x083A61);
	else if (i < fractol->iter_max * 0.05)
		return (0x09416C);
	else if (i < fractol->iter_max * 0.08)
		return (0x094573);
	else if (i < fractol->iter_max * 0.12)
		return (0x0A4A7B);
	else if (i < fractol->iter_max * 0.17)
		return (0x0A4F83);
	else if (i < fractol->iter_max * 0.25)
		return (0x0C5892);
	else if (i < fractol->iter_max * 0.30)
		return (0x0E66A9);
	else if (i < fractol->iter_max * 0.45)
		return (0x0E6AB1);
	else if (i < fractol->iter_max * 0.57)
		return (0x0F6FB8);
	else if (i < fractol->iter_max * 0.72)
		return (0x0F73C0);
	else if (i < fractol->iter_max * 0.87)
		return (0x1078C8);
	else if (i < fractol->iter_max)
		return (0x1183DA);
	else
		return (0x149AFF);
}
/*
int	get_color_blue(int i, t_fractol *fractol)
{
	if (i < fractol->iter_max * 0.02)
		return (0x075059);
	else if (i < fractol->iter_max * 0.03)
		return (0x083A61);
	else if (i < fractol->iter_max * 0.05)
		return (0x09416C);
	else if (i < fractol->iter_max * 0.08)
		return (0x094573);
	else if (i < fractol->iter_max * 0.12)
		return (0x0A4A7B);
	else if (i < fractol->iter_max * 0.17)
		return (0x0A4F83);
	else if (i < fractol->iter_max * 0.25)
		return (0x0C5892);
	else if (i < fractol->iter_max * 0.30)
		return (0x0E66A9);
	else if (i < fractol->iter_max * 0.45)
		return (0x0E6AB1);
	else if (i < fractol->iter_max * 0.57)
		return (0x0F6FB8);
	else if (i < fractol->iter_max * 0.72)
		return (0x0F73C0);
	else if (i < fractol->iter_max * 0.87)
		return (0x1078C8);
	else if (i < fractol->iter_max)
		return (0x1183DA);
	else
		return (0x149AFF);
}*/
