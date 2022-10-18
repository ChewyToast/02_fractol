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
	else if (key == 126 || (key == 125) || (key == 124) || (key == 123) || (key == 8))
		move_center(key, fractol);
	else
		cli_ask(key, fractol);
}

static void	cli_ask(int key, t_fractol *fractol)
{
	if (key == 15)
	{
		ft_printf("\nEnter the desired resolution to see the fractal (default: 150): ");
		fractol->iter_max = ft_atoi(get_next_line(0));
		ft_printf("\nResolution set to: %d", fractol->iter_max);
	}
	else if (key == 12)
	{
		fractol->plus_iter += 20;
		fractol->iter_max = fractol->plus_iter * pow(log10(fractol->setvalue.zoom + 10), 1.25);
	}
	else if (key == 13 && fractol->plus_iter > 20)
	{
		fractol->plus_iter -= 20;
		fractol->iter_max = fractol->plus_iter * pow(log10(fractol->setvalue.zoom + 10), 1.25);
	}
	else if (key == 257 && fractol->set == 'j')
		fractol->shift_press = 1;

	ft_printf("keypress: %d", key);
}

static void	move_center(int key, t_fractol *fractol)
{
	if (key == 126)
		fractol->setvalue.ycenter -= fractol->center_modi;
	if (key == 125)
		fractol->setvalue.ycenter += fractol->center_modi;
	if (key == 124)
		fractol->setvalue.xcenter += fractol->center_modi;
	if (key == 123)
		fractol->setvalue.xcenter -= fractol->center_modi;
	if (key == 8)
	{
		fractol->setvalue.ycenter = 0;
		fractol->setvalue.xcenter = 0;
		fractol->setvalue.zoom = 1;
	}
}
