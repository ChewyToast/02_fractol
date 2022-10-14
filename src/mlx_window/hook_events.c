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
#include "fractol.h"

static void	cli_ask(int key, t_fractol *fractol);
static void	move_center(int key, t_fractol *fractol);

void	key_compare(int key, t_fractol *fractol)
{
	if (key == 53)
		end_fractol();
	if (key == 126 || (key == 125) || (key == 124) || (key == 123))
		move_center(key, fractol);
	if (key == 15)
		cli_ask(key, fractol);
	ft_printf("\n<%d>\n", key);
}

static void	cli_ask(int key, t_fractol *fractol)
{
	if (key == 15)
	{
		ft_printf("\nEnter the desired resolution to see the fractal (default: 150): ");
		fractol->iter_max = ft_atoi(get_next_line(0));
		ft_printf("\nResolution set to: %d", fractol->iter_max);
	}/*
	if (key == 8)
	{
		fractol->color_index++;
		if (fractol->color_index == 2)
			fractol->color_index = 0;
		else if (fractol->color_index == 1)
			fractol->get_color = get_color_green;
		else if (fractol->color_index == 0)
			fractol->get_color = get_color_blue;
	}*/
}

static void	move_center(int key, t_fractol *fractol)
{
	double	modi;
	int	i;

	i = 0;
	modi = 0.05;
	while ((fractol->setvalue.zoom - i) > 100)
	{
		i += 100;
		modi /= 0.55;
	}
	if (key == 126)
		fractol->setvalue.ycenter -= modi;
	if (key == 125)
		fractol->setvalue.ycenter += modi;
	if (key == 124)
		fractol->setvalue.xcenter += modi;
	if (key == 123)
		fractol->setvalue.xcenter -= modi;
}